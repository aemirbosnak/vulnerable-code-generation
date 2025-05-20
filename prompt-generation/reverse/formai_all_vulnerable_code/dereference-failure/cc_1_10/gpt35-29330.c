//FormAI DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    printf("Welcome to the Mind-Bending Process Viewer!\n\n");

    DIR* dir;
    struct dirent* entry;
    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("Error opening directory");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && atoi(entry->d_name))
        {
            char path[40];
            sprintf(path, "/proc/%s/stat", entry->d_name);

            FILE* file = fopen(path, "r");
            if (file == NULL)
            {
                perror("Error opening file");
                exit(1);
            }

            // Read process status from file
            char status[256];
            fseek(file, 0, SEEK_SET);
            fgets(status, 256, file);

            // Parse process status
            int pid;
            char pname[256];
            char state;
            sscanf(status, "%d %s %c", &pid, pname, &state);

            // Display process information
            printf("PID: %d\n", pid);
            printf("Name: %s\n", pname);
            printf("State: %c\n\n", state);

            fclose(file);
        }
    }

    closedir(dir);
    return 0;
}