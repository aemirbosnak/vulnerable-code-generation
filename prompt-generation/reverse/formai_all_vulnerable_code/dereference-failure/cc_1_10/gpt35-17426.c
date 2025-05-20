//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Shocked ANTI-VIRUS Scanner\n");
    printf("Scanning your system for viruses....\n");

    // Open file for scanning
    FILE* file;
    char* filename = "system32.exe";
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("%s is not found\n", filename);
    }

    else
    {
        // Read file to check for viruses
        char buffer[1000];
        int i = 0;
        while (fgets(buffer, 1000, file) != NULL)
        {
            if (strstr(buffer, "virus") != NULL)
            {
                printf("WARNING: Virus detected in %s!\n", filename);
                return 0;
            }

            i++;
            if (i % 10000 == 0)
            {
                printf("Scanning...\n");
            }
        }

        // No virus found
        printf("No virus found in %s\n", filename);
        fclose(file);

        // Prompt user to delete file
        printf("Do you want to delete %s? (y/n)\n", filename);
        char answer;
        scanf("%c", &answer);

        if (answer == 'y' || answer == 'Y')
        {
            remove(filename);
            printf("%s successfully deleted\n", filename);
        }

        else
        {
            printf("%s kept intact\n", filename);
        }
    }

    return 0;
}