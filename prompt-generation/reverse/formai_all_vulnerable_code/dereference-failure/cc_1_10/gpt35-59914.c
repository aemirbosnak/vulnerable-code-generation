//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to count the number of occurrences of a word in a string
int countOccurrences(char* string, char* word) {
    int count = 0;
    char* ptr = strstr(string, word);
    while (ptr != NULL) { //keep searching until word is not found
        count++;
        ptr = strstr(ptr + 1, word);
    }
    return count;
}

//Function to extract n words after an occurrence of a word in a string
char* extractWordsAfter(char* string, char* word, int n) {
    char* ptr = strstr(string, word);
    if (ptr == NULL) { //if word is not found, return NULL
        return NULL;
    }
    ptr += strlen(word);
    char* words = malloc(sizeof(char) * 100);
    int found = 1;
    int i = 0;
    while (found && i < n) { //keep extracting words until n words are extracted or end of string is reached
        if (*ptr == ' ') {
            ptr++;
        } else {
            int j = 0;
            while (*(ptr + j) != ' ' && *(ptr + j) != '\0') {
                *(words + i * 20 + j) = *(ptr + j);
                j++;
            }
            *(words + i * 20 + j) = ' ';
            i++;
            if (i == n) {
                found = 0;
            }
            ptr += j;
        }
    }
    *(words + i * 20) = '\0'; //add null character at end of string
    return words;
}

//Function to summarize the text
char* summarizeText(char* text, int maxWords) {
    char* summary = malloc(sizeof(char) * 1000);
    char* sentence;
    char* word;
    char* current;
    int wordCount = 0;
    int sentenceCount = 0;
    while ((sentence = strtok_r(text, ".", &text))) { //extract sentences from text
        sentenceCount++;
        current = sentence;
        while ((word = strsep(&current, " "))) { //extract words from sentence
            if (strlen(word) > 0) { //ignore white spaces and punctuation marks
                wordCount++;
                if (wordCount <= maxWords) {
                    strcat(summary, word);
                    strcat(summary, " ");
                }
            }
        }
        if (wordCount >= maxWords) { //stop summarizing if maximum words are reached
            break;
        }
        strcat(summary, ". ");
    }
    if (wordCount < maxWords) { //add remaining sentences if maxWords is not reached
        char* remaining = malloc(sizeof(char) * 1000);
        while ((sentence = strtok_r(text, ".", &text))) {
            strcat(remaining, sentence);
            strcat(remaining, ". ");
        }
        strcat(summary, remaining);
    }
    return summary;
}

//Main function to test the summarizer
int main() {
    char text[] = "This is a sample text for testing the text summarizer. The text should have several sentences and a few occurrences of the word 'text'. The text should also have several words that can be ignored such as 'the', 'is' and 'a'. The summary of this text should be about 30 words long.";
    char* summary = summarizeText(text, 30);
    printf("Original text:\n%s\n\n", text);
    printf("Text summary:\n%s\n\n", summary);
    int count = countOccurrences(text, "text");
    printf("The word 'text' occurs %d times in the text.\n\n", count);
    char* words = extractWordsAfter(text, "occurrences", 2);
    printf("The two words after the word 'occurrences' are: %s\n", words);
    free(summary);
    free(words);
    return 0;
}