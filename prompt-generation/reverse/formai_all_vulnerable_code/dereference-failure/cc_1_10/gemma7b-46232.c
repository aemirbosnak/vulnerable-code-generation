//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(FILE *fp)
{
    int i, j, count = 0, prevChar = -1, buffer[MAX_BUFFER_SIZE];

    rewind(fp);
    while (!feof(fp))
    {
        char currentChar = fgetc(fp);

        if (prevChar == currentChar)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                fprintf(fp, "%c%d ", prevChar, count);
            }
            else
            {
                fprintf(fp, "%c ", prevChar);
            }

            prevChar = currentChar;
            count = 1;
        }
    }

    if (count > 1)
    {
        fprintf(fp, "%c%d ", prevChar, count);
    }

    fclose(fp);
}

int main()
{
    FILE *fp = fopen("sample.txt", "r");
    compress(fp);
    fclose(fp);

    return 0;
}