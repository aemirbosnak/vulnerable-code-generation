//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define INITIAL_CAPACITY 10

struct wordFrequency {
    char *word;
    int frequency;
};

typedef struct wordFrequency WordFrequency;

WordFrequency* new_wordFrequency(char *word, int frequency) {
    WordFrequency *wf = (WordFrequency*) malloc(sizeof(WordFrequency));
    wf->word = (char*) malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(wf->word, word);
    wf->frequency = frequency;
    return wf;
}

void print_wordFrequency(WordFrequency *wf) {
    printf("%-20s %d\n", wf->word, wf->frequency);
}

void free_wordFrequency(WordFrequency *wf) {
    free(wf->word);
    free(wf);
}

void resize_wordFrequency_array(WordFrequency **arr, int *capacity, int new_capacity) {
    *arr = (WordFrequency*) realloc(*arr, sizeof(WordFrequency) * new_capacity);
    for(int i = *capacity; i < new_capacity; i++) {
        (*arr)[i] = (WordFrequency) {.word = NULL, .frequency = 0};
    }
    *capacity = new_capacity;
}

void add_word_to_wordFrequency_array(WordFrequency **arr, int *size, int *capacity, char *word) {
    for(int i = 0; i < *size; i++) {
        if(strcmp((*arr)[i].word, word) == 0) {
            (*arr)[i].frequency++;
            return;
        }
    }
    if(*size == *capacity) {
        resize_wordFrequency_array(arr, capacity, (*capacity) * 2);
    }
    (*arr)[*size] = *new_wordFrequency(word, 1);
    (*size)++;
}

WordFrequency* get_highest_frequency_word(WordFrequency *arr, int size) {
    int max_frequency = 0;
    int max_index = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i].frequency > max_frequency) {
            max_frequency = arr[i].frequency;
            max_index = i;
        }
    }
    return &arr[max_index];
}

void selection_sort_wordFrequency_array(WordFrequency *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        WordFrequency temp;
        int min_index = i;
        for(int j = i + 1; j < size; j++) {
            if(strcmp(arr[j].word, arr[min_index].word) < 0) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }
    int size = 0;
    int capacity = INITIAL_CAPACITY;
    WordFrequency *word_freq_arr = (WordFrequency*) malloc(sizeof(WordFrequency) * capacity);
    for(int i = 0; i < capacity; i++) {
        word_freq_arr[i] = (WordFrequency) {.word = NULL, .frequency = 0};
    }
    char *curr_word = (char*) malloc(sizeof(char) * MAX_WORD_SIZE);
    int curr_word_size = 0;
    char c;
    while((c = fgetc(file)) != EOF) {
        if(isalpha(c)) {
            if(curr_word_size < MAX_WORD_SIZE) {
                curr_word[curr_word_size] = tolower(c);
                curr_word_size++;
            }
        } else {
            if(curr_word_size > 0) {
                curr_word[curr_word_size] = '\0';
                add_word_to_wordFrequency_array(&word_freq_arr, &size, &capacity, curr_word);
                curr_word_size = 0;
            }
        }
    }
    if(curr_word_size > 0) {
        curr_word[curr_word_size] = '\0';
        add_word_to_wordFrequency_array(&word_freq_arr, &size, &capacity, curr_word);
    }
    free(curr_word);
    fclose(file);
    selection_sort_wordFrequency_array(word_freq_arr, size);
    printf("%-20s %s\n", "WORD", "FREQUENCY");
    printf("%-20s %s\n", "----", "---------");
    for(int i = 0; i < size; i++) {
        print_wordFrequency(&word_freq_arr[i]);
    }
    printf("\nHighest frequency word: %s\n", get_highest_frequency_word(word_freq_arr, size)->word);
    for(int i = 0; i < size; i++) {
        free_wordFrequency(&word_freq_arr[i]);
    }
    free(word_freq_arr);
    return 0;
}