//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_SENTENCES 1000

struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
};

void add_sentence(struct sentence* sentences, int num_sentences, char* new_sentence) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        exit(1);
    }

    int new_sentence_length = strlen(new_sentence);
    if (new_sentence_length > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence too long.\n");
        exit(1);
    }

    strcpy(sentences[num_sentences].text, new_sentence);
    sentences[num_sentences].length = new_sentence_length;

    num_sentences++;
}

void print_sentences(struct sentence* sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    struct sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    char input_buffer[MAX_SENTENCE_LENGTH];
    char* input_pointer = input_buffer;

    while (fgets(input_buffer, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        char* end_pointer = input_buffer + strlen(input_buffer) - 1;
        while (isspace(*end_pointer)) {
            *end_pointer = '\0';
            end_pointer--;
        }

        if (strlen(input_buffer) == 0) {
            continue;
        }

        add_sentence(sentences, num_sentences, input_buffer);
    }

    print_sentences(sentences, num_sentences);

    return 0;
}