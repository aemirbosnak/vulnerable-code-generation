//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 32

typedef struct proc_info {
    pid_t pid;
    char *name;
    char *path;
    int status;
    struct proc_info *next;
} proc_info;

proc_info *head = NULL;

void add_proc(proc_info *p) {
    if (head == NULL) {
        head = p;
    } else {
        proc_info *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = p;
    }
}

void free_proc(proc_info *p) {
    free(p->name);
    free(p->path);
    free(p);
}

void free_proc_list() {
    proc_info *curr = head;
    while (curr != NULL) {
        proc_info *next = curr->next;
        free_proc(curr);
        curr = next;
    }
    head = NULL;
}

proc_info *get_proc_info(pid_t pid) {
    char proc_path[256];
    sprintf(proc_path, "/proc/%d", pid);

    proc_info *p = (proc_info *)malloc(sizeof(proc_info));
    p->pid = pid;

    char buf[1024];
    int fd;

    // Get process name
    sprintf(proc_path, "/proc/%d/comm", pid);
    fd = open(proc_path, O_RDONLY);
    if (fd != -1) {
        read(fd, buf, sizeof(buf));
        buf[strcspn(buf, "\n")] = 0;
        p->name = (char *)malloc(strlen(buf) + 1);
        strcpy(p->name, buf);
        close(fd);
    }

    // Get process path
    sprintf(proc_path, "/proc/%d/exe", pid);
    fd = open(proc_path, O_RDONLY | O_NOFOLLOW);
    if (fd != -1) {
        readlink(proc_path, buf, sizeof(buf));
        buf[strcspn(buf, "\n")] = 0;
        p->path = (char *)malloc(strlen(buf) + 1);
        strcpy(p->path, buf);
        close(fd);
    }

    // Get process status
    sprintf(proc_path, "/proc/%d/status", pid);
    fd = open(proc_path, O_RDONLY);
    if (fd != -1) {
        char *line;
        while ((line = fgets(buf, sizeof(buf), fd)) != NULL) {
            if (strncmp(line, "State:", 6) == 0) {
                char *state = line + 7;
                p->status = state[0];
                break;
            }
        }
        close(fd);
    }

    return p;
}

void print_proc_info(proc_info *p) {
    printf("%d %s %s %c\n", p->pid, p->name, p->path, p->status);
}

void print_proc_list() {
    proc_info *curr = head;
    while (curr != NULL) {
        print_proc_info(curr);
        curr = curr->next;
    }
}

int main(int argc, char *argv[]) {
    // Get all process IDs
    DIR *procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("opendir");
        return -1;
    }

    struct dirent *dp;
    while ((dp = readdir(procdir)) != NULL) {
        if (dp->d_type == DT_DIR && atoi(dp->d_name) > 0) {
            proc_info *p = get_proc_info(atoi(dp->d_name));
            add_proc(p);
        }
    }
    closedir(procdir);

    // Print process list
    print_proc_list();

    // Free process list
    free_proc_list();

    return 0;
}