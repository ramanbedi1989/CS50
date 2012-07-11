/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

int temp=0;
// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
	int index1,index2;
	for(index1=0;index1<d;index1++)
	{
		for(index2=0;index2<d;index2++)
		{
			if(index1 == d-1 && index2 == d-1)
			{
				board[index1][index2]=95;
			}			
			else
			{			
				board[index1][index2]=(((d*d-1)-(index1*d))-index2);
			}
		}
	} 
	if(temp != 1)
	{
		if(d%2 == 0)
		{
			int swap;
			swap=board[d-1][d-2];
			board[d-1][d-2]=board[d-1][d-3];
			board[d-1][d-3]=swap;
		}
		temp=1;
	}  		
}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
	int index1,index2;
	for(index1=0;index1<d;index1++)
	{
		for(index2=0;index2<d;index2++)
		{
			if(board[index1][index2] == 95)
			{
				printf(" %c  ",board[index1][index2]);
			}		
			else
			{
				printf("%2d  ",board[index1][index2]);
			}	
		}
	printf("\n");
	}
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
	int index1,index2;
	for(index1=0;index1<d;index1++)
	{
		for(index2=0;index2<d;index2++)
		{
			if(board[index1][index2] == 95)
			{
				if(board[index1-1][index2] == tile)
				{
					int swap;
					swap=board[index1-1][index2];
					board[index1-1][index2]=board[index1][index2];
					board[index1][index2]=swap;
					return true;
				}
				else if(board[index1][index2-1] == tile)
				{
					int swap;
					swap=board[index1][index2-1];
					board[index1][index2-1]=board[index1][index2];
					board[index1][index2]=swap;
					return true;
				}
				else if(board[index1][index2+1] == tile)
				{
					int swap;
					swap=board[index1][index2+1];
					board[index1][index2+1]=board[index1][index2];
					board[index1][index2]=swap;
					return true;
				}
				else if(board[index1+1][index2] == tile)
				{
					int swap;
					swap=board[index1+1][index2];
					board[index1+1][index2]=board[index1][index2];
					board[index1][index2]=swap;
					return true;
				}
			}		
				
		}
	
	}
    return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
	int index1,index2;
	for(index1=0;index1<d;index1++)
	{
		for(index2=0;index2<d;index2++)
		{
			if(board[index1][index2] != 95)
			{
				if(board[index1][index2] != ((index1*d)+index2))
				{
					return false;
				}			
			}
		}
	} 
    
    return true;
}
