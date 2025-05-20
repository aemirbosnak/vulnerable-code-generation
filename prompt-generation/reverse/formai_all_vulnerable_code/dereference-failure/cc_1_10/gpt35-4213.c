//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000 // Maximum number of words
#define MAX_LENGTH 50 // Maximum length of each word

// Function to count the occurrence of words in a given sentence
int countWords(char sentence[]) {
    int count = 0;
    char delim[] = " "; // Space delimiter
    char *ptr = strtok(sentence, delim); // Substring using strtok
    
    while(ptr != NULL) {
        count++;
        ptr = strtok(NULL, delim);
    }
    return count;
}

// Function to parse the sentence and store the words in an array
void parseSentence(char sentence[], char *wordArr[]) {
    int i = 0;
    char delim[] = " ";
    char *ptr = strtok(sentence, delim);
    
    while(ptr != NULL) {
        wordArr[i++] = ptr;
        ptr = strtok(NULL, delim);
    }
}

// Function to count the occurrence of each word and store it in a frequency array
void countEachWord(char *wordArr[], int freqArr[], int n) {
    for(int i = 0; i < n; i++) {
        int count = 1; // Initialize the count to 1
        for(int j = i+1; j < n; j++) {
            if(strcmp(wordArr[i], wordArr[j]) == 0) { // If the words match, increment the count
                count++;
            }
        }
        freqArr[i] = count; // Store the frequency count in array
    }
}

// Function to display the word count output
void displayWordCount(char *wordArr[], int freqArr[], int n) {
    printf("\n\nWord Count\n-----------------\n");
    for(int i = 0; i < n; i++) {
        if(freqArr[i] != 0) {
            printf("%s - %d\n", wordArr[i], freqArr[i]);
        }
    }
}

int main() {
    char sentence[MAX_WORDS*MAX_LENGTH]; // Maximum number of words x Maximum length of each word
    char *wordArr[MAX_WORDS];
    int freqArr[MAX_WORDS] = {0};
    
    printf("\nEnter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Read input sentence
    
    int n = countWords(sentence); // Count the number of words in the sentence
    parseSentence(sentence, wordArr); // Parse the sentence and store in an array
    countEachWord(wordArr, freqArr, n); // Count the occurrence frequency of each word
    displayWordCount(wordArr, freqArr, n); // Display the word count output
    
    return 0;
}