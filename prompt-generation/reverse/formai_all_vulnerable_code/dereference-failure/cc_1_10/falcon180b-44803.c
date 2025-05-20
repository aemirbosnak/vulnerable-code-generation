//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define BUFFER_SIZE 1000

char *translate(char *word);
void print_cat_phrase(char *phrase);

int main() {
    char input_buffer[BUFFER_SIZE];
    char *word;
    char output_buffer[MAX_WORD_LEN];
    int i = 0;

    printf("Enter a sentence to translate to Cat Language:\n");
    fgets(input_buffer, BUFFER_SIZE, stdin);

    // Remove newline character from input
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    word = strtok(input_buffer, " ");
    while (word!= NULL) {
        strcpy(output_buffer, translate(word));
        printf("%s ", output_buffer);
        word = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}

char *translate(char *word) {
    char *output_word = malloc(MAX_WORD_LEN * sizeof(char));
    int len = strlen(word);

    // Check if word is a vowel
    if (isalpha(word[0]) && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) {
        strcpy(output_word, word);
        strcat(output_word, "o");
    }
    // Check if word is a consonant
    else {
        strcat(output_word, "at");
    }

    return output_word;
}

void print_cat_phrase(char *phrase) {
    int len = strlen(phrase);

    // Check if phrase is a vowel
    if (isalpha(phrase[0]) && (phrase[0] == 'a' || phrase[0] == 'e' || phrase[0] == 'i' || phrase[0] == 'o' || phrase[0] == 'u')) {
        printf("%s", phrase);
    }
    // Check if phrase is a consonant
    else {
        printf("at ");
    }
}