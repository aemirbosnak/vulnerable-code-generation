//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10

// Define the maximum number of paragraphs in a document
#define MAX_DOCUMENT_LENGTH 10

// Structure to represent a sentence
struct Sentence {
    char text[MAX_SENTENCE_LENGTH];
};

// Structure to represent a paragraph
struct Paragraph {
    struct Sentence sentences[MAX_PARAGRAPH_LENGTH];
    int num_sentences;
};

// Structure to represent a document
struct Document {
    struct Paragraph paragraphs[MAX_DOCUMENT_LENGTH];
    int num_paragraphs;
};

// Function to read a document from a file
struct Document *read_document(char *filename) {
    // Allocate memory for the document
    struct Document *document = malloc(sizeof(struct Document));
    if (document == NULL) {
        return NULL;
    }

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        free(document);
        return NULL;
    }

    // Read the document
    int num_paragraphs = 0;
    while (fgets(document->paragraphs[num_paragraphs].sentences[0].text, MAX_SENTENCE_LENGTH, file) != NULL) {
        // Remove the newline character from the sentence
        document->paragraphs[num_paragraphs].sentences[0].text[strlen(document->paragraphs[num_paragraphs].sentences[0].text) - 1] = '\0';

        // Read the remaining sentences in the paragraph
        int num_sentences = 1;
        while (fgets(document->paragraphs[num_paragraphs].sentences[num_sentences].text, MAX_SENTENCE_LENGTH, file) != NULL && document->paragraphs[num_paragraphs].sentences[num_sentences].text[0] != '\n') {
            // Remove the newline character from the sentence
            document->paragraphs[num_paragraphs].sentences[num_sentences].text[strlen(document->paragraphs[num_paragraphs].sentences[num_sentences].text) - 1] = '\0';

            // Increment the number of sentences in the paragraph
            num_sentences++;
        }

        // Set the number of sentences in the paragraph
        document->paragraphs[num_paragraphs].num_sentences = num_sentences;

        // Increment the number of paragraphs in the document
        num_paragraphs++;
    }

    // Set the number of paragraphs in the document
    document->num_paragraphs = num_paragraphs;

    // Close the file
    fclose(file);

    // Return the document
    return document;
}

// Function to summarize a document
char *summarize_document(struct Document *document) {
    // Allocate memory for the summary
    char *summary = malloc(1000);
    if (summary == NULL) {
        return NULL;
    }

    // Initialize the summary
    strcpy(summary, "");

    // Summarize each paragraph in the document
    for (int i = 0; i < document->num_paragraphs; i++) {
        // Get the first sentence of the paragraph
        char *sentence = document->paragraphs[i].sentences[0].text;

        // Add the sentence to the summary
        strcat(summary, sentence);

        // Add a period to the summary
        strcat(summary, ". ");
    }

    // Return the summary
    return summary;
}

// Function to print a document
void print_document(struct Document *document) {
    // Print each paragraph in the document
    for (int i = 0; i < document->num_paragraphs; i++) {
        // Print each sentence in the paragraph
        for (int j = 0; j < document->paragraphs[i].num_sentences; j++) {
            printf("%s ", document->paragraphs[i].sentences[j].text);
        }

        // Print a newline character
        printf("\n");
    }
}

// Main function
int main() {
    // Read the document from a file
    struct Document *document = read_document("document.txt");
    if (document == NULL) {
        printf("Error reading document\n");
        return 1;
    }

    // Summarize the document
    char *summary = summarize_document(document);
    if (summary == NULL) {
        printf("Error summarizing document\n");
        return 1;
    }

    // Print the document
    printf("Document:\n");
    print_document(document);

    // Print the summary
    printf("\nSummary:\n");
    printf("%s\n", summary);

    // Free the memory allocated for the document and the summary
    free(document);
    free(summary);

    return 0;
}