//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_SUMMARY_SIZE 256

char *summary;

void *summarize(void *input_text) {
    char *text = (char *) input_text;
    char buffer[MAX_BUFFER_SIZE];
    char *temp_summary = (char *) malloc(MAX_SUMMARY_SIZE * sizeof(char));
    int sentence_count = 0;
    int summary_length = 0;
    
    // Analyzing the input text
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_count++;
        }
    }
    int sentences_to_keep = sentence_count / 5;
    int sentences_kept = 0;
    int i = 0;
    
    // Generating the summary
    while (sentences_kept < sentences_to_keep) {
        while (!isalnum(text[i])) i++;
        int j = i + 1;
        while (text[j] != '.' && text[j] != '?' && text[j] != '!' && text[j] != '\0') j++;
        strncpy(buffer, &text[i], j - i + 1);
        buffer[j - i + 1] = '\0';
        
        if (strlen(temp_summary) + strlen(buffer) < MAX_SUMMARY_SIZE) {
            strcat(temp_summary, buffer);
            sentences_kept++;
        } else {
            break;
        }
        i = j + 1;
    }
    
    //Saving the summary
    summary_length = strlen(temp_summary);
    summary = (char *) malloc(summary_length * sizeof(char));
    strncpy(summary, temp_summary, summary_length);
    
    pthread_exit(0);
}

int main() {
    char input_text[MAX_BUFFER_SIZE];
    pthread_t thread;
    
    printf("Enter the text to be summarized: \n");
    fgets(input_text, MAX_BUFFER_SIZE, stdin);
    
    pthread_create(&thread, NULL, summarize, (void *) input_text);
    pthread_join(thread, NULL);
    
    printf("Summary: \n%s\n", summary);
    
    return 0;
}