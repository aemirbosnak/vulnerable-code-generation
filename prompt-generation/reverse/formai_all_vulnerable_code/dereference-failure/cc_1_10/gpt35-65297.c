//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define LEN 1024

int is_number(const char *str);

int main()
{
    DIR *dir;
    struct dirent *ent;
    char path[LEN];
    char pid[LEN];
    char command[LEN];
    char state[LEN];
    char ppid[LEN];
    char memory[LEN];
    char temp[LEN];

    printf("%-7s  %-25s  %-10s  %-7s  %-6s  %-10s\n", "PID", "COMMAND", "STATE", "PPID", "MEMORY", "PATH");

    if ((dir = opendir("/proc")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (is_number(ent->d_name))
            {
                strcpy(pid, ent->d_name);
                strcpy(path, "/proc/");
                strcat(path, pid);
                strcat(path, "/status");

                FILE *fp = fopen(path, "r");

                while (fp && fgets(temp, LEN, fp))
                {
                    if (sscanf(temp, "State:%s", state) == 1)
                        continue;

                    if (sscanf(temp, "PPid:%s", ppid) == 1)
                        continue;

                    if (sscanf(temp, "VmSize:%s", memory) == 1)
                    {
                        snprintf(memory, LEN, "%.2f MB", atof(memory) / 1024.0);
                        continue;
                    }

                    if (sscanf(temp, "Name:%[^\n]", command) == 1)
                    {
                        printf("%-7s  %-25s  %-10s  %-7s  %-6s  %-10s\n", pid, command, state, ppid, memory, path);
                        break;
                    }
                }
                fclose(fp);
            }
        }
        closedir(dir);
    }
    else
    {
        perror("");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int is_number(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}