//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char line[MAX_WORD_LENGTH];
    char *word;
    int count = 0;

    WordCount words[MAX_WORDS];

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        count++;
        if (count > MAX_WORDS) {
            fprintf(stderr, "Error: Too many words in file.\n");
            exit(1);
        }

        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == count) {
                strcpy(words[count].word, word);
                words[count].count = 1;
                count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No file specified.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    read_file(file, filename);

    fclose(file);

    return 0;
}