//Gemma-7B DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s);
void str_replace(char *str, char *old, char *new);

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog.";
    char old[] = "quick";
    char new[] = "fast";

    itoa(12, str);
    str_replace(str, old, new);

    printf("%s", str);

    return 0;
}

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    sprintf(num, "%d", n);
    while (num[i] != '\0')
    {
        s[i] = num[i];
        i++;
    }
    s[i] = '\0';
}

void str_replace(char *str, char *old, char *new)
{
    char *ptr = str;
    char *pos = strstr(ptr, old);

    while (pos)
    {
        int len_old = strlen(old);
        int len_new = strlen(new);

        memmove(pos, pos + len_old, len_new - len_old);
        memcpy(pos, new, len_new);

        pos = strstr(ptr, old) + len_new;
    }
}