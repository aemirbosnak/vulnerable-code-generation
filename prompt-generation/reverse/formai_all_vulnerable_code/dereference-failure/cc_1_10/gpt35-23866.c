//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 1024
#define MAX_DIR_ENTRY_LENGTH 1024
#define MAX_STAT_FILE_LENGTH 4096

const char *STAT_PATH = "/proc/";

void print_process_info(char *pid) {
    char stat_file_path[MAX_NAME_LENGTH + strlen(STAT_PATH) + 1];
    char stat_content[MAX_STAT_FILE_LENGTH];
    FILE *stat_file = NULL;

    // Construct stat file path
    sprintf(stat_file_path, "%s%s/stat", STAT_PATH, pid);

    // Open stat file for reading
    stat_file = fopen(stat_file_path, "r");

    if (stat_file) {
        // Read stat file content
        fread(stat_content, 1, MAX_STAT_FILE_LENGTH, stat_file);

        // Extract command name from the stat file (first field)
        char *field_start = stat_content;
        char *command_name_start = NULL;
        char command_name[MAX_NAME_LENGTH];

        for (int i = 0; i < strlen(stat_content); i++) {
            if (*(field_start + i) == ' ') {
                if (!command_name_start) {
                    continue;
                }

                int field_length = i - (command_name_start - field_start);
                strncpy(command_name, command_name_start, field_length);
                command_name[field_length] = '\0';

                break;
            }

            if (*(field_start + i - 1) == ' ') {
                command_name_start = field_start + i;
            }
        }

        // Print process info
        printf("PID %s: %s\n", pid, command_name);

        // Close stat file
        fclose(stat_file);
    }
}

int is_pid(char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isdigit(*(name + i))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    DIR *proc_dir = opendir(STAT_PATH);
    struct dirent *entry = readdir(proc_dir);

    while (entry) {
        char *name = entry->d_name;

        if (is_pid(name)) {
            print_process_info(name);
        }

        entry = readdir(proc_dir);
    }

    closedir(proc_dir);

    return 0;
}