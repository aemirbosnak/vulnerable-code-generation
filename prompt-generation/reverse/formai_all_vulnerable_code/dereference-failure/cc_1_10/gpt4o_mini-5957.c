//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define BUFFER_SIZE 1024

// Structure to hold word count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to convert a word to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to process a section of the text
void process_text(const char *text_section, int pipe_fd) {
    WordCount word_counts[MAX_WORDS] = {0};
    int total_words = 0;

    // Tokenize the input text section
    char *token = strtok((char *)text_section, " \n");
    while (token != NULL) {
        to_lowercase(token);

        // Check if the word is already counted
        int found = 0;
        for (int i = 0; i < total_words; i++) {
            if (strcmp(word_counts[i].word, token) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is new, add it to the word counts
        if (!found && total_words < MAX_WORDS) {
            strcpy(word_counts[total_words].word, token);
            word_counts[total_words].count = 1;
            total_words++;
        }

        token = strtok(NULL, " \n");
    }

    // Write the counts to the pipe
    write(pipe_fd, &total_words, sizeof(int));
    write(pipe_fd, word_counts, sizeof(WordCount) * total_words);
}

// Function to read text file and split into sections
void read_file_and_process(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int pipe_fds[2];
    pipe(pipe_fds); // Create a pipe for inter-process communication

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        close(pipe_fds[1]); // Close the write end of the pipe

        // Read from pipe
        int total_words;
        WordCount word_counts[MAX_WORDS];
        while (read(pipe_fds[0], &total_words, sizeof(int)) > 0) {
            read(pipe_fds[0], word_counts, sizeof(WordCount) * total_words);

            // Display the word counts
            for (int i = 0; i < total_words; i++) {
                printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
            }
        }

        close(pipe_fds[0]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipe_fds[0]); // Close the read end of the pipe
       
        // Read the file and process it
        while (fgets(buffer, sizeof(buffer), file)) {
            // Process the line in parallel
            process_text(buffer, pipe_fds[1]);
        }

        close(pipe_fds[1]); // Close the write end
        fclose(file);
        wait(NULL); // Wait for the child process to finish
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_file_and_process(argv[1]);

    return EXIT_SUCCESS;
}