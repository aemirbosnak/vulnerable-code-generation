//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store tokens
typedef struct {
    char* type;
    char* value;
} Token;

// Define a function that reads the input text file
char* readInput(const char* filename) {
    FILE* inputFile = fopen(filename, "r"); // open file for reading

    if(inputFile == NULL) { // check if file could be opened
        printf("Failed to open input file.");
        exit(1);
    }

    fseek(inputFile, 0, SEEK_END); // move file pointer to end of file
    long fileSize = ftell(inputFile); // get file size in bytes
    rewind(inputFile); // move file pointer to start of file

    char* fileContents = calloc(fileSize + 1, sizeof(char)); // allocate memory for file contents

    if(fileContents == NULL) { // check if memory allocation was successful
        printf("Failed to allocate memory.");
        exit(1);
    }

    fread(fileContents, sizeof(char), fileSize, inputFile); // read file contents into memory
    fclose(inputFile); // close input file

    return fileContents;
}

// Define a function that creates a list of tokens from input text
Token* tokenize(char* inputText) {
    int numTokens = 0;
    Token* tokenList = calloc(numTokens + 1, sizeof(Token));

    char* tokenChars = strtok(inputText, " \n"); // get the first token

    while(tokenChars != NULL) { // loop through all tokens
        numTokens++; // increment number of tokens in list
        tokenList = realloc(tokenList, (numTokens + 1) * sizeof(Token)); // reallocate memory for token list

        Token newToken;

        if(strcmp(tokenChars, "int") == 0) { // check for integer keyword
            newToken.type = "INTEGER";
            newToken.value = NULL;
        }
        else if(strcmp(tokenChars, "+") == 0) { // check for addition operator
            newToken.type = "OPERATOR";
            newToken.value = "+";
        }
        else if(strcmp(tokenChars, "=") == 0) { // check for assignment operator
            newToken.type = "ASSIGNMENT";
            newToken.value = "=";
        }
        else { // assume token is an integer value
            newToken.type = "VALUE";
            newToken.value = tokenChars;
        }

        tokenList[numTokens - 1] = newToken; // add token to list
        tokenChars = strtok(NULL, " \n"); // get the next token
    }

    Token endToken;
    endToken.type = "END";
    endToken.value = NULL;
    tokenList[numTokens] = endToken; // add end token to list

    return tokenList;
}

// Define a function that parses the token list
void parseTokens(Token* tokenList) {
    int index = 0;
    Token currentToken = tokenList[index];

    while(strcmp(currentToken.type, "END") != 0) { // loop through all tokens
        if(strcmp(currentToken.type, "INTEGER") == 0) { // check for integer keyword
            index++;
            currentToken = tokenList[index];

            if(strcmp(currentToken.type, "VALUE") != 0) { // check if integer has a value
                printf("Error: integer keyword must be followed by a value.\n");
                exit(1);
            }
        }
        else if(strcmp(currentToken.type, "VALUE") == 0) { // check for integer value
            printf("Error: unexpected integer value.\n");
            exit(1);
        }
        else if(strcmp(currentToken.type, "OPERATOR") == 0 || strcmp(currentToken.type, "ASSIGNMENT") == 0) { // check for operator or assignment
            index++;
            currentToken = tokenList[index];

            if(strcmp(currentToken.type, "VALUE") != 0) { // check if operator or assignment has a value
                printf("Error: operator or assignment must be followed by a value.\n");
                exit(1);
            }

            index++;
            currentToken = tokenList[index];

            if(strcmp(currentToken.type, "OPERATOR") == 0 || strcmp(currentToken.type, "ASSIGNMENT") == 0) { // check if multiple operators or assignments in a row
                printf("Error: multiple operators or assignments in a row.\n");
                exit(1);
            }
        }

        index++;
        currentToken = tokenList[index];
    }
}

int main() {
    char* inputText = readInput("example.txt"); // read input text from file
    Token* tokenList = tokenize(inputText); // create token list from input text
    parseTokens(tokenList); // parse token list for syntax errors

    free(inputText);
    free(tokenList);

    return 0;
}