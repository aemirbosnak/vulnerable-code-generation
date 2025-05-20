//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCES 10    // Maximum number of sentences in the summary
#define LENGTH 1000     // Maximum sentence length

typedef struct{
    char sentence[LENGTH];
    int rank;           // Rank of the sentence based on importance
} Sentence;

void print_summary(Sentence* summary, int n) {
    printf("Summary:\n");
    for(int i=0; i<n; i++) {    // Print the top n sentences
        printf("%d. %s\n", i+1, summary[i].sentence);
    }
}

int main() {
    char text[LENGTH];          // The entire input text
    char delimiters[] = ".!?\n"; // Sentence delimiters
    int sentence_count = 0;     // Number of sentences in the input text

    // Read the input text from stdin
    printf("Enter the text to summarize:\n");
    fgets(text, LENGTH, stdin);
    strtok(text, "\n");         // Remove trailing newline

    // Count the number of sentences in the input text
    for(int i=0; i<strlen(text); i++) {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == '\n') {
            sentence_count++;
        }
    }

    // Split the input text into individual sentences
    char* sentence_ptr = strtok(text, delimiters);
    Sentence sentences[sentence_count];
    int i = 0;
    while(sentence_ptr != NULL) {
        strcpy(sentences[i].sentence, sentence_ptr);
        i++;
        sentence_ptr = strtok(NULL, delimiters);
    }

    // Calculate the rank of each sentence based on importance
    for(int i=0; i<sentence_count; i++) {
        // TODO: Define a ranking algorithm here
        sentences[i].rank = rand() % 10;    // Temporary random ranking
    }

    // Sort the sentences in descending order of rank
    for(int i=0; i<sentence_count-1; i++) {
        for(int j=0; j<sentence_count-i-1; j++) {
            if(sentences[j].rank < sentences[j+1].rank) {
                Sentence temp = sentences[j];
                sentences[j] = sentences[j+1];
                sentences[j+1] = temp;
            }
        }
    }

    // Print the top 10% of sentences in the summary
    int summary_size = sentence_count < SENTENCES ? sentence_count : SENTENCES;
    Sentence summary[summary_size];
    for(int i=0; i<summary_size; i++) {
        summary[i] = sentences[i];
    }
    print_summary(summary, summary_size);

    return 0;
}