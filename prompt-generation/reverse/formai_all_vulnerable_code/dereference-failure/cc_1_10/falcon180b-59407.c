//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int count;
} WordCount;

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount word_counts[MAX_LINE_LENGTH];
    int num_words = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LENGTH) {
                len = MAX_WORD_LENGTH;
            }
            strncpy(word_counts[num_words].word, token, len);
            word_counts[num_words].count = 1;
            num_words++;

            if (num_words >= MAX_LINE_LENGTH) {
                break;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}