//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    struct word_count *wc;
    int num_words = 0;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    wc = malloc(sizeof(struct word_count) * 1000);
    if (wc == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            num_words++;

            for (i = 0; i < num_words; i++) {
                if (strcmp(wc[i].word, token) == 0) {
                    wc[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                strncpy(wc[num_words - 1].word, token, MAX_WORD_LENGTH);
                wc[num_words - 1].count = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }

    free(wc);
    return 0;
}