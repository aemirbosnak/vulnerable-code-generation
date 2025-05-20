//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 50

// Function to find the next word in the file
char* find_next_word(FILE* file) {
    char* word = malloc(WORD_SIZE * sizeof(char));
    int i = 0;

    while (i < WORD_SIZE && fgetc(file) != ' ' && fgetc(file) != '\n' && !feof(file)) {
        word[i] = tolower(fgetc(file));
        i++;
    }

    if (i > 0) {
        word[i] = '\0';
    }

    rewind(file);

    return word;
}

// Function to reverse a string
void reverse_string(char* str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    char* word = NULL;
    while ((word = find_next_word(input_file)) != NULL) {
        // Allocate memory for the reversed word
        char* reversed_word = malloc(strlen(word) * sizeof(char) + 1);

        // Reverse the word
        reverse_string(word);
        strcpy(reversed_word, word);

        // Write the reversed word to the output file
        fprintf(output_file, "%s ", reversed_word);

        // Free memory
        free(word);
        free(reversed_word);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Words in file reversed and written to output.txt\n");

    return 0;
}