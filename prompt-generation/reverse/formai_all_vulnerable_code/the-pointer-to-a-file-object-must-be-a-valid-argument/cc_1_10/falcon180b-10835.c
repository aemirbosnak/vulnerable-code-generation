//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

// Function to calculate current RAM usage
long long int get_ram_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[100];
    long long int ram_usage = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "MemTotal")!= NULL) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                ram_usage += atoll(token);
                token = strtok(NULL, " ");
            }
            break;
        }
    }
    fclose(file);
    return ram_usage;
}

// Function to print current RAM usage
void print_ram_usage(long long int ram_usage) {
    double ram_usage_mb = (double)ram_usage / (1024 * 1024);
    printf("Current RAM usage: %.2f MB\n", ram_usage_mb);
}

// Function to monitor RAM usage and print it every 10 seconds
void *monitor_ram_usage(void *arg) {
    while (TRUE) {
        long long int ram_usage = get_ram_usage();
        print_ram_usage(ram_usage);
        sleep(10);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    int ret = pthread_create(&thread_id, NULL, monitor_ram_usage, NULL);
    if (ret!= 0) {
        printf("Error creating thread: %d\n", ret);
        return 1;
    }
    printf("RAM usage monitoring started...\n");
    return 0;
}