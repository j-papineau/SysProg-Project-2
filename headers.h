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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME_SIZE 7
#define SEGMENT_SIZE 9

#include "directives.h"
#include "errors.h"
#include "opcodes.h"
#include "symbols.h"

typedef struct address
{
	int start;
	int current;
	int increment;
	int base;
} address;

typedef struct segment
{
	char label[SEGMENT_SIZE];
	char operation[SEGMENT_SIZE];
	char operand[SEGMENT_SIZE];
} segment;