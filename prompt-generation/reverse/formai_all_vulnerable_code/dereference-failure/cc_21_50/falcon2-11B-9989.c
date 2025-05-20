//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *interface = NULL;
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }
    interface = argv[1];

    FILE *pipe = popen("iw dev %s link", "r");
    if (!pipe)
    {
        fprintf(stderr, "popen(\"iw dev %s link\", \"r\") failed: %s\n", interface, strerror(errno));
        exit(1);
    }

    char buffer[256];
    int i;
    for (i = 0; fgets(buffer, sizeof(buffer), pipe); i++)
    {
        if (buffer[0] == 'I')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'P')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'L')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'B')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'S')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'M')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
        else if (buffer[0] == 'C')
        {
            int j;
            for (j = 0; buffer[j] && buffer[j]!= '\n'; j++)
                printf("%c", buffer[j]);
        }
    }

    pclose(pipe);
    return 0;
}