//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct Word words[MAX_WORDS];
int wordCount;

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                int i;
                for (i = 0; i < wordCount; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (i == wordCount) {
                    strcpy(words[wordCount].word, word);
                    words[wordCount].count = 1;
                    wordCount++;
                }
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
}

int main() {
    loadWords();
    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        char *date = strtok(input, " ");
        if (date == NULL) {
            continue;
        }
        struct tm dateStruct;
        strptime(date, "%Y-%m-%d", &dateStruct);
        int day = dateStruct.tm_mday;
        int month = dateStruct.tm_mon + 1;
        int year = dateStruct.tm_year + 1900;
        if (year < 1000 || year > 9999) {
            printf("Invalid year.\n");
            continue;
        }
        if (month < 1 || month > 12) {
            printf("Invalid month.\n");
            continue;
        }
        if (day < 1 || day > 31) {
            printf("Invalid day.\n");
            continue;
        }
        printf("Today is %s.\n", ctime(&dateStruct.tm_mday));
        int i;
        for (i = 0; i < wordCount; i++) {
            if (words[i].count == 1) {
                printf("Today is %s.\n", words[i].word);
            }
        }
    }
    return 0;
}