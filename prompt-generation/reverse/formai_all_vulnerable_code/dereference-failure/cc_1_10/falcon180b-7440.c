//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

char *remove_punctuation(char *sentence);
char *convert_to_lowercase(char *sentence);
int count_words(char *sentence);
int count_sentences(char *text);
int count_paragraphs(char *text);

int main() {
    char text[MAX_SENTENCE_LENGTH];
    printf("Enter a text: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    char *cleaned_text = remove_punctuation(text);
    int num_words = count_words(cleaned_text);
    int num_sentences = count_sentences(text);
    int num_paragraphs = count_paragraphs(text);

    printf("Number of words: %d\n", num_words);
    printf("Number of sentences: %d\n", num_sentences);
    printf("Number of paragraphs: %d\n", num_paragraphs);

    return 0;
}

char *remove_punctuation(char *sentence) {
    char *cleaned_sentence = malloc(strlen(sentence) + 1);
    int j = 0;

    for (int i = 0; i < strlen(sentence); i++) {
        if (!isspace(sentence[i]) &&!ispunct(sentence[i])) {
            cleaned_sentence[j++] = tolower(sentence[i]);
        }
    }

    cleaned_sentence[j] = '\0';
    return cleaned_sentence;
}

char *convert_to_lowercase(char *sentence) {
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        sentence[i] = tolower(sentence[i]);
    }
    return sentence;
}

int count_words(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int count_sentences(char *text) {
    int count = 0;
    char *sentence = strtok(text, ".?!");

    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".?!");
    }

    return count;
}

int count_paragraphs(char *text) {
    int count = 0;
    char *paragraph = strtok(text, "\n");

    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n");
    }

    return count;
}