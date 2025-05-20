//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_SENTENCES 100
#define MAX_SUMMARY_LENGTH 256

// Structure to hold sentence data
typedef struct {
    char **sentences;
    int count;
} SentenceList;

// Structure to hold the summarization results
typedef struct {
    char summary[MAX_SUMMARY_LENGTH];
    sem_t sem;
} SummaryResult;

// Function to split text into sentences using '.', '!', and '?' as delimiters
void *split_text_into_sentences(void *arg) {
    char *text = (char *)arg;
    SentenceList *sentence_list = malloc(sizeof(SentenceList));
    sentence_list->sentences = malloc(MAX_SENTENCES * sizeof(char *));
    sentence_list->count = 0;

    char *token = strtok(text, ".!?");
    while (token != NULL && sentence_list->count < MAX_SENTENCES) {
        sentence_list->sentences[sentence_list->count] = strdup(token);
        sentence_list->count++;
        token = strtok(NULL, ".!?");
    }

    return (void *)sentence_list;
}

// Function to summarize the text by selecting the first sentence
void *summarize_text(void *arg) {
    SentenceList *sentence_list = (SentenceList *)arg;
    SummaryResult *result = malloc(sizeof(SummaryResult));

    // Simple summarization: Take the first sentence
    if (sentence_list->count > 0) {
        strncpy(result->summary, sentence_list->sentences[0], MAX_SUMMARY_LENGTH);
    } else {
        strncpy(result->summary, "No summary available.", MAX_SUMMARY_LENGTH);
    }

    // Signal that summarization is done
    sem_post(&result->sem);

    // Free allocated sentences
    for (int i = 0; i < sentence_list->count; i++) {
        free(sentence_list->sentences[i]);
    }
    free(sentence_list->sentences);
    free(sentence_list);

    return (void *)result;
}

// Function to print the summary
void print_summary(SummaryResult *result) {
    sem_wait(&result->sem);
    printf("Summary:\n%s\n", result->summary);
}

// Main function
int main() {
    char input_text[MAX_TEXT_LENGTH];

    // Initialize semaphore
    SummaryResult *result = malloc(sizeof(SummaryResult));
    sem_init(&result->sem, 0, 0);

    // Get input text from user
    printf("Enter the text for summarization (Max %d characters):\n", MAX_TEXT_LENGTH);
    fgets(input_text, MAX_TEXT_LENGTH, stdin);
    input_text[strcspn(input_text, "\n")] = '\0'; // Remove newline character

    pthread_t split_thread, summary_thread;

    // Split text into sentences asynchronously
    pthread_create(&split_thread, NULL, split_text_into_sentences, (void *)input_text);
    void *sentence_list_pointer;
    pthread_join(split_thread, &sentence_list_pointer);
    SentenceList *sentence_list = (SentenceList *)sentence_list_pointer;

    // Summarize the text asynchronously
    pthread_create(&summary_thread, NULL, summarize_text, (void *)sentence_list);
    void *summary_result_pointer;
    pthread_join(summary_thread, &summary_result_pointer);
    SummaryResult *summary_result = (SummaryResult *)summary_result_pointer;

    // Print the summary
    print_summary(summary_result);

    // Clean up
    sem_destroy(&result->sem);
    free(summary_result);
    
    return 0;
}