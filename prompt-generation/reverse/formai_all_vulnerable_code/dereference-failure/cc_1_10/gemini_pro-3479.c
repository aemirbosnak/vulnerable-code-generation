//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main()
{
    // Get list of running processes
    FILE *fp = popen("ps -ef", "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }

    // Read each line of output
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse line into fields
        char *fields[10];
        int num_fields = 0;
        char *field = strtok(line, " ");
        while (field != NULL) {
            fields[num_fields++] = field;
            field = strtok(NULL, " ");
        }

        // Get process information
        int pid = atoi(fields[1]);
        char *user = fields[0];
        char *group = fields[1];
        char *state = fields[7];
        char *cpu_time = fields[10];
        char *mem_usage = fields[11];
        char *command = fields[12];

        // Get user and group names
        struct passwd *pw = getpwuid(pid);
        struct group *gr = getgrgid(pid);

        // Get process creation time
        time_t creation_time = atol(fields[8]);
        struct tm *tm = localtime(&creation_time);

        // Print process information
        printf("PID: %d\n", pid);
        printf("User: %s (%d)\n", pw->pw_name, pw->pw_uid);
        printf("Group: %s (%d)\n", gr->gr_name, gr->gr_gid);
        printf("State: %s\n", state);
        printf("CPU Time: %s\n", cpu_time);
        printf("Memory Usage: %s\n", mem_usage);
        printf("Command: %s\n", command);
        printf("Creation Time: %s\n\n", asctime(tm));
    }

    // Close file
    pclose(fp);

    return 0;
}