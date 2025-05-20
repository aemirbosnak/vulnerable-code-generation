//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    int length;
} Sentence;

void read_sentences(Sentence sentences[], int *num_sentences) {
    char buffer[MAX_SENTENCE_LENGTH];
    int i = 0;

    printf("Enter sentences, followed by an empty line to finish:\n");

    while (fgets(buffer, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (buffer[0]!= '\n') {
            sentences[i].text = strdup(buffer);
            sentences[i].length = strlen(sentences[i].text);
            i++;
        }
    }

    *num_sentences = i;
}

void print_sentence(Sentence sentence) {
    printf("%s\n", sentence.text);
}

int compare_sentences(Sentence a, Sentence b) {
    return strcmp(a.text, b.text);
}

void sort_sentences(Sentence sentences[], int num_sentences) {
    qsort(sentences, num_sentences, sizeof(Sentence), compare_sentences);
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;

    read_sentences(sentences, &num_sentences);

    sort_sentences(sentences, num_sentences);

    for (int i = 0; i < num_sentences; i++) {
        print_sentence(sentences[i]);
    }

    return 0;
}