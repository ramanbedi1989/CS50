#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"


int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }
    int index;
    Forest* f1 = mkforest();
    for(index = 0; index<SYMBOLS;index++)
    {
      if(header.frequencies[index] != 0)
      {
        Tree* t1 = mktree();
        t1->symbol = (char)index;
        t1->frequency = header.frequencies[index];
        plant(f1,t1);
      }
    }
    
    while(true)
    {
        Tree* temp1 = pick(f1);
        Tree* temp2 = pick(f1);
        if(temp2 != NULL)
        {
          Tree* new_tree = mktree();
          new_tree->left = temp1;
          new_tree->right = temp2;
          new_tree->frequency = temp1->frequency + temp2->frequency;
          plant(f1,new_tree);
        }
        else
        {
          plant(f1,temp1);
          break;
        }
    }
    Tree* huffman_tree = pick(f1);
    int bit;
    Tree* temp = huffman_tree;
    FILE *output = fopen(argv[2],"w");
    while ((bit = bread(input)) != EOF)
    {
        if(bit == 1)
        {
            temp = temp->right;
            if(temp->right == NULL && temp->left ==NULL)
            {
              fprintf(output,"%c",temp->symbol);
              temp = huffman_tree;
            }
        }
        else
        {
            temp = temp->left;
            if(temp->right == NULL && temp->left ==NULL)
            {
              fprintf(output,"%c",temp->symbol);
              temp = huffman_tree;
            }
        }
    }

    // close input
    hfclose(input);
    return 0;
}
