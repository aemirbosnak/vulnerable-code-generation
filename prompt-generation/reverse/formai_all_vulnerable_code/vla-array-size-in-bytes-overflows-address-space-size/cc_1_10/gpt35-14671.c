//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool detectSpam(char message[], char spamWords[][20], int n)
{
    char *token;
    token = strtok(message, " ");

    while(token != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            if(strcmp(token, spamWords[i]) == 0)
            {
                return true;
            }
        }
        token = strtok(NULL, " ");
    }
    return false;
}

int main()
{
    char message[200];
    int n;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter number of spam words: ");
    scanf("%d", &n);

    char spamWords[n][20];

    for(int i = 0; i < n; i++)
    {
        printf("Enter spam word %d: ", i+1);
        scanf("%s", spamWords[i]);
    }

    bool isSpam = detectSpam(message, spamWords, n);

    if(isSpam)
    {
        printf("Message is spam!\n");
    }
    else
    {
        printf("Message is not spam.\n");
    }
    return 0;
}