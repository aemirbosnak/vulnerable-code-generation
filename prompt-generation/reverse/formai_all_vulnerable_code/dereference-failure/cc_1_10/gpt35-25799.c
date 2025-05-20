//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");

    if (d)
    {
        printf("%-10s %-20s %-20s\n", "PID", "PROCESS NAME", "STATE");
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_type == DT_DIR)
            {
                char path[1024];
                sprintf(path, "/proc/%s/status", dir->d_name);

                FILE *f = fopen(path, "r");

                if (f)
                {
                    char line[128];
                    char name[1024], state[1024];
                    int pid;

                    // Read each line of the file
                    while (fgets(line, sizeof(line), f))
                    {
                        // Check for process name
                        if (strncmp(line, "Name:", 5) == 0)
                        {
                            sscanf(line + 6, "%s", name);
                        }

                        // Check for process ID
                        if (strncmp(line, "Pid:", 4) == 0)
                        {
                            sscanf(line + 5, "%d", &pid);
                        }

                        // Check for process state
                        if (strncmp(line, "State:", 6) == 0)
                        {
                            sscanf(line + 7, "%s", state);
                        }
                    }

                    fclose(f);

                    // Print process information
                    if (pid != 0)
                    {
                        printf("%-10d %-20s %-20s\n", pid, name, state);
                    }
                }
            }
        }

        closedir(d);
    }

    return 0;
}