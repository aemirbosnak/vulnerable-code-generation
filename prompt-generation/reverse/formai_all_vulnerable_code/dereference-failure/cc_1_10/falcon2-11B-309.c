//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_spam(char* email);

int main() {
    char* email = "This is a spam email";
    if (is_spam(email)) {
        printf("This is a spam email\n");
    } else {
        printf("This is not a spam email\n");
    }
    return 0;
}

bool is_spam(char* email) {
    int num_words = 0;
    char* word = NULL;
    char* word_end = NULL;
    bool in_word = false;
    bool is_spam = false;

    // Tokenize the email into words
    for (word = strtok(email, " \t\n\r"); word!= NULL; word = strtok(NULL, " \t\n\r")) {
        num_words++;
        word_end = strchr(word, '\0');
        *word_end = '\0';

        // Check for common spam keywords
        if (strstr(word, "money")!= NULL ||
            strstr(word, "free")!= NULL ||
            strstr(word, "click")!= NULL ||
            strstr(word, "viagra")!= NULL ||
            strstr(word, "porn")!= NULL ||
            strstr(word, "insurance")!= NULL ||
            strstr(word, "credit")!= NULL ||
            strstr(word, "loan")!= NULL) {
            is_spam = true;
            break;
        }
    }

    if (num_words < 3) {
        is_spam = true;
    }

    return is_spam;
}