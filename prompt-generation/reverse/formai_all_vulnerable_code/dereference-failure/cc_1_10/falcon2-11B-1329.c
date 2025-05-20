//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the occurrences of a word in a log file
int count_word(const char* log, const char* word) {
    int count = 0;
    char* word_copy = strdup(word);

    // Find the first occurrence of the word
    int pos = strcspn(log, " \t\n");
    while (pos!= -1) {
        if (strcmp(log + pos, word_copy) == 0) {
            count++;
            break;
        }
        pos = strcspn(log + pos + 1, " \t\n");
    }

    free(word_copy);
    return count;
}

// Function to analyze a log file and print the results
void analyze_log(const char* log_file) {
    FILE* log_file_ptr = fopen(log_file, "r");
    if (log_file_ptr == NULL) {
        printf("Error opening log file\n");
        return;
    }

    char* line = NULL;
    size_t size = 0;
    ssize_t read_size;

    int total_words = 0;
    int total_count[26] = {0};

    // Read each line of the log file
    while ((read_size = getline(&line, &size, log_file_ptr))!= -1) {
        // Count the number of occurrences of each word in the line
        for (int i = 0; i < read_size; i++) {
            char c = tolower(line[i]);
            if (isalpha(c)) {
                int word_len = strlen(line + i);
                for (int j = 0; j < word_len; j++) {
                    if (isalpha(line[i + j])) {
                        if (total_words < 26) {
                            total_count[total_words]++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        total_words++;
    }

    fclose(log_file_ptr);

    // Print the results
    printf("Total words: %d\n", total_words);
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, total_count[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    analyze_log(argv[1]);

    return 0;
}