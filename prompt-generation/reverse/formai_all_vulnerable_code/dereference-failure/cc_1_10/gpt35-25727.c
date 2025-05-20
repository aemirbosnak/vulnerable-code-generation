//FormAI DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char *read_input(char *filename) {
    FILE *fp;
    char *text;
    char buffer[MAX_LEN];
    int text_len = 0;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the entire file into a string
    text = (char *) malloc(MAX_LEN * sizeof(char));
    while (fgets(buffer, MAX_LEN, fp) != NULL) {
        strcat(text, buffer);
        text_len += strlen(buffer);
    }

    // Close the file and return the text
    fclose(fp);
    return text;
}

void summarize_text(char *text, int max_sentences) {
    char *sentence;
    char *last_period;
    char *sentences[MAX_LEN];
    int num_sentences = 0;
    int i;

    // Tokenize the text into sentences
    sentence = strtok(text, ".!?");
    while (sentence != NULL) {
        last_period = strrchr(sentence, '.');
        if (last_period != NULL && *(last_period+1) == '\0') {
            sentences[num_sentences++] = sentence;
            if (num_sentences == max_sentences) {
                break;
            }
        }
        sentence = strtok(NULL, ".!?");
    }

    // Print out the summarized text
    for (i = 0; i < num_sentences; i++) {
        printf("%s. ", sentences[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *filename;
    char *text;
    int max_sentences;

    // Parse the command line arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <max_sentences>\n", argv[0]);
        exit(1);
    }
    filename = argv[1];
    max_sentences = atoi(argv[2]);

    // Read in the text from the file
    text = read_input(filename);

    // Summarize the text and print it out
    summarize_text(text, max_sentences);

    return 0;
}