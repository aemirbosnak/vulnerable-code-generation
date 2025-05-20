//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mystic_intro() {
    printf("**********************************\n");
    printf("* Welcome to the Palindrome Realm *\n");
    printf("**********************************\n");
    printf("Prepare to have your mind twisted and turned...\n");
    printf("Can you find the hidden words within?\n\n");
}

char* get_input() {
    char *str = NULL;
    size_t len = 0;
    
    printf("Whisper your word or phrase (type 'exit' to escape): ");
    getline(&str, &len, stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0; 
    
    return str;
}

char *clean_string(const char *input) {
    size_t size = strlen(input);
    char *cleaned = malloc(size + 1);
    int j = 0;

    for (size_t i = 0; i < size; i++) {
        if (isalnum(input[i])) {
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0'; // Null-terminate the cleaned string
    return cleaned;
}

int is_palindrome_recursive(const char *str, int start, int end) {
    if (start >= end) {
        return 1; // Base case: pointers have crossed or met
    }
    if (str[start] != str[end]) {
        return 0; // Mismatch found
    }
    // Recur with updated positions
    return is_palindrome_recursive(str, start + 1, end - 1);
}

void check_palindrome(char *input) {
    char *cleaned = clean_string(input);
    size_t len = strlen(cleaned);
    
    if (len == 0) {
        printf("Hmm... your input was empty or invalid.\n");
        free(cleaned); // Free the allocated memory
        return;
    }
    
    printf("The cleaned string is: \"%s\"\n", cleaned);
    
    if (is_palindrome_recursive(cleaned, 0, len - 1)) {
        printf("Congratulations, you've found a palindrome!\n");
    } else {
        printf("Alas! This string does not form a palindrome.\n");
    }
    
    free(cleaned); // Free the allocated memory
}

void conclude_musings() {
    printf("\nThank you for exploring the Palindrome Realm!\n");
    printf("May your thoughts always reflect with clarity!\n");
}

int main() {
    mystic_intro();
    char *input;

    while (1) {
        input = get_input();
        
        if (strcmp(input, "exit") == 0) {
            free(input); // Clean up memory before exit
            break; // Exit the loop if the user types "exit"
        }

        check_palindrome(input);
        free(input); // Clean up memory after processing input
    }

    conclude_musings();
    return 0;
}