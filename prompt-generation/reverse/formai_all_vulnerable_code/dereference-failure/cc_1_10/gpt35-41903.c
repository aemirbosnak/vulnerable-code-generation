//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Ask user for file name to scan
    char file_name[100];
    printf("Enter file name to scan: ");
    scanf("%s", file_name);

    // Open the file
    FILE *file = fopen(file_name, "r");

    // Check if file opened successfully
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Calculate file size
    fseek(file, 0, SEEK_END); // seek to end of file
    long file_size = ftell(file); // get current file pointer
    fseek(file, 0, SEEK_SET); // seek back to beginning of file

    // Read the file
    char *buffer = (char*) malloc(file_size + 1); // allocate memory
    fread(buffer, file_size, 1, file); // read file into buffer
    fclose(file); // close the file
    buffer[file_size] = '\0'; // add null terminator to buffer

    // Scan the file for viruses
    int virus_count = 0;
    char viruses[3][20] = {"backdoor", "worm", "trojan"};

    for (int i = 0; i < 3; i++)
    {
        if (strstr(buffer, viruses[i]) != NULL)
        {
            printf("Virus detected: %s\n", viruses[i]);
            virus_count++;
        }
    }

    // Print scan result
    if (virus_count == 0)
    {
        printf("No viruses detected.\n");
    }
    else
    {
        printf("Detected %d virus(es).\n", virus_count);
    }

    // Free allocated memory
    free(buffer);

    return 0;
}