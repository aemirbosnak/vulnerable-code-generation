//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(FILE *fp, FILE *out)
{
    unsigned char buffer[MAX_BUFFER_SIZE];
    int read_size = 0, write_size = 0, count = 0;

    // Read data from the file
    while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0)
    {
        // Count repeated characters
        for (int i = 0; i < read_size; i++)
        {
            int is_repeated = 0;
            for (int j = 0; j < count; j++)
            {
                if (buffer[i] == buffer[j])
                {
                    is_repeated = 1;
                    break;
                }
            }

            // If character is not repeated, write it and increment count
            if (!is_repeated)
            {
                fwrite(&buffer[i], 1, 1, out);
                count++;
            }
        }

        // Write the count of repeated characters
        fwrite(&count, 1, sizeof(int), out);
        count = 0;
    }

    // Flush remaining data
    fwrite(buffer, 1, read_size, out);
    fclose(out);
}

int main()
{
    FILE *fp = fopen("test.txt", "r");
    FILE *out = fopen("compressed.txt", "w");

    compress(fp, out);

    fclose(fp);
    fclose(out);

    return 0;
}