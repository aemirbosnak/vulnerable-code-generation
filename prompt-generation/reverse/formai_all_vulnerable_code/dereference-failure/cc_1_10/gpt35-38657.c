//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function for checking if the character is a letter or not
int isLetter(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    return 0;
}

//function for converting the character to lowercase
char toLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    return c;
}

//function for checking if the word is spelled correctly
int isSpelledCorrectly(char *word, char **dictionary, int dictionarySize){
    int i, j, wordLen = strlen(word);
    for(i=0; i<dictionarySize; i++){
        if(strlen(dictionary[i]) == wordLen){
            int flag = 1;
            for(j=0; j<wordLen; j++){
                if(toLowerCase(dictionary[i][j]) != toLowerCase(word[j])){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    char **dictionary; //array of strings to store words from dictionary
    int dictionarySize; //size of dictionary
    char *text; //string to store text read from file
    char *word; //string to store each word from text while reading
    int textLen, i, j, wordLen, wordCount = 0, spellingMistakes = 0;
    int *mistakeIndices; //array to store indices of spelling mistakes

    //open dictionary file and read words to dictionary array
    FILE *fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("Error: Failed to open dictionary file.\n");
        exit(1);
    }else{
        char ch = getc(fp);
        while(ch != EOF){
            if(ch == '\n'){
                dictionarySize++;
            }
            ch = getc(fp);
        }
        fseek(fp, 0, SEEK_SET);
        dictionary = (char**)malloc(dictionarySize * sizeof(char*));
        for(i=0; i<dictionarySize; i++){
            dictionary[i] = (char*)malloc(100 * sizeof(char));
            fgets(dictionary[i], 100, fp);
            dictionary[i][strlen(dictionary[i])-1] = '\0';
        }
        fclose(fp);
    }

    //open text file and read content to text string
    fp = fopen("text.txt", "r");
    if(fp == NULL){
        printf("Error: Failed to open text file.\n");
        exit(1);
    }else{
        char ch = getc(fp);
        while(ch != EOF){
            textLen++;
            ch = getc(fp);
        }
        fseek(fp, 0, SEEK_SET);
        text = (char*)malloc((textLen+1) * sizeof(char));
        ch = getc(fp);
        while(ch != EOF){
            text[wordCount++] = ch;
            ch = getc(fp);
        }
        text[wordCount] = '\0';
        fclose(fp);
    }

    //process the text word by word and check spelling mistakes
    i = 0;
    mistakeIndices = (int*)malloc(textLen * sizeof(int));
    while(i < textLen){
        //filter non-letter characters
        while(i < textLen && !isLetter(text[i])){
            i++;
        }
        if(i == textLen){
            break;
        }
        j = i;
        wordLen = 0;
        //read the word
        while(j < textLen && isLetter(text[j])){
            wordLen++;
            j++;
        }
        word = (char*)malloc((wordLen+1) * sizeof(char));
        for(j=i; j<i+wordLen; j++){
            word[j-i] = text[j];
        }
        word[wordLen] = '\0';
        //check spelling
        if(!isSpelledCorrectly(word, dictionary, dictionarySize)){
            mistakeIndices[spellingMistakes++] = i;
        }
        free(word);
        i += wordLen;
    }

    //print spelling mistakes
    printf("Spelling Mistakes: \n");
    for(i=0; i<spellingMistakes; i++){
        printf("%d. ", i+1);
        for(j=mistakeIndices[i]; j<textLen && isLetter(text[j]); j++){
            printf("%c", text[j]);
        }
        printf("\n");
    }

    //free memory
    for(i=0; i<dictionarySize; i++){
        free(dictionary[i]);
    }
    free(dictionary);
    free(text);
    free(mistakeIndices);

    return 0;
}