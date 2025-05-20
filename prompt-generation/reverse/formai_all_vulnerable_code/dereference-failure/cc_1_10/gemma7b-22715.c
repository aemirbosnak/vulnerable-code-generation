//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char **c_ptr = NULL;
    char **c_ptr_2 = NULL;
    int i = 0, j = 0, k = 0, l = 0;
    FILE *fp = NULL;
    struct stat st;
    char filename[255];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    stat(filename, &st);
    l = st.st_size;

    c_ptr = (char *)malloc((l + 1) * sizeof(char));
    c_ptr_2 = (char *)malloc((l + 1) * sizeof(char));

    fread(c_ptr, l, 1, fp);
    fclose(fp);

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            for (k = 0; k < l; k++)
            {
                if (c_ptr[i] == c_ptr[j] && c_ptr[j] == c_ptr[k] && c_ptr[k] != '\0')
                {
                    c_ptr_2[l] = '\0';
                    l++;
                }
            }
        }
    }

    c_ptr_2[l] = '\0';

    printf("Metadata Extractor:\n\n");
    printf("Filename: %s\n", filename);
    printf("Size: %d bytes\n", l);
    printf("Content:\n\n");
    printf("%s", c_ptr_2);

    free(c_ptr);
    free(c_ptr_2);

    return 0;
}