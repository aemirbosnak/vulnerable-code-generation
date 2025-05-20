//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int word_count(char* s);
char* to_lowercase(char* s);
void find_longest_word(char* s, char* longest_word);

int main(){
    char text[1000];
    char lowercase[1000];

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    int num_words = word_count(text);
    printf("Number of words: %d\n", num_words);

    strcpy(lowercase, to_lowercase(text));
    printf("Lowercase text: %s\n", lowercase);

    char longest_word[50];
    find_longest_word(text, longest_word);
    printf("Longest word: %s\n", longest_word);

    return 0;
}

int word_count(char* s){
    int count = 0;
    int in_word = 0;
    int i = 0;

    while(s[i] != '\0'){
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
            in_word = 0;
        }
        else if(!in_word){
            in_word = 1;
            count++;
        }
        i++;
    }

    return count;
}

char* to_lowercase(char* s){
    char* lowercase = (char *)malloc(strlen(s) * sizeof(char));
    int i = 0;

    while(s[i] != '\0'){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            lowercase[i] = s[i] + ('a' - 'A');
        }
        else{
            lowercase[i] = s[i];
        }
        i++;
    }
    lowercase[i] = '\0';

    return lowercase;
}

void find_longest_word(char* s, char* longest_word){
    char word[50];
    int i = 0;
    int j = 0;
    int max_len = 0;
    int len = 0;

    while(s[i] != '\0'){
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
            word[j] = '\0';
            len = strlen(word);
            if(len > max_len){
                max_len = len;
                strcpy(longest_word, word);
            }
            j = 0;
        }
        else{
            word[j] = s[i];
            j++;
        }
        i++;
    }
}