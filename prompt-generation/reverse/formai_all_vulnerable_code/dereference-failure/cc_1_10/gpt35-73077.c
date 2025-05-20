//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to remove punctuations from the given string
void removePunctuations(char *str)
{
    int i,j=0;
    for(i=0;str[i];i++)
    {
        if(isalnum(str[i]))
        {
            str[j++] = str[i];
        }
    }
    str[j]='\0'; //Add string terminator
}

//Function to calculate the frequency of each word and return the word with highest frequency
char* calculateFrequency(char* str,int *freq)
{
    char *token;
    char *temp = malloc(strlen(str)+1); //Dynamically allocate memory for temporary string
    strcpy(temp,str);
    removePunctuations(temp);
    char *wordFreq[1000]; //Array of pointers to store the words
    int i=0,j;
    token = strtok(temp," "); //Tokenize the string
    while(token != NULL)
    {
        for(j=0;j<i;j++)
        {
            if(strcmp(wordFreq[j],token)==0) //If word already exists in the array
            {
                freq[j]++; //Increment its frequency count
                break;
            }
        }
        if(j==i) //If word does not exist in the array
        {
            wordFreq[i] = strdup(token); //Allocate memory for new word
            freq[i] = 1; //Set frequency count to 1
            i++;
        }
        token = strtok(NULL," "); //Get next token
    }
    int maxFreq = -1;
    char *maxWord = NULL;
    for(j=0;j<i;j++) //Find word with maximum frequency
    {
        if(freq[j]>maxFreq) //If word has highest frequency until now
        {
            maxFreq = freq[j];
            maxWord = wordFreq[j];
        }
    }
    free(temp); //Free up allocated memory
    return maxWord;
}

//Function to summarize given text
void summarizeText(char* text)
{
    int len = strlen(text);
    if(text[len-1]=='\n') text[len-1]='\0'; //Remove new line character
    int i;
    int nSentences=0;
    for(i=0;i<len;i++) //Count the number of sentences
    {
        if(text[i]=='.' || text[i]=='?' || text[i]=='!')
        {
            nSentences++;
        }
    }
    int *sentenceLengths = malloc(nSentences*sizeof(int)); //Dynamically allocate memory to store lengths of sentences
    char *sentenceTokens[nSentences]; //Array of pointers to store the sentences
    char *token;
    int j=0,start=0;
    for(i=0;i<len;i++) //Tokenize the string into sentences
    {
        if(text[i]=='.' || text[i]=='?' || text[i]=='!') //If end of a sentence is found
        {
            sentenceLengths[j] = i+1-start;
            sentenceTokens[j] = strndup(text+start,i-start+1); //Allocate memory to store sentence in array
            start=i+1;
            j++;
        }
    }
    int maxLen=-1;
    char *maxSentenceToken;
    int sentenceNumber=1;
    int *sentenceScores = malloc(nSentences*sizeof(int)); //Dynamically allocate memory to store score of each sentence
    for(i=0;i<nSentences;i++) //Calculate score of each sentence
    {
        int freq[1000]={0};
        char *maxWord = calculateFrequency(sentenceTokens[i],freq); //Get word with highest frequency in the sentence
        if(maxWord!=NULL)
        {
            sentenceScores[i] = strlen(maxWord)*freq[0]/sentenceLengths[i]; //Calculate score of sentence
        }
        if(sentenceScores[i]>maxLen) //Find sentence with maximum score
        {
            maxLen = sentenceScores[i];
            maxSentenceToken = sentenceTokens[i];
        }
    }
    printf("SUMMARY:\n");
    for(i=0;i<nSentences;i++)
    {
        if(strncmp(sentenceTokens[i],maxSentenceToken,strlen(maxSentenceToken))==0) //If sentence is the most important sentence
        {
            printf("\033[1mSentence%d: %s\033[0m\n",sentenceNumber,sentenceTokens[i]);
        }
        else
        {
            printf("Sentence%d: %s\n",sentenceNumber,sentenceTokens[i]);
        }
        sentenceNumber++;
        free(sentenceTokens[i]); //Free up allocated memory
    }
    free(sentenceLengths);
    free(sentenceScores);
}

int main()
{
    char text[10000];
    printf("Enter text to summarize:\n");
    fgets(text,sizeof(text),stdin); //Get input text from user
    summarizeText(text); //Summarize the text
    return 0;
}