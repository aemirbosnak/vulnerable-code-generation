//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5000
#define MAX_SUMMARY_SIZE 3

// function prototypes
char* read_text_file(FILE* file);
int count_words(char* text);
char* remove_punctuations(char* text);
char** tokenize_text(char* text);
void update_word_frequency(char** tokens, int num_tokens, int* freq_array);
int get_max_index(int* array, int size);
char** generate_summary(char** tokens, int num_tokens, int* freq_array, int num_sentences);

int main() {
    // open file
    FILE* file = fopen("input.txt", "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // read text from file
    char* full_text = read_text_file(file);
    fclose(file);
    
    // remove punctuations from full_text
    char* text_no_punctuations = remove_punctuations(full_text);
    
    // count number of words in text
    int num_words = count_words(text_no_punctuations);
    
    // tokenize text
    char** tokens = tokenize_text(text_no_punctuations);
    
    // create and initialize frequency array to all zeroes
    int* freq_array = calloc(num_words, sizeof(int));
    
    // update word frequency in freq_array
    update_word_frequency(tokens, num_words, freq_array);
    
    // generate summary
    char** summary = generate_summary(tokens, num_words, freq_array, MAX_SUMMARY_SIZE);
    
    // print summary
    printf("\nSUMMARY:\n");
    for(int i=0; i<MAX_SUMMARY_SIZE; i++) {
        printf("%s ", summary[i]);
    }
    
    // free memory
    free(full_text);
    free(text_no_punctuations);
    for(int i=0; i<num_words; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(freq_array);
    for(int i=0; i<MAX_SUMMARY_SIZE; i++) {
        free(summary[i]);
    }
    free(summary);
    
    return 0;
}

// read text from file and return as a string
char* read_text_file(FILE* file) {
    char* full_text = malloc(MAX_SIZE * sizeof(char));
    fgets(full_text, MAX_SIZE, file);
    return full_text;
}

// count number of words in text
int count_words(char* text) {
    int count = 0;
    char* token = strtok(text, " ");
    while(token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// remove punctuations from text and return new string
char* remove_punctuations(char* text) {
    char* new_text = malloc(strlen(text) * sizeof(char));
    int j=0;
    for(int i=0; text[i]!='\0'; i++) {
        if(text[i]>='a' && text[i]<='z') {
            new_text[j++] = text[i];
        } else if(text[i]>='A' && text[i]<='Z') {
            new_text[j++] = text[i] + 32;
        } else if(text[i]==' ') {
            new_text[j++] = ' ';
        }
    }
    new_text[j] = '\0';
    return new_text;
}

// tokenize text into an array of words
char** tokenize_text(char* text) {
    char** tokens = malloc(MAX_SIZE * sizeof(char*));
    int i=0;
    char* token = strtok(text, " ");
    while(token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

// update word frequency in frequency array
void update_word_frequency(char** tokens, int num_tokens, int* freq_array) {
    for(int i=0; i<num_tokens; i++) {
        for(int j=i+1; j<num_tokens; j++) {
            if(strcmp(tokens[i], tokens[j]) == 0) {
                freq_array[i]++;
            }
        }
    }
}

// get index of maximum element in array
int get_max_index(int* array, int size) {
    int max_idx = 0;
    for(int i=1; i<size; i++) {
        if(array[i] > array[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

// generate summary from list of tokens, with a maximum number of sentences
char** generate_summary(char** tokens, int num_tokens, int* freq_array, int num_sentences) {
    int sentence_end_indices[MAX_SIZE];
    int num_sentences_found = 0;
    
    // find indices of end of sentences
    for(int i=0; i<num_tokens; i++) {
        if(tokens[i][strlen(tokens[i])-1] == '.' || tokens[i][strlen(tokens[i])-1] == '?' || tokens[i][strlen(tokens[i])-1] == '!') {
            sentence_end_indices[num_sentences_found++] = i;
        }
    }
    
    // create summary array and initialize with NULL
    char** summary = malloc(MAX_SUMMARY_SIZE * sizeof(char*));
    for(int i=0; i<MAX_SUMMARY_SIZE; i++) {
        summary[i] = NULL;
    }
    
    // generate summary
    for(int i=0; i<num_sentences_found && i<num_sentences; i++) {
        int start_index = i==0 ? 0 : sentence_end_indices[i-1]+1;
        int end_index = sentence_end_indices[i];
        int summary_index = get_max_index(freq_array+start_index, end_index-start_index+1) + start_index;
        summary[i] = strdup(tokens[summary_index]);
    }
    
    return summary;
}