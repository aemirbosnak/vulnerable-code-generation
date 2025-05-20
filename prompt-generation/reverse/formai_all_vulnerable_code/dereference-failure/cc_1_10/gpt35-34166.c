//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <ctype.h> 

#define TRUE 1
#define FALSE 0

FILE *file;
char *word;
int length;

// Function to check if the word is correctly spelled
int check_word(char *word, int length) {
    // Check each letter of the word
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return FALSE; // Contains non-alphabetic characters
        } 
    }

    // Word is correctly spelled
    return TRUE;
}

// Function to read the file and check each word
void check_file(FILE *file) {
    char ch;
    int i = 0;

    // Read each character of the file
    while ((ch = fgetc(file)) != EOF) {
        // If character is not a space, add it to the word
        if (ch != ' ') {
            word[i++] = tolower(ch);
        } else { // Otherwise, check the word
            if (check_word(word, i)) {
                printf("%s ", word); // Print correctly spelled word
            } else {
                printf("[%s] ", word); // Print misspelled word
            }
            i = 0; // Reset the word
        }
    }

    // Check the last word of the file
    if (check_word(word, i)) {
        printf("%s", word); // Print correctly spelled word
    } else {
        printf("[%s]", word); // Print misspelled word
    }
}

int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: spellcheck <filename>\n");
        return 1;
    }

    // Open the file
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for word
    length = 50;
    word = (char *) malloc(length * sizeof(char));

    // Call check_file to read the file and check each word
    check_file(file);

    // Free the memory and close the file
    free(word);
    fclose(file);

    return 0; // Exit the program
}