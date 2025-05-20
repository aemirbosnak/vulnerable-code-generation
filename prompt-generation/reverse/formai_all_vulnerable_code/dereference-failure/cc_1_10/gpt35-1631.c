//FormAI DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sentence {
    char *content;
    float rank;
} Sentence;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Invalid arguments!\nUsage: ./summarizer input_file_path output_file_path\n");
        return 1;
    }
    char *input_file_path = argv[1];
    char *output_file_path = argv[2];

    FILE *input_file = fopen(input_file_path, "r");
    FILE *output_file = fopen(output_file_path, "w");

    if(input_file == NULL || output_file == NULL) {
        printf("Failed to open file!\n");
        return 1;
    }

    char *content = (char *) malloc(10000 * sizeof(char));
    char *line = (char *) malloc(500 * sizeof(char));
    int num_sentences = 0;

    while(fgets(line, 500, input_file) != NULL) {
        strcat(content, line);
        num_sentences++;
    }

    Sentence *sentences = (Sentence *) malloc(num_sentences * sizeof(Sentence));
    char *token;
    token = strtok(content, ".\n");

    // Calculate rank for each sentence
    for(int i = 0; i < num_sentences; i++) {
        sentences[i].content = token;
        sentences[i].rank = rand() % 10; // This is a mind-bending summarizer, so why not use random ranks?
        token = strtok(NULL, ".\n");
    }

    // Sort sentences in descending order based on rank
    for(int i = 0; i < num_sentences - 1; i++) {
        for(int j = 0; j < num_sentences - i - 1; j++) {
            if(sentences[j].rank < sentences[j+1].rank) {
                Sentence temp = sentences[j];
                sentences[j] = sentences[j+1];
                sentences[j+1] = temp;
            }
        }
    }

    // Write top 3 sentences to output file
    for(int i = 0; i < 3; i++) {
        fprintf(output_file, "%s. ", sentences[i].content);
    }

    printf("Text summarized to %d sentences!\n", 3);

    free(content);
    free(line);
    free(sentences);

    fclose(input_file);
    fclose(output_file);

    return 0;
}