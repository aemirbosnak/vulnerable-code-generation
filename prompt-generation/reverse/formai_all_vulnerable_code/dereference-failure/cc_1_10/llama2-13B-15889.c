//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_REPEAT 10

typedef struct {
    char *word;
    int count;
} repeat;

repeat repeats[MAX_REPEAT];

void init_repeats() {
    int i;
    for (i = 0; i < MAX_REPEAT; i++) {
        repeats[i].word = NULL;
        repeats[i].count = 0;
    }
}

void add_repeat(char *word) {
    int i;
    for (i = 0; i < MAX_REPEAT; i++) {
        if (strcmp(word, repeats[i].word) == 0) {
            repeats[i].count++;
            break;
        }
    }
    if (i == MAX_REPEAT) {
        repeats[i].word = word;
        repeats[i].count = 1;
    }
}

void print_repeats() {
    int i;
    for (i = 0; i < MAX_REPEAT; i++) {
        if (repeats[i].word != NULL) {
            printf("%d occurrences of %s\n", repeats[i].count, repeats[i].word);
        }
    }
}

int main() {
    srand(time(NULL));
    init_repeats();

    char text[] = "The quick brown fox jumps over the lazy dog";
    char word[50];
    int count = 0;

    for (int i = 0; i < strlen(text); i++) {
        word[count] = text[i];
        count++;
        if (count == 50) {
            add_repeat(word);
            count = 0;
        }
    }

    add_repeat(word);
    print_repeats();

    return 0;
}