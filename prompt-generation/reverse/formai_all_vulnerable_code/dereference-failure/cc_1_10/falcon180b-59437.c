//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

// Struct to hold sentence and its length
typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

// Function to read sentences from file and store in array
int read_sentences(Sentence sentences[], FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '.') {
            sentences[count].length = strlen(sentences[count].sentence);
            count++;
        } else if (count < MAX_SENTENCES - 1) {
            strncat(sentences[count].sentence, &ch, 1);
        }
    }
    return count;
}

// Function to print summary with specified number of sentences
void print_summary(Sentence sentences[], int num_sentences) {
    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].sentence);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <number_of_sentences>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int num_sentences = atoi(argv[2]);

    Sentence sentences[MAX_SENTENCES];
    int num_sentences_read = read_sentences(sentences, input_file);

    if (num_sentences_read < num_sentences) {
        printf("Not enough sentences in file\n");
        return 1;
    }

    print_summary(sentences, num_sentences);

    fclose(input_file);
    return 0;
}