//FormAI DATASET v1.0 Category: System process viewer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <ctype.h>

#define MAX_PID 32768
#define CMD_MAX_SIZE 256

struct process_info {
    char cmd[CMD_MAX_SIZE];
    uid_t uid;
    pid_t pid;
    int vsize;
    long int rss;
};

int main()
{
    struct process_info *processes = malloc(MAX_PID * sizeof(struct process_info));
    int num_processes = 0;

    DIR *dirp;
    struct dirent *dir_entry;
    char process_path[32], proc_cmd[CMD_MAX_SIZE];
    uid_t uid;
    pid_t pid;
    int i;
    long int rss;
    char *user_name;

    dirp = opendir("/proc");
    if (dirp) {
        while ((dir_entry = readdir(dirp))) {
            if (isdigit(dir_entry->d_name[0])) { // Check if directory name is a PID
                pid = (pid_t)atoi(dir_entry->d_name);
                snprintf(process_path, 31, "/proc/%d/cmdline", pid);

                FILE *cmd_file = fopen(process_path, "r");
                if (cmd_file) {
                    fread(proc_cmd, CMD_MAX_SIZE, 1, cmd_file);
                    fclose(cmd_file);

                    // Remove trailing newline characters
                    for (i = 0; i < strlen(proc_cmd); i++) {
                        if (proc_cmd[i] == '\n' || proc_cmd[i] == '\0') {
                            proc_cmd[i] = '\0';
                            break;
                        }
                    }

                    struct stat stat_buf;
                    snprintf(process_path, 31, "/proc/%d", pid);
                    stat(process_path, &stat_buf);
                    rss = stat_buf.st_size / 1024; // Get RSS in kilobytes

                    // Get the UID of the process
                    struct passwd *pw = getpwuid(stat_buf.st_uid);
                    if (pw) {
                        uid = pw->pw_uid;
                        user_name = pw->pw_name;
                    } else {
                        uid = stat_buf.st_uid;
                        user_name = "";
                    }

                    // Store process info in processes array
                    strncpy(processes[num_processes].cmd, proc_cmd, CMD_MAX_SIZE);
                    processes[num_processes].pid = pid;
                    processes[num_processes].uid = uid;
                    processes[num_processes].vsize = 0; // Not implemented
                    processes[num_processes].rss = rss;
                    num_processes++;
                }
            }
        }
        closedir(dirp);
    }

    // Output process info
    printf("%-10s %-8s %-8s %-8s %s\n", "USER", "PID", "RSS", "VSZ", "COMMAND");
    for (i = 0; i < num_processes; i++) {
        printf("%-10s %-8d %-8ld %-8d %s\n", user_name, processes[i].pid, processes[i].rss, processes[i].vsize, processes[i].cmd);
    }

    free(processes);
    return 0;
}