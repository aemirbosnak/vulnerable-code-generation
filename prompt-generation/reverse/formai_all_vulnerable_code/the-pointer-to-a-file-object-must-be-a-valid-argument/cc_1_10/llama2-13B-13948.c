//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_WORD_LEN 256
#define MAX_LOG_LEN 1024

struct word {
    char *word;
    int freq;
};

int main(void) {
    char log[MAX_LOG_LEN];
    struct word *words = NULL;
    int word_count = 0;

    // read log file
    FILE *log_file = fopen("log.txt", "r");
    assert(log_file != NULL);
    while (fgets(log, MAX_LOG_LEN, log_file) != NULL) {
        // tokenize log line
        char *token = strtok(log, " ");
        while (token != NULL && token[0] != '\0') {
            // check if word is not empty and not a whitespace
            if (token[0] != ' ' && token[0] != '\0') {
                // count word frequency
                int freq = 1;
                for (int i = 0; i < word_count; i++) {
                    if (strcmp(words[i].word, token) == 0) {
                        freq = words[i].freq + freq;
                        break;
                    }
                }
                if (freq > words[word_count - 1].freq) {
                    // add word to list
                    words = realloc(words, (word_count + 1) * sizeof(struct word));
                    words[word_count].word = token;
                    words[word_count].freq = freq;
                    word_count++;
                }
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(log_file);

    // print summary
    printf("Top words and their frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%d. %s (%d)\n", i + 1, words[i].word, words[i].freq);
    }

    // free memory
    free(words);

    return 0;
}