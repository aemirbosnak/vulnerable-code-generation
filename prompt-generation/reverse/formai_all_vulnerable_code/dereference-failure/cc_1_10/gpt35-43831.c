//FormAI DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIR "/proc"

int is_number(const char *s)
{
    // check if a string is a number
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

void print_proc_info(const char *pid, const char *name)
{
    char file_path[100];
    snprintf(file_path, sizeof(file_path), PROC_DIR "/%s/status", pid);

    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        return;
    }

    char line[256];
    char *mem_kb = NULL;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Name:"))
        {
            printf("%-10s: %s", "Name", name);
            continue;
        }

        if (strstr(line, "VmRSS:"))
        {
            mem_kb = strchr(line, ':') + 1;
            printf("%-10s: %s", "Memory", mem_kb);
            break;
        }
    }
    if (mem_kb == NULL)
    {
        printf("%-10s: %s", "Memory", "Unknown");
    }

    fclose(file);
}

int main()
{
    DIR *dir = opendir(PROC_DIR);
    if (!dir)
    {
        printf("Unable to open " PROC_DIR);
        return EXIT_FAILURE;
    }

    // print the header
    printf("%-10s %-15s %s\n", "PID", "Name", "Memory");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (!is_number(entry->d_name))
        {
            continue;
        }

        char file_path[100];
        snprintf(file_path, sizeof(file_path), PROC_DIR "/%s/stat", entry->d_name);

        FILE *file = fopen(file_path, "r");
        if (file == NULL)
        {
            continue;
        }

        char name[256];
        char pid[10];
        fscanf(file, "%s %s", pid, name);
        fclose(file);

        // trim parentheses from the name
        size_t len = strlen(name);
        if (name[0] == '(' && name[len - 1] == ')')
        {
            name[len - 1] = '\0';
            memmove(name, &name[1], len - 1);
        }

        print_proc_info(entry->d_name, name);
        printf("\n");
    }

    closedir(dir);
    return EXIT_SUCCESS;
}