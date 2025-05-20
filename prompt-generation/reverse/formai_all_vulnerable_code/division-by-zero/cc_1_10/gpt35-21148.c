//FormAI DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SENTENCES 100
#define MAX_SENT_LENGTH 100

// defining a structure to store a sentence and its score
typedef struct {
    char sentence[MAX_SENT_LENGTH];
    int score;
} Sentence;

// function to remove punctuations from a string
void remove_punctuations(char *str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '?' || str[i] == '!')
            str[i] = ' ';
    }
}

int main() {
    char text[5000];
    printf("Enter the text to be summarized:\n");
    fgets(text, 5000, stdin);

    // removing punctuations from the text
    remove_punctuations(text);

    // splitting the text into sentences and storing in an array
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    
    char *tok = strtok(text, "\n");
    while(tok != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences] = tok;
        num_sentences++;
        tok = strtok(NULL, "\n");
    }

    // counting the number of words in each sentence and storing in a score for each sentence
    Sentence sentence_array[MAX_SENTENCES];
    int total_words = 0;
    for(int i=0; i<num_sentences; i++) {
        int words = 0;
        char *tok = strtok(sentences[i], " ");
        while(tok != NULL) {
            words++;
            tok = strtok(NULL, " ");
        }
        total_words += words;
        sentence_array[i].score = words;
        strcpy(sentence_array[i].sentence, sentences[i]);
    }

    // calculating the average score of a sentence
    int avg_score = total_words / num_sentences;

    // assigning bonus points to sentences with a score above the average
    for(int i=0; i<num_sentences; i++) {
        if(sentence_array[i].score > avg_score)
            sentence_array[i].score += 5;
    }

    // sorting the sentences in descending order of score
    for(int i=0; i<num_sentences-1; i++) {
        for(int j=0; j<num_sentences-i-1; j++) {
            if(sentence_array[j].score < sentence_array[j+1].score) {
                Sentence temp = sentence_array[j];
                sentence_array[j] = sentence_array[j+1];
                sentence_array[j+1] = temp;
            }
        }
    }

    // printing the top 5 sentences with highest score
    printf("Summary:\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s\n", i+1, sentence_array[i].sentence);
    }

    return 0;
}