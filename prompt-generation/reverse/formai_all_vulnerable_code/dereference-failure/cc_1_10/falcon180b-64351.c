//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char **words;
int num_words;
int max_word_length;

void read_words(char *filename) {
    FILE *file;
    char *line;
    char *word;
    int line_number = 0;
    int word_number = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    words = (char **)malloc(MAX_WORDS * sizeof(char *));

    while ((line = fgets(line, MAX_WORD_LENGTH, file))!= NULL) {
        line_number++;
        word = strtok(line, " ");
        while (word!= NULL) {
            word_number++;
            if (word_number > num_words) {
                printf("Error: too many words in file %s\n", filename);
                exit(1);
            }
            if (strlen(word) > max_word_length) {
                printf("Error: word \"%s\" in file %s is too long\n", word, filename);
                exit(1);
            }
            words[word_number] = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(words[word_number], word);
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sort_words() {
    qsort(words, num_words, sizeof(char *), compare_strings);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_words(argv[1]);
    sort_words();

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}