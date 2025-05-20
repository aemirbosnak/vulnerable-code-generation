//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void print_processes(const char* path);

int main()
{
    printf("PID\tPPID\tCOMMAND\n");
    print_processes("/proc");
    return 0;
}

void print_processes(const char* path)
{
    DIR* dir = opendir(path);
    if (!dir)
    {
        printf("Error! Could not open directory %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)))
    {
        const char* dname = entry->d_name;
        if (entry->d_type == DT_DIR && strcmp(dname, ".") != 0 && strcmp(dname, "..") != 0)
        {
            char subpath[256];
            sprintf(subpath, "%s/%s", path, dname);
            char statpath[256];
            sprintf(statpath, "%s/%s", subpath, "stat");

            FILE* f = fopen(statpath, "r");
            if (!f)
            {
                continue;
            }

            int pid, ppid;
            char comm[256];
            fscanf(f, "%d %s %*c %d", &pid, comm, &ppid);

            if (ppid == 1)
            {
                printf("%d\t%d\t%s\n", pid, ppid, comm);
            }

            fclose(f);
            print_processes(subpath);
        }
    }

    closedir(dir);
}