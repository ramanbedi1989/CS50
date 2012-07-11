/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
    //If number of command line inputs are not equal to 2 or 3 print the usage required
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    //Convert the first command line argument into an integer
    int n = atoi(argv[1]);

    //If the second optional input is given put it into srand()
    if (argc == 3)
        srand((unsigned int) atoi(argv[2]));
    else
        srand((unsigned int) time(NULL));

    // print a random number--the random number is genrated by using rand()
    for (int i = 0; i < n; i++)
        printf("%d\n", rand() % LIMIT);

    // return 0 to tell that program is finished
    return 0;
}
