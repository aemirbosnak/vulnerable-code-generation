//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_t {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

int main() {
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    char input_line[100];
    char *token;

    // Read in the English-to-Cat translation file
    FILE *fp = fopen("english_to_cat.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open english_to_cat.txt\n");
        return 1;
    }

    // Parse each line of the file and store the translations in the words array
    while (fgets(input_line, sizeof(input_line), fp)!= NULL) {
        token = strtok(input_line, " ");
        strcpy(words[num_words].english, token);
        token = strtok(NULL, " ");
        strcpy(words[num_words].cat, token);
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: Reached maximum number of words\n");
            return 1;
        }
    }
    fclose(fp);

    // Prompt the user for input and translate to Cat
    printf("Enter a sentence to translate to Cat:\n");
    fgets(input_line, sizeof(input_line), stdin);
    token = strtok(input_line, " ");
    while (token!= NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}