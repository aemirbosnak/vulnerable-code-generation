//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to generate a summary of the text
void summarizeText(char* text) {
    char* summary = (char*)malloc(strlen(text) * 2);
    int len = strlen(text);
    int count = 0;
    int i = 0;
    
    // Iterate through the text and count the frequency of each word
    while (text[i]!= '\0') {
        if (strchr("aeiou", text[i])!= NULL) {
            count++;
        }
        i++;
    }
    
    // Generate the summary by selecting the most frequent words
    for (int j = 0; j < len; j++) {
        if (count <= 0) {
            break;
        }
        
        if (strchr("aeiou", text[j])!= NULL) {
            summary[count] = text[j];
            count--;
        }
    }
    
    // Append the summary to the text
    char* newText = (char*)malloc(strlen(text) + strlen(summary));
    strcpy(newText, text);
    strcat(newText, " ");
    strcat(newText, summary);
    
    // Print the summary
    printf("%s\n", newText);
    
    // Free the memory
    free(summary);
    free(newText);
}

int main() {
    // Test the summarizeText function
    char* text = "The quick brown fox jumps over the lazy dog.";
    summarizeText(text);
    
    return 0;
}