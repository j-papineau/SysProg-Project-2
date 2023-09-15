/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 2.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

void displayError(int errorType, char* errorInfo)
{

    char* errorText;
    bool showErrorInfo = true;

    switch (errorType) {
        case BLANK_RECORD:
            errorText = "Blank Record";
            break;
        case DUPLICATE:
            errorText = "Duplicate";
            break;
        case FILE_NOT_FOUND:
            errorText = "File Not Found";
            break;
        case ILLEGAL_OPCODE_DIRECTIVE:
            errorText = "Illegal Opcode or Directive";
            break;
        case ILLEGAL_SYMBOL:
            errorText = "Illegal Symbol: Cannot be Opcode or Directive";
            break;
        case MISSING_COMMAND_LINE_ARGUMENTS:
            showErrorInfo = false;
            errorText = "Missing Command Line Arguments";
            break;
        case OUT_OF_MEMORY:
            errorText = "Out of Memory";
            break;
        case OUT_OF_RANGE_BYTE:
            errorText = "Out of Range Byte";
            break;
        case OUT_OF_RANGE_WORD:
            errorText = "Out of Range Work";
            break;
        
        default:
            errorText = "Undefined Error";
            break;
    }

    if(showErrorInfo){
        printf("ERROR: %s (%s) \n", errorText, errorInfo);
    }else{
        printf("ERROR: %s \n", errorText);
    }
    
}