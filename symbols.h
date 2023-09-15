/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 2.
*
*  DO NOT MODIFY THIS FILE WITHOUT PERMISSION
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/
#pragma once

typedef struct symbol
{
	char name[NAME_SIZE];
	int address;
} symbol;

void displaySymbolTable(symbol* symbolTable[]);
void initializeSymbolTable(symbol* symbolTable[]);
void insertSymbol(symbol* symbolTable[], char symbolName[], int symbolAddress);