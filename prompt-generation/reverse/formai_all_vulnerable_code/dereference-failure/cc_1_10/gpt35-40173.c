//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100 // Define maximum word size

int main()
{
    char sentence[MAX_WORD_SIZE]; // Create a character array to store sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Get input sentence from the user

    if (strlen(sentence) > 0 && sentence[strlen(sentence) - 1] == '\n') 
        sentence[strlen(sentence) - 1] = '\0'; // Remove the new line character from the sentence

    int word_count = 0; // Initialize word count to zero
    char * word; // Declare a character pointer variable to hold current word
    char * temp = strdup(sentence); // Make a copy of the sentence

    // Loop through the copy of the sentence, tokenize it and count the words
    for (word = strtok(temp, " "); word; word = strtok(NULL, " ")) 
        word_count++;

    // Create a dynamic array of structures to store every unique word and its frequency
    struct WordFreq {
        char word[MAX_WORD_SIZE];
        int frequency;
    } word_freq_arr[word_count];

    // Reset the copy pointer
    temp = strdup(sentence);

    // Loop through the copy of the sentence, tokenize it again and fill the dynamic array with unique words and their frequency
    int i = 0;
    for (word = strtok(temp, " "); word; word = strtok(NULL, " ")) 
    {
        int flag = 0;
        int j;
        // Loop through the filled array of unique words and their frequency to check if the current word exists
        for (j = 0; j < i; j++) 
        {
            if (strstr(word_freq_arr[j].word, word)) 
            {
                word_freq_arr[j].frequency++; // Increment frequency of existing word if found
                flag = 1;
            }
        }
        // If the current word is not already in the array, add it with a frequency of one
        if (flag==0) 
        {
            strcpy(word_freq_arr[i].word, word);
            word_freq_arr[i].frequency = 1;
            i++;
        }
    }

    // Print the unique words and their frequency in an organized table format
    printf("\nWord\tFrequency\n");
    for (int k = 0; k < i; k++) 
    {
        printf("%s\t%d\n", word_freq_arr[k].word, word_freq_arr[k].frequency);
    }

    return 0;
}