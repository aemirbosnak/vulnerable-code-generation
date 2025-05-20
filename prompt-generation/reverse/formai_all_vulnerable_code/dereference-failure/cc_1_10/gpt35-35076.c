//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int isPalindrome(char *str)
{
    int len = strlen(str);
    int i=0, j=len-1;
    char c1, c2;

    while(i<j)
    {
        c1 = tolower(str[i]);
        c2 = tolower(str[j]);

        // Skip non-alphanumeric characters
        while(!isalnum(c1))
        {
            i++;
            c1 = tolower(str[i]);
        }

        while(!isalnum(c2))
        {
            j--;
            c2 = tolower(str[j]);
        }

        if(c1 != c2)
            return 0;  // Not a palindrome

        i++;
        j--;
    }

    return 1;  // Palindrome
}

int main()
{
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    if(isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}