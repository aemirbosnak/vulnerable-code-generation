//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 1000

char *to_lower(char *str) {
    char *result = malloc(strlen(str) + 1);
    for (int i = 0; i <= strlen(str); i++) {
        if (isupper(str[i])) {
            result[i] = tolower(str[i]);
        } else {
            result[i] = str[i];
        }
    }
    return result;
}

int count_words(char *text) {
    int counter = 0;
    bool was_space = true;
    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            was_space = true;
        } else if (was_space) {
            counter++;
            was_space = false;
        }
    }
    return counter;
}

char *read_text(FILE *fp) {
    char *text = malloc(MAX_LEN + 1);
    char *cur_pos = text;
    size_t max_len = MAX_LEN;
    while (fgets(cur_pos, max_len, fp) != NULL) {
        cur_pos += strlen(cur_pos);
        max_len -= strlen(text);
    }
    return text;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file!\n");
        return -1;
    }
    char *text = read_text(fp);
    fclose(fp);
    char *lower_text = to_lower(text);
    int word_count = count_words(lower_text);
    printf("There are %d words in the text.\n", word_count);
    free(text);
    free(lower_text);
    return 0;
}