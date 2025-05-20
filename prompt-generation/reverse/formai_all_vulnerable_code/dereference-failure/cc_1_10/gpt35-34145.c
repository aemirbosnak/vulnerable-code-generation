//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <dirent.h>  
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_PID_LENGTH 10
#define MAX_PROCESS_NAME_LENGTH 1024

struct ProcessInfo {
    char pid[MAX_PID_LENGTH];
    char name[MAX_PROCESS_NAME_LENGTH];
    char state;
};

// helper function for parsing fields from proc stat file
char* get_next_field(char* buffer) {
  while (*buffer != '\0' && isspace(*buffer)) {
    ++buffer;
  }
  char* field_start = buffer;
  while (*buffer != '\0' && !isspace(*buffer)) {
    ++buffer;
  }
  if (*buffer != '\0') {
    *buffer++ = '\0';
  }
  return field_start;
}

void print_process_info(struct ProcessInfo* process_info) {
    printf("%s\t%c\t%s\n", process_info->pid, process_info->state, process_info->name);
}

int main() {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // skip any non-directory entries (e.g. "." and "..")
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // check if the directory name is a valid PID
        char* endptr;
        int pid = strtol(entry->d_name, &endptr, 10);
        if (*endptr != '\0') {
            continue;
        }

        // read the process status file for this PID
        char status_path[MAX_PATH];
        snprintf(status_path, MAX_PATH, "/proc/%d/stat", pid);
        FILE* status_file = fopen(status_path, "r");
        if (status_file == NULL) {
            continue;
        }

        // parse the fields we care about from the status file
        char buffer[MAX_PATH];
        if (fgets(buffer, MAX_PATH, status_file) == NULL) {
            fclose(status_file);
            continue;
        }
        fclose(status_file);

        struct ProcessInfo process_info = {
            .state = '?'
        };
        char* next_field = buffer;
        next_field = get_next_field(next_field); // skip PID field
        next_field = get_next_field(next_field); // skip process name in parentheses
        strncpy(process_info.name, next_field, MAX_PROCESS_NAME_LENGTH);
        next_field = get_next_field(next_field); // skip state field
        process_info.state = *next_field; // get state field
        snprintf(process_info.pid, MAX_PID_LENGTH, "%d", pid);

        // print out the process info
        print_process_info(&process_info);
        
        usleep(50000); // sleep for 50ms to reduce strain on CPU
    }

    closedir(proc_dir);
    return 0;
}