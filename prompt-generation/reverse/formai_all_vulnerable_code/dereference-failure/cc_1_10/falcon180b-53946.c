//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX_SIZE 1000

int main()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int i, j, k, len1, len2, max_len, flag;
    char *result;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if(len1 > len2)
        max_len = len1;
    else
        max_len = len2;

    result = (char*)malloc(max_len+1);

    flag = 0;
    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2; j++)
        {
            if(str1[i] == str2[j])
            {
                result[k++] = str1[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            result[k++] = str1[i];
        }
        flag = 0;
    }

    if(k == 0)
        printf("No common characters found!\n");
    else
    {
        result[k] = '\0';
        printf("Common characters in the two strings are: %s\n", result);
    }

    return 0;
}