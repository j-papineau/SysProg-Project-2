/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 2.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

#define MOD_SIZE 10
#define SYMBOL_TABLE_SEGMENTS 10
#define SYMBOL_TABLE_SIZE 100

int computeHash(char* input);

int computeHash(char* symbolName)
{
	// return hashValue % MOD_SIZE * SYMBOL_TABLE_SEGMENTS;
}

void displaySymbolTable(symbol* symbolTable[])
{
    for(int i = 0; i < SYMBOL_TABLE_SIZE; i++){
        if(symbolTable[i] != NULL){
            printf("Print Row will be here\n");
        }else{
            printf("NULL row in symbol table\n");
        }
    }
}

void initializeSymbolTable(symbol* symbolTable[])
{
    for (int i = 0; i < SYMBOL_TABLE_SIZE; ++i) {
        symbolTable[i] = NULL;
    }
}

void insertSymbol(symbol* symbolTable[], char symbolName[], int symbolAddress)
{
	
}