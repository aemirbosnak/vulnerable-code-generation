//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100
#define MAX_SENTENCES 1000

typedef struct {
    char *word;
    int score;
} Word;

typedef struct {
    Word *words[MAX_WORDS];
    int num_words;
} Dictionary;

typedef struct {
    char *sentence;
    int score;
} Sentence;

typedef struct {
    Sentence *sentences[MAX_SENTENCES];
    int num_sentences;
} Document;

// Load the dictionary from a file
Dictionary *load_dictionary(const char *filename) {
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->num_words = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file: %s", filename);
        exit(1);
    }

    char line[MAX_WORD_LEN + 2];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, " ");
        char *score = strtok(NULL, " ");
        if (word != NULL && score != NULL) {
            Word *w = malloc(sizeof(Word));
            w->word = strdup(word);
            w->score = atoi(score);
            dict->words[dict->num_words++] = w;
        }
    }

    fclose(fp);

    return dict;
}

// Free the dictionary
void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->num_words; i++) {
        free(dict->words[i]->word);
        free(dict->words[i]);
    }

    free(dict);
}

// Load the document from a file
Document *load_document(const char *filename) {
    Document *doc = malloc(sizeof(Document));
    doc->num_sentences = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening document file: %s", filename);
        exit(1);
    }

    char line[MAX_SENTENCES * MAX_WORD_LEN + 2];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *sentence = strtok(line, ". ");
        if (sentence != NULL) {
            Sentence *s = malloc(sizeof(Sentence));
            s->sentence = strdup(sentence);
            s->score = 0;
            doc->sentences[doc->num_sentences++] = s;
        }
    }

    fclose(fp);

    return doc;
}

// Free the document
void free_document(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        free(doc->sentences[i]->sentence);
        free(doc->sentences[i]);
    }

    free(doc);
}

// Analyze the sentiment of a document
int analyze_sentiment(Document *doc, Dictionary *dict) {
    int total_score = 0;
    for (int i = 0; i < doc->num_sentences; i++) {
        Sentence *sentence = doc->sentences[i];
        char *word = strtok(sentence->sentence, " ");
        while (word != NULL) {
            for (int j = 0; j < dict->num_words; j++) {
                if (strcmp(word, dict->words[j]->word) == 0) {
                    sentence->score += dict->words[j]->score;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
        total_score += sentence->score;
    }
    return total_score;
}

// Print the sentiment analysis results
void print_results(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        Sentence *sentence = doc->sentences[i];
        printf("Sentence: %s\n", sentence->sentence);
        printf("Score: %d\n", sentence->score);
        if (sentence->score > 0) {
            printf("Sentiment: positive\n");
        } else if (sentence->score < 0) {
            printf("Sentiment: negative\n");
        } else {
            printf("Sentiment: neutral\n");
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <document_file>", argv[0]);
        exit(1);
    }

    Dictionary *dict = load_dictionary(argv[1]);
    Document *doc = load_document(argv[2]);

    int total_score = analyze_sentiment(doc, dict);

    printf("Total score: %d\n", total_score);
    if (total_score > 0) {
        printf("Overall sentiment: positive\n");
    } else if (total_score < 0) {
        printf("Overall sentiment: negative\n");
    } else {
        printf("Overall sentiment: neutral\n");
    }

    print_results(doc);

    free_dictionary(dict);
    free_document(doc);

    return 0;
}