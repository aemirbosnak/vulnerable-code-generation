//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 512
#define MAX_KEYWORDS 20
#define MAX_KEYWORD_LENGTH 50
#define MAX_SUMMARY_LENGTH 10000

// Function to check if a sentence contains any keyword
int contains_keyword(const char *sentence, char keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH], int keyword_count) {
    for (int i = 0; i < keyword_count; i++) {
        if (strstr(sentence, keywords[i]) != NULL) {
            return 1; // Keyword found in the sentence
        }
    }
    return 0; // No keywords found
}

// Function to extract sentences from text
void extract_sentences(const char *text, char sentences[][MAX_SENTENCE_LENGTH], int *sentence_count) {
    const char *token = strtok((char *)text, ".!?");
    while (token != NULL) {
        strncpy(sentences[*sentence_count], token, MAX_SENTENCE_LENGTH);
        (*sentence_count)++;
        token = strtok(NULL, ".!?");
    }
}

// Function to create summary based on keywords
void create_summary(char sentences[][MAX_SENTENCE_LENGTH], int sentence_count, char keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH], int keyword_count, char *summary) {
    for (int i = 0; i < sentence_count; i++) {
        if (contains_keyword(sentences[i], keywords, keyword_count)) {
            strcat(summary, sentences[i]);
            strcat(summary, ". "); // Adding period back after sentence
        }
    }
}

int main() {
    FILE *file;
    char *text;
    long length;
    
    // Prompt for file name
    char filename[256];
    printf("Enter the name of the text file to summarize: ");
    scanf("%s", filename);
    
    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 1;
    }

    // Read the entire file into a buffer
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    text = (char *)malloc(length + 1);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }
    fread(text, 1, length, file);
    fclose(file);
    text[length] = '\0'; // Null-terminate the string

    // Define keywords for summarization
    char keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH];
    int keyword_count = 0;

    printf("Enter the number of keywords: ");
    scanf("%d", &keyword_count);
    getchar(); // Consume newline
    
    for (int i = 0; i < keyword_count; i++) {
        printf("Enter keyword %d: ", i + 1);
        fgets(keywords[i], MAX_KEYWORD_LENGTH, stdin);
        strtok(keywords[i], "\n"); // Remove newline character
    }

    char sentences[MAX_SUMMARY_LENGTH][MAX_SENTENCE_LENGTH];
    int sentence_count = 0;

    // Extract sentences from text
    extract_sentences(text, sentences, &sentence_count);

    // Create summary from extracted sentences
    char summary[MAX_SUMMARY_LENGTH] = "";
    create_summary(sentences, sentence_count, keywords, keyword_count, summary);

    // Output the summary
    printf("\n--- Summary ---\n");
    if (strlen(summary) > 0) {
        printf("%s\n", summary);
    } else {
        printf("No relevant sentences found for the given keywords.\n");
    }

    // Free the allocated memory
    free(text);
    return 0;
}