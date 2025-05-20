//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_WORDS 1000

char *words[MAX_WORDS];    // Array to store words
int count[MAX_WORDS];      // Array to store count of words
int position = 0;          // Position for adding words to the array
int numOfWords = 0;        // Total words count
bool done = false;         // Checks when the threads are done
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   // Mutex for synchronization

void *countWords(void *data) {
    int *threadNum = (int*) data;
    int localPos;

    while (!done) {
        pthread_mutex_lock(&mutex);
        localPos = position++;
        pthread_mutex_unlock(&mutex);

        if (localPos < numOfWords) {
            char *word = words[localPos];
            int len = strlen(word);

            // Make sure the word ends with a null terminator
            if (word[len-1] == '.' || word[len-1] == ',' || word[len-1] == '\n') {
                word[len-1] = '\0';
                len--;
            }
            
            // Remove any leading/trailing white spaces
            while (isspace(word[len-1])) {
                word[len-1] = '\0';
                len--;
            }
            while (isspace(*word)) {
                word++;
                len--;
            }

            // Ignore empty words
            if (len > 0) {
                pthread_mutex_lock(&mutex);
                for (int i = 0; i < numOfWords; i++) {
                    if (strcmp(words[i], word) == 0) {
                        count[i]++;
                        break;
                    }
                    if (i == numOfWords-1) {
                        words[numOfWords] = word;
                        count[numOfWords++] = 1;
                        break;
                    }
                }
                pthread_mutex_unlock(&mutex);
            }
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    printf("Word count tool!\n");

    // Open the file and read the words
    FILE *file = fopen(argv[1], "r");
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            words[numOfWords++] = token;
            token = strtok(NULL, " ");
        }
    }
    fclose(file);

    printf("Total words: %d\n", numOfWords);

    // Create threads
    pthread_t threads[MAX_THREADS];
    int threadNum[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        threadNum[i] = i;
        pthread_create(&threads[i], NULL, countWords, &threadNum[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the word count
    printf("Word count:\n");
    for (int i = 0; i < numOfWords; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}