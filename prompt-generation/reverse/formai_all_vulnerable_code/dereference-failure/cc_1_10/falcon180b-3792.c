//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(char *filename, WordCount words[]) {
    FILE *file;
    char ch;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = ch;
            words[i].word[1] = '\0';
            words[i].count = 1;
            i++;
        } else if (isdigit(ch)) {
            strcat(words[i - 1].word, &ch);
        }
    }

    fclose(file);
}

void count_words(WordCount words[], int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void print_words(WordCount words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[100];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    read_words(filename, words);
    count_words(words, num_words);
    print_words(words, num_words);

    return 0;
}