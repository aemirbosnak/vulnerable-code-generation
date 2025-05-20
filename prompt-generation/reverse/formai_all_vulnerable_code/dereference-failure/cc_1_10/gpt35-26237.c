//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

/* Function to check if input string is a valid identifier */
bool isValidIdentifier(char* inputString){

    /* Check for first character of the identifier */
    if (!(inputString[0] == '_' || 
          (inputString[0] >= 'a' && inputString[0] <= 'z') || 
          (inputString[0] >= 'A' && inputString[0] <= 'Z')))
        return false;
  
    /* Check for the rest of the characters in the identifier */
    for (int i = 1; inputString[i] != '\0'; i++){
        if (!(inputString[i] == '_' || 
              (inputString[i] >= 'a' && inputString[i] <= 'z') || 
              (inputString[i] >= 'A' && inputString[i] <= 'Z') || 
              (inputString[i] >= '0' && inputString[i] <= '9')))
            return false;
    }
    return true;
}

/* Function to parse the input C syntax */
void parseCSyntax(char* inputString){

    /* Check for valid identifier */
    if(isValidIdentifier(inputString))
        printf("Valid identifier!\n");
    else
        printf("Invalid identifier!\n");

    /* Check for semicolon at the end of line */
    if(inputString[strlen(inputString)-1] == ';')
        printf("Semicolon found!\n");
    else
        printf("Semicolon not found!\n");

    /* Check for keywords in the input string */
    char keywords[32][10] = {"auto", "break", "case", "char", "const",
                             "continue", "default", "do", "double", "else",
                             "enum", "extern", "float", "for", "goto", 
                             "if", "int", "long", "register", "return",
                             "short", "signed", "sizeof", "static", "struct",
                             "switch", "typedef", "union", "unsigned", "void",
                             "volatile", "while"};
    char* token = strtok(inputString, " ");
    while (token != NULL){
        for(int i=0; i<32; i++){
            if(strcmp(token, keywords[i]) == 0){
                printf("Keyword '%s' found!\n", token);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

}

/* Driver function */
int main(){
    char inputString[100];
    printf("Enter the C syntax to parse: \n");
    fgets(inputString, 100, stdin);
  
    parseCSyntax(inputString);
  
    return 0;
}