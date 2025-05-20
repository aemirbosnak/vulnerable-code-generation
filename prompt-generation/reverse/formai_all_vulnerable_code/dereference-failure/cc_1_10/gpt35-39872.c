//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true (1==1)
#define false (!true)

typedef enum {ERROR, OK} status;

status is_palindrome(const char* s);

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input = argv[1];
    status is_pal = is_palindrome(input);

    if(is_pal == OK) 
    {
        printf("The string is a palindrome!\n");
    } 
    else 
    {
        printf("The string is not a palindrome :(\n");
    }

    return EXIT_SUCCESS;
}

/*
 * This function returns OK if the input string is a palindrome
 */
status is_palindrome(const char* s) 
{
    size_t len = strlen(s);
    int left = 0, right = len - 1;

    while(left < right) 
    {
        if(s[left++] != s[right--]) 
        {
            return ERROR;
        }
    }

    return OK;
}