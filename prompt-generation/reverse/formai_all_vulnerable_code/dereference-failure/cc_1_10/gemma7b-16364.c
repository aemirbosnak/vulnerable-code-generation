//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

int main()
{
    char buffer[MAX_BUFFER];
    char *p, *q, *r, *s, *t;
    int i, j, l, n;

    printf("Enter JSON data: ");
    fgets(buffer, MAX_BUFFER, stdin);

    p = strchr(buffer, '{');
    if (p == NULL)
    {
        printf("Error: Invalid JSON format.\n");
        return 1;
    }

    l = strlen(p);
    q = malloc(l + 1);
    memcpy(q, p, l);
    q[l] = '\0';

    n = 0;
    r = q;
    s = NULL;
    while (r && *r)
    {
        if (*r == '"')
        {
            t = strchr(r, '"');
            if (t)
            {
                s = malloc(t - r + 1);
                memcpy(s, r, t - r);
                s[t - r] = '\0';
                printf("Key: %s, Value: ", s);
                n++;
            }
        }
        r++;
    }

    printf("\nNumber of key-value pairs: %d\n", n);

    free(q);
    return 0;
}