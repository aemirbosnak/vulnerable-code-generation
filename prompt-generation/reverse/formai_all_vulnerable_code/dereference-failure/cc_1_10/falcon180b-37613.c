//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 10000

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char word[MAX_WORD_LEN] = {0};
    int word_count = 0;
    struct word_count *word_array = (struct word_count *)malloc(MAX_WORD_COUNT * sizeof(struct word_count));
    int i, j;

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(word, tolower(ch));
        } else {
            if (strlen(word) > 0) {
                for (i = 0; i < word_count; i++) {
                    if (strcmp(word_array[i].word, word) == 0) {
                        word_array[i].count++;
                        break;
                    }
                }
                if (i == word_count) {
                    strcpy(word_array[word_count].word, word);
                    word_array[word_count].count = 1;
                    word_count++;
                }
            }
            strcpy(word, "");
        }
    }

    fclose(fp);

    printf("Word\tFrequency\n");
    for (i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_array[i].word, word_array[i].count);
    }

    free(word_array);
    return 0;
}