//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse C syntax
int parseC(char* input) {
    int len = strlen(input);
    char* result = (char*)malloc(len + 1);
    char* token;
    char c;
    
    // Iterate through the input string
    for (int i = 0; i < len; i++) {
        c = input[i];
        
        // Check if the current character is a valid token
        if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[') {
            // Check for balanced parentheses
            if (c == '(') {
                if (result[i - 1] == '(') {
                    token = result + i - 1;
                    result[i - 1] = '\0';
                    printf("%s\n", token);
                    free(token);
                }
            } else if (c == ')') {
                if (result[i - 1] == '(') {
                    token = result + i - 1;
                    result[i - 1] = '\0';
                    printf("%s\n", token);
                    free(token);
                }
            } else if (c == '{' || c == '}') {
                if (result[i - 1] == '{' || result[i - 1] == '}') {
                    token = result + i - 1;
                    result[i - 1] = '\0';
                    printf("%s\n", token);
                    free(token);
                }
            } else if (c == '[') {
                if (result[i - 1] == '[') {
                    token = result + i - 1;
                    result[i - 1] = '\0';
                    printf("%s\n", token);
                    free(token);
                }
            }
        }
    }
    
    // Check for unbalanced parentheses
    if (result[len - 1] == '(' || result[len - 1] == ')' || result[len - 1] == '{' || result[len - 1] == '}' || result[len - 1] == '[') {
        token = result + len - 1;
        result[len - 1] = '\0';
        printf("%s\n", token);
        free(token);
    }
    
    // Free allocated memory
    free(result);
    
    return 0;
}

int main() {
    char input[] = "int main() { printf(\"Hello, World!\"); }";
    parseC(input);
    return 0;
}