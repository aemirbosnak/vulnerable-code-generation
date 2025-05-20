//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#define MAX_PATH 256

void display_shocked_message() {
    printf("⚡️🚨 WOW! Look at all these running processes! 🚨⚡️\n");
    printf("Prepare yourself for an astonishing display of process IDs! 😱\n\n");
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    FILE *fp;
    char line[256];
    pid_t pid;

    if (!(dir = opendir("/proc"))) {
        perror("Cannot open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("🔥 Here we go! Scanning the /proc directory... 🔍\n");

    while ((entry = readdir(dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            pid = atoi(entry->d_name);
            snprintf(path, sizeof(path), "/proc/%d/stat", pid);
            fp = fopen(path, "r");
            if (fp) {
                if (fgets(line, sizeof(line), fp) != NULL) {
                    // Parse and display process info based on /proc/[pid]/stat structure
                    char comm[256];
                    sscanf(line, "%d (%[^)])", &pid, comm);
                    printf("👀 PID: %d - Command: %s\n", pid, comm);
                }
                fclose(fp);
            }
        }
    }
    closedir(dir);
    printf("\n✌️ Scanning complete! What a wild ride! 🎢\n");
}

int main() {
    display_shocked_message();
    list_processes();
    printf("🦄 Thank you for using the SHOCKING Process Viewer! 🎉\n");
    return 0;
}