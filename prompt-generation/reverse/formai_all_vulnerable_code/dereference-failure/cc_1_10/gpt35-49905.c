//FormAI DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Function to check if a string is an integer
int is_integer(const char *str)
{
    if (*str == '+' || *str == '-')
        str++;

    while(*str) {
        if(!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

// Function to print the process info with the given pid
void print_process_info(const char *pid)
{
    char path[50];
    FILE *fp;

    // Open the stat file for the given pid
    sprintf(path, "/proc/%s/stat", pid);
    fp = fopen(path, "r");

    if (fp != NULL)
    {
        char stat[255];
        fgets(stat, 255, fp);
        fclose(fp);

        // Retrieve the process name from the stat file
        char *start_brace = strrchr(stat, '(') + 1;
        char *end_brace = strrchr(stat, ')');

        // Format the process info and print it
        printf("%-10s %-10s\n", pid, strtok(start_brace, " "));
    }
}

int main(int argc, char *argv[])
{
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    // Print the table header
    printf("%-10s %-10s\n", "PID", "NAME");

    // Loop through all entries in the /proc directory
    while ((entry = readdir(dir)) != NULL)
    {
        if (is_integer(entry->d_name))
        {
            // If the current entry is a valid pid, print its info
            print_process_info(entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}