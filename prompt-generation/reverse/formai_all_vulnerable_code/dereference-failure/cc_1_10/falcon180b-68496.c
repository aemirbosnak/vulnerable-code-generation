//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char *word;
    int frequency;
};

int main() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    fclose(fp);
                    return 1;
                }
                words[num_words].word = strdup(word);
                words[num_words].frequency = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word\t\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}