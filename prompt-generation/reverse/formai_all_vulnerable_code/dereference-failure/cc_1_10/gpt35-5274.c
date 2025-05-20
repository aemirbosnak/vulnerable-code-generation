//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define PROC "/proc"

int main()
{
    DIR* dir = opendir(PROC);
    struct dirent* file;
    char pid[10];

    if (dir)
    {
        printf("PID\tUSER\tSTAT\tCOMMAND\n");

        while ((file = readdir(dir)) != NULL)
        {
            snprintf(pid, sizeof(pid), "%s", file->d_name);

            if (atoi(pid) != 0)
            {
                char stat_file[512], cmd[512], status[512];
                snprintf(stat_file, sizeof(stat_file), "/proc/%s/stat", pid);
                FILE* fp = fopen(stat_file, "r");

                if (fp)
                {
                    fscanf(fp, "%*s %*s %s", status);
                    fclose(fp);

                    snprintf(cmd, sizeof(cmd), "/proc/%s/cmdline", pid);
                    fp = fopen(cmd, "r");

                    if (fp)
                    {
                        char ch;
                        char command[1024];
                        int i = 0;

                        while ((ch = fgetc(fp)) != EOF)
                        {
                            if (ch == '\0')
                            {
                                command[i++] = ' ';
                            }
                            else
                            {
                                command[i++] = ch;
                            }
                        }

                        fclose(fp);
                        printf("%s\t%s\t%s\t%s\n", pid, "User", status, command);
                    }
                }
            }
        }

        closedir(dir);
    }

    return 0;
}