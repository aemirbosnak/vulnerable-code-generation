//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word) {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    char *token;
    while (fgets(line, MAX_WORD_LENGTH, dictionary_file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, word) == 0) {
                fclose(dictionary_file);
                return 1;
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(dictionary_file);
    return 0;
}

// Function to read the input file
void read_input_file(char *filename) {
    FILE *input_file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    char *token;
    int word_count = 0;
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (is_in_dictionary(token)) {
                printf("%s\n", token);
            } else {
                printf("Possible misspelling: %s\n", token);
            }
            token = strtok(NULL, " ");
        }
        word_count++;
    }
    fclose(input_file);
    printf("Checked %d words.\n", word_count);
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    read_input_file(filename);
    return 0;
}