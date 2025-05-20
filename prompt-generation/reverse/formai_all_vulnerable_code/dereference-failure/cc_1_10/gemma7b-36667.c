//Gemma-7B DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

void analyze_data(char **data) {
    int i, j, k, frequency[MAX_SIZE] = {0}, total_words = 0, unique_words = 0;
    char word[MAX_SIZE], tmp[MAX_SIZE];

    for (i = 0; data[i] != NULL; i++) {
        char *sentence = data[i];
        int sentence_length = strlen(sentence);

        for (j = 0; j < sentence_length; j++) {
            word[0] = sentence[j];
            word[1] = '\0';

            if (frequency[word[0]] == 0) {
                unique_words++;
                frequency[word[0]] = 1;
            }

            frequency[word[0]]++;
            total_words++;
        }
    }

    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", unique_words);
    printf("Word frequency:\n");

    for (k = 0; k < MAX_SIZE; k++) {
        if (frequency[k] > 0) {
            sprintf(tmp, "%c: %d", k, frequency[k]);
            printf("%s\n", tmp);
        }
    }
}

int main() {
    char **data = NULL;

    data = malloc(sizeof(char *) * MAX_SIZE);
    data[0] = "The quick brown fox jumps over the lazy dog.";
    data[1] = "A man, a plan, a canal: Panama.";
    data[2] = "The cat sat on the mat.";

    analyze_data(data);

    free(data);

    return 0;
}