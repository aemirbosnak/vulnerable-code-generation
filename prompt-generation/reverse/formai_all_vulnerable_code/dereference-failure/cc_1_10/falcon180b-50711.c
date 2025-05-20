//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define NUM_CLASSES 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int *classes;
    int num_classes;
} Document;

void init_document(Document *doc) {
    doc->num_words = 0;
    doc->num_classes = NUM_CLASSES;
    doc->classes = (int *)malloc(sizeof(int) * NUM_CLASSES);
    for (int i = 0; i < NUM_CLASSES; i++) {
        doc->classes[i] = 0;
    }
}

void add_word(Document *doc, char *word) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->count = 1;
    doc->words = (Word *)realloc(doc->words, sizeof(Word) * (doc->num_words + 1));
    doc->words[doc->num_words] = *new_word;
    doc->num_words++;
}

void add_class(Document *doc, int class) {
    doc->classes[class]++;
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_classes; i++) {
        printf("%d: %d\n", i, doc->classes[i]);
    }
}

int main() {
    Document doc;
    init_document(&doc);

    char *text = "The quick brown fox jumps over the lazy dog";
    char *word = strtok(text, " ");
    while (word!= NULL) {
        add_word(&doc, word);
        word = strtok(NULL, " ");
    }

    print_document(&doc);

    return 0;
}