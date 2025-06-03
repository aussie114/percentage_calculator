#include <ncurses.h>
#include "entry.h"

void draw_boxes(ENTRY entries[], int count)
{
	for (int i = 0; i < count; i++)
	{
		box(entries[i].box, 0, 0);
		wrefresh(entries[i].box);
	}
}

void set_keypad(ENTRY entries[], int count, int value)
{
	for (int i = 0; i < count; i++)
	{
		keypad(entries[i].box, value);
	}
}
