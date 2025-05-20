//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void printProcess(char pid[], char pname[]);
void showSubDirs(char dirPath[]);

int main(void)
{
    printf("PID\tProcess Name\n");
    showSubDirs("/proc"); //starting from the /proc directory

    return 0;
}

void showSubDirs(char dirPath[])
{
    DIR *dir;
    struct dirent *dirEntry;

    if((dir = opendir(dirPath)) == NULL)
    {
        fprintf(stderr, "Cannot open directory '%s': %s\n", dirPath, strerror(errno));
        return;
    }

    while((dirEntry = readdir(dir)) != NULL)
    {
        char subDirPath[256] = {0};

        if((strncmp(dirEntry->d_name, ".", 1) == 0) || !isdigit(*(dirEntry->d_name)))
            continue;

        snprintf(subDirPath, sizeof(subDirPath), "%s/%s", dirPath, dirEntry->d_name);

        printProcess(dirEntry->d_name, subDirPath);

        showSubDirs(subDirPath);
    }

    closedir(dir);
}

void printProcess(char pid[], char pname[])
{
    char *process = calloc(256, 1);
    char processName[256] = {0};
    char filePath[256] = {0};
    FILE *fp;

    snprintf(filePath, sizeof(filePath), "%s/cmdline", pname);

    if((fp = fopen(filePath, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file '%s': %s\n", filePath, strerror(errno));

        return;
    }

    if(fread(process, sizeof(char), 256, fp) <= 0)
    {
        fprintf(stderr, "Error reading file '%s': %s\n", filePath, strerror(errno));

        return;
    }

    fclose(fp);

    //truncating the string at the first NULL character to get the process name
    snprintf(processName, sizeof(processName), "%s", strtok(process, "\0"));

    if((strlen(processName) > 0) && (strlen(processName) < 256)) //if valid process name
        printf("%s\t%s\n", pid, processName);

    free(process);
}