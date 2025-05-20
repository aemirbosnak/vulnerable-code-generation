//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100
#define MAX_SUMMARY_SIZE 1000

// Structure to represent a word
typedef struct {
    char* word;
    int frequency;
} Word;

// Structure to represent a sentence
typedef struct {
    char* sentence;
    int length;
    int score;
} Sentence;

// Structure to represent the entire text
typedef struct {
    Word words[MAX_WORDS];
    int num_words;
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
    int total_length;
} Text;

// Function to create a new word
Word* new_word(char* word) {
    Word* w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = 1;
    return w;
}

// Function to create a new sentence
Sentence* new_sentence(char* sentence, int length) {
    Sentence* s = malloc(sizeof(Sentence));
    s->sentence = strdup(sentence);
    s->length = length;
    s->score = 0;
    return s;
}

// Function to create a new text
Text* new_text() {
    Text* t = malloc(sizeof(Text));
    t->num_words = 0;
    t->num_sentences = 0;
    t->total_length = 0;
    return t;
}

// Function to add a word to the text
void add_word(Text* t, char* word) {
    // Check if the word already exists
    for (int i = 0; i < t->num_words; i++) {
        if (strcmp(t->words[i].word, word) == 0) {
            t->words[i].frequency++;
            return;
        }
    }

    // Add the new word to the list
    t->words[t->num_words++] = *new_word(word);
}

// Function to add a sentence to the text
void add_sentence(Text* t, char* sentence, int length) {
    // Add the new sentence to the list
    t->sentences[t->num_sentences++] = *new_sentence(sentence, length);
}

// Function to calculate the score of a sentence
void calculate_sentence_score(Text* t, Sentence* s) {
    // Split the sentence into words
    char* words[MAX_WORDS];
    int num_words = 0;
    char* token = strtok(s->sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the score of the sentence
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < t->num_words; j++) {
            if (strcmp(words[i], t->words[j].word) == 0) {
                s->score += t->words[j].frequency;
            }
        }
    }
}

// Function to sort the sentences by score
void sort_sentences(Text* t) {
    for (int i = 0; i < t->num_sentences - 1; i++) {
        for (int j = i + 1; j < t->num_sentences; j++) {
            if (t->sentences[i].score < t->sentences[j].score) {
                Sentence temp = t->sentences[i];
                t->sentences[i] = t->sentences[j];
                t->sentences[j] = temp;
            }
        }
    }
}

// Function to generate a summary of the text
char* generate_summary(Text* t, int summary_size) {
    // Calculate the total length of the summary
    int total_length = 0;
    for (int i = 0; i < t->num_sentences; i++) {
        total_length += t->sentences[i].length;
    }

    // Create a buffer to store the summary
    char* summary = malloc(summary_size);
    int summary_length = 0;

    // Add sentences to the summary until the total length is reached
    for (int i = 0; i < t->num_sentences; i++) {
        if (summary_length + t->sentences[i].length < summary_size) {
            strcat(summary, t->sentences[i].sentence);
            summary_length += t->sentences[i].length;
        } else {
            break;
        }
    }

    return summary;
}

// Function to free the memory allocated for a text
void free_text(Text* t) {
    for (int i = 0; i < t->num_words; i++) {
        free(t->words[i].word);
    }
    for (int i = 0; i < t->num_sentences; i++) {
        free(t->sentences[i].sentence);
    }
    free(t);
}

// Main function
int main() {
    // Create a new text
    Text* t = new_text();

    // Add words to the text
    add_word(t, "the");
    add_word(t, "quick");
    add_word(t, "brown");
    add_word(t, "fox");
    add_word(t, "jumped");
    add_word(t, "over");
    add_word(t, "the");
    add_word(t, "lazy");
    add_word(t, "dog");

    // Add sentences to the text
    add_sentence(t, "The quick brown fox jumped over the lazy dog.", 43);
    add_sentence(t, "The dog was very lazy.", 20);
    add_sentence(t, "The fox was very quick.", 18);

    // Calculate the score of each sentence
    for (int i = 0; i < t->num_sentences; i++) {
        calculate_sentence_score(t, &t->sentences[i]);
    }

    // Sort the sentences by score
    sort_sentences(t);

    // Generate a summary of the text
    char* summary = generate_summary(t, 100);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the memory allocated for the text
    free_text(t);

    return 0;
}