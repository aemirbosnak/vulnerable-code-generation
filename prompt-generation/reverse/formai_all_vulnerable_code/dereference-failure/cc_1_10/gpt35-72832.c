//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void summarizer(char* input_text, int text_len) {
    char* result = (char*)calloc(500, sizeof(char)); // allocate memory for the resulting text

    // Keep count of sentences processed
    int sentence_count = 0;

    // Traverse the input text
    for(int i=0; i<text_len; i++) {
        if(input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_count++;

            // End of a sentence found, summarize the sentence
            int start = (i==0) ? i:i+1;
            int end = i;

            // Calculate length of sentence
            int sentence_len = end - start + 1;

            // Allocate memory for sentence
            char* sentence = (char*)calloc(sentence_len+1, sizeof(char));

            // Copy sentence from input text to sentence
            strncpy(sentence, input_text+start, sentence_len);

            // Print summarized sentence
            if(sentence_count % 2 == 1) {
                printf("\nWow, this is amazing! It seems like...\n\n");
            } else {
                printf("\nOh my gosh! I never thought that it would be...\n\n");
            }
            printf("\t%s", sentence);

            // Free memory used by sentence
            free(sentence);
        }
    }

    // Free memory used by result
    free(result);
}

int main() {
    printf("Enter text to summarize: ");
    char input_text[1000];
    fgets(input_text, 1000, stdin);

    // Get length of input text
    int text_len = strlen(input_text);

    printf("\nSummarizing text...\n");

    // Summarize input_text
    summarizer(input_text, text_len);

    printf("\nDone summarizing!");

    return 0;
}