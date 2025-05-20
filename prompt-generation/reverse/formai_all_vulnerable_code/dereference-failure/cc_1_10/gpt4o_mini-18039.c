//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_HISTORY 10
#define MAX_LENGTH 100

// Function Prototypes
void clearBuffer();
int isPalindrome(const char *str);
char *getFilteredString(const char *str);
void displayHistory(char history[MAX_HISTORY][MAX_LENGTH], int count);

int main() {
    char input[MAX_LENGTH];
    char history[MAX_HISTORY][MAX_LENGTH];
    int historyCount = 0;
    char continueCheck;
    
    printf("Welcome to the C Palindrome Checker!\n");
    printf("Type a phrase and I will check if it is a palindrome.\n\n");

    do {
        printf("Enter a phrase: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char *filteredInput = getFilteredString(input);

        // Check if the filtered input is a palindrome
        if (isPalindrome(filteredInput)) {
            printf("\"%s\" is a palindrome!\n\n", input);
        } else {
            printf("\"%s\" is not a palindrome.\n\n", input);
        }

        // Store the result in history
        if (historyCount < MAX_HISTORY) {
            strcpy(history[historyCount], input);
            historyCount++;
        } else {
            // Shift history to the left if full
            for (int i = 1; i < MAX_HISTORY; i++) {
                strcpy(history[i-1], history[i]);
            }
            strcpy(history[MAX_HISTORY - 1], input);
        }

        printf("Do you want to check another phrase? (y/n): ");
        continueCheck = getchar();
        clearBuffer();
        
        // Free the filtered input
        free(filteredInput);

    } while (continueCheck == 'y' || continueCheck == 'Y');
    
    printf("\nThank you for using the Palindrome Checker!\n");
    printf("Here are your attempts:\n");
    displayHistory(history, historyCount);

    return 0;
}

int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    
    return 1; // Is a palindrome
}

char *getFilteredString(const char *str) {
    // Filter out non-alphanumeric characters and convert to lowercase
    char *filtered = (char *)malloc(MAX_LENGTH);
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char)str[i])) {
            filtered[index++] = tolower((unsigned char)str[i]);
        }
    }
    filtered[index] = '\0'; // Null-terminate the filtered string

    return filtered;
}

void displayHistory(char history[MAX_HISTORY][MAX_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
}