//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char date[10];
    char entry[200];
    char filename[20];
    char command[50];
    FILE *fp;

    printf("Enter today's date (MM/DD/YYYY): ");
    fgets(date, 10, stdin);
    date[strcspn(date, "\n")] = 0; // remove trailing newline

    // create filename using date
    strcpy(filename, date);
    strcat(filename, ".txt");

    // check if file already exists
    fp = fopen(filename, "r");
    if (fp != NULL)
    {
        printf("You already have a diary entry for today, do you want to replace it (Y/N)? ");
        char ans = getchar();
        getchar(); // consume newline character
        if (ans == 'N' || ans == 'n')
        {
            printf("Exiting program...\n");
            return 0;
        }
    }

    // get diary entry from user
    printf("Write your entry for today: ");
    fgets(entry, 200, stdin);
    entry[strcspn(entry, "\n")] = 0; // remove trailing newline

    // open file in write mode and write entry
    fp = fopen(filename, "w");
    fprintf(fp, "Date: %s\n\n%s", date, entry);
    fclose(fp);

    // print success message and open file for viewing
    printf("Diary entry saved successfully!\n");
    sprintf(command, "notepad %s", filename);
    system(command);

    return 0;
}