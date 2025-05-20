//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 500
#define MAX_SENTENCE_LENGTH 2000
#define SUMMARY_LENGTH 200

// Function to read file into a string
char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char* filestring = (char *)malloc(filesize + 1);
    if (filestring == NULL) {
        printf("Error: Unable to allocate memory!\n");
        exit(1);
    }

    fread(filestring, filesize, 1, fp);

    if (ferror(fp)) {
        printf("Error: Unable to read file!\n");
        exit(1);
    }

    fclose(fp);

    filestring[filesize] = '\0';

    return filestring;
}

// Function to split a string into sentences
int split_sentences(char* text, char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH]) {
    int index = 0;
    char* sentence = strtok(text, ".!?");

    while (sentence != NULL) {
        if (strlen(sentence) > 2) {
            strcpy(sentences[index], sentence);
            index++;
        }
        sentence = strtok(NULL, ".!?");
    }

    return index;
}

// Function to calculate the score of a sentence
float sentence_score(char* sentence, char* summary_words[]) {
    float score = 0;
    int word_count = 0;
    char* word = strtok(sentence, " ");

    while (word != NULL) {
        for (int i=0; i < SUMMARY_LENGTH; i++) {
            if (strcmp(word, summary_words[i]) == 0) {
                score++;
                break;
            }
        }
        word_count++;
        word = strtok(NULL, " ");
    }

    return score / word_count;
}

// Main function
int main(int argc, char* argv[]) {

    // Check if enough arguments provided
    if (argc != 4) {
        printf("Error: Invalid arguments! Usage: ./summarize input_file summary_file output_file\n");
        return 1;
    }

    char* input_file = argv[1];
    char* summary_file = argv[2];
    char* output_file = argv[3];

    // Read input and summary files
    char* input_text = read_file(input_file);
    char* summary_text = read_file(summary_file);
    char summary_words[SUMMARY_LENGTH][MAX_SENTENCE_LENGTH];
    int word_count = 0;
    char* word = strtok(summary_text, " ");

    while (word != NULL) {
        if (word_count >= SUMMARY_LENGTH) {
            break;
        }
        strcpy(summary_words[word_count], word);
        word_count++;
        word = strtok(NULL, " ");
    }

    // Split input into sentences and calculate scores
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_count = split_sentences(input_text, sentences);
    float sentence_scores[sentence_count];

    for (int i=0; i < sentence_count; i++) {
        sentence_scores[i] = sentence_score(sentences[i], summary_words);
    }

    // Sort sentences by score
    for (int i=0; i < sentence_count; i++) {
        for (int j=0; j < sentence_count-i-1; j++) {
            if (sentence_scores[j] < sentence_scores[j+1]) {
                float temp_score = sentence_scores[j+1];
                sentence_scores[j+1] = sentence_scores[j];
                sentence_scores[j] = temp_score;

                char temp_sentence[MAX_SENTENCE_LENGTH];
                strcpy(temp_sentence, sentences[j+1]);
                strcpy(sentences[j+1], sentences[j]);
                strcpy(sentences[j], temp_sentence);
            }
        }
    }

    // Write top 5 sentences to output file
    FILE* fp = fopen(output_file, "w");
    if (fp == NULL) {
        printf("Error: Unable to open output file!\n");
        exit(1);
    }

    for (int i=0; i < 5; i++) {
        fputs(sentences[i], fp);
        fputs(". ", fp);
    }

    fclose(fp);

    return 0;
}