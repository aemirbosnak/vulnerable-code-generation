//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORDS];
    int count;
} WordCount;

void word_count(char *resume, WordCount *counts) {
    char *word = strtok(resume, " ");
    while (word!= NULL) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (counts[i].word[0] == '\0') {
                strcpy(counts[i].word, word);
                counts[i].count = 1;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *resume = NULL;
    size_t size = 0;
    ssize_t read;
    while ((read = getline(&resume, &size, fp))!= -1) {
        if (read > 0) {
            resume[read - 1] = '\0';
        }
    }
    fclose(fp);

    WordCount counts[MAX_WORDS];
    memset(counts, 0, sizeof(counts));

    word_count(resume, counts);

    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (counts[i].word[0]!= '\0') {
            printf("%s\t%d\n", counts[i].word, counts[i].count);
        }
    }

    free(resume);
    return 0;
}