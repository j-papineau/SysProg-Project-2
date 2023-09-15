/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 2.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BASE, BYTE, END, RESB, RESW, START, WORD
};

int getMemoryAmount(int directiveType, char* string)
{
	
}

int isDirective(char* string) 
{
	if (strcmp(string, "BASE") == 0) { return BASE; }
	else if (strcmp(string, "BYTE") == 0) { return BYTE; }
	else if(strcmp(string, "END") == 0) { return END; }
	else if (strcmp(string, "RESB") == 0) { return RESB; }
	else if (strcmp(string, "RESW") == 0) { return RESW; }
	else if (strcmp(string, "START") == 0) { return START; }
	else if (strcmp(string, "WORD") == 0) { return WORD; }
	else { return ERROR; }
}

bool isStartDirective(int directiveType)
{
	
}