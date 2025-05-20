//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define SHM_SIZE (MAX_WORDS * (MAX_WORD_LENGTH + sizeof(int)))

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void count_words(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    char buffer[256];
    while (fscanf(file, "%255s", buffer) != EOF) {
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        
        int found = 0;
        for (int i = 0; i < *wordCountSize; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && *wordCountSize < MAX_WORDS) {
            strcpy(wordCounts[*wordCountSize].word, buffer);
            wordCounts[*wordCountSize].count = 1;
            (*wordCountSize)++;
        }
    }

    fclose(file);
}

void print_word_counts(WordCount *wordCounts, int wordCountSize) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int shmId = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmId < 0) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    WordCount *wordCounts = shmat(shmId, NULL, 0);
    if (wordCounts == (void *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    int wordCountSize = 0;
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        count_words(argv[1], wordCounts, &wordCountSize);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        wait(NULL); // wait for child to finish
        int status = shmdt(wordCounts);
        if (status == -1) {
            perror("shmdt failed");
            exit(EXIT_FAILURE);
        }

        WordCount sortedWords[MAX_WORDS];
        memcpy(sortedWords, wordCounts, wordCountSize * sizeof(WordCount));

        // Sort the words by frequency (simple selection sort for demonstration)
        for (int i = 0; i < wordCountSize - 1; i++) {
            for (int j = i + 1; j < wordCountSize; j++) {
                if (sortedWords[i].count < sortedWords[j].count) {
                    WordCount temp = sortedWords[i];
                    sortedWords[i] = sortedWords[j];
                    sortedWords[j] = temp;
                }
            }
        }

        // Print sorted count
        print_word_counts(sortedWords, wordCountSize);
        
        shmctl(shmId, IPC_RMID, NULL); // remove shared memory
    }

    return 0;
}