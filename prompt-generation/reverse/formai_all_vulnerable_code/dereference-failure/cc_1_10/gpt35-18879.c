//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

char* summarize(char*);
int count_words(char*);

int main(){
    char input[MAX_INPUT_LENGTH];
    char* summary;

    printf("Enter text to summarize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);  

    summary = summarize(input);

    printf("Summary:\n%s", summary);

    return 0;
}

char* summarize(char* input){
    int input_length = strlen(input);
    int summary_length = 0;
    char* summary = calloc(MAX_SUMMARY_LENGTH, sizeof(char));
    char temp_input[MAX_INPUT_LENGTH];
    char* token;

    strcpy(temp_input, input);

    token = strtok(temp_input, " ");

    while(token != NULL){
        int token_length = strlen(token);

        // Check if adding the token will exceed the summary length
        if(token_length + summary_length > MAX_SUMMARY_LENGTH - 1){
            // If so, stop adding tokens
            strcat(summary, "...");
            break;
        }

        strcat(summary, token);
        strcat(summary, " ");
        summary_length += token_length + 1;

        token = strtok(NULL, " ");
    }

    return summary;
}

int count_words(char* input){
    int count = 0;
    char temp_input[MAX_INPUT_LENGTH];
    char* token;

    strcpy(temp_input, input);

    token = strtok(temp_input, " ");

    while(token != NULL){
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}