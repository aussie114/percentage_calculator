#include <ncurses.h>
#include "entry.h"
#include "builder.h"

void build_ui(ENTRY input_entries[], ENTRY output_entries[])
{
	mvprintw( 1, 0, " What is                   %%                  of                   ?");
	mvprintw( 4, 0, "                           is what percentage of                   ?                    %%");
	mvprintw( 6, 0, " What is the percentage increase/decrease                       ");
	mvprintw( 8, 0, "  from                              to                             ?                    %%");
	mvprintw(11, 0, " What is                                                           %%");

	refresh();

	input_entries[0] = (ENTRY){ 1, 10, newwin(3, 17,  0,  9), {0}};
	input_entries[1] = (ENTRY){ 1, 50, newwin(3, 17,  0, 49), {0}};

	input_entries[2] = (ENTRY){ 4, 10, newwin(3, 17,  3,  9), {0}};
	input_entries[3] = (ENTRY){ 4, 50, newwin(3, 17,  3, 49), {0}};

	input_entries[4] = (ENTRY){ 8, 10, newwin(3, 17,  7,  9), {0}};
	input_entries[5] = (ENTRY){ 8, 50, newwin(3, 17,  7, 49), {0}};

	input_entries[6] = (ENTRY){11, 10, newwin(3, 17, 10,  9), {0}};
	input_entries[7] = (ENTRY){11, 27, newwin(3, 23, 10, 26), {0}};
	input_entries[8] = (ENTRY){11, 50, newwin(3, 17, 10, 49), {0}};

	output_entries[0] = (ENTRY){ 1, 70, newwin(3, 17,  0, 70), {0}};
	output_entries[1] = (ENTRY){ 4, 70, newwin(3, 17,  3, 70), {0}};
	output_entries[2] = (ENTRY){ 8, 70, newwin(3, 17,  7, 70), {0}};
	output_entries[3] = (ENTRY){11, 70, newwin(3, 17, 10, 70), {0}};

	input_entries[7].buffer[0] = '+';
	mvwprintw(input_entries[7].box, 1,1, "          %s", input_entries[7].buffer);
}

