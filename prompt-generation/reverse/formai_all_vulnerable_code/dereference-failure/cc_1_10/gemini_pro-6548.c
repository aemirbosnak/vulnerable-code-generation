//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// get current CPU usage in percentage
double get_cpu_usage() {
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    char* token = strtok(line, " ");
    if (token == NULL) {
        return -1;
    }

    long long user = 0, nice = 0, system = 0, idle = 0;
    for (int i = 0; i < 4; i++) {
        long long value = atoll(token);
        switch (i) {
            case 0:
                user = value;
                break;
            case 1:
                nice = value;
                break;
            case 2:
                system = value;
                break;
            case 3:
                idle = value;
                break;
        }
        token = strtok(NULL, " ");
    }

    double total = user + nice + system + idle;
    double usage = (total - idle) / total * 100;
    return usage;
}

int main() {
    double usage = get_cpu_usage();
    if (usage < 0) {
        printf("Error getting CPU usage\n");
        return 1;
    }

    printf("CPU usage: %.2f%%\n", usage);
    return 0;
}