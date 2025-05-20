//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

char words[MAX_WORDS][WORD_LENGTH];
int num_words = 0;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

int find_word(char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return i;
        }
    }

    return -1;
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s load <filename> or %s search <word>\n", argv[0], argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "load") == 0) {
        load_words(argv[2]);
        printf("Loaded %d words from file\n", num_words);
    } else if (strcmp(argv[1], "search") == 0) {
        char word[WORD_LENGTH];
        printf("Enter word to search for: ");
        scanf("%s", word);

        int index = find_word(word);
        if (index == -1) {
            printf("Word not found\n");
        } else {
            printf("Word found at index %d\n", index);
        }
    } else {
        printf("Invalid command\n");
    }

    return 0;
}