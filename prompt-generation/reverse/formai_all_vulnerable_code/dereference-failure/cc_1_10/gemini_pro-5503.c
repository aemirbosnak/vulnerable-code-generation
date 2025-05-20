//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char *words[MAX_WORDS_PER_SENTENCE];
    int num_words;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

Text *read_text(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Text *text = malloc(sizeof(Text));
    text->num_sentences = 0;

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Parse the line into sentences.
        char *sentence_start = line;
        while (*sentence_start != '\0') {
            // Find the end of the sentence.
            char *sentence_end = sentence_start;
            while (*sentence_end != '\0' && *sentence_end != '.' && *sentence_end != '!' && *sentence_end != '?') {
                sentence_end++;
            }

            // Create a new sentence.
            Sentence sentence;
            sentence.num_words = 0;

            // Parse the sentence into words.
            char *word_start = sentence_start;
            while (word_start != sentence_end) {
                // Find the end of the word.
                char *word_end = word_start;
                while (*word_end != '\0' && *word_end != ' ' && *word_end != ',' && *word_end != ';') {
                    word_end++;
                }

                // Copy the word into the sentence.
                char *word = malloc(word_end - word_start + 1);
                strncpy(word, word_start, word_end - word_start);
                word[word_end - word_start] = '\0';
                sentence.words[sentence.num_words] = word;
                sentence.num_words++;

                // Move to the next word.
                word_start = word_end + 1;
            }

            // Add the sentence to the text.
            text->sentences[text->num_sentences] = sentence;
            text->num_sentences++;

            // Move to the next sentence.
            sentence_start = sentence_end + 1;
        }
    }

    fclose(fp);

    return text;
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        for (int j = 0; j < text->sentences[i].num_words; j++) {
            free(text->sentences[i].words[j]);
        }
    }
    free(text);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Text *text = read_text(argv[1]);
    if (text == NULL) {
        return 1;
    }

    // Summarize the text.
    char summary[1024];
    sprintf(summary, "The text is about %s.", text->sentences[0].words[0]);

    // Print the summary.
    printf("%s\n", summary);

    free_text(text);

    return 0;
}