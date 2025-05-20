//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

char *read_message(void);
int analyze_message(char *);
int detect_spam(char *);

int main()
{
    char *message = read_message();
    int score = analyze_message(message);
    if (detect_spam(message) && score > 5)
    {
        printf("Spam detected!\n");
    }
    else
    {
        printf("No spam detected.\n");
    }

    return 0;
}

char *read_message(void)
{
    char *message = malloc(MAX_LEN);
    printf("Enter the message: ");
    fgets(message, MAX_LEN, stdin);
    return message;
}

int analyze_message(char *message)
{
    int score = 0;
    char *words[] = {"spam", "free", "lottery", "miracle", "prize"};
    for (int i = 0; i < 5; i++)
    {
        if (strstr(message, words[i]) != NULL)
        {
            score++;
        }
    }

    return score;
}

int detect_spam(char *message)
{
    char *subject = strstr(message, "Subject:");
    if (subject)
    {
        char *subject_words[] = {"urgent", "important", "free", "lottery", "prize"};
        for (int i = 0; i < 5; i++)
        {
            if (strstr(subject, subject_words[i]) != NULL)
            {
                return 1;
            }
        }
    }

    return 0;
}