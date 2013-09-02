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
    printf("opening input\n");
    // open input
    FILE* input = fopen(argv[1],"r");
    if(input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }
    
    
    // declare header
    Huffeader header;
    
    printf("writing magic number\n");
    //insert magic number
    header.magic = MAGIC;
    char c;
    int checksum = 0;
    int index;
    printf("initializing frequencies\n");
    for(index = 0;index<SYMBOLS;index++)
    {
        header.frequencies[index] = 0;
        
    }
    printf("calculating checksum\n");
    while((c = getc(input)) != EOF)
    {
        header.frequencies[(int)c] += 1;
        checksum += 1;
    }
    header.checksum = checksum;
    fclose(input);
    
    // open output file
    Huffile* output = hfopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open %s for writing.\n", argv[2]);
        return 1;
    }
    if (hwrite(&header, output) == false)
    {
        hfclose(output);
        printf("Could not write header.\n");
        return 1;
    }
    
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
    input = fopen(argv[1],"r");
    if(input == NULL)
    {
        printf("Could not open %s again for reading.\n", argv[1]);
        return 1;
    }
    printf("huffman tree complete\n");
    Tree* temp = huffman_tree;
    int count_input[SYMBOLS][100];
    int temp_array[100];
    int bit = 1;
    index = 0;
    printf("traversing the tree\n");
    while(true)
    {   
        temp_array[index] = bit;
        if(bit == 1)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
            bit = 1;
        }
        if(temp->right == NULL && temp->left == NULL)
        {
            int index1,check=0;
            for(index1 = 0;index1<=index;index1++)
            {   printf("%d",temp_array[index1]);
                count_input[(int)temp->symbol][index1] = temp_array[index1];
            }printf("\n");
            count_input[(int)temp->symbol][index+1] = -1;
            for(index1=0;index1<=index;index1++)
            {
                 check+=temp_array[index1];
            }
            if(check == 0)
            {
                break;
            }
            temp = huffman_tree;
            int moveup=0,cont_zeros=0;
            for(index1=index;index1>=0;index1--)
            {
                cont_zeros+=temp_array[index1];
                if(temp_array[index1] == 0 && cont_zeros == 0)
                {
                  moveup++;
                }
            }
            for(index1=0;index1<index-moveup;index1++)
            {
                if(temp_array[index1])
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }    
            }
            bit = 0;
            index -=(1+moveup); 
        }
        index++;
    }
    printf("traversing complete\n");
    temp=huffman_tree;
    while ((c = getc(input)) != EOF)
    {
        for(index=0;count_input[(int)c][index] != -1;index++)
        {
            bwrite(count_input[(int)c][index],output);
        }
    }

    // close input
    fclose(input);
    hfclose(output);
    return 0;
}
