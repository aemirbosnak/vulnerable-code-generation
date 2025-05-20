//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define CONF_FILE "ram_usage.conf"

typedef struct {
    uint64_t threshold;
    char *notification_cmd;
} config_t;

config_t config;

void read_config() {
    FILE *fp;
    char buf[256];

    fp = fopen(CONF_FILE, "r");
    if (fp == NULL) {
        perror("Error opening config file");
        exit(1);
    }

    while (fgets(buf, sizeof(buf), fp)) {
        if (buf[0] == '#') {
            continue;
        }

        char *key, *value;

        key = strtok(buf, "=");
        if (key == NULL) {
            fprintf(stderr, "Error parsing config file: invalid line '%s'\n", buf);
            exit(1);
        }

        value = strtok(NULL, "\n");
        if (value == NULL) {
            fprintf(stderr, "Error parsing config file: invalid line '%s'\n", buf);
            exit(1);
        }

        if (strcmp(key, "threshold") == 0) {
            config.threshold = strtoull(value, NULL, 10);
        } else if (strcmp(key, "notification_cmd") == 0) {
            config.notification_cmd = strdup(value);
        }
    }

    fclose(fp);
}

uint64_t get_ram_usage() {
    FILE *fp;
    char buf[256];
    uint64_t ram_usage;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(1);
    }

    while (fgets(buf, sizeof(buf), fp)) {
        if (buf[0] == 'M' && strstr(buf, "MemTotal") != NULL) {
            ram_usage = strtoull(buf, NULL, 10);
            break;
        }
    }

    fclose(fp);

    return ram_usage;
}

void check_ram_usage() {
    uint64_t ram_usage;

    ram_usage = get_ram_usage();

    if (ram_usage > config.threshold) {
        system(config.notification_cmd);
    }
}

int main() {
    read_config();

    check_ram_usage();

    return 0;
}