//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char word[100];
    char *data = NULL;
    int size = 0;

    while (fgets(word, sizeof(word), file)) {
        size += strlen(word);
        data = (char*)realloc(data, size * sizeof(char));
        strcat(data, word);
    }

    char *words[100];
    int word_count[100];
    int i, j;
    int max_count = 0;
    char *max_word = NULL;

    for (i = 0; i < size; i++) {
        words[i] = (char*)malloc(strlen(data + i) + 1);
        strcpy(words[i], data + i);
        word_count[i] = 1;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_count[i] += word_count[j];
                free(words[j]);
                j--;
            }
        }

        if (max_count < word_count[i]) {
            max_count = word_count[i];
            max_word = words[i];
        }
    }

    free(data);
    for (i = 0; i < size; i++) {
        free(words[i]);
    }

    printf("Most common word: %s\n", max_word);

    fclose(file);
    return 0;
}