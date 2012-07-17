/****************************************************************************
 * sudoku.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Implements the game of Sudoku.
 ***************************************************************************/

#include "sudoku.h"

#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// macro for processing control characters
#define CTRL(x) ((x) & ~0140)

// size of each int (in bytes) in *.bin files
#define INTSIZE 4


// wrapper for our game's globals
struct
{
    // the current level
    char *level;

    // the game's board
    int board[9][9];

    // the board's number
    int number;

    // the board's top-left coordinates
    int top, left;

    // the cursor's current location between (0,0) and (8,8)
    int y, x;
} g;


// prototypes
void draw_grid(void);
void draw_borders(void);
void draw_logo(void);
void draw_numbers(void);
void hide_banner(void);
bool load_board(void);
void handle_signal(int signum);
void log_move(int ch);
void redraw_all(void);
bool restart_game(void);
void show_banner(char *b);
void show_cursor(void);
void shutdown(void);
bool startup(void);
void check(int n,int x_dir,int y_dir);
int win(void);


/*
 * Main driver for the game.
 */

int
main(int argc, char *argv[])
{
    // define usage
   // const char *usage="Usage: sudoku n00b|l33t [#]\n";
    
    // ensure that number of arguments is as expected
    if (argc != 2 && argc != 3)
    {
        fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
        return 1;
    }

    // ensure that level is valid
    if (strcmp(argv[1], "debug") == 0)
        g.level = "debug";
    else if (strcmp(argv[1], "n00b") == 0)
        g.level = "n00b";
    else if (strcmp(argv[1], "l33t") == 0)
        g.level = "l33t";
    else
    {
        fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
        return 2;
    }

    // n00b and l33t levels have 1024 boards; debug level has 9
    int max = (strcmp(g.level, "debug") == 0) ? 9 : 1024;

    // ensure that #, if provided, is in [1, max]
    if (argc == 3)
    {
        // ensure n is integral
        char c;
        if (sscanf(argv[2], " %d %c", &g.number, &c) != 1)
        {
            fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
            return 3;
        }

        // ensure n is in [1, max]
        if (g.number < 1 || g.number > max)
        {
            fprintf(stderr, "That board # does not exist!\n");
            return 4;
        }

        // seed PRNG with # so that we get same sequence of boards
        srand(g.number);
    }
    else
    {
        // seed PRNG with current time so that we get any sequence of boards
        srand(time(NULL));

        // choose a random n in [1, max]
        g.number = rand() % max + 1;
    }

    // start up ncurses
    if (!startup())
    {
        fprintf(stderr, "Error starting up ncurses!\n");
        return 5;
    }

    // register handler for SIGWINCH (SIGnal WINdow CHanged)
    signal(SIGWINCH, (void (*)(int)) handle_signal);

    // start the first game
    if (!restart_game())
    {
        shutdown();
        fprintf(stderr, "Could not load board from disk!\n");
        return 6;
    }
    redraw_all();

    // let the user play!
    int ch,index,ji;
    int board_c[9][9];
    for(index=0;index<9;index++)
	{
		for(ji=0;ji<9;ji++)
		{
			board_c[index][ji]=g.board[index][ji];	
		}
	}
    do
    {
        // refresh the screen
        refresh();

        // get user's input
        ch = getch();

        // capitalize input to simplify cases
        ch = toupper(ch);

        // process user's input
        switch (ch)
        {
            // start a new game
            	case 'N': 
                g.number = rand() % max + 1;
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // restart current game
            	case 'R': 
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // let user manually redraw screen with ctrl-L
            	case CTRL('l'):
                redraw_all();
                break;
		case KEY_UP:
		if(g.y!=0)
		{		
			g.y+=-1;
		}
		show_cursor();
		refresh();
		break;
		case KEY_DOWN:
		if(g.y!=8)
		{		
			g.y+=1;
		}
		show_cursor();		
		refresh();
		break;
		case KEY_LEFT:
		if(g.x!=0)
		{		
			g.x+=-1;
		}		
		show_cursor();
		refresh();
		break;
	  	case KEY_RIGHT:
		if(g.x!=8)
		{		
			g.x+=1;
		}		
		show_cursor();
		refresh();
		break;
		case '1':
		if(board_c[g.y][g.x]==0 )
		{
			g.board[g.y][g.x]=1;
		}
		redraw_all();
		check(1,g.x,g.y);
		show_cursor();
		break;
		case '2':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=2;
		}
		redraw_all();
		check(2,g.x,g.y);
		show_cursor();
		break;
		case '3':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=3;
		}
		redraw_all();
		check(3,g.x,g.y);
		show_cursor();
		break;
		case '4':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=4;
		}
		redraw_all();
		check(4,g.x,g.y);
		show_cursor();
		break;
		case '5':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=5;
		}
		redraw_all();
		check(5,g.x,g.y);
		show_cursor();
		break;
		case '6':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=6;
		}
		redraw_all();
		check(6,g.x,g.y);
		show_cursor();
		break;
		case '7':
		if(g.board[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=7;
		}
		redraw_all();
		check(7,g.x,g.y);
		show_cursor();
		break;
		case '8':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=8;
		}
		redraw_all();
		check(8,g.x,g.y);
		show_cursor();
		break;
		case '9':
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=9;
		}
		redraw_all();
		check(9,g.x,g.y);
		show_cursor();
		break;
		case '0':
		case '.':
		case KEY_BACKSPACE:
		case KEY_DC:
		if(board_c[g.y][g.x]==0)
		{
			g.board[g.y][g.x]=0;
		}
		redraw_all();
		show_cursor();
        }
	int chek;
	chek=win();
	if(chek==0)
	{
		ch = 'Q';
	}
        // log input (and board's state) if any was received this iteration
        if (ch != ERR)
            log_move(ch);
    }
    while (ch != 'Q');

    // shut down ncurses
    shutdown();

    // tidy up the screen (using ANSI escape sequences)
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    // that's all folks
    printf("\nThanks!\n\n");
    return 0;
}


/*
 * Draw's the game's board.
 */

void
draw_grid(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // determine where top-left corner of board belongs 
    g.top = maxy/2 - 7;
    g.left = maxx/2 - 30;

    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_GRID));

    // print grid
    for (int i = 0 ; i < 3 ; ++i )
    {
        mvaddstr(g.top + 0 + 4 * i, g.left, "+-------+-------+-------+");
        mvaddstr(g.top + 1 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 2 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 3 + 4 * i, g.left, "|       |       |       |");
    }
    mvaddstr(g.top + 4 * 3, g.left, "+-------+-------+-------+" );

    // remind user of level and #
    char reminder[maxx+1];
    sprintf(reminder, "   playing %s #%d", g.level, g.number);
    mvaddstr(g.top + 14, g.left + 25 - strlen(reminder), reminder);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_GRID));
}
int win(void)
{
	int p,q;
	for(p=0;p<9;p++)
	{
	for(q=0;q<9;q++)
	{
	int n=g.board[p][q];
	if(n==0)
	{
		return 1;
	}
	int x_dir=q;
	int y_dir=p;	
	int m=(q%3);
	int no=(p%3);
	int i,j; 
	for(i=0;i<9;i++)
	{	
		if(i != y_dir)
		{
			if(g.board[i][x_dir] == n)
			{	
				/*redraw_all();
				mvaddstr(maxy-2, 1, "Hey this number is already present in this coloumn");*/
				return 1;
			}
		}
	}			
	for(i=0;i<9;i++)
	{	
		if(i != x_dir)
		{
			if(g.board[y_dir][i] == n)
			{	
				/*redraw_all();
				mvaddstr(maxy-2, 1, "Hey this number is already present in this row");*/
				return 1;
			}
		}
	}
	if(m==0 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					/*redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");*/
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==0 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==0 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
						return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					return 1;	
				}
				}		
			}		
		}
	
	}
	}
	}
	int ch;
	do
	{
        // refresh the screen
        refresh();

        // get user's input
        ch = getch();

        // capitalize input to simplify cases
        ch = toupper(ch);

        // process user's input
        //PAIR_GRID=COLOR_GREEN;
 	//BG_GRID=COLOR_BLACK;
	//FG_BORDER=COLOR_WHITE;
	//PAIR_BORDER=COLOR_GREEN;
	attron(COLOR_PAIR(PAIR_FINAL));
	redraw_all();
	int maxy, maxx;
   	getmaxyx(stdscr, maxy, maxx);
	mvaddstr(maxy-2, 1, "Congos you won the game!!!");

	}while(ch != 'Q');
	return 0;
	
}
void check(int n,int x_dir,int y_dir)
{
	int maxy, maxx;
   	getmaxyx(stdscr, maxy, maxx);			
	int i;
	for(i=0;i<9;i++)
	{	
		if(i != y_dir)
		{
			if(g.board[i][x_dir] == n)
			{	
				redraw_all();
				mvaddstr(maxy-2, 1, "Hey this number is already present in this coloumn");
				return;
			}
		}
	}			
	for(i=0;i<9;i++)
	{	
		if(i != x_dir)
		{
			if(g.board[y_dir][i] == n)
			{	
				redraw_all();
				mvaddstr(maxy-2, 1, "Hey this number is already present in this row");
				return;
			}
		}
	}
        int m=(x_dir%3);
	int no=(y_dir%3);
	int j; 
	if(m==0 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==0 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==0 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=0;j<3;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==1 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=-1;j<2;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==1)
	{
		for(i=-1;i<2;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	if(m==2 && no==2)
	{
		for(i=-2;i<1;i++)
		{
			for(j=-2;j<1;j++)
			{
				if((y_dir+i != y_dir)&&(x_dir+j!= x_dir))
				{
				if(g.board[y_dir+i][x_dir+j]==n)
				{
					redraw_all();
					mvaddstr(maxy-2, 1, "Hey this number is already present in this grid");
					return;	
				}
				}		
			}		
		}
	
	}
	redraw_all();
}
/*
 * Draws game's borders.
 */

void
draw_borders(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // enable color if possible (else b&w highlighting)
    if (has_colors())
    {
        attron(A_PROTECT);
        attron(COLOR_PAIR(PAIR_BORDER));
    }
    else
        attron(A_REVERSE);

    // draw borders
    for (int i = 0; i < maxx; i++)
    {
        mvaddch(0, i, ' ');
        mvaddch(maxy-1, i, ' ');
    }

    // draw header
    char header[maxx+1];
    sprintf(header, "%s by %s", TITLE, AUTHOR);
    mvaddstr(0, (maxx - strlen(header)) / 2, header);

    // draw footer
    mvaddstr(maxy-1, 1, "[N]ew Game   [R]estart Game");
    mvaddstr(maxy-1, maxx-13, "[Q]uit Game");

    // disable color if possible (else b&w highlighting)
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_BORDER));
    else
        attroff(A_REVERSE);
}


/*
 * Draws game's logo.  Must be called after draw_grid has been
 * called at least once.
 */

void
draw_logo(void)
{
    // determine top-left coordinates of logo
    int top = g.top + 2;
    int left = g.left + 30;

    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_LOGO));

    // draw logo
    mvaddstr(top + 0, left, "               _       _          ");
    mvaddstr(top + 1, left, "              | |     | |         ");
    mvaddstr(top + 2, left, " ___ _   _  __| | ___ | | ___   _ ");
    mvaddstr(top + 3, left, "/ __| | | |/ _` |/ _ \\| |/ / | | |");
    mvaddstr(top + 4, left, "\\__ \\ |_| | (_| | (_) |   <| |_| |");
    mvaddstr(top + 5, left, "|___/\\__,_|\\__,_|\\___/|_|\\_\\\\__,_|");

    // sign logo
    char signature[3+strlen(AUTHOR)+1];
    sprintf(signature, "by %s", AUTHOR);
    mvaddstr(top + 7, left + 35 - strlen(signature) - 1, signature);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_LOGO));
}


/*
 * Draw's game's numbers.  Must be called after draw_grid has been
 * called at least once.
 */

void
draw_numbers(void)
{
    // iterate over board's numbers
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // determine char
            char c = (g.board[i][j] == 0) ? '.' : g.board[i][j] + '0';
            mvaddch(g.top + i + 1 + i/3, g.left + 2 + 2*(j + j/3), c);
            refresh();
        }
    }
}


/*
 * Designed to handles signals (e.g., SIGWINCH).
 */

void
handle_signal(int signum)
{
    // handle a change in the window (i.e., a resizing)
    if (signum == SIGWINCH)
        redraw_all();

    // re-register myself so this signal gets handled in future too
    signal(signum, (void (*)(int)) handle_signal);
}


/*
 * Hides banner.
 */

void
hide_banner(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // overwrite banner with spaces
    for (int i = 0; i < maxx; i++)
        mvaddch(g.top + 16, i, ' ');
}


/*
 * Loads current board from disk, returning true iff successful.
 */

bool
load_board(void)
{
    // open file with boards of specified level
    char filename[strlen(g.level) + 5];
    sprintf(filename, "%s.bin", g.level);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        return false;

    // determine file's size
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    // ensure file is of expected size
    if (size % (81 * INTSIZE) != 0)
    {
        fclose(fp);
        return false;
    }

    // compute offset of specified board
    int offset = ((g.number - 1) * 81 * INTSIZE);

    // seek to specified board
    fseek(fp, offset, SEEK_SET);

    // read board into memory
    if (fread(g.board, 81 * INTSIZE, 1, fp) != 1)
    {
        fclose(fp);
        return false;
    }

    // w00t
    fclose(fp);
    return true;
}


/*
 * Logs input and board's state to log.txt to facilitate automated tests.
 */

void
log_move(int ch)
{
    // open log
    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL)
        return;

    // log input
    fprintf(fp, "%d\n", ch);

    // log board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        	fprintf(fp, "%d", g.board[i][j]);
        fprintf(fp, "\n");
    }

    // that's it
    fclose(fp);
}


/*
 * (Re)draws everything on the screen.
 */

void
redraw_all(void)
{
    // reset ncurses
    endwin();
    refresh();

    // clear screen
    clear();

    // re-draw everything
    draw_borders();
    draw_grid();
    draw_logo();
    draw_numbers();

    // show cursor
    show_cursor();
}


/*
 * (Re)starts current game, returning true iff succesful.
 */

bool
restart_game(void)
{
    // reload current game
    if (!load_board())
        return false;

    // redraw board
    draw_grid();
    draw_numbers();

    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // move cursor to board's center
    g.y = g.x = 4;
    show_cursor();

    // remove log, if any
    remove("log.txt");

    // w00t
    return true;
}


/*
 * Shows cursor at (g.y, g.x).
 */

void
show_cursor(void)
{
    // restore cursor's location
    move(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3));
}


/*
 * Shows a banner.  Must be called after show_grid has been
 * called at least once.
 */

void
show_banner(char *b)
{
    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_BANNER));

    // determine where top-left corner of board belongs 
    mvaddstr(g.top + 16, g.left + 64 - strlen(b), b);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_BANNER));
}


/*
 * Shuts down ncurses.
 */

void
shutdown(void)
{
    endwin();
}


/*
 * Starts up ncurses.  Returns true iff successful.
 */

bool
startup(void)
{
    // initialize ncurses
    if (initscr() == NULL)
        return false;

    // prepare for color if possible
    if (has_colors())
    {
        // enable color
        if (start_color() == ERR || attron(A_PROTECT) == ERR)
        {
            endwin();
            return false;
        }

        // initialize pairs of colors
        if (init_pair(PAIR_BANNER, FG_BANNER, BG_BANNER) == ERR ||
            init_pair(PAIR_GRID, FG_GRID, BG_GRID) == ERR ||
            init_pair(PAIR_BORDER, FG_BORDER, BG_BORDER) == ERR ||
            init_pair(PAIR_LOGO, FG_LOGO, BG_LOGO) == ERR)
        {
            endwin();
            return false;
        }
    }

    // don't echo keyboard input
    if (noecho() == ERR)
    {
        endwin();
        return false;
    }

    // disable line buffering and certain signals
    if (raw() == ERR)
    {
        endwin();
        return false;
    }

    // enable arrow keys
    if (keypad(stdscr, true) == ERR)
    {
        endwin();
        return false;
    }

    // wait 1000 ms at a time for input
    timeout(1000);

    // w00t
    return true;
}
