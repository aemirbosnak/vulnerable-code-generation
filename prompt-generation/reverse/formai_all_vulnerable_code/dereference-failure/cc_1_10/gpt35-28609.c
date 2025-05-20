//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

//Function prototypes
void printDirectory(char *path, int n);
void printTabs(int n);

int main()
{
    char path[100];

    printf("Enter directory path: ");
    scanf("%s", path);

    printf("Directory tree:\n");
    printDirectory(path, 0);

    return 0;
}

void printDirectory(char *path, int n)
{
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) 
    {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        printTabs(n);
        printf("|-- %s\n", entry->d_name);

        char newPath[100];
        snprintf(newPath, sizeof newPath, "%s/%s", path, entry->d_name);
        struct stat st;
        if(stat(newPath, &st) == -1)
        {
            perror("Error in fetching file statistics");
            continue;
        }

        if(S_ISDIR(st.st_mode))
        {
            printDirectory(newPath, n+1);
        }
    }

    closedir(dir);
}

void printTabs(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\t");
    }
}