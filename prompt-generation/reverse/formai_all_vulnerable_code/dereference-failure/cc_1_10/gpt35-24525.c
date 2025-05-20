//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char *translate_word(char *word) {
    int len = strlen(word);
    char *translated_word;

    if (len % 2 == 0) {
        translated_word = (char *) malloc(len * sizeof(char));
    } else {
        translated_word = (char *) malloc((len + 1) * sizeof(char));
    }

    for (int i = 0; i < len; i += 2) {
        char temp = word[i];
        translated_word[i] = word[i+1];
        translated_word[i+1] = temp;
    }

    if (len % 2 != 0) {
        translated_word[len] = '\0';
    }

    return translated_word;
}

void translate_sentence(char *sentence) {
    char *word, *translated_word;
    char *words[MAX_WORDS];
    int word_count = 0;

    word = strtok(sentence, " ");

    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++) {
        translated_word = translate_word(words[i]);
        printf("%s ", translated_word);
        free(translated_word);
    }
}

int main() {
    char sentence[1000];

    printf("Enter a sentence in C Alien Language: ");
    fgets(sentence, 1000, stdin);

    translate_sentence(sentence);

    return 0;
}