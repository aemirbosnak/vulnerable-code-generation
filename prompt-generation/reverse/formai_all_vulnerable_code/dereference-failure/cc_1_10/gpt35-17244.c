//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
// Welcome to my C Text Summarizer program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the file
char* readFile(char* filename){
    FILE *file;
    file = fopen(filename, "r");
    if(!file){
        printf("Could not open file %s", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    char* contents = (char*) malloc(size * (sizeof(char)));
    int count = fread(contents, sizeof(char), size, file);
    if(count != size){
        printf("Failed to read %s", filename);
        return NULL;
    }
    fclose(file);
    printf("Successfully read in %d characters from %s\n", count, filename);
    return contents;
}

// Function to summarize the text
char* summarizeText(char* text, int length){
    char* summary = (char*) malloc(length * (sizeof(char)));
    int currPos = 0;
    int sumLength = 0;

    // Loop through text to extract sentences
    while(currPos < length){
        int sentenceLength = 0;
        int endOfSentence = 0;
        while(!endOfSentence){
            char currChar = *(text + currPos + sentenceLength);
            if(currChar == '.' || currChar == '!' || currChar == '?'){
                endOfSentence = 1;
            }
            sentenceLength++;
        }
        currPos += sentenceLength;

        // Append sentence to summary if less than 100 characters
        if(sentenceLength < 100){
            strncat(summary, text + currPos - sentenceLength, sentenceLength);
            sumLength += sentenceLength;
        }
    }
    printf("Summary of text generated. Original length: %d. Summary length: %d\n", length, sumLength);
    return summary;
}

int main(){
    char* inputText = readFile("input.txt");
    if(!inputText){
        exit(1);
    }

    // Print the original text
    printf("Original Text:\n%s\n\n", inputText);

    char* summary = summarizeText(inputText, strlen(inputText));
    if(!summary){
        exit(1);
    }

    // Print the summary
    printf("Summary:\n%s\n", summary);

    free(inputText);
    free(summary);
    return 0;
}