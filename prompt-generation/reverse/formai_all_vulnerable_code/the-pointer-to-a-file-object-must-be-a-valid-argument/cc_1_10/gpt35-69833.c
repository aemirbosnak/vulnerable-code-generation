//FormAI DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global Variables */
char filename[] = "my_diary.txt";

/* Function Prototypes */
void menu();
void add_entry();
void view_entries();
void delete_entry();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;

    printf("Welcome to your Digital Diary!\n");
    printf("Please select an option:\n");
    printf("1. Add an entry\n");
    printf("2. View entries\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            printf("Thank you for using Digital Diary!\n");
            exit(0);
            break;
        default:
            printf("Invalid option, please try again.\n");
            menu();
            break;
    }
}

void add_entry()
{
    char entry[500];
    FILE *fp;

    fp = fopen(filename, "a");

    printf("\nEnter your diary entry (max 500 characters):\n");
    scanf(" %[^\n]", entry);

    fprintf(fp, "%s\n", entry);

    printf("\nEntry added successfully!\n");

    fclose(fp);

    menu();
}

void view_entries()
{
    FILE *fp;
    char buffer[1000];

    fp = fopen(filename, "r");

    printf("\nYour previous entries:\n");

    while(fgets(buffer, 1000, fp))
    {
        printf("%s", buffer);
    }

    fclose(fp);

    menu();
}

void delete_entry()
{
    FILE *tempfp, *fp;
    char buffer[1000], entry[1000], confirm;
    int line = 1, count = 0;

    fp = fopen(filename, "r");

    printf("Enter the number of the entry you want to delete:\n");

    while(fgets(buffer, 1000, fp))
    {
        printf("%d. %s", line, buffer);
        line++;
    }

    fclose(fp);

    scanf("%d", &line);

    fp = fopen(filename, "r");
    tempfp = fopen("temp.txt", "w");

    while(fgets(buffer, 1000, fp))
    {
        count++;

        if(count != line)
        {
            fprintf(tempfp, "%s", buffer);
        }
        else
        {
            strcpy(entry, buffer);
        }
    }

    fclose(fp);
    fclose(tempfp);

    printf("\nAre you sure you want to delete this entry? (Y/N)\n");
    scanf(" %c", &confirm);

    if(confirm == 'Y' || confirm == 'y')
    {
        remove(filename);
        rename("temp.txt", filename);

        printf("\n%sEntry deleted successfully!\n", entry);
    }
    else
    {
        remove("temp.txt");
        printf("\nEntry not deleted.\n");
    }

    menu();
}