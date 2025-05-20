//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_OUTPUT_SIZE 10000
#define MAX_WORD_SIZE 200

char *get_summary(char *input){
    char buffer[MAX_OUTPUT_SIZE];
    char word_buffer[MAX_WORD_SIZE];
    char *words[MAX_INPUT_SIZE];
    int num_words = 0;
    int i,j,k,count;

    // Split the input into individual words
    i = 0;
    while(input[i] != '\0'){
        count = 0;
        while(input[i] != ' ' && input[i] != '\0'){
            word_buffer[count] = input[i];
            count++;
            i++;
        }
        word_buffer[count] = '\0';
        words[num_words] = malloc(sizeof(char) * (count+1));
        strcpy(words[num_words], word_buffer);
        num_words++;

        if(input[i] == ' ') i++;
    }

    // Sort the words by length
    for(i=0;i<num_words-1;i++){
        for(j=i+1;j<num_words;j++){
            if(strlen(words[i]) < strlen(words[j])){
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Create the summary
    buffer[0] = '\0';
    count = 0;
    for(i=0;i<num_words;i++){
        if(strlen(words[i]) < 4) continue;
        if(count + strlen(words[i]) + 2 > MAX_OUTPUT_SIZE) break;
        strcat(buffer, words[i]);
        strcat(buffer, " ");
        count += strlen(words[i]) + 1;
    }
    buffer[count-1] = '\0';

    // Free allocated memory
    for(i=0;i<num_words;i++){
        free(words[i]);
    }

    // Return the summary
    char *output = malloc(sizeof(char) * (count+1));
    strcpy(output, buffer);
    return output;
}

int main(){
    char input[MAX_INPUT_SIZE];
    char *summary;

    printf("Enter text to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    summary = get_summary(input);

    printf("Summary: %s\n", summary);

    free(summary);
    return 0;
}