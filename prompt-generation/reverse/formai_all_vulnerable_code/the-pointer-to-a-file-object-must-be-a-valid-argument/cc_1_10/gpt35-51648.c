//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 100

char* remove_punctuations(char* sentence) {
    char* clean_sentence = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    int j = 0;
    for(int i = 0; sentence[i] != '\0'; i++) {
        if(isalnum(sentence[i]))
            clean_sentence[j++] = sentence[i];
        else if(sentence[i] == ' ')
            clean_sentence[j++] = sentence[i];
    }
    clean_sentence[j] = '\0';
    return clean_sentence;
}

void summarizer(char* input, char* output) {
    FILE *finput, *foutput;

    finput = fopen(input, "r");
    foutput = fopen(output, "w");

    char sentence[MAX_INPUT_LENGTH];
    char keyword[MAX_INPUT_LENGTH];
    char buffer[MAX_INPUT_LENGTH];
    char output_buffer[MAX_OUTPUT_LENGTH];

    fgets(keyword, MAX_INPUT_LENGTH, finput);

    while(fgets(sentence, MAX_INPUT_LENGTH, finput)) {
        strcpy(buffer, sentence);
        char* clean_sentence = remove_punctuations(sentence);
        char* clean_keyword = remove_punctuations(keyword);
        if(strstr(clean_sentence, clean_keyword)) {
            if(strlen(sentence) > 60) {
                strncpy(output_buffer, sentence, 57);
                strcat(output_buffer, "...\n");
                fprintf(foutput, "%s", output_buffer);
            }
            else {
                fprintf(foutput, "%s", sentence);
            }
        }
    }
    fclose(finput);
    fclose(foutput);
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    summarizer(input_file, output_file);

    return 0;
}