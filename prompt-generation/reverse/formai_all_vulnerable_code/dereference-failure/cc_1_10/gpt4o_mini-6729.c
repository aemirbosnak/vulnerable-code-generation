//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

// Struct to hold individual sentences
typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

// Function prototypes
void extract_sentences(const char *text, Sentence sentences[], int *sentence_count);
int is_significant_sentence(Sentence sentence);
void summarize_text(Sentence sentences[], int sentence_count, Sentence summary[], int *summary_count);
void display_summary(Sentence summary[], int summary_count);

int main() {
    char text[MAX_TEXT_LENGTH];
    Sentence sentences[MAX_SENTENCES];
    Sentence summary[MAX_SENTENCES];
    int sentence_count = 0, summary_count = 0;

    printf("Welcome to the Text Summarizer!\n");
    printf("Please enter the text you want to summarize (press CTRL+D to end input):\n");

    // Read input until EOF
    fgets(text, MAX_TEXT_LENGTH, stdin);
    
    extract_sentences(text, sentences, &sentence_count);
    summarize_text(sentences, sentence_count, summary, &summary_count);
    display_summary(summary, summary_count);

    return 0;
}

void extract_sentences(const char *text, Sentence sentences[], int *sentence_count) {
    const char *delimiters = ".!?";
    char *token, *text_copy;
    text_copy = malloc(strlen(text) + 1);
    strcpy(text_copy, text);

    token = strtok(text_copy, delimiters);
    while (token != NULL && *sentence_count < MAX_SENTENCES) {
        // Trim whitespace and store the sentence
        strcpy(sentences[*sentence_count].sentence, token);
        sentences[*sentence_count].length = strlen(token);
        (*sentence_count)++;
        token = strtok(NULL, delimiters);
    }

    free(text_copy);
}

int is_significant_sentence(Sentence sentence) {
    // A sentence is considered significant if it has more than five words
    int word_count = 0;
    char *token = strtok(sentence.sentence, " ");
    
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    return word_count > 5;
}

void summarize_text(Sentence sentences[], int sentence_count, Sentence summary[], int *summary_count) {
    for (int i = 0; i < sentence_count; i++) {
        // Check if the sentence is significant
        if (is_significant_sentence(sentences[i])) {
            // If significant, copy to summary
            strcpy(summary[*summary_count].sentence, sentences[i].sentence);
            summary[*summary_count].length = sentences[i].length;
            (*summary_count)++;
        }
    }
}

void display_summary(Sentence summary[], int summary_count) {
    printf("\n--- Summary ---\n");
    if (summary_count == 0) {
        printf("No significant sentences were found in the provided text.\n");
        return;
    }

    for (int i = 0; i < summary_count; i++) {
        printf("%d. %s.\n", i + 1, summary[i].sentence);
    }
}