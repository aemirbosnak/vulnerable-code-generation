//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

typedef struct {
    char **sentences;
    int sentence_count;
} Text;

// Function to initialize the Text structure
Text* initialize_text() {
    Text *text = (Text*) malloc(sizeof(Text));
    text->sentences = (char**) malloc(MAX_SENTENCES * sizeof(char*));
    for (int i = 0; i < MAX_SENTENCES; i++) {
        text->sentences[i] = (char*) malloc(MAX_TEXT_LENGTH * sizeof(char));
    }
    text->sentence_count = 0;
    return text;
}

// Function to free memory allocated for the Text structure
void free_text(Text* text) {
    for (int i = 0; i < MAX_SENTENCES; i++) {
        free(text->sentences[i]);
    }
    free(text->sentences);
    free(text);
}

// Function to split text into sentences
void split_into_sentences(Text *text, const char *input_text) {
    const char *delimiters = ".!?";
    char *token;
    char *text_copy = strdup(input_text);

    token = strtok(text_copy, delimiters);
    while (token != NULL && text->sentence_count < MAX_SENTENCES) {
        strcpy(text->sentences[text->sentence_count], token);
        text->sentence_count++;
        token = strtok(NULL, delimiters);
    }
    free(text_copy);
}

// Function to count words in a sentence
int count_words(const char *sentence) {
    int count = 0;
    char *temp = strdup(sentence);
    char *word = strtok(temp, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    free(temp);
    return count;
}

// Function to generate summary from sentences based on word count
void generate_summary(Text *text, int word_limit) {
    printf("Summary:\n");
    int total_words = 0;
    for (int i = 0; i < text->sentence_count && total_words < word_limit; i++) {
        int words_in_sentence = count_words(text->sentences[i]);
        if (total_words + words_in_sentence <= word_limit) {
            printf("%s. ", text->sentences[i]);
            total_words += words_in_sentence;
        }
    }
    printf("\n");
}

int main() {
    Text *text = initialize_text();
    char input_text[MAX_TEXT_LENGTH];
    
    printf("Enter text (up to %d characters, end with **):\n", MAX_TEXT_LENGTH);
    fgets(input_text, sizeof(input_text), stdin);
    
    // Handling ending input gracefully
    if (strcmp(input_text, "**\n") == 0) {
        printf("No text provided.\n");
        free_text(text);
        return 1;
    }

    // Stripping the ending marker if present
    size_t len = strlen(input_text);
    if (len > 2 && strcmp(input_text + len - 3, "**\n") == 0) {
        input_text[len - 3] = '\0';
    }

    // Split input text into sentences
    split_into_sentences(text, input_text);
    
    // Generate summary with a word limit
    int word_limit;
    printf("Enter word limit for summary: ");
    scanf("%d", &word_limit);
    
    generate_summary(text, word_limit);
    
    free_text(text);
    return 0;
}