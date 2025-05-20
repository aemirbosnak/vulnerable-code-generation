//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 100

// Define the maximum number of paragraphs in a text
#define MAX_TEXT_LENGTH 10

// Define the structure of a sentence
typedef struct sentence {
    char *text;
    int length;
} sentence_t;

// Define the structure of a paragraph
typedef struct paragraph {
    sentence_t *sentences;
    int num_sentences;
} paragraph_t;

// Define the structure of a text
typedef struct text {
    paragraph_t *paragraphs;
    int num_paragraphs;
} text_t;

// Create a new text
text_t *create_text() {
    text_t *text = malloc(sizeof(text_t));
    text->paragraphs = malloc(sizeof(paragraph_t) * MAX_TEXT_LENGTH);
    text->num_paragraphs = 0;
    return text;
}

// Free the memory allocated for a text
void free_text(text_t *text) {
    for (int i = 0; i < text->num_paragraphs; i++) {
        for (int j = 0; j < text->paragraphs[i].num_sentences; j++) {
            free(text->paragraphs[i].sentences[j].text);
        }
        free(text->paragraphs[i].sentences);
    }
    free(text->paragraphs);
    free(text);
}

// Add a new paragraph to a text
void add_paragraph(text_t *text, paragraph_t *paragraph) {
    text->paragraphs[text->num_paragraphs] = *paragraph;
    text->num_paragraphs++;
}

// Create a new paragraph
paragraph_t *create_paragraph() {
    paragraph_t *paragraph = malloc(sizeof(paragraph_t));
    paragraph->sentences = malloc(sizeof(sentence_t) * MAX_PARAGRAPH_LENGTH);
    paragraph->num_sentences = 0;
    return paragraph;
}

// Free the memory allocated for a paragraph
void free_paragraph(paragraph_t *paragraph) {
    for (int i = 0; i < paragraph->num_sentences; i++) {
        free(paragraph->sentences[i].text);
    }
    free(paragraph->sentences);
    free(paragraph);
}

// Add a new sentence to a paragraph
void add_sentence(paragraph_t *paragraph, sentence_t *sentence) {
    paragraph->sentences[paragraph->num_sentences] = *sentence;
    paragraph->num_sentences++;
}

// Create a new sentence
sentence_t *create_sentence(char *text) {
    sentence_t *sentence = malloc(sizeof(sentence_t));
    sentence->text = malloc(strlen(text) + 1);
    strcpy(sentence->text, text);
    sentence->length = strlen(text);
    return sentence;
}

// Free the memory allocated for a sentence
void free_sentence(sentence_t *sentence) {
    free(sentence->text);
    free(sentence);
}

// Print a text
void print_text(text_t *text) {
    for (int i = 0; i < text->num_paragraphs; i++) {
        for (int j = 0; j < text->paragraphs[i].num_sentences; j++) {
            printf("%s ", text->paragraphs[i].sentences[j].text);
        }
        printf("\n");
    }
}

// Summarize a text
text_t *summarize_text(text_t *text) {
    text_t *summary = create_text();

    for (int i = 0; i < text->num_paragraphs; i++) {
        paragraph_t *paragraph = &text->paragraphs[i];

        // Find the longest sentence in the paragraph
        int longest_sentence_index = 0;
        for (int j = 1; j < paragraph->num_sentences; j++) {
            if (paragraph->sentences[j].length > paragraph->sentences[longest_sentence_index].length) {
                longest_sentence_index = j;
            }
        }

        // Add the longest sentence to the summary
        add_sentence(summary, &paragraph->sentences[longest_sentence_index]);
    }

    return summary;
}

int main() {
    // Create a new text
    text_t *text = create_text();

    // Add a new paragraph to the text
    paragraph_t *paragraph = create_paragraph();
    add_sentence(paragraph, create_sentence("This is the first sentence."));
    add_sentence(paragraph, create_sentence("This is the second sentence."));
    add_sentence(paragraph, create_sentence("This is the third sentence."));
    add_paragraph(text, paragraph);

    // Add another new paragraph to the text
    paragraph = create_paragraph();
    add_sentence(paragraph, create_sentence("This is the fourth sentence."));
    add_sentence(paragraph, create_sentence("This is the fifth sentence."));
    add_sentence(paragraph, create_sentence("This is the sixth sentence."));
    add_paragraph(text, paragraph);

    // Print the original text
    printf("Original text:\n");
    print_text(text);

    // Summarize the text
    text_t *summary = summarize_text(text);

    // Print the summary
    printf("\nSummary:\n");
    print_text(summary);

    // Free the memory allocated for the text and the summary
    free_text(text);
    free_text(summary);

    return 0;
}