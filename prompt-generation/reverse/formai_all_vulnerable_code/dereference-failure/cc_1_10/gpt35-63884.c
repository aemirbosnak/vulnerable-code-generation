//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// setting the maximum length of input word
#define MAX_LENGTH 20

// function to check if a character is a letter
int is_letter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to convert a word to lowercase
void to_lower_case(char* word){
    int i;
    for(i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
}

// function to check if a word is spelled correctly
int check_spelling(char* word){

    // list of valid words
    char* valid_words[] = {"hello", "world", "foo", "bar", "baz"};

    // convert word to lowercase
    to_lower_case(word);

    // iterate through the list of valid words and check if the input word matches
    int i;
    for(i = 0; i < sizeof(valid_words)/sizeof(char*); i++){
        if(strcmp(word, valid_words[i]) == 0){
            return 1;
        }
    }

    // if input word does not match any valid words
    return 0;
}

int main(){

    // initialize input buffer and index counter
    char buffer[MAX_LENGTH];
    int index = 0;

    printf("Please enter a word to check its spelling:\n");

    // read input character by character until newline character or maximum length is reached
    char c;
    while((c = getchar()) != '\n' && index < MAX_LENGTH){

        // if the character is a letter, add it to buffer
        if(is_letter(c)){
            buffer[index] = c;
            index++;
        }

        // if not a letter, ignore character
    }

    // add null terminator to buffer to convert to string
    buffer[index] = '\0';

    // check spelling of input word and print result
    if(check_spelling(buffer)){
        printf("The word \"%s\" is spelled correctly!\n", buffer);
    }
    else{
        printf("The word \"%s\" is not spelled correctly!\n", buffer);
    }

    return 0;
}