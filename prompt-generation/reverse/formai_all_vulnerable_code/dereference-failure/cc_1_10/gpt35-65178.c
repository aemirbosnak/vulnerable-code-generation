//FormAI DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct dict {
    char word[20];
};

/*
    The loadDict() function reads in the dictionary file and stores each
    word in an array of struct dict. The function takes two arguments -
    the pointer to the file and the size of the dictionary array.
    The function returns the number of words read in from the dictionary.
*/
int loadDict(FILE *fp, struct dict *dictionary, int size) {
    int i = 0;
    while ((i < size) && (fscanf(fp, "%s", dictionary[i].word) == 1)) {
        i++;
    }
    return i;
}

/*
    The spellCheck() function takes a string as input and checks each word
    against the dictionary array. If the word is not found in the dictionary,
    it is marked as misspelled and printed to the console.
*/
void spellCheck(char *line, struct dict *dictionary, int size) {
    int i, j, len = strlen(line);
    char word[20] = "";
    for (i = 0; i < len; i++) {
        if (isalpha(line[i])) {
            strncat(word, &line[i], 1);
        }
        else {
            for (j = 0; j < size; j++) {
                if (strcmp(word, dictionary[j].word) == 0) {
                    break;
                }
            }
            if (j == size) {
                printf("%s is misspelled\n", word);
            }
            memset(word, 0, sizeof(word));
        }
    }
}

int main() {
    char filename[] = "dictionary.txt";
    FILE* fp;
    struct dict *dictionary;
    int size, i;
    char line[100];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    // Count the number of words in the dictionary file
    size = 0;
    while (fscanf(fp, "%*s") == 1) size++;
    rewind(fp);
    // Allocate memory for the dictionary array
    dictionary = malloc(size * sizeof(struct dict));
    if (dictionary == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    // Load the dictionary into memory
    loadDict(fp, dictionary, size);
    fclose(fp);

    // Get user input
    printf("Enter a sentence: ");
    fgets(line, 100, stdin);

    // Check the spelling of the input sentence
    spellCheck(line, dictionary, size);

    // Free the memory allocated for the dictionary array
    free(dictionary);
    return 0;
}