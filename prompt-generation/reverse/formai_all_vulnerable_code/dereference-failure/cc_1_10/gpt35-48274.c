//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int count_unique_words(char* text);
char* remove_punctuation(char* str);
void print_most_common_words(char* text, int n);

int main() {
    char text[1000];
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    printf("\nNumber of unique words: %d\n", count_unique_words(text));
    
    printf("\nThe most common words are:\n");
    print_most_common_words(text, 3);

    return 0;
}

int count_unique_words(char* text) {
    int count = 0, i, j, is_unique;
    char words[MAX_WORD_LEN][MAX_WORD_LEN];    // stores unique words
    char* token;
    
    // convert text to lowercase
    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // tokenize text and count unique words
    token = strtok(text, " \t\n");
    while (token != NULL) {
        is_unique = 1;
        for (j = 0; j < count; j++) {
            if (strcmp(words[j], token) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(words[count], token);
            count++;
        }
        token = strtok(NULL, " \t\n");
    }

    return count;
}

void print_most_common_words(char* text, int n) {
    int i, j, k, max_count, counts[MAX_WORD_LEN] = {0};
    char words[MAX_WORD_LEN][MAX_WORD_LEN];    // stores unique words
    char* token;
    
    // convert text to lowercase and remove punctuation
    text = remove_punctuation(text);
    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // tokenize text and count occurrences of each word
    token = strtok(text, " \t\n");
    while (token != NULL) {
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        for (i = 0; i < MAX_WORD_LEN; i++) {
            if (counts[i] == 0) {
                strcpy(words[i], token);
                counts[i]++;
                break;
            }
            else if (strcmp(words[i], token) == 0) {
                counts[i]++;
                break;
            }
        }
        token = strtok(NULL, " \t\n");
    }
    
    // print n most common words
    for (i = 0; i < n; i++) {
        max_count = -1;
        k = -1;
        for (j = 0; j < MAX_WORD_LEN; j++) {
            if (counts[j] > max_count) {
                max_count = counts[j];
                k = j;
            }
        }
        printf("%s (%d occurrences)\n", words[k], counts[k]);
        counts[k] = 0;
    }
}

char* remove_punctuation(char* str) {
    int i, j;
    char* clean_str = (char*)malloc(strlen(str) + 1);
    
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (isalnum(str[i]) || isspace(str[i])) {
            clean_str[j++] = str[i];
        }
    }
    clean_str[j] = '\0';    // null terminate
    
    return clean_str;
}