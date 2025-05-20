//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(const char* filename, WordCount* word_counts, int count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        char word[MAX_WORD_LENGTH];
        char* token = strtok(line, ",.!?;:");
        while (token!= NULL && i < MAX_WORD_LENGTH) {
            strcat(word, token);
            strcat(word, " ");
            token = strtok(NULL, ",.!?;:");
            i++;
        }
        word[i] = '\0';

        for (int j = 0; j < count; j++) {
            if (strcmp(word, word_counts[j].word) == 0) {
                word_counts[j].count++;
                break;
            }
        }
    }

    fclose(file);
}

void print_word_counts(WordCount* word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <word1> <word2>...\n", argv[0]);
        return 1;
    }

    int count = argc - 2;
    WordCount word_counts[count];

    for (int i = 0; i < count; i++) {
        strcpy(word_counts[i].word, argv[i + 2]);
        word_counts[i].count = 0;
    }

    read_file(argv[1], word_counts, count);
    print_word_counts(word_counts, count);

    return 0;
}