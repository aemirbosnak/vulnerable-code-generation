//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fw_rand_string(char **str, int len);
void fw_rand_num(int *n);
int fw_rand_bool(void);

int main()
{
    char **txt = NULL;
    int txt_len = 0;
    int n = 0;
    int i = 0;

    fw_rand_num(&n);
    txt_len = n;
    txt = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        txt[i] = malloc(rand() % 10 + 1);
        fw_rand_string(txt[i], rand() % 100);
    }

    for (i = 0; i < n; i++)
    {
        free(txt[i]);
    }
    free(txt);

    return 0;
}

void fw_rand_string(char **str, int len)
{
    *str = malloc(len + 1);
    (*str)[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        (*str)[i] = (char)rand() % 26 + 'a';
    }
}

void fw_rand_num(int *n)
{
    *n = rand() % 1000;
}

int fw_rand_bool(void)
{
    return rand() % 2 ? 1 : 0;
}