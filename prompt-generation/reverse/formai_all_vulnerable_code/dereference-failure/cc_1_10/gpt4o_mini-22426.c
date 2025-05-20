//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define BUFFER_SIZE 256

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

int is_digit_string(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void display_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIR, pid);
    FILE *stat_file = fopen(path, "r");
    if (stat_file) {
        int pid_num;
        char comm[BUFFER_SIZE];
        char state;
        unsigned long utime, stime;

        fscanf(stat_file, "%d %s %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", 
               &pid_num, comm, &state, &utime, &stime);
        fclose(stat_file);
        
        // Remove parentheses from command name
        trim_newline(comm);
        
        printf("PID: %d, Command: %s, State: %c, User Time: %lu, System Time: %lu\n",
               pid_num, comm, state, utime, stime);
    } else {
        fprintf(stderr, "Error reading process stats for PID %s\n", pid);
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir(PROC_DIR);
    
    if (!proc_dir) {
        fprintf(stderr, "Could not open proc directory.\n");
        return;
    }
    
    while ((entry = readdir(proc_dir))) {
        if (is_digit_string(entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }
    
    closedir(proc_dir);
}

int main(int argc, char *argv[]) {
    printf("Introspective Process Viewer\n");
    printf("============================\n");
    
    list_processes();

    printf("\nTotal processes displayed.\n");
    return 0;
}