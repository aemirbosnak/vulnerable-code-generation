//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_summary(char *file_name, char **word_list, int *word_counts) {
    FILE *fp;
    char line[1000];
    char *word;
    int i, j, k;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", file_name);
        return;
    }

    for (i = 0; i < 1000; i++) {
        word[i] = '\0';
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        word = strtok(line, " \t\n");
        while (word!= NULL) {
            for (j = 0; j < 1000; j++) {
                word_list[j][0] = '\0';
            }
            for (k = 0; k < i; k++) {
                if (strcmp(word, word_list[k]) == 0) {
                    word_counts[k]++;
                }
            }
            if (strcmp(word, word_list[i]) == 0) {
                word_counts[i]++;
            } else {
                strcpy(word_list[i], word);
                word_counts[i] = 1;
            }
            i++;
            word = strtok(NULL, " \t\n");
        }
    }
    fclose(fp);
}

int main() {
    char *file_name = "input.txt";
    char **word_list;
    int word_counts[1000];
    int i, j;

    word_list = (char **)malloc(sizeof(char *) * 1000);
    if (word_list == NULL) {
        printf("Unable to allocate memory\n");
        return 1;
    }
    memset(word_list, '\0', sizeof(char *) * 1000);
    memset(word_counts, '\0', sizeof(int) * 1000);

    get_summary(file_name, word_list, word_counts);

    printf("Summary:\n");
    for (i = 0; i < 1000; i++) {
        if (word_counts[i] > 0) {
            printf("%s: %d\n", word_list[i], word_counts[i]);
        }
    }

    return 0;
}