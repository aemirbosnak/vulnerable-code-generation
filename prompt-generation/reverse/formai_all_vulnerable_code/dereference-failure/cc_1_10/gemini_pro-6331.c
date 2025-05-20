//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
    char *word;
    int sentiment;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int num_words;
} Dictionary;

typedef struct {
    char *sentence;
    int sentiment;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

Dictionary *create_dictionary() {
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->num_words = 0;
    return dict;
}

void add_word_to_dictionary(Dictionary *dict, char *word, int sentiment) {
    if (dict->num_words >= MAX_WORDS) {
        return;
    }
    dict->words[dict->num_words].word = malloc(strlen(word) + 1);
    strcpy(dict->words[dict->num_words].word, word);
    dict->words[dict->num_words].sentiment = sentiment;
    dict->num_words++;
}

Text *create_text() {
    Text *text = malloc(sizeof(Text));
    text->num_sentences = 0;
    return text;
}

void add_sentence_to_text(Text *text, char *sentence, int sentiment) {
    if (text->num_sentences >= MAX_SENTENCES) {
        return;
    }
    text->sentences[text->num_sentences].sentence = malloc(strlen(sentence) + 1);
    strcpy(text->sentences[text->num_sentences].sentence, sentence);
    text->sentences[text->num_sentences].sentiment = sentiment;
    text->num_sentences++;
}

int analyze_text(Text *text, Dictionary *dict) {
    int total_sentiment = 0;
    for (int i = 0; i < text->num_sentences; i++) {
        int sentence_sentiment = 0;
        char *sentence = text->sentences[i].sentence;
        char *word = strtok(sentence, " ");
        while (word != NULL) {
            for (int j = 0; j < dict->num_words; j++) {
                if (strcmp(word, dict->words[j].word) == 0) {
                    sentence_sentiment += dict->words[j].sentiment;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
        total_sentiment += sentence_sentiment;
    }
    return total_sentiment;
}

int main() {
    Dictionary *dict = create_dictionary();
    add_word_to_dictionary(dict, "good", 1);
    add_word_to_dictionary(dict, "bad", -1);
    add_word_to_dictionary(dict, "great", 2);
    add_word_to_dictionary(dict, "terrible", -2);

    Text *text = create_text();
    add_sentence_to_text(text, "The movie was great!", 2);
    add_sentence_to_text(text, "The service was terrible!", -2);

    int total_sentiment = analyze_text(text, dict);
    printf("The overall sentiment of the text is %d.\n", total_sentiment);

    return 0;
}