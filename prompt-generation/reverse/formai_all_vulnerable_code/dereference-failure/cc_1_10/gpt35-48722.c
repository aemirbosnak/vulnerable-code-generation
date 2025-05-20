//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 1000 //Maximum length of string

//Thread function to check Palindrome
void* checkPalindrome(void *strPtr) {
    char *str = (char *)strPtr;
    int start = 0;
    int end = strlen(str) - 1;
    while(end > start) {
        if(str[start++] != str[end--]) {
            printf("%s is NOT a Palindrome\n", str);
            return (void *)0;
        }
    }
    printf("%s is a Palindrome!\n", str);
    return (void *)1;
}

int main() {
    pthread_t threads[MAX_STRING_LENGTH];
    int threadIndex = 0;
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; //Removing newline character
    int strLength = strlen(str);
    //Generating all possible substrings and checking for Palindrome using threads
    for(int i=0; i<strLength; i++){
        for(int j=i+1; j<=strLength; j++){
            int subStringLength = j - i;
            char* tempStr = (char*)malloc(sizeof(char)*subStringLength+1);
            strncpy(tempStr, &str[i], subStringLength);
            tempStr[subStringLength] = '\0';
            threadIndex++;
            if (pthread_create(&threads[threadIndex-1], NULL, checkPalindrome, (void *)tempStr) != 0){
                printf("Unable to create thread\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    //Joining all the threads and checking the thread return value to get the final result.
    int finalResult = 1;
    for(int i=0; i<threadIndex; i++){
        void *returnValue;
        if(pthread_join(threads[i], &returnValue) != 0){
            printf("Thread Join operation failed\n");
            exit(EXIT_FAILURE);
        }
        if((int)returnValue == 0)
            finalResult = 0;
    }
    if(finalResult)
        printf("The string %s is a Palindrome!\n", str);
    else
        printf("The string %s is NOT a Palindrome!\n", str);
    return 0;
}