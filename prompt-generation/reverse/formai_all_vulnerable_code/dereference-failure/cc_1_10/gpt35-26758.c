//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define MAX_LENGTH 50

char* read_input();
void summarize(char* input);

int main(){
    char* input = read_input();
    summarize(input);
    return 0;
}

char* read_input(){
    char* input = (char*)malloc(MAX_WORDS * MAX_LENGTH * sizeof(char));
    if(input == NULL){
        printf("Error allocating memory.");
        exit(1);
    }
    printf("Enter the text to be summarized:\n");
    fgets(input, MAX_WORDS * MAX_LENGTH, stdin);
    if(input[strlen(input) - 1] == '\n') { //removing newline character
        input[strlen(input) - 1] = '\0';
    }
    return input;
}

void summarize(char* input){
    char* word;
    char* delimiters = ".?!";
    char* sentence;
    char summary[1000] = {0};
    int counter = 0;
    int length;
    word = strtok(input, " ");
    while(word != NULL){
        length = strlen(summary);
        if(length + strlen(word) < 1000){  
            strcat(summary, word); 
            strcat(summary, " "); 
            sentence = strtok(word, delimiters);
            while(sentence != NULL){
                if(strlen(sentence) > 1 && islower(sentence[0]) && counter < 3) {
                    strcat(summary, sentence); 
                    strcat(summary, ". "); 
                    counter++;
                }
                sentence = strtok(NULL, delimiters);
            }
        }else{
            break;
        }
        word = strtok(NULL, " ");
    }
    printf("Summary:\n%s", summary);
    free(input);
}