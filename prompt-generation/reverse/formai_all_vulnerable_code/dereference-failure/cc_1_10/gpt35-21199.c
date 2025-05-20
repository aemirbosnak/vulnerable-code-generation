//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LENGTH 10
#define MAX_COMMAND_LENGTH 100

void process_viewer()
{
    DIR* directory = opendir("/proc");
    struct dirent* entry;
    FILE* file;
    int pid;
    char path[MAX_COMMAND_LENGTH], line[MAX_COMMAND_LENGTH], command[MAX_COMMAND_LENGTH];

    printf("%10s %s\n", "PID", "COMMAND");

    while ((entry = readdir(directory)) != NULL) 
    {
        if (isdigit(*entry->d_name)) 
        {
            pid = atoi(entry->d_name);
            sprintf(path, "/proc/%d/cmdline", pid);
            file = fopen(path, "r");
            fgets(line, MAX_COMMAND_LENGTH, file);
            fclose(file);
            if(strlen(line) == 0)
            {
                sprintf(path, "/proc/%d/comm", pid);
                file = fopen(path, "r");
                fscanf(file, "%s", line);
                fclose(file);
            }
            int i;
            for (i = 0; i < strlen(line); i++)
            {
                  if(line[i] == '\0')
                      line[i] = ' ';
            }
            printf("%10d %s\n", pid, line); 
        }
    }
    closedir(directory);
}

int main()
{
    process_viewer();
    return 0;
}