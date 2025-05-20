//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_CHARS 20000
#define MAX_SUMMARY 1000

char* summarize(char*);

int main() {

    char text[MAX_CHARS];
    printf("Please enter the text you would like to summarize: \n");

    fgets(text, MAX_CHARS, stdin);  //read input from user

    char* summary = summarize(text);

    printf("\nSummary: \n %s", summary);

    return 0;
}

char* summarize(char* text){

    int i, j, k;

    char* summary = (char*) malloc(MAX_SUMMARY * sizeof(char));
    if(summary == NULL){
        printf("Memory could not be allocated.");
        exit(1);
    }

    char* words[MAX_WORDS]; //array to store individual words
    int freq[MAX_WORDS] = {0}; //array to store frequency of each unique word
    int counter = 0; //counter to track number of unique words

    for(i = 0; text[i] != '\0'; i++){
        char word[MAX_CHARS] = ""; 
        for(j = i, k = 0; isalpha(text[j]) && k < MAX_CHARS; j++, k++){ //extract words from text
            word[k] = text[j];
        }
        if(strlen(word) > 0){
            int match = 0;
            for(int m = 0; m < counter; m++){ //check if word already exists
                if(strcmp(word, words[m]) == 0){
                    freq[m]++;
                    match = 1;
                    break;
                }
            }
            if(match == 0){ //if word doesn't already exist, add to array
                words[counter] = strdup(word);
                freq[counter] = 1;
                counter++;
            }
        }
        i = j;
    }

    int max_index, max_freq;
    for(int n = 0; n < 10; n++){ //loop to find and add top 10 most frequent words to summary
        max_index = 0;
        max_freq = freq[0];
        for(int p = 1; p < counter; p++){
            if(freq[p] > max_freq){
                max_index = p;
                max_freq = freq[p];
            }
        }
        freq[max_index] = 0; //set frequency to 0 so it doesn't get added again
        strcat(summary, words[max_index]);
        strcat(summary, " ");
    }

    return summary;
}