#ifndef ENTRY_H
#define ENTRY_H

#define BUFFER_SIZE 16
#define  INPUT_ENTRY_COUNT 9
#define OUTPUT_ENTRY_COUNT 4

typedef struct 
{
	int y;
	int x;
	WINDOW * box;
	char buffer[BUFFER_SIZE];
} ENTRY;

#endif
