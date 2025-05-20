//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount words[]) {
    char line[MAX_WORD_LEN];
    char *word;
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORD_LEN; i++) {
                if (word[i] == '\0') {
                    word[i] = '\'';
                }
            }
            int j;
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == MAX_WORDS) {
                strcpy(words[j].word, word);
                words[j].count = 1;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void generate_alien_language(WordCount words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < words[i].count; j++) {
            printf("%s ", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;

    read_file(fp, argv[1], words);

    generate_alien_language(words, num_words);

    fclose(fp);
    return 0;
}