//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure to hold a sentence
typedef struct sentence {
    char *text;
    int length;
} sentence;

// Function to create a new sentence
sentence *new_sentence(char *text) {
    sentence *s = malloc(sizeof(sentence));
    s->text = strdup(text);
    s->length = strlen(text);
    return s;
}

// Function to free a sentence
void free_sentence(sentence *s) {
    free(s->text);
    free(s);
}

// Function to compare two sentences
int compare_sentences(const void *a, const void *b) {
    const sentence *sa = a;
    const sentence *sb = b;
    return sa->length - sb->length;
}

// Function to summarize a text
char *summarize_text(char *text, int num_sentences) {
    // Split the text into sentences
    char *token;
    char *delim = ".,!?";
    int num_tokens = 0;
    sentence **sentences = NULL;

    for (token = strtok(text, delim); token != NULL; token = strtok(NULL, delim)) {
        sentences = realloc(sentences, sizeof(sentence *) * (num_tokens + 1));
        sentences[num_tokens++] = new_sentence(token);
    }

    // Sort the sentences by length
    qsort(sentences, num_tokens, sizeof(sentence *), compare_sentences);

    // Create the summary
    char *summary = malloc(1);
    summary[0] = '\0';
    for (int i = 0; i < num_sentences && i < num_tokens; i++) {
        strcat(summary, sentences[i]->text);
        strcat(summary, " ");
    }

    // Free the sentences
    for (int i = 0; i < num_tokens; i++) {
        free_sentence(sentences[i]);
    }
    free(sentences);

    // Return the summary
    return summary;
}

// Main function
int main() {
    // Get the text from the user
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, stdin);

    // Get the number of sentences to include in the summary
    int num_sentences;
    printf("How many sentences would you like to include in the summary? ");
    scanf("%d", &num_sentences);

    // Summarize the text
    char *summary = summarize_text(text, num_sentences);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the summary
    free(summary);
    free(text);

    return 0;
}