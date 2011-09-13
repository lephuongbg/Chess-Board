#ifndef CB_FUNCTION
#define CB_FUNCTION

#define CELL_HEIGHT 2
#define CELL_WIDTH 3

#define BOARD_COLLUMNS 8
#define BOARD_ROWS 8

/*Function: print_row
 * Print a big row of the chess board
 * Parameter:
 * 	  chess_row		the row number of the board
 * 	  scale			the scale factor of the board
 */
void print_row(int chess_row, int scale)
{
	int x, y;
	int row = CELL_HEIGHT, col = CELL_WIDTH * BOARD_COLLUMNS;
	int white_first;
	int black_or_white;		/*Variable to check whether the pointer is in the black or white range */
	
	if (chess_row%2 == 0)	/*Check the board row*/
		white_first = 0;	/*Even row: Print black cell first*/
	else 
		white_first = 1;	/*Odd row: Print white cell first*/

	/*Scale the board*/
	row = row*scale;
	col = col*scale;
	
	
	for (x = 0; x < row; x++)					/*Loop on rows inside the board's big row*/
	{
		for (y = 0; y < col; y++)				/*Loop on cols inside the board's big row*/
		{
			if (white_first)								/*When print white cell first*/
			{
				black_or_white = (y/(CELL_WIDTH*scale))%2;	/*return 0 if in white and 1 if in black*/
				if (black_or_white == 0)
				{
					printf("%c[1;30;47m ",0x1B);			/*change the terminal background to black (47)*/
				}
				else
				{
					printf("%c[1;30;40m ", 0x1B);			/*change the terminal background to white (40)*/
				}
			} else {										/*When print black cell first*/
				black_or_white = (y/(CELL_WIDTH*scale))%2;	/*return 1 if in white and 0 if in black*/
				if (black_or_white == 0)
				{
					printf("%c[1;30;40m ",0x1B);
				}
				else
				{
					printf("%c[1;30;47m ", 0x1B);
				}
			}
			printf("%c[0m",0x1B);			/*Return terminal background to normal*/
		}
		printf("\n");			/*End one row inside the board's big row*/
	}
}


#endif
