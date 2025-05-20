//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_SIZE 10000

// Function to count the number of occurrences of a word in a log line
int count_word(char *word, char *log_line) {
    int count = 0;
    while (strstr(log_line, word) != NULL) {
        count++;
    }
    return count;
}

// Function to print the most frequent words in the log file
void print_frequent_words(char *log_file) {
    int most_frequent_word = 0;
    int most_frequent_count = 0;
    char *word;

    // Open the log file and read its contents
    FILE *log_fp = fopen(log_file, "r");
    char log_line[MAX_LOG_SIZE];
    while (fgets(log_line, MAX_LOG_SIZE, log_fp) != NULL) {
        // Tokenize the log line into individual words
        char *token = strtok(log_line, " ");
        while (token != NULL) {
            // Count the number of occurrences of each word
            int count = count_word(token, log_line);
            if (count > most_frequent_count) {
                most_frequent_word = token;
                most_frequent_count = count;
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(log_fp);

    // Print the most frequent words
    printf("Most frequent words in %s:\n", log_file);
    printf("1. %s (%d times)\n", most_frequent_word, most_frequent_count);
    for (word = most_frequent_word; *word != '\0'; word++) {
        printf("2. %c (%d times)\n", *word, count_word(word, log_file));
    }
}

int main() {
    char log_file[] = "example.log";

    // Open the log file and read its contents
    FILE *log_fp = fopen(log_file, "r");
    char log_line[MAX_LOG_SIZE];
    while (fgets(log_line, MAX_LOG_SIZE, log_fp) != NULL) {
        // Tokenize the log line into individual words
        char *token = strtok(log_line, " ");
        while (token != NULL) {
            // Count the number of occurrences of each word
            int count = count_word(token, log_line);
            printf("Token: %s, Count: %d\n", token, count);
            token = strtok(NULL, " ");
        }
    }

    // Print the most frequent words
    print_frequent_words(log_file);

    return 0;
}