//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

char wordlist[MAX_WORDS][MAX_WORDS];

void load_wordlist()
{
    FILE *fp = fopen("words.txt", "r");
    char line[MAX_WORDS];

    int i = 0;
    while (fgets(line, MAX_WORDS, fp))
    {
        strcpy(wordlist[i], line);
        i++;
    }
    fclose(fp);
}

int detect_spam(char *email)
{
    load_wordlist();

    char words[MAX_WORDS];
    char *p = email;
    int n = 0;

    // Tokenize the email and extract words
    while (p)
    {
        char *word = strtok(p, " ");
        if (word)
        {
            strcpy(words[n], word);
            n++;
        }
        p = strchr(p, ' ') + 1;
    }

    // Check if the extracted words are in the wordlist
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_WORDS; j++)
        {
            if (strcmp(words[i], wordlist[j]) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    char email[] = "Subject: Free Money! Click Here!";

    if (detect_spam(email))
    {
        printf("Email is spam!\n");
    }
    else
    {
        printf("Email is not spam.\n");
    }

    return 0;
}