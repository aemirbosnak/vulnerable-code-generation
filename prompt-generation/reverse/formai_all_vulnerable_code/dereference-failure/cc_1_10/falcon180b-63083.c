//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* kingdom_greeting = "Hail to thee, noble adventurer! Welcome to the Kingdom of Coderonia. I am Sir Stringman, the keeper of the royal archives. How may I assist thee on this fine day?";

void print_kingdom_greeting() {
    printf("%s\n", kingdom_greeting);
}

void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed_str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed_str[i] = str[length - i - 1];
    }
    reversed_str[length] = '\0';
    printf("Reversed string: %s\n", reversed_str);
}

void replace_substring(char* str, char* old_substring, char* new_substring) {
    char* modified_str = strdup(str);
    char* modified_substring = strdup(old_substring);
    char* modified_new_substring = strdup(new_substring);
    char* token = strtok(modified_str, modified_substring);
    while (token!= NULL) {
        printf("%s -> %s\n", token, modified_new_substring);
        strcat(modified_str, modified_new_substring);
        token = strtok(NULL, modified_substring);
    }
    printf("Modified string: %s\n", modified_str);
    free(modified_str);
    free(modified_substring);
    free(modified_new_substring);
}

void count_words_sentences_paragraphs(char* str) {
    int word_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;
    char* token = strtok(str, ".?!");
    while (token!= NULL) {
        if (token[strlen(token) - 1] == '.' || token[strlen(token) - 1] == '?' || token[strlen(token) - 1] == '!') {
            sentence_count++;
        }
        if (token[strlen(token) - 1] == '.') {
            paragraph_count++;
        }
        word_count++;
        token = strtok(NULL, ".?!");
    }
    printf("Word count: %d\n", word_count);
    printf("Sentence count: %d\n", sentence_count);
    printf("Paragraph count: %d\n", paragraph_count);
}

int main() {
    print_kingdom_greeting();
    char* user_input = malloc(1000);
    printf("Enter thy message: ");
    fgets(user_input, 1000, stdin);
    reverse_string(user_input);
    replace_substring(user_input, "thee", "you");
    count_words_sentences_paragraphs(user_input);
    free(user_input);
    return 0;
}