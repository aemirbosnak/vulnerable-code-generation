//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(FILE *fp, FILE *op)
{
    unsigned char buffer[MAX_BUFFER_SIZE];
    int i, j, count = 0, previousCharacter = -1;

    while (!feof(fp))
    {
        i = fread(buffer, 1, MAX_BUFFER_SIZE, fp);

        for (j = 0; j < i; j++)
        {
            if (previousCharacter == buffer[j])
            {
                count++;
            }
            else
            {
                if (count > 0)
                {
                    fprintf(op, "%c%d ", previousCharacter, count);
                    count = 1;
                }
                previousCharacter = buffer[j];
            }
        }

        if (count > 0)
        {
            fprintf(op, "%c%d ", previousCharacter, count);
        }
    }

    fclose(fp);
    fclose(op);
}

int main()
{
    FILE *fp = fopen("example.txt", "r");
    FILE *op = fopen("compressed.txt", "w");

    compress(fp, op);

    fclose(fp);
    fclose(op);

    return 0;
}