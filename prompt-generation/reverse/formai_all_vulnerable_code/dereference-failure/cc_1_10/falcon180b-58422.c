//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

// Function prototypes
char* translate(char* word);
int is_vowel(char c);

int main() {
    char word[MAX_WORD_SIZE];
    char translated_word[MAX_WORD_SIZE];
    char* cat_word;
    int vowel_count = 0;

    printf("Enter a word to translate to Cat Language: ");
    fgets(word, MAX_WORD_SIZE, stdin);
    word[strcspn(word, "\n")] = '\0';

    cat_word = translate(word);
    printf("Translated word: %s\n", cat_word);

    printf("Number of vowels in the original word: %d\n", vowel_count);

    return 0;
}

char* translate(char* word) {
    char* cat_word = malloc(strlen(word) + 1);
    int i = 0;
    int j = 0;

    while (word[i]) {
        if (is_vowel(word[i])) {
            cat_word[j++] = 'a';
        } else {
            cat_word[j++] = word[i];
        }
        i++;
    }

    cat_word[j] = '\0';
    return cat_word;
}

int is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    } else {
        return 0;
    }
}