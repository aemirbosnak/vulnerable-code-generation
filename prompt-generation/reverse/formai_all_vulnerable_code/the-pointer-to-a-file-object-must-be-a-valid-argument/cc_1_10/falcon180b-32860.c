//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define RAM_CHECK_INTERVAL 5000 // 5 seconds

typedef struct {
    unsigned long long total;
    unsigned long long available;
    unsigned long long used;
} MemInfo;

MemInfo get_mem_info() {
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[1024];
    MemInfo info = {0};

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %llu kB", &info.total);
        } else if (strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line, "MemAvailable: %llu kB", &info.available);
        }
    }

    info.used = info.total - info.available;

    fclose(fp);

    return info;
}

void *monitor_ram(void *arg) {
    while (true) {
        MemInfo info = get_mem_info();
        printf("Total RAM: %llu MB\n", info.total / 1024);
        printf("Available RAM: %llu MB\n", info.available / 1024);
        printf("Used RAM: %llu MB\n", info.used / 1024);
        printf("\n");

        sleep(RAM_CHECK_INTERVAL);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, monitor_ram, NULL)!= 0) {
        printf("Error creating thread\n");
        return 1;
    }

    while (true) {
        printf("Press any key to exit...\n");
        getchar();

        pthread_cancel(thread_id);
        pthread_join(thread_id, NULL);

        break;
    }

    return 0;
}