//Falcon-180B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 50

// Function to split a string into words
void split_string(char *str, char **words) {
    int i = 0;
    char *token = strtok(str, " \t\n\r\f\v.,!?;:\"'");
    while (token!= NULL) {
        words[i++] = token;
        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
    }
    words[i] = NULL;
}

// Function to generate a random string of given length
char *random_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
    return str;
}

// Function to generate a random sentence of given length
void generate_sentence(int len, char *sentence) {
    int i = 0;
    while (i < len) {
        int word_len = rand() % 10 + 1;
        char *word = random_string(word_len);
        strcat(sentence, word);
        strcat(sentence, " ");
        i += word_len + 1;
    }
    sentence[i - 1] = '\0';
}

// Function to count the frequency of each word in a sentence
void count_words(char *sentence, int *word_counts) {
    char *token = strtok(sentence, " \t\n\r\f\v.,!?;:\"'");
    while (token!= NULL) {
        int word_len = strlen(token);
        for (int i = 0; i < word_len; i++) {
            if (isalpha(token[i])) {
                token[i] = tolower(token[i]);
            }
        }
        int index = token[0] - 'a';
        word_counts[index]++;
        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
    }
}

int main() {
    srand(time(NULL));

    char *sentence = malloc(MAX_WORD_LEN * MAX_WORDS);
    int word_counts[26] = { 0 };

    int num_sentences = 10;
    for (int i = 0; i < num_sentences; i++) {
        int sentence_len = rand() % MAX_WORDS + 1;
        generate_sentence(sentence_len, sentence);
        count_words(sentence, word_counts);
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', word_counts[i]);
    }

    free(sentence);
    return 0;
}