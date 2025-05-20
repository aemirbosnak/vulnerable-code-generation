//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

// Constants
#define MAX_PROC_PATH_LEN 256
#define MAX_PROC_NAME_LEN 32
#define MAX_PROC_CMDLINE_LEN 256

// Struct definitions
typedef struct {
    int pid;
    char name[MAX_PROC_NAME_LEN];
    char cmdline[MAX_PROC_CMDLINE_LEN];
} Process;

// Function prototypes
int is_proc_dir(const struct dirent *dirp);
char* read_proc_cmdline(const char* path);
char* trim(char* str);
int parse_pid_from_proc_path(const char* path);
int parse_process_info(const char* proc_path, Process* process);
void print_process_info(const Process* process);

int main() {
    DIR* proc_dir = opendir("/proc");
    if (!proc_dir) {
        printf("Error: Failed to open /proc directory. errno=%d\n", errno);
        exit(EXIT_FAILURE);
    }

    struct dirent** procs;
    int n = scandir("/proc", &procs, is_proc_dir, alphasort);
    if (n < 0) {
        printf("Error: Failed to scan /proc directory. errno=%d\n", errno);
        exit(EXIT_FAILURE);
    }

    printf("PID\tNAME\t\t\t\tCMDLINE\n");
    printf("===\t====\t\t\t\t=======\n");
    for (int i = 0; i < n; ++i) {
        // Parse process information
        char proc_path[MAX_PROC_PATH_LEN];
        sprintf(proc_path, "/proc/%s", procs[i]->d_name);
        Process process;
        if (!parse_process_info(proc_path, &process)) {
            // Failed to parse, skip
            continue;
        }

        // Print process information
        print_process_info(&process);
    }

    // Clean up
    for (int i = 0; i < n; ++i) {
        free(procs[i]);
    }
    free(procs);
    closedir(proc_dir);

    return EXIT_SUCCESS;
}

/**
 * Filters directory entries to only include directories whose names are integers (i.e., process directories).
 */
int is_proc_dir(const struct dirent *dirp) {
    if (dirp->d_type != DT_DIR) {
        return 0;
    }
    for (const char* p = dirp->d_name; *p; ++p) {
        if (!isdigit(*p)) {
            return 0;
        }
    }
    return 1;
}

/**
 * Reads the cmdline file for the process at the given path and returns its contents as a string.
 */
char* read_proc_cmdline(const char* path) {
    char cmdline_path[MAX_PROC_PATH_LEN];
    sprintf(cmdline_path, "%s/cmdline", path);

    FILE* f = fopen(cmdline_path, "r");
    if (!f) {
        printf("Error: Failed to read %s. errno=%d\n", cmdline_path, errno);
        return NULL;
    }

    // Allocate initial buffer
    size_t buf_size = MAX_PROC_CMDLINE_LEN;
    char* buf = (char*) malloc(buf_size);
    if (!buf) {
        printf("Error: Failed to allocate memory for cmdline buffer. errno=%d\n", errno);
        fclose(f);
        return NULL;
    }

    // Read and append cmdline file contents to buffer
    char* buf_pos = buf;
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (buf_pos - buf >= buf_size) {
            // Buffer is full, double its size
            buf_size *= 2;
            buf = (char*) realloc(buf, buf_size);
            if (!buf) {
                printf("Error: Failed to reallocate memory for cmdline buffer. errno=%d\n", errno);
                fclose(f);
                return NULL;
            }
            buf_pos = buf + strlen(buf);
        }
        *buf_pos++ = c;
    }

    // Trim trailing newline and null-terminate string
    buf_pos = trim(buf);
    *buf_pos = '\0';

    fclose(f);
    return buf;
}

/**
 * Trims leading and trailing whitespace from the given string and returns a pointer to the trimmed string.
 */
char* trim(char* str) {
    char* start = str;
    while (isspace(*start)) {
        ++start;
    }

    char* end = start + strlen(start) - 1;
    while (isspace(*end)) {
        --end;
    }
    *(end + 1) = '\0';

    return start;
}

/**
 * Parses the process ID from the given proc directory path.
 */
int parse_pid_from_proc_path(const char* path) {
    const char* pid_str = strrchr(path, '/');
    if (!pid_str || !isdigit(*(pid_str + 1))) {
        return -1;
    }
    return atoi(pid_str + 1);
}

/**
 * Parses process information from the given proc directory path and stores it in the given process struct.
 * Returns 1 on success, 0 on failure.
 */
int parse_process_info(const char* proc_path, Process* process) {
    // Parse PID from proc path
    process->pid = parse_pid_from_proc_path(proc_path);
    if (process->pid < 0) {
        return 0;
    }

    // Read process name from /proc/[pid]/comm
    char comm_path[MAX_PROC_PATH_LEN];
    sprintf(comm_path, "%s/comm", proc_path);
    FILE* f = fopen(comm_path, "r");
    if (!f) {
        // Failed to open file, skip
        return 0;
    }
    fgets(process->name, MAX_PROC_NAME_LEN, f);
    fclose(f);

    // Strip trailing newline from process name
    char* p = strrchr(process->name, '\n');
    if (p) {
        *p = '\0';
    }

    // Read cmdline file contents
    char* cmdline = read_proc_cmdline(proc_path);
    if (!cmdline) {
        // Failed to read cmdline, skip
        return 0;
    }
    strncpy(process->cmdline, cmdline, MAX_PROC_CMDLINE_LEN);
    free(cmdline);

    return 1;
}

/**
 * Prints the given process information in the format: "PID\tNAME\tCMDLINE".
 */
void print_process_info(const Process* process) {
    printf("%d\t%s\t%s\n", process->pid, process->name, process->cmdline);
}