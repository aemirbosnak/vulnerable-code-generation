//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 500

int main(int argc, char* argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <message file>\n", argv[0]);
        return 1;
    }

    char* message_file = argv[1];

    FILE* fp = fopen(message_file, "r");
    if (fp == NULL)
    {
        printf("Failed to open file '%s'\n", message_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    while (fgets(line, sizeof(line), fp))
    {
        if (line[0] == '>')
        {
            fgets(email, sizeof(email), fp);
            fgets(message, sizeof(message), fp);

            // Check for spam words in email
            int num_spam_words = check_spam_words(email);
            if (num_spam_words > 0)
            {
                printf("SPAM EMAIL: %s\n", email);
                printf("SPAM MESSAGE: %s\n", message);
                return 1;
            }

            // Check for spam words in message
            num_spam_words = check_spam_words(message);
            if (num_spam_words > 0)
            {
                printf("SPAM MESSAGE: %s\n", message);
                return 1;
            }
        }
    }

    fclose(fp);
    printf("No spam detected.\n");

    return 0;
}

// Function to check if a given string contains any spam words
int check_spam_words(char* str)
{
    char* words[] = {"free", "offer", "discount", "sale", "win", "prize"};
    int num_words = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < num_words; i++)
    {
        int found = 0;
        while (str[0]!= '\0')
        {
            if (strcasecmp(words[i], str) == 0)
            {
                found = 1;
                break;
            }
            str++;
        }

        if (found == 1)
        {
            return 1;
        }
    }

    return 0;
}