//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to read a text file into a string
char *read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    fread(buffer, size, 1, fp);
    fclose(fp);

    buffer[size] = '\0';

    return buffer;
}

// Function to summarize a text
char *summarize(char *text, int num_sentences) {
    // Split the text into sentences
    char **sentences = malloc(sizeof(char *) * num_sentences);
    int num_sentences_found = 0;
    char *start = text;
    char *end = strchr(text, '.');
    while (end != NULL) {
        sentences[num_sentences_found++] = strndup(start, end - start);
        start = end + 1;
        end = strchr(start, '.');
    }

    // Calculate the sentence scores
    int *scores = malloc(sizeof(int) * num_sentences_found);
    for (int i = 0; i < num_sentences_found; i++) {
        scores[i] = 0;
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strlen(word) > 3) {
                scores[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort the sentences by score
    for (int i = 0; i < num_sentences_found - 1; i++) {
        for (int j = 0; j < num_sentences_found - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;

                char *temp_sentence = sentences[j];
                sentences[j] = sentences[j + 1];
                sentences[j + 1] = temp_sentence;
            }
        }
    }

    // Generate the summary
    char *summary = malloc(sizeof(char) * 1024);
    summary[0] = '\0';
    for (int i = 0; i < num_sentences && i < num_sentences_found; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
    }

    // Free the allocated memory
    for (int i = 0; i < num_sentences_found; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(scores);

    return summary;
}

// Main function
int main() {
    // Read the text file
    char *text = read_file("input.txt");
    if (text == NULL) {
        return 1;
    }

    // Summarize the text
    char *summary = summarize(text, 5);
    if (summary == NULL) {
        return 1;
    }

    // Print the summary
    printf("%s", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}