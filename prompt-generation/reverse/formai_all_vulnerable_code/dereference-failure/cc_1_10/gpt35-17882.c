//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

char *read_input() {
    char *input = malloc(MAX_INPUT_SIZE * sizeof(char));
    printf("Enter the text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    return input;
}

void remove_punctuation(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(ispunct(str[i])) {
            for(int j = i; j < len; j++) {
                str[j] = str[j+1];
            }
            len--;
        }
    }
}

int count_words(char *str) {
    int count = 0, len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(isalpha(str[i])) {
            while(isalpha(str[i])) {
                i++;
            }
            count++;
        }
    }
    return count;
}

char *summarize(char *input) {
    char *summary = malloc(MAX_SUMMARY_SIZE * sizeof(char));
    int word_count = count_words(input), summary_count = 0, i = 0, j = 0;
    double percentage = 0.4;
    if(word_count <= 10) {
        percentage = 1.0;
    }
    int summary_words = (int)(percentage * word_count);
    if(word_count == 0) {
        printf("Error: Empty input\n");
        exit(0);
    }
    remove_punctuation(input);
    while(summary_count < summary_words) {
        if(input[i] == ' ') {
            summary[j] = input[i];
            summary_count++;
            while(input[i+1] == ' ') {
                i++;
            }
            j++;
        } else if(isalpha(input[i])) {
            summary[j] = input[i];
            summary_count++;
            while(isalpha(input[i+1])) {
                summary[j+1] = input[i+1];
                i++;
                j++;
            }
            j++;
        }
        i++;
    }
    summary[j] = '\0';
    return summary;
}

int main() {
    char *input = read_input();
    char *summary = summarize(input);
    printf("\nSummary:\n%s\n", summary);
    free(input);
    free(summary);
    return 0;
}