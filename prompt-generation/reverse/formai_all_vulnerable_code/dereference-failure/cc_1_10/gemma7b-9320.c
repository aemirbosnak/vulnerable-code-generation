//Gemma-7B DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

void paranoid_string_manipulation(char *str)
{
    char **ptr = NULL;
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, flag = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        ptr = (char **)malloc(sizeof(char *) * (i + 1));

        for (j = 0; ptr[j] = str[i], j < i + 1; j++)
        {
            if (ptr[j] == 'a' || ptr[j] == 'e' || ptr[j] == 'i' || ptr[j] == 'o' || ptr[j] == 'u')
            {
                flag = 1;
            }
        }

        free(ptr);

        if (flag)
        {
            str[i] = '\0';
            l = 0;
            for (k = 0; str[k] != '\0'; k++)
            {
                if (str[k] != str[i])
                {
                    str[l++] = str[k];
                }
            }
            str[l] = '\0';
        }

        flag = 0;
    }

    return;
}

int main()
{
    char str[] = "Hello, world!";

    paranoid_string_manipulation(str);

    printf("%s\n", str);

    return 0;
}