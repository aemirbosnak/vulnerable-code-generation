//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void grateful_str_split(char *str, char **words);
void grateful_str_join(char **words, char *sep);

int main() {
    char *str = "I am so grateful for this opportunity to learn and grow!";
    char *words[5];

    grateful_str_split(str, words);
    printf("Grateful words: ");
    grateful_str_join(words, " ");
    printf("\n");

    return 0;
}

void grateful_str_split(char *str, char **words) {
    size_t i, j;
    char *token;

    *words = NULL;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            token = str + i;
            while (token[0] == ' ' || token[0] == '\t') {
                token++;
            }
            if (token[0] != '\0') {
                words = realloc(words, (i - j) * sizeof(char *) + 1);
                words[j] = token;
                j++;
            }
        }
    }
}

void grateful_str_join(char **words, char *sep) {
    size_t i, j;

    for (i = 0; words[i] != NULL; i++) {
        for (j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] == ' ' || words[i][j] == '\t') {
                words[i][j] = sep[0];
            }
        }
    }
    printf("%s\n", words[0]);
}