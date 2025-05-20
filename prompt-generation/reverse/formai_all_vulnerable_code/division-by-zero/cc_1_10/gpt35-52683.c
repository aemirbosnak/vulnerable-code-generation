//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int wordCount(char* text){
    int count = 0;
    int i = 0;
    while(text[i] != '\0'){
        if(text[i] == ' '){
            count++;
        }
        i++;
    }
    return count + 1;
}

void summarize(char* text, int numSentences){
    int totalWords = wordCount(text);

    // Calculate the number of words in each sentence.
    int numWordsPerSentence = totalWords / numSentences;

    // Set up our array to hold all the sentences.
    char sentences[numSentences][MAX_SIZE];

    //copying the entered text into our char array
    strcpy(sentences[0], strtok(text, "."));

    for(int i = 1; i < numSentences; i++){
        strcpy(sentences[i], strtok(NULL, "."));
    }

    //print the first sentence in full
    printf("%s.\n", sentences[0]);

    for(int i = 1; i < numSentences; i++){
        //count the total number of words
        int count=wordCount(sentences[i]);

        //if this sentence is shorter than average
        if(count<numWordsPerSentence){
            printf("%s.\n", sentences[i]);
        }else{
            //otherwise, summarize it
            char words[count][MAX_SIZE];
            strcpy(words[0], strtok(sentences[i], " "));

            for(int j = 1; j < count; j++){
                strcpy(words[j], strtok(NULL, " "));
            }

            //print the summary
            printf("%s %s %s...\n", words[0], words[1], words[2]);
        }
    }
}

int main(){
    char text[MAX_SIZE];
    int numSentences;

    printf("Enter the text to summarize: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the number of sentences to summarize to: ");
    scanf("%d", &numSentences);

    printf("\nSummary:\n");

    summarize(text, numSentences);

    return 0;
}