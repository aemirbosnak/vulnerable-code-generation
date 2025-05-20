//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare(const void *a, const void *b) {
    return strcmp(*(char *const *)a, *(char *const *)b);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *output = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    char *corrected = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    int word_count = 0;
    int max_word_length = 0;
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Dictionary file not found.\n");
        return 1;
    }
    struct word *word_list = (struct word *)malloc(MAX_WORDS * sizeof(struct word));
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        strcpy(word_list[word_count].word, line);
        word_list[word_count].count = 1;
        word_count++;
    }
    fclose(dictionary);
    qsort(word_list, word_count, sizeof(struct word), compare);
    printf("Enter a sentence or paragraph:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    char *token = strtok(input, ",.!?;:");
    while (token!= NULL) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word_list[i].word, token) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            strcpy(corrected, token);
        } else {
            strcpy(corrected, "Unknown word: ");
            strcat(corrected, token);
        }
        strcat(output, corrected);
        strcat(output, " ");
        token = strtok(NULL, ",.!?;:");
    }
    printf("Corrected sentence:\n%s\n", output);
    free(word_list);
    free(output);
    free(corrected);
    return 0;
}