//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if input is happy
int checkHappy(char *str) {
    char happy_words[6][10] = {"happy", "joyful", "excited", "delighted", "gleeful", "ecstatic"};
    
    for(int i=0; i<6; i++) {
        if(strstr(str, happy_words[i]) != NULL)
            return 1;
    }
    
    return 0;
}

// Function to sanitize user input
void sanitizeInput(char *str) {
    int len = strlen(str);
    char *sanitized = malloc(sizeof(char) * len);
    int j = 0;
    
    for(int i=0; i<len; i++) {
        if(isalpha(str[i])) {
            sanitized[j++] = tolower(str[i]);
        }
    }
    
    sanitized[j] = '\0';
    
    // Check if input is happy
    if(checkHappy(sanitized)) {
        printf("Yay! Thank you for your happy message!");
    }
    else {
        printf("Sorry, we only accept happy messages.");
    }
}

int main() {
    char input[100];
    
    printf("Please enter a happy message (e.g. I am happy today): ");
    fgets(input, 100, stdin);
    
    // Replace newline with null char
    input[strcspn(input, "\n")] = '\0';
    
    sanitizeInput(input);
    
    return 0;
}