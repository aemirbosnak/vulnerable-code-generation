//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100 // Maximum length of a word

int is_valid_char(char ch) {
    // Check if the character is valid for a word
    return isalpha(ch) || ch == '\''; // Allow apostrophes in contractions
}

int main() {
    // Open the input file for reading
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) { // File could not be opened
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Open the output file for writing
    FILE *fout = fopen("output.txt", "w");
    if (fout == NULL) { // File could not be opened
        printf("Error: Could not open output file\n");
        fclose(fp);
        return 1;
    }

    // Read the dictionary file into memory
    FILE *fdic = fopen("dictionary.txt", "r");
    if (fdic == NULL) { // File could not be opened
        printf("Error: Could not open dictionary file\n");
        fclose(fp);
        fclose(fout);
        return 1;
    }
    int num_words = 0;
    char **dict = malloc(sizeof(char *) * MAX_WORD_LEN);
    char word_buf[MAX_WORD_LEN];
    while (fscanf(fdic, "%s", word_buf) != EOF) {
        dict[num_words] = malloc(sizeof(char) * (strlen(word_buf) + 1)); 
        strcpy(dict[num_words], word_buf);
        num_words++;
    }
    fclose(fdic);

    // Read the input file line by line
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        char word[MAX_WORD_LEN];
        int i, j;
        for (i = 0, j = 0; line[i] != '\0'; i++) {
            // Clear the word buffer
            memset(word, 0, MAX_WORD_LEN);
            if (is_valid_char(line[i])) {
                int k;
                for (k = 0; is_valid_char(line[i]) && k < MAX_WORD_LEN; i++, k++) {
                    word[k] = tolower(line[i]);
                }
                int found = 0;
                // Check if the word is in the dictionary
                for (k = 0; k < num_words; k++) {
                    if (strcmp(word, dict[k]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    // Word was not found, print it to the output file
                    fprintf(fout, "%s ", word);
                }
                else {
                    // Word was found, print it to the output file with no changes
                    fprintf(fout, "%s", dict[k]);
                    if (line[i] != '\0') {
                        fprintf(fout, "%c", line[i]); // Print the character which comes after the word
                    }
                }
                j = i; // Update the index of last processed character
            }
        }
        if (line[j - 1] != '\n') { // Add a newline character if the line does not end with one
            fprintf(fout, "\n");
        }
    }
    fclose(fp);
    fclose(fout);

    // Free the dictionary memory
    int k;
    for (k = 0; k < num_words; k++) {
        free(dict[k]);
    }
    free(dict);

    return 0;
}