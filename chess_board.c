#include <stdio.h>
#include "chess_board_fnc.h"

#ifndef BOARD_ROWS
#define BOARD_ROWS 8
#endif

int main()
{
	int row;
	int scale;

	/*Input*/
	printf("Enter scale quantifier: "); scanf("%d", &scale);

	/*Output*/
	for (row = 1; row <= BOARD_ROWS; row++)
		print_row(row, scale);

	return 0;
}
