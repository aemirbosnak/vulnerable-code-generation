//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define SPAM_THRESHOLD 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int is_spam(char *email) {
    int spam_count = 0;
    char *token;
    WordCount *word_counts = calloc(26, sizeof(WordCount));

    // Initialize word counts for each letter of the alphabet
    for (int i = 0; i < 26; i++) {
        sprintf(word_counts[i].word, "%c", 'a' + i);
        word_counts[i].count = 0;
    }

    // Split email into words and count frequency of each word
    token = strtok(email, " ");
    while (token!= NULL) {
        int letter_index = tolower(token[0]) - 'a';
        if (letter_index >= 0 && letter_index < 26) {
            word_counts[letter_index].count++;
        }
        spam_count += word_counts[letter_index].count;
        token = strtok(NULL, " ");
    }

    // Free memory allocated for word counts
    for (int i = 0; i < 26; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return spam_count >= SPAM_THRESHOLD;
}

int main() {
    char email[1000];
    printf("Enter an email: ");
    fgets(email, sizeof(email), stdin);
    if (is_spam(email)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }
    return 0;
}