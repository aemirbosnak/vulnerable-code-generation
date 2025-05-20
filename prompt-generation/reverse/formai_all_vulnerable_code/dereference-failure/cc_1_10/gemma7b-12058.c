//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alien_translator(char **str)
{
    char *a = "Glb'ztph'zn";
    char *b = "Nxr'ylk'bzt";
    char *c = "Hyl'zdw'zt";
    char *d = "Zzz'rtw'zt";
    char *e = "Rrr'yk'zt";
    char *f = "Frr'wht'zt";

    int i = 0;
    while (*str[i] != '\0')
    {
        switch (*str[i])
        {
            case 'a':
                *str[i] = a[0];
                break;
            case 'b':
                *str[i] = b[0];
                break;
            case 'c':
                *str[i] = c[0];
                break;
            case 'd':
                *str[i] = d[0];
                break;
            case 'e':
                *str[i] = e[0];
                break;
            case 'f':
                *str[i] = f[0];
                break;
            default:
                *str[i] = *str[i];
                break;
        }
        i++;
    }
}

int main()
{
    char *str = "Alien language is so cool!";
    alien_translator(&str);
    printf("%s\n", str);

    return 0;
}