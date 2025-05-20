//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXFILES 100

struct file{
   char name[100];
   int size;
   char* content;
};

int i = 0;
int count = 0;
struct file files[MAXFILES];

void createfile()
{
    if (count < MAXFILES)
    {
        printf("Enter the file name: ");
        scanf("%s", files[i].name);

        printf("Enter the content: ");
        getchar();
        files[i].content = malloc(1000* sizeof(char));
        fgets(files[i].content, 1000, stdin);
        files[i].size = strlen(files[i].content);

        printf("\nFile %s created successfully\n",files[i].name);
        i++;
        count++;
    }
    else
    {
        printf("\nSorry, you can't create more files!\n");
    }
}

void readfile()
{
    char name[100];
    printf("Enter the file name: ");
    scanf("%s", &name);

    for (int j = 0; j < count; j++)
    {
        if (strcmp(files[j].name, name) == 0)
        {
            printf("Content of the file %s:\n%s \n", name, files[j].content);
            return;
        }
    }
    printf("File not found!\n");
}

void deletefile()
{
    char name[100];
    printf("Enter the file name: ");
    scanf("%s", &name);

    for (int j = 0; j < count; j++)
    {
        if (strcmp(files[j].name, name) == 0)
        {

            printf("\nFile %s deleted successfully!\n",files[j].name);

            for(int k = j; k < count; k++)
            {
                files[k] = files[k+1];
            }
            count--;
            return;
        }
    }
    printf("File not found!\n");
}

int main()
{
    int choice;
    printf("Welcome to File System Simulation\n");

    while(1)
    {
        printf("\nChoose an option:\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                createfile();
                break;
            case 2:
                readfile();
                break;
            case 3:
                deletefile();
                break;
            case 4:
                exit(1);
            default:
                printf("\nWrong Choice! Please enter a valid option.\n");
                break;
        }
    }
}