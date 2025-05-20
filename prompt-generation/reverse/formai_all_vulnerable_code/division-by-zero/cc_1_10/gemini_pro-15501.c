//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    FILE *file;
    char line[1024];
    char *p;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    int total, used, idle2;

    while (1) {
        file = fopen("/proc/stat", "r");
        if (file == NULL) {
            perror("fopen");
            exit(1);
        }

        fgets(line, sizeof(line), file);
        fclose(file);

        p = strtok(line, " ");
        while (p != NULL) {
            if (strcmp(p, "cpu") == 0) {
                p = strtok(NULL, " ");
                user = atoi(p);
                p = strtok(NULL, " ");
                nice = atoi(p);
                p = strtok(NULL, " ");
                system = atoi(p);
                p = strtok(NULL, " ");
                idle = atoi(p);
                p = strtok(NULL, " ");
                iowait = atoi(p);
                p = strtok(NULL, " ");
                irq = atoi(p);
                p = strtok(NULL, " ");
                softirq = atoi(p);
                p = strtok(NULL, " ");
                steal = atoi(p);
            }
            p = strtok(NULL, " ");
        }

        total = user + nice + system + idle + iowait + irq + softirq + steal;
        used = total - idle;

        printf("CPU Usage: %d%%\r", (used * 100) / total);
        fflush(stdout);

        sleep(1);
    }

    return 0;
}