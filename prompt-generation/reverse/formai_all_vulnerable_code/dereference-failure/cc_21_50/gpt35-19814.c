//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    //Declare a String variable and get input from user
    char input[100];
    printf("Please enter a word or phrase: ");
    fgets(input, 100, stdin);
    
    //Remove any whitespace from both sides of the input string
    char *trimmed = input;
    while (*trimmed == ' ') trimmed++;
    if (*trimmed == '\n') return 0;
    char* end = trimmed + strlen(trimmed) - 1;
    while (end > trimmed && *end == ' ') end--;
    *(end + 1) = '\0';
    
    //Find the length of the input string
    int length = strlen(trimmed);
    
    //Check if the input string is a palindrome
    int isPalindrome = 1;
    for (int i = 0; i < length / 2; i++)
    {
        if (trimmed[i] != trimmed[length - i - 1])
        {
            isPalindrome = 0;
            break;
        }
    }
    
    //Count the number of vowels and consonants in the input string
    int vowels = 0, consonants = 0;
    for (int i = 0; i < length; i++)
    {
        if (trimmed[i] == 'a' || trimmed[i] == 'e' || trimmed[i] == 'i' || trimmed[i] == 'o' || trimmed[i] == 'u' || trimmed[i] == 'A' || trimmed[i] == 'E' || trimmed[i] == 'I' || trimmed[i] == 'O' || trimmed[i] == 'U')
            vowels++;
        else if ((trimmed[i] >= 'a' && trimmed[i] <= 'z') || (trimmed[i] >= 'A' && trimmed[i] <= 'Z'))
            consonants++;
    }
    
    //Reverse the input string and output the result
    char reversed[100];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = trimmed[i];
    reversed[length] = '\0';
    printf("Original string: %s\n", trimmed);
    printf("Length of string: %d\n", length);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    printf("Reversed string: %s\n", reversed);
    
   return 0;
}