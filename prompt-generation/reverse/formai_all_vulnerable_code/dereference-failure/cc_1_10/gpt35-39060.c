//FormAI DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUMMARY_LENGTH 100

/*
    Function to tokenize the input text based on space, newline and tab characters.
    Returns the number of tokens found.
*/
int tokenize(char* text, char* tokens[]) {
    int count = 0;
    char* token = strtok(text, " \n\t");
    
    while(token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " \n\t");
    }
    
    return count;
}

/*
    Function to calculate the frequency of each token in the input text.
    Returns a dynamically allocated array of size num_tokens representing the frequencies.
*/
int* calculate_frequencies(char* tokens[], int num_tokens) {
    int* freq = (int*) malloc(num_tokens * sizeof(int));
    
    for(int i = 0; i < num_tokens; i++) {
        freq[i] = 1;
        
        // Check if this token exists earlier in the list
        for(int j = 0; j < i; j++) {
            if(strcmp(tokens[j], tokens[i]) == 0) {
                freq[j]++;
                freq[i] = 0;
                break;
            }
        }
    }
    
    return freq;
}

/*
    Function to find the n most frequent words and generate a summary
*/
void generate_summary(char* text, int n) {
    char* tokens[1000]; // Assuming no more than 1000 tokens
    int num_tokens = tokenize(text, tokens);
    int* freq = calculate_frequencies(tokens, num_tokens);
    
    // Find the n most frequent words
    int max_freq[n];
    char* max_word[n];
    for(int i = 0; i < n; i++) {
        max_freq[i] = 0;
        max_word[i] = "";
    }
    
    for(int i = 0; i < num_tokens; i++) {
        for(int j = 0; j < n; j++) {
            if(freq[i] > max_freq[j]) {
                // Shift all elements from j onwards by one
                for(int k = n-1; k > j; k--) {
                    max_freq[k] = max_freq[k-1];
                    max_word[k] = max_word[k-1];
                }
                
                max_freq[j] = freq[i];
                max_word[j] = tokens[i];
                
                break;
            }
        }
    }
    
    // Generate the summary
    int summary_length = 0;
    char summary[MAX_SUMMARY_LENGTH];
    for(int i = 0; i < n; i++) {
        if(max_freq[i] == 0) break;
        
        int max_words = (MAX_SUMMARY_LENGTH - summary_length) / (strlen(max_word[i]) + 1);
        int num_words = (max_freq[i] < max_words) ? max_freq[i] : max_words;
        
        for(int j = 0; j < num_words; j++) {
            strcat(summary, max_word[i]);
            summary_length += strlen(max_word[i]);
            
            if(j < num_words - 1) {
                strcat(summary, " ");
                summary_length++;
            }
        }
        
        strcat(summary, ". ");
        summary_length += 2;
    }
    
    printf("%s\n", summary);
    
    free(freq);
}

int main() {
    char* text = "A text summarizer is a tool that automatically creates a short, concise summary of a longer text. It extracts the most important sentences and keywords from the original text and presents them in a condensed form. Text summarization is a useful technique for people who need to read a lot of information but have limited time. It is also used by search engines to display short snippets of text related to a search query. There are two main types of text summarization: extractive and abstractive. Extractive summarization involves selecting sentences from the original text and combining them into a summary. Abstractive summarization involves generating new sentences that capture the essence of the original text. In this example program, we will implement an extractive text summarizer.";
    
    generate_summary(text, 4);
    
    return 0;
}