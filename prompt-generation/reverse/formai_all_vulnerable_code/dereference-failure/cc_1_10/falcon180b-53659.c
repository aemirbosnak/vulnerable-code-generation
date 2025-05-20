//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *file;
    char filename[50];
    char line[100];
    int num_words = 0;
    WordPair words[MAX_WORDS];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read in words and translations
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: Invalid line in file.\n");
            exit(1);
        }

        strcpy(words[num_words].word, word);
        strcpy(words[num_words].translation, translation);
        num_words++;

        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
    }

    // Close file
    fclose(file);

    // Prompt user for input
    printf("Enter a sentence: ");
    scanf("%s", line);

    // Translate words
    int i = 0;
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int j = 0;
        while (j < num_words && strcmp(words[j].word, word)!= 0) {
            j++;
        }
        if (j < num_words) {
            printf("%s ", words[j].translation);
        } else {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}