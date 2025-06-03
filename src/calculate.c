#include <ncurses.h>
#include <stdlib.h>
#include "entry.h"

void calculate(char x_string[], char y_string[], WINDOW * output, char operator, int mode)
{
	double x = strtod(x_string, NULL);
	double y = strtod(y_string, NULL);

	switch (mode)
	{
		case 0:
			wclear(output);
			mvwprintw(output, 1 ,1, "%g", y * (x / 100) );
			break;
		case 1:
			wclear(output);
			mvwprintw(output, 1 ,1, "%g", x / (y / 100) );
			break;
		case 2:
			wclear(output);
			mvwprintw(output, 1 ,1, "%g", (y - x) / (x / 100) );
			break;
		case 3:
			wclear(output);
			if      (operator == '+')
			{
				mvwprintw(output, 1 ,1, "%g", x + (x * (y/100)) );
			}
			else if (operator == '-')
			{
				mvwprintw(output, 1 ,1, "%g", x - (x * (y/100)) );
			}
			break;
	}
}

