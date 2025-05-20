//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCE_LENGTH 100

void summarize(char *inFile, char *outFile, int summary_length);

int main(int argc, char *argv[]) {
    char *inFile, *outFile;
    int summary_length;
    if (argc == 4) {
        inFile = argv[1];
        outFile = argv[2];
        summary_length = atoi(argv[3]);
        summarize(inFile, outFile, summary_length);
    }
    else {
        printf("Usage: %s <input_file> <output_file> <summary_length>\n", argv[0]);
    }
    return 0;
}

void summarize(char *inFile, char *outFile, int summary_length) {
    FILE *fp_in = fopen(inFile, "r");
    FILE *fp_out = fopen(outFile, "w");
    char input[MAX_STRING_LENGTH];
    char sentences[MAX_SENTENCE_LENGTH][MAX_STRING_LENGTH];
    int num_sentences = 0, i;

    while (fgets(input, MAX_STRING_LENGTH, fp_in)) {
        /* Split input into sentences */
        char *token = strtok(input, ".");
        while (token != NULL) {
            strcpy(sentences[num_sentences], token);
            num_sentences++;
            token = strtok(NULL, ".");
        }
    }

    /* Calculate sentence scores */
    float sentence_scores[num_sentences];
    for (i = 0; i < num_sentences; i++) {
        sentence_scores[i] = 0;
    }

    /* Output summary */
    for (i = 0; i < summary_length; i++) {
        int best_sentence_index = 0, j;
        float best_sentence_score = 0;
        for (j = 0; j < num_sentences; j++) {
            if (sentence_scores[j] > best_sentence_score) {
                best_sentence_index = j;
                best_sentence_score = sentence_scores[j];
            }
        }
        sentence_scores[best_sentence_index] = -1;
        fprintf(fp_out, "%s. ", sentences[best_sentence_index]);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Done summarizing!\n");
}