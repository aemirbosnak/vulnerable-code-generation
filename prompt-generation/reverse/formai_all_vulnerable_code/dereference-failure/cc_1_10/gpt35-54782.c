//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function prototypes
char* toLowerCase(char* str);
int isWordChar(const char c);

//Struct to hold dictionary words
struct DictionaryNode{
    char* word;
    struct DictionaryNode* next;
};

//Function to add a word to the dictionary
void addToDictionary(struct DictionaryNode** dictionary, const char* word){
    //Create the new dictionary node
    struct DictionaryNode* newNode = (struct DictionaryNode*) malloc(sizeof(struct DictionaryNode));
    newNode->word = (char*) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    //Add the new node to the dictionary
    if(*dictionary == NULL){
        *dictionary = newNode;
    }else{
        struct DictionaryNode* curr = *dictionary;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

//Function to check if a given word is in the dictionary
int isInDictionary(const struct DictionaryNode* dictionary, const char* word){
    const char* lowerWord = toLowerCase(word);
    const struct DictionaryNode* curr = dictionary;
    while(curr != NULL){
        if(strcmp(curr->word, lowerWord) == 0){
            free((void*) lowerWord);
            return 1;
        }else{
            curr = curr->next;
        }
    }
    free((void*) lowerWord);
    return 0;
}

//Function to convert a string to lowercase
char* toLowerCase(char* str){
    char* lowerStr = (char*) malloc((strlen(str) + 1) * sizeof(char));
    int i;
    for(i = 0; i < strlen(str); i++){
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[i] = '\0';
    return lowerStr;
}

//Function to check if a character is part of a word (alphabetical character or ')
int isWordChar(const char c){
    return isalpha(c) || c == '\'';
}

int main(){
    //Create the dictionary
    struct DictionaryNode* dictionary = NULL;
    addToDictionary(&dictionary, "hello");
    addToDictionary(&dictionary, "world");
    addToDictionary(&dictionary, "apple");
    addToDictionary(&dictionary, "orange");
    addToDictionary(&dictionary, "banana");
    addToDictionary(&dictionary, "pear");
    addToDictionary(&dictionary, "grape");
    addToDictionary(&dictionary, "watermelon");
    addToDictionary(&dictionary, "strawberry");

    //Read in the input string
    printf("Enter the string to check: ");
    char input[1000];
    fgets(input, 1000, stdin);

    //Loop over the input string and check each word
    char* wordStart = input;
    int wordLength = 0;
    int i;
    for(i = 0; i < strlen(input); i++){
        if(isWordChar(input[i])){
            wordLength++;
        }else{
            if(wordLength > 0){
                //Extract the word from the input string
                char* word = (char*) malloc((wordLength + 1) * sizeof(char));
                strncpy(word, wordStart, wordLength);
                word[wordLength] = '\0';

                //Check if the word is in the dictionary
                if(!isInDictionary(dictionary, word)){
                    printf("Possible spelling mistake: %s\n", word);
                }

                free((void*) word);
                wordLength = 0;
            }
            wordStart = input + i + 1;
        }
    }

    //Check the last word in the input string
    if(wordLength > 0){
        //Extract the word from the input string
        char* word = (char*) malloc((wordLength + 1) * sizeof(char));
        strncpy(word, wordStart, wordLength);
        word[wordLength] = '\0';

        //Check if the word is in the dictionary
        if(!isInDictionary(dictionary, word)){
            printf("Possible spelling mistake: %s\n", word);
        }

        free((void*) word);
    }

    //Free the dictionary memory
    struct DictionaryNode* curr = dictionary;
    while(curr != NULL){
        struct DictionaryNode* temp = curr;
        curr = curr->next;
        free((void*) temp->word);
        free((void*) temp);
    }

    return 0;
}