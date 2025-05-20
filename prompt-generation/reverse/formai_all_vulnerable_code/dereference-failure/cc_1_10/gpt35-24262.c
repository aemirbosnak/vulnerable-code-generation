//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to count the number of words in the given string
int countWords(char *str) {
    int count = 0, i;
    char prevChar = ' ';
  
    // traversing through the string character by character
    for(i=0; str[i]!='\0'; i++) {
      
        // if current character is not a whitespace and the previous character is a whitespace, increase the word count
        if(str[i]!=' ' && prevChar==' ') {
            count++;
        }

        // updating the previous character
        prevChar = str[i];
    }

    // returning the word count
    return count;
}

int main() {
    char *str;
    int wordCount;

    // dynamic memory allocation for the input string
    str = (char*) malloc(sizeof(char) * 100);

    // accepting the input string from the user
    printf("Enter the string: ");
    fgets(str, 100, stdin);

    // replacing the newline character with the null terminator to remove any unwanted characters from the input
    str[strlen(str)-1] = '\0';

    // calling the countWords function to count the number of words in the given string
    wordCount = countWords(str);

    // printing the word count
    printf("The number of words in the given string is: %d", wordCount);

    // freeing the dynamically allocated memory
    free(str);

    return 0;
}