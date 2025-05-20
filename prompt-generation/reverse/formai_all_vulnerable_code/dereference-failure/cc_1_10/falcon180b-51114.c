//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 10

char *dict[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
int dict_size = sizeof(dict) / sizeof(dict[0]);

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int rand_bool() {
    return rand() % 2;
}

int rand_element(int *arr, int size) {
    return arr[rand() % size];
}

void rand_string(char *str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
}

int main() {
    srand(time(NULL));

    int num_words = rand_int(1, MAX_WORDS);
    char *sentence = malloc(MAX_LENGTH * sizeof(char));
    sprintf(sentence, "The ");

    for (int i = 1; i < num_words; i++) {
        int word_len = rand_int(3, 8);
        char *word = malloc((word_len + 1) * sizeof(char));
        rand_string(word, word_len);

        if (i == num_words - 1) {
            strcat(sentence, " and ");
            strcat(sentence, word);
        } else {
            strcat(sentence, ", ");
            strcat(sentence, word);
        }

        free(word);
    }

    printf("%s\n", sentence);

    return 0;
}