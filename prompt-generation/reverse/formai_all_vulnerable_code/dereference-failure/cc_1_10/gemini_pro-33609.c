//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// A linked list node to store a word and its count
typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node;

// A linked list to store all the words in a sentence
typedef struct sentence_node {
    word_node *head;
    word_node *tail;
    struct sentence_node *next;
} sentence_node;

// A linked list to store all the sentences in a document
typedef struct document {
    sentence_node *head;
    sentence_node *tail;
} document;

// Create a new word node
word_node *create_word_node(char *word) {
    word_node *new_node = malloc(sizeof(word_node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Create a new sentence node
sentence_node *create_sentence_node() {
    sentence_node *new_node = malloc(sizeof(sentence_node));
    new_node->head = NULL;
    new_node->tail = NULL;
    new_node->next = NULL;
    return new_node;
}

// Create a new document
document *create_document() {
    document *new_document = malloc(sizeof(document));
    new_document->head = NULL;
    new_document->tail = NULL;
    return new_document;
}

// Add a word to a sentence
void add_word_to_sentence(sentence_node *sentence, char *word) {
    word_node *new_word = create_word_node(word);
    if (sentence->head == NULL) {
        sentence->head = new_word;
        sentence->tail = new_word;
    } else {
        sentence->tail->next = new_word;
        sentence->tail = new_word;
    }
}

// Add a sentence to a document
void add_sentence_to_document(document *document, sentence_node *sentence) {
    if (document->head == NULL) {
        document->head = sentence;
        document->tail = sentence;
    } else {
        document->tail->next = sentence;
        document->tail = sentence;
    }
}

// Load a document from a file
document *load_document(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    document *document = create_document();
    sentence_node *sentence = create_sentence_node();
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            add_word_to_sentence(sentence, word);
            word = strtok(NULL, " ");
        }
        add_sentence_to_document(document, sentence);
        sentence = create_sentence_node();
    }

    fclose(fp);
    return document;
}

// Print a document
void print_document(document *document) {
    sentence_node *sentence = document->head;
    while (sentence != NULL) {
        word_node *word = sentence->head;
        while (word != NULL) {
            printf("%s ", word->word);
            word = word->next;
        }
        printf("\n");
        sentence = sentence->next;
    }
}

// Free a document
void free_document(document *document) {
    sentence_node *sentence = document->head;
    while (sentence != NULL) {
        word_node *word = sentence->head;
        while (word != NULL) {
            free(word->word);
            free(word);
            word = word->next;
        }
        free(sentence);
        sentence = sentence->next;
    }
    free(document);
}

// The main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    document *document = load_document(argv[1]);
    print_document(document);
    free_document(document);

    return 0;
}