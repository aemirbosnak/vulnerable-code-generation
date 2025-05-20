//FormAI DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50

// Function to clean the input string from non-alphabetic and non-space characters
void clean_string(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(!isalpha(str[i]) && !isspace(str[i])) {
            for(int j=i; j<len; j++)
                str[j] = str[j+1];
            len--;
            i--;
        }
    }
}

// Function to count the number of each word in the input string
void word_count(char* str) {
    int count = 0;
    char* word[MAX_WORD_LENGTH];
    char* token = strtok(str, " ");
    while(token != NULL) {
        count++;
        word[count] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(word[count], token);
        token = strtok(NULL, " ");
    }
    printf("Word Count:\n");

    // Loop to count the number of each word
    for(int i=1; i<=count; i++) {
        int word_count = 1;
        for(int j=i+1; j<=count; j++) {
            if(strcmp(word[i], word[j]) == 0) {
                word_count++;
                for(int k=j; k<=count; k++)
                    strcpy(word[k], word[k+1]);
                j--;
                count--;
            }
        }
        printf("%s: %d\n", word[i], word_count);
    }
}

int main() {
    char input_string[200];
    printf("Enter a string to count the number of words: ");
    fgets(input_string, sizeof(input_string), stdin);

    clean_string(input_string);

    word_count(input_string);
    return 0;
}