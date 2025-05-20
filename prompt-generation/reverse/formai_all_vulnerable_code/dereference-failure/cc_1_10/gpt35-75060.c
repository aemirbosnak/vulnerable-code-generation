//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to count number of vowels */
int count_vowels(char *str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(tolower(str[i])=='a' || tolower(str[i])=='e' || tolower(str[i])=='i' ||tolower(str[i])=='o' ||tolower(str[i])=='u') {
            count++;
        }
    }
    return count;
}

/* Function to count number of consonants */
int count_consonants(char *str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(isalpha(str[i])) {
            if (tolower(str[i])!='a' && tolower(str[i])!='e' && tolower(str[i])!='i' &&tolower(str[i])!='o' &&tolower(str[i])!='u') {
                count++;
            }
        }
    }
    return count;
}

/* Function to reverse a string */
char *reverse_string(char *str) {
    int length = strlen(str);
    char *reverse_str = malloc(sizeof(char)*(length+1));
    for(int i=length-1,j=0; i>=0; i--,j++) {
        reverse_str[j] = str[i];
    }
    reverse_str[length] = '\0';
    return reverse_str;
}

int main() {
    char string[100];
    printf("Enter a string:\n");
    fgets(string, 100, stdin);

    // remove trailing newline character
    string[strcspn(string, "\n")] = 0;

    // count number of vowels and consonants
    int num_vowels = count_vowels(string);
    int num_consonants = count_consonants(string);

    // print the results
    printf("Number of vowels in the string: %d\n", num_vowels);
    printf("Number of consonants in the string: %d\n", num_consonants);

    // reverse the string
    char *reverse_str = reverse_string(string);
    printf("The reversed string is: %s\n", reverse_str);

    free(reverse_str);
    return 0;
}