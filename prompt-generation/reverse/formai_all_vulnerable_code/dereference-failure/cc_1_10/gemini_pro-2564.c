//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A cheerful greeting to welcome the user.
void welcome() {
    printf("****** Welcome to the C Word Count Tool! ******\n");
    printf("Let's count those words together! :D\n\n");
}

// A simple function to get a string from the user.
char* get_string() {
    char* str = (char*)malloc(100);

    printf("Enter your text here (max 100 characters): ");
    scanf("%[^\n]%*c", str);

    return str;
}

// The heart of the program: counting the words in a string.
int count_words(char* str) {
    int word_count = 0;
    int i = 0;
    int in_word = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        i++;
    }

    return word_count;
}

// A cheerful function to display the results.
void display_results(char* str, int word_count) {
    printf("\n****** Results for '%s': ******\n", str);
    printf("Number of words: %d\n", word_count);
    printf("Keep writing, keep shining! :D\n\n");
}

int main() {
    // Start with a cheerful greeting.
    welcome();

    // Get the input string from the user.
    char* str = get_string();

    // Count the words in the string.
    int word_count = count_words(str);

    // Display the results.
    display_results(str, word_count);

    // Free up the allocated memory.
    free(str);

    return 0;
}