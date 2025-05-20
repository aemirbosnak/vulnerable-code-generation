//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    // Get the current working directory.
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() failed");
        return 1;
    }

    // Open the current working directory.
    DIR *dir = opendir(cwd);
    if (dir == NULL) {
        perror("opendir() failed");
        return 1;
    }

    // Read the directory entries.
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Get the process ID.
        int pid = atoi(entry->d_name);
        if (pid == 0) {
            continue;
        }

        // Get the process information.
        char path[1024];
        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        FILE *file = fopen(path, "r");
        if (file == NULL) {
            perror("fopen() failed");
            continue;
        }

        char line[1024];
        if (fgets(line, sizeof(line), file) == NULL) {
            perror("fgets() failed");
            fclose(file);
            continue;
        }

        fclose(file);

        // Parse the process information.
        char *fields[20];
        int num_fields = 0;
        char *field = strtok(line, " ");
        while (field != NULL) {
            fields[num_fields++] = field;
            field = strtok(NULL, " ");
        }

        // Print the process information.
        printf("%d %s (%s)\n", pid, fields[1], fields[2]);
    }

    // Close the directory.
    closedir(dir);

    return 0;
}