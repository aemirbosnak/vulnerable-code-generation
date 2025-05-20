//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

void read_file(FILE* file, word_count* word_counts) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(word_counts[i].word, "");
            word_counts[i].count = 1;
            while (isalpha(ch)) {
                if (strlen(word_counts[i].word) >= MAX_WORD_LENGTH) {
                    printf("Error: Maximum word length reached.\n");
                    exit(1);
                }
                strcat(word_counts[i].word, &ch);
                ch = fgetc(file);
            }
            word_counts[i].word[strlen(word_counts[i].word) - 1] = '\0';
        } else if (isspace(ch)) {
            if (strlen(word_counts[i].word) > 0) {
                word_counts[i].count++;
            }
            word_counts[i].word[0] = '\0';
        } else {
            printf("Error: Invalid character found.\n");
            exit(1);
        }
        i++;
    }
}

void print_word_counts(word_count* word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(word_counts[i].word) > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    word_count word_counts[MAX_WORDS];
    read_file(file, word_counts);

    print_word_counts(word_counts);

    fclose(file);
    return 0;
}