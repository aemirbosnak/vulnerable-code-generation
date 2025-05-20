//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void reverse(char* str)
{
    int len = strlen(str);
    char* temp = (char*) malloc((len+1) * sizeof(char));
    int j = 0;
    for (int i = len-1; i >= 0; i--)
    {
        temp[j++] = str[i];
    }
    temp[j] = '\0';
    strcpy(str, temp);
    free(temp);
}

void removeDuplicates(char* str)
{
    int n = strlen(str);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
                break;
        }
        if (j == i)
            str[index++] = str[i];
    }
    str[index] = '\0';
}

void toUpperCase(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

int main()
{
    char str[MAX_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character

    printf("\nOriginal string: %s\n", str);

    // reverse the string
    reverse(str);
    printf("\nAfter reversing the string: %s\n", str);

    // remove duplicates
    removeDuplicates(str);
    printf("\nAfter removing duplicates: %s\n", str);

    // convert to uppercase
    toUpperCase(str);
    printf("\nAfter converting to uppercase: %s\n", str);

    return 0;
}