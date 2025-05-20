//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <signal.h>

#define BUF_SIZE 1024 // Buffer size
#define INTERVAL 5 // Interval in seconds

char *cpu_percent() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *result = NULL;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        return "Error: Failed to open /proc/stat";
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (strstr(line, "cpu ")) { // Find the line that starts with "cpu "
            char *token = strtok(line, " ");
            while (token!= NULL) {
                if (strcmp(token, "cpu") == 0) {
                    token = strtok(NULL, " ");
                    break;
                }
                token = strtok(NULL, " ");
            }
            if (token!= NULL) {
                result = strdup(token);
                break;
            }
        }
    }

    fclose(file);
    free(line);
    return result;
}

void print_cpu_usage(char *cpu_percent) {
    printf("CPU Usage: %s\n", cpu_percent);
}

void sigalrm_handler(int signum) {
    print_cpu_usage(cpu_percent());
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    alarm(INTERVAL);

    while (1) {
        print_cpu_usage(cpu_percent());
        sleep(1);
    }

    return 0;
}