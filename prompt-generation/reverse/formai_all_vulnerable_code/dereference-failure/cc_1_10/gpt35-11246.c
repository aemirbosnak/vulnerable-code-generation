//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

void print_usage(long int usage) {
    printf("Current RAM usage: ");
    if (usage < KB) printf("%ld bytes\n", usage);
    else if (usage < MB) printf("%ld KB\n", usage/KB);
    else if (usage < GB) printf("%ld MB\n", usage/MB);
    else printf("%ld GB\n", usage/GB);
}

long int get_ram_usage(void) {
    long int pid = getpid();

    char command[50];
    sprintf(command, "cat /proc/%ld/status | grep VmRSS | awk '{print $2}'", pid);

    FILE* file = popen(command, "r");
    if (!file) {
        printf("Error while reading /proc/%ld/status file\n", pid);
        exit(1);
    }

    char usage_str[50];
    fgets(usage_str, 50, file);
    long int usage = strtol(usage_str, NULL, 10) * KB;

    pclose(file);

    return usage;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interval_in_seconds>\n", argv[0]);
        exit(1);
    }

    int interval = atoi(argv[1]);

    while (1) {
        long int usage = get_ram_usage();
        print_usage(usage);
        sleep(interval);
    }

    return 0;
}