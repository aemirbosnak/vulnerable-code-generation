//Gemma-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "treasure.txt"

int main()
{
    FILE *fp;
    int choice;

    // Open a file named treasure.txt
    fp = fopen(FILE_NAME, "r");

    // If the file is open, display its contents
    if (fp)
    {
        printf("You have opened the file: %s\n", FILE_NAME);
        printf("Please choose an option:\n");
        printf("1. Read the file\n");
        printf("2. Write to the file\n");
        printf("3. Close the file\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Read the file and display its contents
                printf("The contents of the file are:\n");
                fprintf(stdout, "%s", fread(fp, 1, 1024, fp));
                break;
            case 2:
                // Write to the file
                printf("Please enter your message: ");
                scanf("%s", fp);
                break;
            case 3:
                // Close the file
                fclose(fp);
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    else
    {
        // File not open
        printf("Error opening file: %s\n", FILE_NAME);
    }

    return 0;
}