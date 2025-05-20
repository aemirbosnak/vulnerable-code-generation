//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_WORD_LEN 64
#define MAX_WORD_COUNT 1000

// Function to split a line into words
void split_line(char *line, char **words) {
    char *token = strtok(line, " ");
    int word_count = 0;

    while (token!= NULL) {
        if (word_count >= MAX_WORD_COUNT) {
            printf("Too many words in line! Ignoring...\n");
            break;
        }

        if (strlen(token) > MAX_WORD_LEN) {
            printf("Word too long! Ignoring...\n");
            continue;
        }

        words[word_count++] = strdup(token);
        token = strtok(NULL, " ");
    }
}

// Function to check if a word is a palindrome
int is_palindrome(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i])!= tolower(word[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to print the current date and time
void print_timestamp() {
    time_t now = time(NULL);
    char timestamp[MAX_LINE];
    strftime(timestamp, MAX_LINE, "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("Timestamp: %s\n", timestamp);
}

// Main function
int main() {
    char line[MAX_LINE];
    char *words[MAX_WORD_COUNT];

    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        print_timestamp();

        split_line(line, words);

        for (int i = 0; words[i]!= NULL; i++) {
            if (is_palindrome(words[i])) {
                printf("Possible palindrome detected: %s\n", words[i]);
            }
        }
    }

    return 0;
}