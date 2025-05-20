//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#define MAX_INPUT 1000 //maximum input length
#define MAX_SENTENCE 100 //maximum number of sentences in a summary

//function to count the number of sentences in a text
int count_sentences(char input[]) {
    int count = 0;
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            count++;
        }
    }
    return count;
}

//function to split the input into an array of sentences
char** split_sentences(char input[]) {
    char** sentences = malloc(MAX_SENTENCE*sizeof(char*));
    int i, j, k;
    for(i = 0; i < MAX_SENTENCE; i++) {
        sentences[i] = malloc(MAX_INPUT*sizeof(char));
    }
    i = 0;
    j = 0;
    k = 0;
    while(input[i] != '\0') {
        if(input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentences[j][k] = input[i];
            k++;
            sentences[j][k] = '\0';
            j++;
            k = 0;
        }
        else {
            sentences[j][k] = input[i];
            k++;
        }
        i++;
    }
    return sentences;
}

//function to calculate the score of a sentence based on the frequency of its words in the input
int sentence_score(char sentence[], char input[]) {
    char words[MAX_INPUT][MAX_INPUT];
    int count[MAX_INPUT];
    int num_words = 0;
    int i, j, k;

    //split the input into an array of words
    i = 0;
    j = 0;
    k = 0;
    while(input[i] != '\0') {
        if(input[i] == ' ') {
            words[j][k] = '\0';
            k = 0;
            j++;
        }
        else {
            words[j][k] = input[i];
            k++;
        }
        i++;
    }
    words[j][k] = '\0';
    num_words = j+1;

    //count the frequency of each word in the sentence
    for(i = 0; i < num_words; i++) {
        count[i] = 0;
        j = 0;
        k = 0;
        while(sentence[j] != '\0') {
            if(sentence[j] == ' ' || sentence[j] == '.' || sentence[j] == '?' || sentence[j] == '!') {
                words[i][k] = '\0';
                k = 0;
                if(strcmp(words[i], "") != 0 && strcmp(words[i], " ") != 0) {
                    if(strcmp(words[i], &sentence[j-k]) == 0) {
                        count[i]++;
                    }
                }
                j++;
            }
            else {
                k++;
                j++;
            }
        }
        if(strcmp(words[i], &sentence[j-k]) == 0) {
            count[i]++;
        }
    }

    //calculate the score of the sentence
    int score = 0;
    for(i = 0; i < num_words; i++) {
        score += count[i];
    }
    return score;
}

//function to find the most important sentences in the input
void summarizer(char input[]) {
    char** sentences = split_sentences(input);
    int num_sentences = count_sentences(input);
    int scores[MAX_SENTENCE];
    int i;
    for(i = 0; i < num_sentences; i++) {
        scores[i] = sentence_score(sentences[i], input);
    }
    int n = 3; //number of sentences in the summary
    printf("Summary:\n");
    for(i = 0; i < n; i++) {
        int max_score = -1;
        int max_index = -1;
        int j;
        for(j = 0; j < num_sentences; j++) {
            if(scores[j] > max_score) {
                max_score = scores[j];
                max_index = j;
            }
        }
        printf("%s", sentences[max_index]);
        scores[max_index] = -1;
    }

}

//main function
int main() {
    char input[MAX_INPUT] = "The quick brown fox jumps over the lazy dog. This is a test sentence. The lazy dog jumps over the quick brown fox. This is another test sentence.";
    summarizer(input);
    return 0;
}