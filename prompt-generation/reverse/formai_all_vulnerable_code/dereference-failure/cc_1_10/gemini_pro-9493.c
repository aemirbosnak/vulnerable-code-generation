//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Get process information
struct proc_info {
    pid_t pid;
    char *name;
    int state;
    long rss;
};

struct proc_info get_proc_info(pid_t pid) {
    struct proc_info info;
    char buf[256];
    FILE *fp;

    // Get process name
    snprintf(buf, sizeof(buf), "/proc/%d/comm", pid);
    fp = fopen(buf, "r");
    if (fp != NULL) {
        fscanf(fp, "%s", buf);
        info.name = strdup(buf);
        fclose(fp);
    }

    // Get process state
    snprintf(buf, sizeof(buf), "/proc/%d/stat", pid);
    fp = fopen(buf, "r");
    if (fp != NULL) {
        fscanf(fp, "%*d %s", buf);
        info.state = buf[0];
        fclose(fp);
    }

    // Get process RSS
    snprintf(buf, sizeof(buf), "/proc/%d/statm", pid);
    fp = fopen(buf, "r");
    if (fp != NULL) {
        fscanf(fp, "%ld", &info.rss);
        fclose(fp);
    }

    info.pid = pid;
    return info;
}

// Display process information
void display_proc_info(const struct proc_info *info) {
    printf("PID: %d\n", info->pid);
    printf("Name: %s\n", info->name);
    printf("State: %c\n", info->state);
    printf("RSS: %ld kB\n", info->rss / 1024);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = atoi(argv[1]);
    struct proc_info info = get_proc_info(pid);

    display_proc_info(&info);

    free(info.name);
    return EXIT_SUCCESS;
}