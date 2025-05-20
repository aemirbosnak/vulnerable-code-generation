//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc"
#define STATUS_FILE_SIZE 256
#define BUFFER_SIZE 1024

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // All spaces?
    if (*str == 0) return;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

void read_process_status(const char *pid) {
    char path[STATUS_FILE_SIZE];
    snprintf(path, sizeof(path), "%s/%s/status", PROC_PATH, pid);

    FILE *status_file = fopen(path, "r");
    if (status_file == NULL) {
        perror("Couldn't read process status");
        return;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), status_file) != NULL) {
        // Display relevant information
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "Pid:", 4) == 0 || 
            strncmp(line, "State:", 6) == 0) {
            trim_whitespace(line);
            printf("%s\n", line);
        }
    }

    fclose(status_file);
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_PATH);
    struct dirent *entry;

    if (proc_dir == NULL) {
        perror("Couldn't open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("PID\tName\tState\n");
    printf("-------------------------\n");
    
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (i.e., a PID)
            if (isdigit(entry->d_name[0])) {
                read_process_status(entry->d_name);
            }
        }
    }

    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-p") == 0) {
        if (argc > 2) {
            read_process_status(argv[2]);
        } else {
            fprintf(stderr, "Specify a PID after -p option.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        list_processes();
    }

    return 0;
}