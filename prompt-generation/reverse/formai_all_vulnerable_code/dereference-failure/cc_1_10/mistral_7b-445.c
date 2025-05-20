//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp))) {
        char *token = strtok(buffer, " .,\n");
        while (token) {
            if (num_words >= MAX_WORDS) {
                fprintf(stderr, "Word count limit reached\n");
                break;
            }
            to_lower(words[num_words].word);
            strcpy(words[num_words].word, token);
            num_words++;
            token = strtok(NULL, " .,\n");
        }
    }

    if (ferror(fp)) {
        perror("Error reading file");
        return 1;
    }

    fclose(fp);

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                num_words--;
                free(words + j);
                break;
            }
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}