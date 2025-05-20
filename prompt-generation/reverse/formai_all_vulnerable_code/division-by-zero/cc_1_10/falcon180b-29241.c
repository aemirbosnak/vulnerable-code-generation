//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

void read_text_file(Text *text, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char ch;
    int sentence_length = 0;
    int num_sentences = 0;

    Sentence current_sentence;
    current_sentence.length = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n' || ch == '.' || ch == '!' || ch == '?') {
            if (sentence_length >= MIN_SENTENCE_LENGTH) {
                current_sentence.text[sentence_length] = '\0';
                strcpy(text->sentences[num_sentences].text, current_sentence.text);
                text->sentences[num_sentences].length = sentence_length;
                num_sentences++;
                sentence_length = 0;
            }
        } else if (isspace(ch)) {
            if (sentence_length >= MIN_SENTENCE_LENGTH) {
                current_sentence.text[sentence_length] = '\0';
                strcpy(text->sentences[num_sentences].text, current_sentence.text);
                text->sentences[num_sentences].length = sentence_length;
                num_sentences++;
                sentence_length = 0;
            }
        } else if (sentence_length < MAX_SENTENCE_LENGTH) {
            current_sentence.text[sentence_length++] = tolower(ch);
        }
    }

    if (sentence_length >= MIN_SENTENCE_LENGTH) {
        current_sentence.text[sentence_length] = '\0';
        strcpy(text->sentences[num_sentences].text, current_sentence.text);
        text->sentences[num_sentences].length = sentence_length;
        num_sentences++;
    }

    text->num_sentences = num_sentences;

    fclose(file);
}

void print_sentence(Sentence sentence) {
    printf("%s", sentence.text);
}

void print_text(Text text) {
    for (int i = 0; i < text.num_sentences; i++) {
        print_sentence(text.sentences[i]);
        printf("\n");
    }
}

int main() {
    Text text;

    read_text_file(&text, "input.txt");

    srand(time(NULL));
    int num_sentences_to_keep = rand() % text.num_sentences + 1;

    for (int i = 0; i < num_sentences_to_keep; i++) {
        int random_index = rand() % text.num_sentences;
        Sentence *random_sentence = &text.sentences[random_index];

        print_sentence(*random_sentence);
        printf("\n");
    }

    return 0;
}