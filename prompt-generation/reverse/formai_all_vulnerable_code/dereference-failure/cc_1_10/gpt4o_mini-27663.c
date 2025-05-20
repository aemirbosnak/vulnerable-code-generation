//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 2048
#define SUMMARY_LENGTH 5

// Function prototypes
void to_lowercase(char *str);
void remove_punctuation(char *str);
void summarize_text(char *input_text, char **summary);
void print_summary(char **summary);

int main() {
    char *input_text = malloc(BUFFER_SIZE * sizeof(char));
    char *summary[SUMMARY_LENGTH];
    
    // The Matrix of the mind, where the bytes pulse with illumination.
    printf("Enter the text for summarization (type 'exit' to finish):\n");
    
    while (1) {
        fgets(input_text, BUFFER_SIZE, stdin);
        
        // Exiting the text input
        if (strcmp(input_text, "exit\n") == 0) {
            break;
        }
        
        // Prepare the text for summarization
        summarize_text(input_text, summary);
        print_summary(summary);
        
        // Clean the summary for the next run
        for (int i = 0; i < SUMMARY_LENGTH; i++) {
            free(summary[i]);
            summary[i] = NULL;
        }
    }

    free(input_text);  // Release the allocated memory
    return 0;
}

// Function to convert string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove punctuation from the string
void remove_punctuation(char *str) {
    char *src, *dst;
    src = dst = str;
    
    while (*src) {
        if (!ispunct((unsigned char)*src)) {
            *dst++ = *src; // Copy character
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the cleaned string
}

// Basic algorithm to summarize text
void summarize_text(char *input_text, char **summary) {
    char *token;
    int count = 0;

    // Convert to lowercase to normalize the text
    to_lowercase(input_text);
    
    // Remove punctuation for cleaner tokenization
    remove_punctuation(input_text);
    
    // Tokenize the input text by spaces
    token = strtok(input_text, " \n");
    while (token != NULL && count < SUMMARY_LENGTH) {
        summary[count] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(summary[count], token);
        count++;
        token = strtok(NULL, " \n");
    }
}

// Function to print the summary
void print_summary(char **summary) {
    printf("\n=== Cyberpunk Text Summary ===\n");
    for (int i = 0; i < SUMMARY_LENGTH; i++) {
        if (summary[i] != NULL) {
            printf("- %s\n", summary[i]);
        }
    }
    printf("==============================\n");
}