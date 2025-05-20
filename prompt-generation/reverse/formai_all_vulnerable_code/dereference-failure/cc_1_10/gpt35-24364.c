//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

struct sys_info {
    long total_ram;
    long free_ram;
};

void get_system_info(struct sys_info* si) {
    struct sysinfo info;
    sysinfo(&info);
    si->total_ram = info.totalram;
    si->free_ram = info.freeram;
}

int main(int argc, char* argv[]) {
    struct sys_info si;
    char* config_file = NULL;
    int interval = 1;
    int i;

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
                config_file = argv[i + 1];
                i++;
            }
            else if (strcmp(argv[i], "-i") == 0 && i + 1< argc) {
                interval = atoi(argv[i + 1]);
                i++;
            }
        }
    }

    if (config_file == NULL) {
        printf("Usage: %s -c CONFIG_FILE [-i INTERVAL]\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(config_file, "r");
    if (f == NULL) {
        printf("Failed to read config file.\n");
        return 1;
    }

    char line[512];
    char* key;
    char* value;
    int found;
    int threshold = 90;

    while (fgets(line, sizeof(line), f)) {
        key = strtok(line, "=");
        value = strtok(NULL, "=");

        if (strcmp(key, "threshold") == 0) {
            threshold = atoi(value);
        }
    }

    fclose(f);

    while (1) {
        get_system_info(&si);
        int usage = 100 - si.free_ram * 100 / si.total_ram;
        printf("RAM usage: %d%%\n", usage);

        if (usage >= threshold) {
            printf("RAM usage above threshold! Free up some memory!\n");
        }

        sleep(interval);
    }

    return 0;
}