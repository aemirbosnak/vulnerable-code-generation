//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCES 1000

void remove_newline(char* string) {
    int length = strlen(string);
    if (string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }
}

int find_word_count(char sentence[]) {
    int count = 0;
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

void copy_string(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int main() {
    char input[MAX_STRING_LENGTH];
    char sentences[MAX_SENTENCES][MAX_STRING_LENGTH];

    printf("Enter text to summarize: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    remove_newline(input);

    int sentence_count = 0;
    char* sentence = strtok(input, ".");
    while (sentence != NULL) {
        copy_string(sentence, sentences[sentence_count]);
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    printf("\nOriginal Text:\n%s\n", input);

    int total_word_count = 0;
    int sentence_word_count[sentence_count];
    for (int i = 0; i < sentence_count; i++) {
        sentence_word_count[i] = find_word_count(sentences[i]);
        total_word_count += sentence_word_count[i];
    }

    int target_word_count = total_word_count / 3;

    printf("Summarized Text:\n");
    int current_word_count = 0;
    for (int i = 0; i < sentence_count; i++) {
        if ((current_word_count + sentence_word_count[i]) <= target_word_count) {
            printf("%s.", sentences[i]);
            current_word_count += sentence_word_count[i];
        }
    }
    printf("\n");

    return 0;
}