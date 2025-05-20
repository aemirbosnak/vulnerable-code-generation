//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove special characters and spaces from a string
void sanitize_url(char *str){
    int j = 0;
    for(int i = 0; str[i]; i++) {
        // Copy only alphanumeric characters into the new string
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // terminate the new string
}

// Function to remove duplicate characters in a string
void remove_duplicates(char *str){
    int len = strlen(str);
    if(len < 2) return; // nothing to do for strings of length 0 or 1
    
    int tail = 1;
    for(int i = 1; i < len; i++) {
        int j;
        for(j = 0; j < tail; j++) {
            if(str[i] == str[j]) break; // character is already in the new string
        }
        if(j == tail) str[tail++] = str[i]; // unique character, add it to the new string
    }
    str[tail] = '\0'; // terminate the new string
}

int main(int argc, char **argv){
    if(argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }
    
    char *url = argv[1];
    char *clean_url = malloc(strlen(url) + 1);
    if(clean_url == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    
    sanitize_url(url);
    remove_duplicates(url);
    
    printf("Clean URL: %s\n", url);
    
    free(clean_url); // free the allocated memory
    return 0;
}