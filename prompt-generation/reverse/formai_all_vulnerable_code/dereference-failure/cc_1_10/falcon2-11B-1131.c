//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_SENTENCES 10

int main() {
    // Read input from user
    char text[MAX_LENGTH];
    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    text[strcspn(text, "\n")] = '\0';
    
    // Split text into sentences
    char sentence[MAX_LENGTH];
    int sentence_count = 0;
    char *sentence_list[MAX_SENTENCES];
    int index = 0;
    char *token = strtok(text, " \n");
    
    while (token!= NULL) {
        if (strlen(token) > 0) {
            strcpy(sentence, token);
            sentence_list[index++] = sentence;
        }
        token = strtok(NULL, " \n");
    }
    
    // Sort sentences based on length
    int sentence_lengths[MAX_SENTENCES];
    for (int i = 0; i < MAX_SENTENCES; i++) {
        sentence_lengths[i] = strlen(sentence_list[i]);
    }
    
    for (int i = 0; i < MAX_SENTENCES - 1; i++) {
        for (int j = i + 1; j < MAX_SENTENCES; j++) {
            if (sentence_lengths[i] > sentence_lengths[j]) {
                char *temp = sentence_list[i];
                sentence_list[i] = sentence_list[j];
                sentence_list[j] = temp;
                int temp_length = sentence_lengths[i];
                sentence_lengths[i] = sentence_lengths[j];
                sentence_lengths[j] = temp_length;
            }
        }
    }
    
    // Select top 3 sentences
    int top_sentences[MAX_SENTENCES];
    int top_sentences_count = 0;
    for (int i = 0; i < MAX_SENTENCES; i++) {
        if (sentence_lengths[i] > 50) {
            top_sentences[top_sentences_count++] = i;
        }
    }
    
    // Print selected sentences
    for (int i = 0; i < top_sentences_count; i++) {
        printf("%s\n", sentence_list[top_sentences[i]]);
    }
    
    return 0;
}