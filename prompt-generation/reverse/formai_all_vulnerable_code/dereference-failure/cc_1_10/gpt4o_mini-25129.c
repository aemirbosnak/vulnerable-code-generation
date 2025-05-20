//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_SUMMARY_LENGTH 200
#define MAX_THREADS 4

typedef struct {
    char *text;
    char *summary;
    int start;
    int end;
} ThreadData;

sem_t semaphore;

void *summarize_part(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *text_part = (char *)malloc((data->end - data->start + 1) * sizeof(char));
    strncpy(text_part, data->text + data->start, data->end - data->start);
    text_part[data->end - data->start] = '\0';
    
    //Simple summarizing logic (tokenizing and picking first few sentences)
    char *sentence = strtok(text_part, ".");
    int sentence_count = 0;
    
    while (sentence != NULL && sentence_count < 3) { // Taking only first 3 sentences
        sem_wait(&semaphore); // Wait to enter critical section
        strcat(data->summary, sentence);
        strcat(data->summary, ".");
        sem_post(&semaphore); // Release the critical section
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    free(text_part);
    return NULL;
}

void summarize_text(char *text, char *summary) {
    int len = strlen(text);
    int part_size = len / MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].text = text;
        thread_data[i].summary = summary;
        thread_data[i].start = i * part_size;
        thread_data[i].end = (i == MAX_THREADS - 1) ? len : (i + 1) * part_size;

        // Initialize summary string for each thread
        if (i == 0) {
            summary[0] = '\0'; // Start the summary as an empty string
        }

        pthread_create(&threads[i], NULL, summarize_part, (void *)&thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = "";

    // Initialize semaphore
    sem_init(&semaphore, 0, 1);

    printf("Enter text to summarize (up to %d characters, end with `EOF`):\n", MAX_TEXT_LENGTH);
    fread(text, sizeof(char), MAX_TEXT_LENGTH, stdin);

    summarize_text(text, summary);

    printf("\nSummary:\n%s\n", summary);

    // Destroy semaphore
    sem_destroy(&semaphore);
    
    return 0;
}