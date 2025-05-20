//FormAI DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    printf("Enter a C Syntax:\n");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    int length = strlen(input);
    int numOfTokens = 0;
    char* tokens[length];
    
    char* temp = strtok(input, " ");
    
    while(temp != NULL) {
        tokens[numOfTokens] = temp;
        ++numOfTokens;
        temp = strtok(NULL, " ");
    }
    
    if(numOfTokens == 0) {
        printf("Invalid syntax.\n");
        return 0;
    }
    
    int i;
    printf("Parsed tokens:\n");
    for(i = 0; i < numOfTokens; ++i) {
        printf("%d. %s\n", i+1, tokens[i]);
    }
    
    // Perform syntax analysis
    if(strcmp(tokens[0], "int") != 0) {
        printf("Error: Invalid data type.\n");
        return 0;
    }
    
    if(strspn(tokens[1], "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789") != strlen(tokens[1])) {
        printf("Error: Invalid identifier.\n");
        return 0;
    }
    
    if(strcmp(tokens[2], "=") != 0) {
        printf("Error: Missing assignment operator.\n");
        return 0;
    }
    
    int j = 3;
    while(j < numOfTokens) {
        if(strspn(tokens[j], "0123456789") != strlen(tokens[j])) {
            printf("Error: Invalid integer value.\n");
            return 0;
        }
        ++j;
    }
    
    printf("Syntax is correct.\n");
    return 0;
}