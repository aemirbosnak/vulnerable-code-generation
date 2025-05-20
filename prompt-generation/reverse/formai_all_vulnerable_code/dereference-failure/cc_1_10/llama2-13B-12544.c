//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_WORD_LENGTH 20
#define MAX_PROCESSES 5

struct word {
    char *word;
    int length;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    // Initialize the text file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Initialize the word count array
    int word_count[MAX_PROCESSES];
    memset(word_count, 0, sizeof(word_count));

    // Create processes to count words
    pid_t *processes = malloc(MAX_PROCESSES * sizeof(pid_t));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = fork();
        if (processes[i] == 0) {
            // Child process: count words
            char buffer[4096];
            while (fgets(buffer, sizeof(buffer), file)) {
                // Tokenize the line
                char *token = strtok(buffer, " ");
                while (token != NULL) {
                    struct word *word = malloc(sizeof(struct word));
                    word->word = token;
                    word->length = strlen(token);
                    // Add word to the word count array
                    word_count[getpid()]++;
                    token = strtok(NULL, " ");
                }
            }
            exit(0);
        }
    }

    // Wait for all processes to finish
    for (int i = 0; i < MAX_PROCESSES; i++) {
        wait(NULL);
    }

    // Print the word count
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d: %d\n", i, word_count[i]);
    }

    return 0;
}