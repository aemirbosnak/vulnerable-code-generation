//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

#define MAX_SIZE 50

bool isPalindrome(char* str);

int main(void){

    printf("Enter a string: ");
    char str[MAX_SIZE];
    scanf("%49s", str);

    if(isPalindrome(str)){
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome :(\n", str);
    }

    return EXIT_SUCCESS;
}

bool isPalindrome(char* str){

    // Clean string from non-alpha characters and convert to lowercase
    int length = strlen(str);
    char* cleanStr = (char*)malloc(length * sizeof(char));
    for(int i=0,j=0; i<length; i++){
        if(isalpha(str[i])){
            cleanStr[j++] = tolower(str[i]);
        }
    }
    cleanStr[length] = '\0';

    // Check if the clean string is a palindrome
    int leftIndex = 0;
    int rightIndex = strlen(cleanStr) - 1;
    while(leftIndex < rightIndex){
        if(cleanStr[leftIndex++] != cleanStr[rightIndex--]){
            return false;
        }
        // Simulate some async work being done
        printf("Checking for palindromicity...\n");
        sleep(1);
    }

    free(cleanStr);
    return true;
}