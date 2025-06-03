#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"
#include "calculate.h"

void input_handling(int * key, int * index, ENTRY input_entries[], ENTRY output_entries[])
{
	*key = getch();
	if (*key == 'q') return;
	if (*key == KEY_RIGHT && *index < 8) (*index)++;
	if (*key == KEY_LEFT  && *index > 0) (*index)--;

	if      (*key == KEY_IC && *index != 7)
	{
		mvprintw(13,0, "-- INSERT --");
		wrefresh(stdscr);
		mvwprintw(input_entries[*index].box, 1, 1, "               ");
		mvwgetnstr( input_entries[*index].box, 1, 1, input_entries[*index].buffer, BUFFER_SIZE-1);
		mvprintw(13,0, "            ");
		// Row 0
		if      ( (*index == 0 || *index == 1) && (strlen(input_entries[0].buffer) && strlen(input_entries[1].buffer)) )
		{
			calculate(input_entries[0].buffer, input_entries[1].buffer, output_entries[0].box, input_entries[7].buffer[0], 0);
		}
		// Row 1
		else if ( (*index == 2 || *index == 3) && (strlen(input_entries[2].buffer) && strlen(input_entries[3].buffer)) )
		{
			calculate(input_entries[2].buffer, input_entries[3].buffer, output_entries[1].box, input_entries[7].buffer[0], 1);
		}
		// Row 2
		else if ( (*index == 4 || *index == 5) && (strlen(input_entries[4].buffer) && strlen(input_entries[5].buffer)) )
		{
			calculate(input_entries[4].buffer, input_entries[5].buffer, output_entries[2].box, input_entries[7].buffer[0], 2);
		}
		// Row 3
		else if ( (*index == 6 || *index == 8) && (strlen(input_entries[6].buffer) && strlen(input_entries[8].buffer)) )
		{
			calculate(input_entries[6].buffer, input_entries[8].buffer, output_entries[3].box, input_entries[7].buffer[0], 3);
		}


	}
	else if (*key == KEY_IC && *index == 7)
	{
		if (input_entries[7].buffer[0] == '+')
		{
			input_entries[7].buffer[0] = '-';
		}
		else
		{
			input_entries[7].buffer[0] = '+';
		}
		mvwprintw(input_entries[7].box, 1,1, "          %s", input_entries[7].buffer);

		if (strlen(input_entries[6].buffer) && strlen(input_entries[8].buffer))
		{
			calculate(input_entries[6].buffer, input_entries[8].buffer, output_entries[3].box, input_entries[7].buffer[0], 3);
		}
	}
	move(input_entries[*index].y, input_entries[*index].x);
}
