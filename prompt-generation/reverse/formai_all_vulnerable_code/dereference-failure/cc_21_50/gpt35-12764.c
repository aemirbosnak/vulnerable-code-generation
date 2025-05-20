//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main(){
    char str1[20]= "I love";
    char str2[]=" programming";
    char strConcat[50];
    char str1Rev[20];
    char str2Rev[20];
    
    printf("%s%s\n", str1, str2);
    
    strcat(str1, str2); // concatenate the two strings
    printf("After concatenation: %s\n\n", str1);
    
    // reverse string 1 and string 2
    for(int i=0, j=strlen(str1)-1; i<strlen(str1); i++, j--){
        str1Rev[i] = str1[j];
    }
    for(int i=0, j=strlen(str2)-1; i<strlen(str2); i++, j--){
        str2Rev[i] = str2[j];
    }
    printf("Reversed String 1: %s\n", str1Rev);
    printf("Reversed String 2: %s\n\n", str2Rev);
    
    // check if string 1 is a palindrome
    int isPalindrome = 1;
    for(int i=0; i<strlen(str1)/2; i++){
        if(str1[i] != str1[strlen(str1)-i-1]){
            isPalindrome = 0;
            break;
        }
    }
    if(isPalindrome == 1){
        printf("String 1 is a palindrome!\n");
    }else{
        printf("String 1 is NOT a palindrome!\n");
    }
    
    // copy string 1 into string 2
    strcpy(str2, str1);
    printf("After copying String 1 to String 2: %s\n\n", str2);
    
    // remove all vowels from string 1
    char str1NoVowels[20];
    int index = 0;
    for(int i=0; i<strlen(str1); i++){
        if(str1[i] != 'a' && str1[i] != 'e' && str1[i] != 'i' && str1[i] != 'o' && str1[i] != 'u' && str1[i] != 'A' && str1[i] != 'E' && str1[i] != 'I' && str1[i] != 'O' && str1[i] != 'U'){
            str1NoVowels[index] = str1[i];
            index++;
        }
    }
    str1NoVowels[index] = '\0';
    printf("String 1 without vowels: %s\n", str1NoVowels);
    
    // convert string 1 to uppercase and string 2 to lowercase
    for(int i=0; i<strlen(str1); i++){
        str1[i] = toupper(str1[i]);
    }
    for(int i=0; i<strlen(str2); i++){
        str2[i] = tolower(str2[i]);
    }
    printf("String 1 in uppercase: %s\n", str1);
    printf("String 2 in lowercase: %s\n\n", str2);
    
    // create a new string by alternating characters from string 1 and string 2
    int length = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
    for(int i=0, j=0; i<length; i++){
        if(i % 2 == 0){
            strConcat[i] = str1[j];
            j++;
        }else{
            strConcat[i] = str2[j];
            j++;
        }
    }
    strConcat[length] = '\0';
    printf("After alternating characters: %s\n", strConcat);
    
    return 0;
}