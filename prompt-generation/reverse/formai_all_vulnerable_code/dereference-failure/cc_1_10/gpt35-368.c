//FormAI DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

char* get_process_name(char* pid) {
    DIR* dir;
    struct dirent* ent;
    char* cmdl_path = malloc(strlen("/proc/") + strlen(pid) + strlen("/cmdline") + 1);

    // create path to cmdline file for process
    strcpy(cmdl_path, "/proc/");
    strcat(cmdl_path, pid);
    strcat(cmdl_path, "/cmdline");

    // open cmdl_path and read contents
    FILE* cmdl_file = fopen(cmdl_path, "r");
    size_t cmdl_size = 1024;
    char* cmdl_buf = malloc(cmdl_size);
    fgets(cmdl_buf, cmdl_size, cmdl_file);

    // strip any newline characters from buffer
    char* newline = strchr(cmdl_buf, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    // get name of process from cmdline
    char* name = strrchr(cmdl_buf, '/');
    if (name == NULL) {
        name = cmdl_buf;
    } else {
        name = name + 1;
    }

    fclose(cmdl_file);
    free(cmdl_path);
    free(cmdl_buf);

    return name;
}

void print_process_info(char* pid) {
    // print basic info about process
    printf("PID: %s\n", pid);

    // get name of process from cmdline
    char* name = get_process_name(pid);
    printf("Name: %s\n", name);
    free(name);

    // get status of process
    char* status_path = malloc(strlen("/proc/") + strlen(pid) + strlen("/status") + 1);
    strcpy(status_path, "/proc/");
    strcat(status_path, pid);
    strcat(status_path, "/status");

    FILE* status_file = fopen(status_path, "r");
    if (status_file == NULL) {
        perror("Error opening status file");
        return;
    }

    // read file line by line and print relevant info
    char* line = NULL;
    size_t len = 0;
    while (getline(&line, &len, status_file) != -1) {
        if (strstr(line, "Uid:") != NULL) {
            // get user ID
            char* uid_start = strchr(line, '\t') + 1;
            char* uid_end = strchr(uid_start, '\t');
            *uid_end = '\0';

            // make sure UID is valid and print info
            if (isdigit(uid_start[0])) {
                printf("UID: %s\n", uid_start);
            } else {
                printf("UID: <Unknown>\n");
            }
        } else if (strstr(line, "VmRSS:") != NULL) {
            // get resident set size (i.e. amount of memory used by process)
            char* rss_start = strchr(line, ':') + 2;
            char* rss_end = strchr(rss_start, ' ');
            *rss_end = '\0';

            // convert RSS to kilobytes and print info
            int rss = atoi(rss_start);
            printf("RSS: %d KB\n", rss);
        }
    }

    fclose(status_file);
    free(status_path);
    free(line);

    printf("\n");
}

int main() {
    DIR* proc_dir;
    struct dirent* proc_ent;

    // open directory for reading
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc directory");
        return 1;
    }

    // loop through contents of /proc directory
    while ((proc_ent = readdir(proc_dir)) != NULL) {
        // check if entry is a directory and its name is a number (i.e. it's a process ID)
        if (proc_ent->d_type == DT_DIR && isdigit(proc_ent->d_name[0])) {
            // print info for process
            print_process_info(proc_ent->d_name);
        }
    }

    closedir(proc_dir);
    return 0;
}