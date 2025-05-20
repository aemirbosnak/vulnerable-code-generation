//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            dictionary[i].count++;
            return;
        }
    }

    if (num_words >= MAX_WORDS) {
        fprintf(stderr, "Error: Dictionary is full.\n");
        return;
    }

    strcpy(dictionary[num_words].word, word);
    dictionary[num_words].count = 1;
    num_words++;
}

int check_spelling(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    FILE *fp;
    char line[1024];
    char *word;

    // Open the dictionary file.
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read each line from the dictionary file and add it to the dictionary.
    while (fgets(line, sizeof(line), fp) != NULL) {
        word = strtok(line, " \n");
        add_word(word);
    }

    // Close the dictionary file.
    fclose(fp);

    // Get the input text from the user.
    printf("Enter some text: ");
    fgets(line, sizeof(line), stdin);

    // Split the input text into words and check the spelling of each word.
    word = strtok(line, " \n");
    while (word != NULL) {
        if (!check_spelling(word)) {
            printf("Error: The word \"%s\" is not in the dictionary.\n", word);
        }
        word = strtok(NULL, " \n");
    }

    return 0;
}