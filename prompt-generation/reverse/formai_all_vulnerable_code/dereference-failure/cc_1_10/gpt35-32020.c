//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10000 // maximum size for the summary
#define BUFFER_SIZE 100 // size of the buffer
#define NUM_THREADS 4 // number of threads to use

char* text; // pointer to the text to summarize
char summary[MAX_LEN] = ""; // array to store summary
char buffer[BUFFER_SIZE] = ""; // buffer to hold current line being processed
int buffer_idx = 0; // index of current buffer
int summary_idx = 0; // index of current summary
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex to control thread access to data

// thread function to process lines of text
void* process_lines(void* arg) {
    int tid = *(int*)arg;
    int start = tid * (strlen(text) / NUM_THREADS);
    int end = (tid + 1) * (strlen(text) / NUM_THREADS);

    for (int i = start; i < end; i++) { // loop through lines assigned to thread
        if (text[i] == '\n') { // if end of line, process buffer
            pthread_mutex_lock(&mutex); // acquire lock on data
            strcat(summary, buffer); // concatenate buffer to summary
            buffer_idx = 0; // reset buffer
            memset(buffer, 0, sizeof(buffer)); // clear buffer
            pthread_mutex_unlock(&mutex); // release lock on data
        } else {
            buffer[buffer_idx] = text[i]; // add character to buffer
            buffer_idx++; // increment buffer index
        }
    }
    pthread_exit(NULL); // exit thread
}

int main(int argc, char** argv) {
    if (argc < 2) { // not enough arguments
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    // open file and read text into memory
    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    text = malloc(file_size + 1);
    fread(text, 1, file_size, fp);
    text[file_size] = '\0';
    fclose(fp);

    // create threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, process_lines, (void*)&thread_ids[i]);
    }

    // wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print summary
    printf("%s\n", summary);

    // free memory
    free(text);

    return 0;
}