//Falcon2-11B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sanitize_input(char *input) {
    int i, j;
    int len = strlen(input);
    
    // Check for null character
    if (input[len - 1] == '\0') {
        input[len - 1] = '\0'; // Remove trailing null character
        len--; // Adjust length
    }
    
    // Check for special characters
    for (i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            printf("Invalid character: %c\n", input[i]);
            return 1;
        }
    }
    
    // Check for repeated characters
    for (i = 0, j = 0; i < len - 1; i++) {
        if (input[i] == input[i+1]) {
            printf("Repeated character: %c\n", input[i]);
            return 1;
        }
    }
    
    // Check for string length
    if (len < 3 || len > 20) {
        printf("String length must be between 3 and 20 characters\n");
        return 1;
    }
    
    return 0;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';
    
    // Sanitize input
    if (sanitize_input(input)) {
        return 1;
    }
    
    printf("Input sanitized successfully!\n");
    
    return 0;
}