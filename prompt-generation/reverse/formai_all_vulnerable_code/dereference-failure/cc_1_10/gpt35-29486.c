//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50

// Data structure to store the tokenized representation of the input string
typedef struct Token {
    char type[MAX_LENGTH];
    char value[MAX_LENGTH];
} Token;

// Function to tokenize the input string
Token* tokenize(char* input) {
    Token* tokens = malloc(sizeof(Token));
    int position = 0;
  
    // Loop through the input string character by character
    for(int i = 0; i < strlen(input); i++) {
        char current = input[i];
      
        // Skip over any whitespaces
        if(current == ' ') {
            continue;
        }
      
        // If the character is a digit, generate a token for a number
        if(isdigit(current)) {
            char value[MAX_LENGTH];
            value[0] = current;
            int j = 1;
            while(isdigit(input[i+1])) {
                value[j] = input[i+1];
                i++;
                j++;
            }
            value[j] = '\0';
            strcpy(tokens[position].type,"NUMBER");
            strcpy(tokens[position].value,value);
            position++;
            continue;
        }
      
        // If the character is an operator, generate a token for an operator
        if(current == '+' || current == '-' || current == '*' || current == '/') {
            char operator[MAX_LENGTH];
            operator[0] = current;
            operator[1] = '\0';
            strcpy(tokens[position].type,"OPERATOR");
            strcpy(tokens[position].value,operator);
            position++;
            continue;
        }
    }
  
    // Add a null token at the end to mark the end of the list of tokens
    strcpy(tokens[position].type,"NULL");
    strcpy(tokens[position].value,"NULL");
  
    return tokens;
}

int main() {
    // Get input string from the user
    char input[MAX_LENGTH];
    printf("Enter an arithmetic expression: ");
    fgets(input, MAX_LENGTH, stdin);
  
    // Tokenize the input string
    Token* tokens = tokenize(input);
  
    // Print out the list of tokens
    printf("List of tokens:\n");
    for(int i = 0; strcmp(tokens[i].type,"NULL") != 0; i++) {
        printf("type: %s, value: %s\n",tokens[i].type,tokens[i].value);
    }
  
    free(tokens);
    return 0;
}