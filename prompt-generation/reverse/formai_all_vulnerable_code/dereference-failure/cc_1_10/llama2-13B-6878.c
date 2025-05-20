//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void remove_duplicates(char *text) {
    char *temp = strtok(text, " ");
    char *result = "";
    while (temp != NULL) {
        if (strcmp(result, temp) != 0) {
            strcat(result, " ");
            strcat(result, temp);
        }
        temp = strtok(NULL, " ");
    }
    printf("%s\n", result);
}

void reverse_words(char *text) {
    char *temp = strtok(text, " ");
    char *result = "";
    while (temp != NULL) {
        strcat(result, temp);
        temp = strtok(NULL, " ");
    }
    printf("%s\n", result);
}

void count_words(char *text) {
    char *temp = strtok(text, " ");
    int count[26] = {0};
    while (temp != NULL) {
        int i = temp[0] - 'a';
        count[i]++;
        temp = strtok(NULL, " ");
    }
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', count[i]);
    }
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter a sentence or paragraph: ");
    fgets(text, MAX_LENGTH, stdin);

    remove_duplicates(text);
    reverse_words(text);
    count_words(text);

    return 0;
}