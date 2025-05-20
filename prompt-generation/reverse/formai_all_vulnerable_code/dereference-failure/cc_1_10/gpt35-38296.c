//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_count_t { // a structure to store the word and its count
    char word[100];
    int count;
} word_count;

word_count *count_frequencies(FILE *fp, int *num_words) { // function to count the frequencies

    char word[100];
    int i,j;
    word_count *words = (word_count*) malloc(sizeof(word_count) * 1000); // allocate an array to store the word counts

    while (fscanf(fp, "%s", word) == 1) { // read words from the file one at a time

        for(i = 0; word[i]; i++){ // convert all letters to lowercase
            word[i] = tolower(word[i]);
        }

        for(j = 0; j < *num_words; j++){ // check if this word has already been encountered
            if(strcmp(word, words[j].word) == 0){
                words[j].count++;
                break;
            }
        }

        if(j == *num_words){ // if the word has not been encountered before, add it to the array
            strcpy(words[*num_words].word, word);
            words[*num_words].count = 1;
            (*num_words)++;
        }
    }

    return words; // return the array
}

int main() {

    FILE *fp = fopen("input.txt", "r"); // open the input file
    if(fp == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int num_words = 0, i;
    word_count *words = count_frequencies(fp, &num_words); // count the frequencies

    printf("Word Frequency Count:\n\n");
    printf("------------------------\n");
    printf("|  %-15s| %s  |\n", "Word", "Count");
    printf("------------------------\n");

    for(i = 0; i < num_words; i++){ // print the results
        printf("|  %-15s|  %d |\n", words[i].word, words[i].count);
    }

    printf("------------------------\n");
    fclose(fp); // close the file

    return 0;
}