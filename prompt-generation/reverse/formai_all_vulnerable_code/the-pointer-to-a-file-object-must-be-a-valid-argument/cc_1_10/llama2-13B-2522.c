//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_SIZE 100000

struct word {
    char *word;
    int frequency;
};

int main(void) {
    char *log_file = "example.log";
    int word_count = 0;
    int unique_words = 0;
    struct word *word_list = NULL;
    int i, j;

    // Open the log file and read its contents
    FILE *log_file_ptr = fopen(log_file, "r");
    char line[100];
    while (fgets(line, sizeof(line), log_file_ptr) != NULL) {
        // Tokenize the line and count the words
        char *token = strtok(line, " ");
        while (token != NULL && token[0] != '\0') {
            int word_len = strlen(token);
            if (word_len > MAX_WORD_LENGTH) {
                word_len = MAX_WORD_LENGTH;
            }
            char *word = (char *)malloc(word_len + 1);
            strncpy(word, token, word_len);
            word[word_len] = '\0';
            // Check if the word is already in the list
            for (i = 0; i < word_count; i++) {
                if (strcmp(word, word_list[i].word) == 0) {
                    word_list[i].frequency++;
                    break;
                }
            }
            if (i == word_count) {
                // Add the word to the list
                word_list = realloc(word_list, (word_count + 1) * sizeof(struct word));
                word_list[word_count].word = word;
                word_list[word_count].frequency = 1;
                word_count++;
            }
            token = strtok(NULL, " ");
        }
    }
    // Calculate the total number of unique words
    unique_words = word_count - (word_list[0].frequency > 1);

    // Print the report
    printf("Log Analysis Report:\n");
    printf("Total words: %d\n", word_count);
    printf("Unique words: %d\n", unique_words);
    for (i = 0; i < word_count; i++) {
        printf("%d. %s (%d times)\n", i + 1, word_list[i].word, word_list[i].frequency);
    }

    // Free the memory
    free(word_list);

    return 0;
}