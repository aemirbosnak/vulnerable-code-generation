//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) 
{
    char filename[BUFSIZE];
    char backupname[BUFSIZE];

    if (argc < 2)  // check if there is an argument passed
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, argv[1]);  // store filename to a variable

    FILE *fptr;
    FILE *backupfptr;   // create file pointers

    // opening the original file for reading
    fptr = fopen(filename, "r");

    if (fptr == NULL)   // check if the file exists
    {
        printf("The file %s does not exist.\n", filename);
        exit(EXIT_FAILURE);
    }

    // create a backup file name by adding "_backup" to original name
    strcpy(backupname, filename);
    strcat(backupname, "_backup");

    // opening the backup file for writing
    backupfptr = fopen(backupname, "w");

    if (backupfptr == NULL)   // check if there is an error creating a backup file
    {
        printf("Error creating backup file.\n");
        exit(EXIT_FAILURE);
    }

    char line[BUFSIZE];
    int line_count = 0;

    while (fgets(line, BUFSIZE, fptr))  // read the original file line by line
    {
        fputs(line, backupfptr);  // write the line to the backup file
        line_count++;   // count the lines
    }

    fclose(fptr);   // close the original file
    fclose(backupfptr);  // close the backup file

    printf("%d lines have been backed up from %s to %s.\n", line_count, filename, backupname);

    return 0;
}