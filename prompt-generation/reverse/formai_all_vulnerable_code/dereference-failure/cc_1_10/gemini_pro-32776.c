//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Spam Detection System
// This program uses a variety of heuristics to detect spam emails.

// Heuristics
#define HEURISTIC_WORD_COUNT        10
#define HEURISTIC_PUNCTUATION_COUNT 5
#define HEURISTIC_CAPITALIZATION_COUNT 10
#define HEURISTIC_URL_COUNT        5
#define HEURISTIC_NUMBER_COUNT       2
#define HEURISTIC_SYMBOL_COUNT       3

// Scoring
#define SCORE_EACH_WORD            1
#define SCORE_EACH_PUNCTUATION     2
#define SCORE_EACH_CAPITALIZATION  3
#define SCORE_EACH_URL             5
#define SCORE_EACH_NUMBER           4
#define SCORE_EACH_SYMBOL           5

// Main
int main(void) {
    // Get email text from user
    char *email_text = malloc(1024);
    printf("Enter email text: ");
    fgets(email_text, 1024, stdin);

    // Clean email text
    for (int i = 0; i < strlen(email_text); i++) {
        email_text[i] = tolower(email_text[i]);
    }

    // Calculate heuristic scores
    int score_word_count = 0;
    int score_punctuation_count = 0;
    int score_capitalization_count = 0;
    int score_url_count = 0;
    int score_number_count = 0;
    int score_symbol_count = 0;

    int word_count = 0;
    int punctuation_count = 0;
    int capitalization_count = 0;
    int url_count = 0;
    int number_count = 0;
    int symbol_count = 0;

    char *token = strtok(email_text, " ");
    while (token != NULL) {
        word_count++;
        if (strchr(".,?!:;", token[0])) {
            punctuation_count++;
        }
        if (isupper(token[0])) {
            capitalization_count++;
        }
        if (strstr(token, "http://") || strstr(token, "https://")) {
            url_count++;
        }
        if (strspn(token, "0123456789") == strlen(token)) {
            number_count++;
        }
        if (strspn(token, "!@#$%^&*()-_=+[]{}\\|;:'\",<.>/?") == strlen(token)) {
            symbol_count++;
        }
        token = strtok(NULL, " ");
    }

    score_word_count += word_count * SCORE_EACH_WORD;
    score_punctuation_count += punctuation_count * SCORE_EACH_PUNCTUATION;
    score_capitalization_count += capitalization_count * SCORE_EACH_CAPITALIZATION;
    score_url_count += url_count * SCORE_EACH_URL;
    score_number_count += number_count * SCORE_EACH_NUMBER;
    score_symbol_count += symbol_count * SCORE_EACH_SYMBOL;

    // Calculate total score
    int total_score = score_word_count + score_punctuation_count + score_capitalization_count + score_url_count + score_number_count + score_symbol_count;

    // Print results
    printf("Word count: %d\n", word_count);
    printf("Punctuation count: %d\n", punctuation_count);
    printf("Capitalization count: %d\n", capitalization_count);
    printf("URL count: %d\n", url_count);
    printf("Number count: %d\n", number_count);
    printf("Symbol count: %d\n", symbol_count);

    printf("Total score: %d\n", total_score);

    // Free memory
    free(email_text);

    return 0;
}