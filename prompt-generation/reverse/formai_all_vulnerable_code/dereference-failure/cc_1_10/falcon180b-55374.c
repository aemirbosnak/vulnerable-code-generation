//Falcon-180B DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    int words_count = 0, i = 0;
    struct word words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", argv[2]);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (words_count >= MAX_WORDS) {
                printf("Error: Too many words\n");
                return 1;
            }

            int len = strlen(word);
            if (len > MAX_WORD_LENGTH) {
                printf("Error: Word too long\n");
                return 1;
            }

            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;

            word = strtok(NULL, ",.?!;:");
        }
        words_count++;
    }

    for (i = 0; i < words_count; i++) {
        fprintf(fp, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    return 0;
}