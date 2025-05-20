//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

char *words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    words[num_words++] = strdup(word);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_words() {
    qsort(words, num_words, sizeof(char *), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    char line[MAX_WORD_LEN];
    FILE *file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        int len = strlen(line);
        if (len > 0 && isalpha(line[0])) {
            char *word = malloc(len + 1);
            strcpy(word, line);
            add_word(word);
        }
    }
    fclose(file);
    print_words();
    return 0;
}