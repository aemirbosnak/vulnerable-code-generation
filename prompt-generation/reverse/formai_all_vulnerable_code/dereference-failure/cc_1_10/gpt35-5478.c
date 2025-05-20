//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char *compress(char *input);

int main()
{
    char input[MAX_SIZE];
    printf("Enter the input string: ");
    fgets(input, MAX_SIZE, stdin);
    char *output = compress(input);

    printf("Original String: %s", input);
    printf("Compressed String: %s", output);

    free(output);
    return 0;
}

char *compress(char *input)
{
    int len = strlen(input);
    char *output = (char *) malloc(len + 1);
    output[0] = input[0];
    int count = 1;
    for(int i=1; i<len; i++)
    {
        if(input[i-1] == input[i])
        {
            count++;
        }
        else
        {
            if(count > 1)
            {
                char countChar[sizeof(int)];
                snprintf(countChar, sizeof(countChar), "%d", count);
                strcat(output, countChar);
            }
            output[strlen(output)] = input[i];
            count = 1;
        }
    }

    if(count > 1)
    {
        char countChar[sizeof(int)];
        snprintf(countChar, sizeof(countChar), "%d", count);
        strcat(output, countChar);
    }

    return output;
}