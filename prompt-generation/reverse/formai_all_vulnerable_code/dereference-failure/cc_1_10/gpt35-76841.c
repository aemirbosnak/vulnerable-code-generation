//FormAI DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20      //maximum length of a word
#define MAX_WORDS 100000    //maximum number of words in dictionary
 
//function to convert all characters in a string to lowercase
void strToLower(char *str){
    while (*str){
        *str = tolower(*str);
        str++;
    }
}

//function to compare two strings ignoring case
int strCompare(char *str1, char *str2){
    int len1=strlen(str1), len2=strlen(str2);
    if (len1!=len2){
        return -1;
    }
    for (int i=0; i<len1; i++){
        if (tolower(str1[i])!=tolower(str2[i])){
            return -1;
        }
    }
    return 0;
}

//function to read words from a file and store them in an array
int readWordsFromFile(char *fileName, char **wordArray){
    FILE *file=fopen(fileName, "r");
    if (file==NULL){
        return -1;
    }
    int wordCount=0;
    char line[MAX_WORD_LEN+1];
    while (fgets(line, MAX_WORD_LEN+1, file)!=NULL){
        line[strcspn(line,"\n")]=0;      //remove newline character from end of line
        strToLower(line);                //convert to lowercase
        char *word=strdup(line);          //make a copy of the line
        wordArray[wordCount++]=word;     //store the word in the array
    }
    fclose(file);
    return wordCount;                     //return the number of words read
}

int main(){
    char **dictionary = malloc(MAX_WORDS * sizeof(char *));
    int dictSize = readWordsFromFile("dictionary.txt", dictionary); //read dictionary from file
    char **misspelledWords = malloc(MAX_WORDS * sizeof(char *));
    int numMisspelledWords = 0;

    char *inputWord;
    size_t len = 0;
    while (getline(&inputWord, &len, stdin) != -1) { //read input words from user
        if (inputWord[strlen(inputWord)-1] == '\n'){
            inputWord[strlen(inputWord)-1] = '\0'; //remove newline character
        }
        strToLower(inputWord); //convert to lowercase
        int found = 0;
        for(int i=0; i<dictSize; i++){ //search for word in the dictionary
            if(strCompare(inputWord, dictionary[i]) == 0){
                found = 1;
                break;
            }
        }
        if(!found){ //if word is not in dictionary, add it to list of misspelled words
            misspelledWords[numMisspelledWords++] = strdup(inputWord);
        }
    }

    //print the misspelled words
    printf("Misspelled words:\n");
    for(int i=0; i<numMisspelledWords; i++){
        printf("%s\n",misspelledWords[i]);
    }

    //free memory
    for(int i=0; i<dictSize; i++){
        free(dictionary[i]);
    }
    for(int i=0; i<numMisspelledWords; i++){
        free(misspelledWords[i]);
    }
    free(dictionary);
    free(misspelledWords);

    return 0;
}