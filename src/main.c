#include <ncurses.h>
#include "entry.h"
#include "builder.h"
#include "batching_functions.h"
#include "input_handling.h"

int main() 
{

	initscr();

	// delay until window is correct size
	int ms = 0;
	while(getmaxx(stdscr) < 90 && ms < 100) 
	{
		refresh();
		napms(1);
		ms++;
	}

	// Create UI
	ENTRY input_entries[INPUT_ENTRY_COUNT];
	ENTRY output_entries[OUTPUT_ENTRY_COUNT];
	build_ui(input_entries, output_entries);

	// Configure ncurses
	keypad(stdscr, TRUE);
	set_keypad( input_entries,  INPUT_ENTRY_COUNT, TRUE);
	set_keypad(output_entries, OUTPUT_ENTRY_COUNT, TRUE);

	int key = 0;
	int index = 0;
	move(input_entries[index].y, input_entries[index].x);

	while(key != 'q')
	{
		draw_boxes( input_entries,  INPUT_ENTRY_COUNT);
		draw_boxes(output_entries, OUTPUT_ENTRY_COUNT);

		input_handling(&key, &index, input_entries, output_entries);
	}

	endwin();
}
