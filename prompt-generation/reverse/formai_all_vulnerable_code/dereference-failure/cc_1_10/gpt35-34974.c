//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of the C code string
#define MAX_LENGTH 10000

// Define the starting syntax of a function and its corresponding function name
#define FUNCTION_SYNTAX "void "

// Define the main function name
#define MAIN_FUNCTION_NAME "main"

// Define the starting syntax of a variable declaration
#define VARIABLE_SYNTAX "int "

// Define the ending syntax for a statement
#define STATEMENT_ENDING ";\n"

// Define the starting syntax of a comment
#define COMMENT_SYNTAX "//"

// Prototype functions
char* parseFunctionName(char* code);
void parseVariables(char* code);
void removeComments(char* code);
void protectCode(char* code);

int main() {
    // Allocate memory for the C code string
    char* code = (char*) malloc(MAX_LENGTH);
    
    // Read in the C code string
    printf("Enter your C code:\n");
    fgets(code, MAX_LENGTH, stdin);

    // Remove any comments from the code string
    removeComments(code);

    // Parse the function name and print it out
    char* functionName = parseFunctionName(code);
    printf("Function Name: %s\n", functionName);

    // Parse any variables and print them out
    parseVariables(code);

    // Protect the code by adding an additional set of curly braces
    protectCode(code);

    // Print out the protected code
    printf("\nProtected Code\n");
    printf("%s", code);

    // Free the memory allocated for the code string
    free(code);

    return 0;
}

// Parses the name of the function from the C code string
char* parseFunctionName(char* code) {
    // Find the function syntax in the code string
    char* ptrFunctionSyntax = strstr(code, FUNCTION_SYNTAX);

    // If the function syntax is found
    if(ptrFunctionSyntax != NULL) {
        // Find the end of the function name
        char* ptrFunctionEnd = strstr(ptrFunctionSyntax, "(");

        // Allocate memory for the function name and copy it over
        int functionNameLength = ptrFunctionEnd - (ptrFunctionSyntax + strlen(FUNCTION_SYNTAX));
        char* functionName = (char*) malloc(functionNameLength + 1);
        strncpy(functionName, ptrFunctionSyntax + strlen(FUNCTION_SYNTAX), functionNameLength);
        functionName[functionNameLength] = '\0';

        // Return the function name
        return functionName;
    } else {
        // If the function syntax is not found, return an empty string
        char* emptyString = (char*) malloc(1);
        emptyString[0] = '\0';
        return emptyString;
    }
}

// Parses any variables from the C code string and prints them out
void parseVariables(char* code) {
    // Find the main function in the code string
    char* ptrMainFunction = strstr(code, MAIN_FUNCTION_NAME);

    // If the main function is found
    if(ptrMainFunction != NULL) {
        // Find the end of the main function declaration
        char* ptrMainFunctionEnd = strchr(ptrMainFunction, '{');

        // Loop through the code and search for variable syntax
        char* ptrStart = ptrMainFunctionEnd + 1;
        while(*ptrStart != '}') {
            char* ptrVariableSyntax = strstr(ptrStart, VARIABLE_SYNTAX);

            // If variable syntax is found
            if(ptrVariableSyntax != NULL) {
                // Find the end of the variable declaration
                char* ptrVariableEnd = strstr(ptrVariableSyntax, STATEMENT_ENDING);

                // Print out the variable
                int variableLength = ptrVariableEnd - (ptrVariableSyntax + strlen(VARIABLE_SYNTAX));
                char* variableName = (char*) malloc(variableLength + 1);
                strncpy(variableName, ptrVariableSyntax + strlen(VARIABLE_SYNTAX), variableLength);
                variableName[variableLength] = '\0';
                printf("Variable: %s\n", variableName);

                // Move the pointer to the end of the statement
                ptrStart = ptrVariableEnd + strlen(STATEMENT_ENDING);
            } else {
                // If variable syntax is not found, break out of the loop
                break;
            }
        }
    }
}

// Removes any comments from the C code string
void removeComments(char* code) {
    char* ptrCommentStart;

    // Loop through the code and search for comment syntax
    while((ptrCommentStart = strstr(code, COMMENT_SYNTAX)) != NULL) {
        // Find the end of the comment (either a newline or end of string)
        char* ptrCommentEnd = strchr(ptrCommentStart, '\n');
        if(ptrCommentEnd == NULL) {
            ptrCommentEnd = code + strlen(code) - 1;
        }

        // Remove the comment by shifting everything after it forward
        memmove(ptrCommentStart, ptrCommentEnd, strlen(ptrCommentEnd) + 1);
    }
}

// Protects the C code by adding an additional set of curly braces
void protectCode(char* code) {
    // Find the main function in the code string
    char* ptrMainFunction = strstr(code, MAIN_FUNCTION_NAME);

    // If the main function is found
    if(ptrMainFunction != NULL) {
        // Find the end of the main function declaration
        char* ptrMainFunctionEnd = strchr(ptrMainFunction, '{');

        // Insert the opening brace before the main function
        *(ptrMainFunctionEnd + 1) = '{';

        // Find the end of the code string
        char* ptrEndOfCode = code + strlen(code);

        // Insert the closing brace at the end of the code
        *(ptrEndOfCode - 1) = '}';
        *(ptrEndOfCode) = '\0';
    }
}