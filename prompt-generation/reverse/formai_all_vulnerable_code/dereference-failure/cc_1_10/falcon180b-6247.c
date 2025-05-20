//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    char filename[100];
    char sentence[MAX_SENTENCE_LENGTH];
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];

    printf("Enter input file name: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("summary.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        if (num_sentences >= MAX_SENTENCES) {
            printf("Maximum number of sentences reached.\n");
            break;
        }
        sentences[num_sentences].length = strlen(sentence);
        strcpy(sentences[num_sentences].text, sentence);
        num_sentences++;
    }

    int total_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        total_words += sentences[i].length;
    }

    int summary_length = total_words / 10;
    if (summary_length < 1) {
        summary_length = 1;
    }

    fprintf(output_file, "Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        int sentence_length = sentences[i].length;
        if (sentence_length > summary_length) {
            sentence_length = summary_length;
        }
        fprintf(output_file, "%s ", sentences[i].text);
        for (int j = sentence_length; j < summary_length; j++) {
            fprintf(output_file, " ");
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}