//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <string.h>

int spam_detector(char **str)
{
    int i = 0;
    int flag = 0;
    char *p = NULL;

    while (*str[i] != '\0')
    {
        p = str[i];

        if (strcmp(p, "spam") == 0)
        {
            flag = 1;
            break;
        }

        i++;
    }

    if (flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char **str = NULL;
    str = malloc(10 * sizeof(char *));

    str[0] = "This email is not spam";
    str[1] = "This email is spam";
    str[2] = "This email is not spam";
    str[3] = "This email is spam";
    str[4] = "This email is not spam";
    str[5] = "This email is spam";
    str[6] = "This email is not spam";
    str[7] = "This email is spam";
    str[8] = "This email is not spam";
    str[9] = "This email is spam";

    for (int i = 0; i < 10; i++)
    {
        if (spam_detector(str) == 1)
        {
            printf("Email: %s is spam\n", str[i]);
        }
    }

    free(str);

    return 0;
}