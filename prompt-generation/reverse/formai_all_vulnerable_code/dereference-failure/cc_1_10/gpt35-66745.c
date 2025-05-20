//FormAI DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Calculates the total number of words in a given text
int countWords(char* text)
{
    int numWords = 0;
    char* word;

    word = strtok(text, " ");

    while (word != NULL)
    {
        numWords++;
        word = strtok(NULL, " ");
    }

    return numWords;
}


// Converts all the letters in a string to lowercase
void toLowercase(char* text)
{
    int i;

    for (i = 0; text[i]; i++)
    {
        text[i] = tolower(text[i]);
    }
}


// Removes common words and punctuation from a given text
void sanitizeText(char* text, char** stopwords)
{
    int i;
    char* token;
    char* newText = "";

    token = strtok(text, " ");

    while (token != NULL)
    {
        // Check if the word is a common stopword
        for (i = 0; i < 50; i++)
        {
            if (strcmp(token, stopwords[i]) == 0)
            {
                token = strtok(NULL, " ");
                break;
            }
        }

        // Check if the word is a punctuation symbol
        if (ispunct(token[0]))
        {
            token = strtok(NULL, " ");
        }

        // Add the word to the new text string
        strcat(newText, token);
        strcat(newText, " ");
        token = strtok(NULL, " ");
    }

    strcpy(text, newText);
}


// Calculates the frequency of each word in a given text
void getWordFrequencies(char* text, char** words, int numWords, int* frequencies)
{
    int i, j;

    for (i = 0; i < numWords; i++)
    {
        frequencies[i] = 0;

        for (j = 0; text[j]; j++)
        {
            if (strcmp(words[i], &text[j]) == 0)
            {
                frequencies[i]++;
            }
        }
    }
}


// Calculates the score of each sentence in a given text
void getSentenceScores(char* text, int* scores, char** stopwords, char** words, int numWords)
{
    int i, j;
    char* sentence;
    int numSentences = 0;

    // Split the text into individual sentences
    sentence = strtok(text, ".!?");

    while (sentence != NULL)
    {
        // Remove any unwanted characters from the sentence
        sanitizeText(sentence, stopwords);

        // Calculate the score of the sentence
        for (i = 0; sentence[i]; i++)
        {
            scores[numSentences] += getSentenceScore(&sentence[i], words, numWords);
        }

        numSentences++;
        sentence = strtok(NULL, ".!?");
    }
}


// Calculates the score of a given sentence
int getSentenceScore(char* sentence, char** words, int numWords)
{
    int i, score = 0;
    char* token;

    // Count the number of words in the sentence
    int numWordsInSentence = countWords(sentence);

    // Split the sentence into individual words
    token = strtok(sentence, " ");

    while (token != NULL)
    {
        // Check if the word is a valid keyword
        for (i = 0; i < numWords; i++)
        {
            if (strcmp(token, words[i]) == 0)
            {
                score += numWordsInSentence;
            }
        }

        token = strtok(NULL, " ");
    }

    return score;
}


// Prints out the most relevant sentences from a given text
void summarizeText(char* text, char** stopwords, char** words, int numWords, int maxSentences)
{
    int i, j, numSentences = 0;
    int numWordsInSentence, totalWords = countWords(text);
    char* sentence;
    int* scores = (int*)malloc(sizeof(int) * totalWords);
    int* selectedSentences = (int*)malloc(sizeof(int) * maxSentences);

    for (i = 0; i < totalWords; i++)
    {
        scores[i] = 0;
    }

    // Calculate the score of each sentence in the text
    getSentenceScores(text, scores, stopwords, words, numWords);

    // Select the top-scoring sentences
    for (i = 0; i < maxSentences; i++)
    {
        int maxScore = -1;
        int maxScoreIndex = -1;

        for (j = 0; j < totalWords; j++)
        {
            if (scores[j] > maxScore)
            {
                maxScore = scores[j];
                maxScoreIndex = j;
            }
        }

        selectedSentences[i] = maxScoreIndex;
        scores[maxScoreIndex] = -1;

        if (maxScoreIndex != -1)
        {
            numSentences++;
        }
    }

    // Print out the top-scoring sentences in their original order
    sentence = strtok(text, ".!?");

    while (sentence != NULL)
    {
        for (i = 0; i < numSentences; i++)
        {
            if (strstr(sentence, words[selectedSentences[i]]) != NULL)
            {
                numWordsInSentence = countWords(sentence);
                printf("%s (%d words)\n", sentence, numWordsInSentence);
                break;
            }
        }

        sentence = strtok(NULL, ".!?");
    }
}


// Driver code - main function
int main()
{
    // The text that we want to summarize
    char* text = "The quick brown fox jumps over the lazy dog. However, the lazy dog isn't very happy about it. He barks loudly and chases the fox away. In the end, the fox is too quick for him. The end.";

    // A list of common stopwords to ignore
    char* stopwords[50] = { "a", "an", "and", "the", "to", "is", "in", "that", "it", "of", "with", "for", "as", "on", "was", "by", "at", "be", "this", "have", "from", "or", "you", "not", "are", "all", "we", "but", "they", "his", "her", "she", "he", "which", "there", "if", "their", "been", "would", "our", "your", "will", "who", "these", "had", "has", "those", "yet" };

    // A list of keywords for our summarization
    char* words[10] = { "quick", "brown", "fox", "lazy", "dog", "happy", "chases", "away", "end" };

    // Convert the text to lowercase and remove any unwanted words/punctuation
    toLowercase(text);
    sanitizeText(text, stopwords);

    // Summarize the text and print out the most relevant sentences
    summarizeText(text, stopwords, words, 9, 2);

    return 0;
}