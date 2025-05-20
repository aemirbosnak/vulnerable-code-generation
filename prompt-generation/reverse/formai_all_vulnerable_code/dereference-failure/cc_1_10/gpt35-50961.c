//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] -= 5;
    }
}

int main(int argc, char *argv[])
{
    char *file1;
    char *file2;

    if (argc == 1)
    {
        printf("Please specify two files to synchronize!\n");
        return 1;
    }
    else if (argc == 2)
    {
        file1 = argv[1];
        file2 = "synchronized_file";
    }
    else
    {
        file1 = argv[1];
        file2 = argv[2];
    }

    FILE *fp1, *fp2;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Failed to open file!\n");
        return 1;
    }

    char line1[100];
    char line2[100];

    while (fgets(line1, 100, fp1) != NULL)
    {
        decrypt(line1);
        if (fgets(line2, 100, fp2) != NULL)
        {
            if (strcmp(line1, line2) != 0)
            {
                fprintf(stdout, "Line mismatch: %s != %s\n", line1, line2);
            }
        }
        else
        {
            fprintf(fp2, "%s", line1);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files synchronized successfully!\n");

    return 0;
}