//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to count the number of words in a given sentence or phrase
int count_words(char *str) 
{
    int count = 0, i;
    for (i = 0;str[i] != '\0';i++) 
    {
        if (str[i] == ' ')
            count++;
    }
    count++; // Add 1 to include the last word
    return count;
}

// Function to split a given string into an array of words
char **split_into_words(char *str, int num_words) 
{
    char **words = (char**) malloc(num_words * sizeof(char*));
    int i = 0;
    char *word = strtok(str, " "); // Split the words based on space delimiter
    while (word) 
    {
        words[i++] = word; // Add the words to the words array
        word = strtok(NULL, " ");
    }
    return words;
}

// Function to determine the sentiment score of a given sentence or phrase
int determine_sentiment(char **words, int num_words) 
{
    int i, score = 0;
    // Define the list of positive and negative words
    char *positive_words[] = {"happy", "good", "great", "excellent", "success", "love", "awesome"};
    char *negative_words[] = {"sad", "bad", "poor", "terrible", "failure", "hate", "awful"};
    // Calculate the sentiment score based on the number of positive and negative words
    for (i = 0;i < num_words;i++) 
    {
        char *word = words[i];
        int j;
        for (j = 0;j < 7;j++) 
        {
            if (strcmp(word, positive_words[j]) == 0) 
            {
                score++;
                break;
            }
            else if (strcmp(word, negative_words[j]) == 0) 
            {
                score--;
                break;
            }
        }
    }
    return score;
}

// Main function to test the sentiment analysis tool
int main() 
{
    char sentence[200]; // Define a maximum limit for the input sentence
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin); // Read the input sentence from the user
    sentence[strcspn(sentence, "\n")] = 0; // Remove the new line character from the sentence
    int num_words = count_words(sentence); // Determine the number of words in the sentence
    char **words = split_into_words(sentence, num_words); // Split the sentence into an array of words
    int score = determine_sentiment(words, num_words); // Determine the sentiment score of the sentence
    if (score > 0) 
    {
        printf("The sentence has a positive sentiment score of %d.\n", score);
    }
    else if (score < 0) 
    {
        printf("The sentence has a negative sentiment score of %d.\n", score);
    }
    else 
    {
        printf("The sentence has a neutral sentiment score.\n");
    }
    free(words); // Free the dynamically allocated memory for the words array
    return 0;
}