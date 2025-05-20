//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words;

void generate_words() {
    FILE *fp;
    char ch;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    num_words = 0;
    while (num_words < MAX_WORDS && (ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            words[num_words].length = strlen(words[num_words].word);
            num_words++;
        } else {
            if (num_words < MAX_WORDS) {
                words[num_words].word[words[num_words].length] = ch;
                words[num_words].length++;
            }
        }
    }

    fclose(fp);
}

void print_words() {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    srand(time(0));
    generate_words();
    print_words();

    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int word_index = rand() % num_words;
    char word[MAX_WORD_LENGTH];
    strcpy(word, words[word_index].word);

    while (1) {
        printf("Type the word: %s\n", word);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strlen(input) == strlen(word) && strcmp(input, word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;

        if (total == 10) {
            break;
        }

        word_index = rand() % num_words;
        strcpy(word, words[word_index].word);
    }

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}