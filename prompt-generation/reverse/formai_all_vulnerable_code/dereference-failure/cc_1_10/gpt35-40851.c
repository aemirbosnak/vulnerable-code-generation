//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
/* C Syntax Parsing Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store the parsed code */
typedef struct {
    char* varType;      /* Variable Type */
    char* varName;      /* Variable Name */
    char* varValue;     /* Variable Value */
} ParsedCode;

/* Declare the parsing function */
ParsedCode parseCode(char* code);

/* Main Function */
int main() {
    /* Define a sample code */
    char code[] = "int x = 5;\n float y = 3.14;\n char z = 'a';\n";
    
    /* Parse the code */
    ParsedCode parsedCode = parseCode(code);
    
    /* Print the parsed code */
    printf("Variable Type: %s\n", parsedCode.varType);
    printf("Variable Name: %s\n", parsedCode.varName);
    printf("Variable Value: %s\n", parsedCode.varValue);
    
    return 0;
}

/* Parse Code Function */
ParsedCode parseCode(char* code) {
    /* Define a variable to store the parsed code */
    ParsedCode parsedCode;
    parsedCode.varType = calloc(10, sizeof(char));
    parsedCode.varName = calloc(10, sizeof(char));
    parsedCode.varValue = calloc(10, sizeof(char));
    
    /* Define a variable to keep track of the current position in the code */
    int pos = 0;
    
    /* Loop through the code and parse the variables */
    while(code[pos] != '\0') {
        /* Ignore whitespace */
        while(code[pos] == ' ' || code[pos] == '\n' || code[pos] == '\t') {
            pos++;
        }
        
        /* Get the variable type */
        int i = 0;
        while(code[pos] != ' ') {
            parsedCode.varType[i++] = code[pos++];
        }
        
        /* Ignore whitespace */
        while(code[pos] == ' ' || code[pos] == '\t') {
            pos++;
        }
        
        /* Get the variable name */
        i = 0;
        while(code[pos] != ' ') {
            parsedCode.varName[i++] = code[pos++];
        }
        
        /* Ignore whitespace */
        while(code[pos] == ' ' || code[pos] == '\t') {
            pos++;
        }
        
        /* Ignore equals sign */
        pos++;
        
        /* Ignore whitespace */
        while(code[pos] == ' ' || code[pos] == '\t') {
            pos++;
        }
        
        /* Get the variable value */
        i = 0;
        while(code[pos] != ';' && code[pos] != '\n') {
            parsedCode.varValue[i++] = code[pos++];
        }
        
        /* Ignore the semicolon */
        pos++;
        
        /* Ignore whitespace */
        while(code[pos] == ' ' || code[pos] == '\n' || code[pos] == '\t') {
            pos++;
        }
    }
    
    /* Return the parsed code */
    return parsedCode;
}