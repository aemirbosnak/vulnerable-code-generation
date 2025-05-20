//Gemma-7B DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char buf[1024] = "";
    char *pbuf = NULL;

    // Open and read the file
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory and read the file contents
    pbuf = malloc(1024);
    if (pbuf == NULL)
    {
        perror("Error allocating memory");
        return 1;
    }

    fread(pbuf, 1024, 1, fp);
    fclose(fp);

    // Parse the file contents
    char *line = strtok(pbuf, "\n");
    while (line)
    {
        // Check if the line contains the user's name
        if (strstr(line, "john.doe") != NULL)
        {
            // Replace the user's password with a random string
            char *pass = strtok(line, ":") + 1;
            strcpy(pass, "Secret_Secret");
        }

        line = strtok(NULL, "\n");
    }

    // Write the modified file contents to a new file
    fp = fopen("/etc/passwd.tmp", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fwrite(pbuf, 1024, 1, fp);
    fclose(fp);

    // Rename the temporary file to the original file
    system("mv /etc/passwd.tmp /etc/passwd");

    // Free the memory
    free(pbuf);

    return 0;
}