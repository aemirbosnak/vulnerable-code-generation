//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1024];
    printf("Enter a message: ");
    fgets(str, 1024, stdin);

    int is_spam = spam_detection(str);

    if (is_spam)
    {
        printf("Sorry, your message is spam.\n");
    }
    else
    {
        printf("Congratulations, your message is not spam.\n");
    }

    return 0;
}

int spam_detection(char *str)
{
    int words_count = count_words(str);
    int exclamation_marks_count = count_exclamation_marks(str);
    int spam_words_count = count_spam_words(str);

    if (words_count > 20 || exclamation_marks_count > 3 || spam_words_count > 5)
    {
        return 1;
    }

    return 0;
}

int count_words(char *str)
{
    char *word = strtok(str, " ");
    int count = 0;

    while (word)
    {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int count_exclamation_marks(char *str)
{
    char *exclamation_mark = strchr(str, '!');
    int count = 0;

    while (exclamation_mark)
    {
        count++;
        exclamation_mark = strchr(NULL, '!');
    }

    return count;
}

int count_spam_words(char *str)
{
    char *spam_words[] = {"spam", "junk", "garbage", "trash", "phishing"};
    int i = 0;
    int count = 0;

    for (i = 0; i < 5; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            count++;
        }
    }

    return count;
}