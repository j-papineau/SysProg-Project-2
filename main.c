#include "headers.h"

#define COMMENT 35
#define INPUT_BUF_SIZE 60
#define NEW_LINE 10
#define SPACE 32
#define SYMBOL_TABLE_SIZE 100

void performPass1(symbol* symbolTable[], char* filename, address* addresses);
void printSummary(address* addresses);
bool validateLine(segment* input);
struct segment* prepareSegments(char* line);
void trim(char string[]);


int main(int argc, char* argv[])
{
    char filename[80];

    //make sure file is present, if not, display error and exit
    if(argv[1] == NULL){
        displayError(MISSING_COMMAND_LINE_ARGUMENTS, "");
        exit(0);

    }else {
        strcpy(filename, argv[1]);
    }
    printf("Loading File: %s\n", filename);

	// Do not modify this statement
	//start, end, temp
	address addresses = { 0x00, 0x00, 0x00 };

	


	// Create the symbol table for storing the symbol data

    struct symbol* symbolTable[SYMBOL_TABLE_SIZE];
    initializeSymbolTable(symbolTable);

	// Perform Pass 1: read records from input file and load symbol data into the symbol table
	performPass1(symbolTable, filename, &addresses);
	
	// Display the symbol data contained in the symbol table
    //displaySymbolTable(symbolTable);
	
	// Display the assembly summary data
	
}

void performPass1(symbol* symbolTable[], char* filename, address* addresses)
{
	printf("Performing pass 1\n");
	
	//attempt to open file
	FILE *fptr = fopen(filename, "r");
	char readBuffer[INPUT_BUF_SIZE + 1];

	if(fptr == NULL){
		displayError(FILE_NOT_FOUND, filename);
	}else{
		//start reading file

		/*
			Steps:
			1. Check for Errors
				blanks
				labels with directive/opcode names
				operations with invalid d/o names
				verify directive is legal
				address exceeds memory
			2. Compute address
				determine memory reqs
			3. if label exists, add to symbol table
			4. summarize
		
		*/
		

		printf("Symbol Table Log\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		while(fgets(readBuffer, INPUT_BUF_SIZE, fptr)) {
			
			//line by line
			//ignore comments
			segment* tempSeg = prepareSegments(readBuffer);
			

			if(validateLine(tempSeg)){
				//continue doing stuff
				//start directive for start address
				if (isDirective(tempSeg->operation) == 6)
				{
					//store start address in index 0 of addresses array
					//convert hex value in code for easy incrementing
					sscanf(tempSeg->operand, "%x", &addresses[0].start);
					// addresses[0].start = atoi(tempSeg->operand);
					//also set address 2 for tracking purposes
					printf("START ADDRESS FOUND: %x\n", addresses[0].start);
				
					addresses[2].start = addresses[0].start;

					
					
				}
				//check if line has symbol, if so do stuff

				//else, track address and increment accordingly
				
			}

			

			memset(readBuffer, NULL, INPUT_BUF_SIZE);
		}
		fclose(fptr);

		printSummary(addresses);
	}
}

void printSummary(address* addresses){

	//print starting and ending address, as well as program size
	int size = 0;
	printf("Assembly Summary\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Starting Address: 0x%x\n", addresses[0].start);
	printf("Ending Address: 0x%x\n", addresses[1].start);
	printf("Program Size (bytes): %d \n", (addresses[1].start - addresses[0].start));

	

}

bool validateLine(segment* input){

	//check first for commented lines, return false but no error
	if (input->label[0] == '#')
	{
		return false;
	}
	//check for label on line, if there is one, validate it
		if(isDirective(input->label) != 0 || isOpcode(input->label)){
			displayError(ILLEGAL_SYMBOL, input->label);
			return false;
		}

		//validate operation

		bool validOperation = false;

		if(isDirective(input->operation) != 0){
			validOperation = true;
		}
		if(isOpcode(input->operation)){
			validOperation = true;
		}
		if(!validOperation){
			displayError(ILLEGAL_OPCODE_DIRECTIVE, input->operation);
			return false;
		}

		return true;

}

// Do no modify any part of this function
segment* prepareSegments(char* statement)
{
	struct segment* temp = malloc(sizeof(segment));
	strncpy(temp->label, statement, SEGMENT_SIZE - 1);
	strncpy(temp->operation, statement + SEGMENT_SIZE - 1, SEGMENT_SIZE - 1);
	strncpy(temp->operand, statement + (SEGMENT_SIZE - 1) * 2, SEGMENT_SIZE - 1);

	trim(temp->label); // Label
	trim(temp->operation); // Operation
	trim(temp->operand); // Operand
	return temp;
}

// Do no modify any part of this function
void trim(char value[])
{
	for (int x = 0; x < SEGMENT_SIZE; x++)
	{
		if (value[x] == SPACE)
		{
			value[x] = '\0';
		}
	}
}