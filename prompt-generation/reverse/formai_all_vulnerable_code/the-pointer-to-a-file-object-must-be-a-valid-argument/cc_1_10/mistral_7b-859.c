//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CONFIG_FILE "config.txt"
#define BUFFER_SIZE 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct ConfigEntry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} ConfigEntry;

void read_config_file(ConfigEntry config[], int *num_entries) {
    int file_fd, num_read = 0;
    char buffer[BUFFER_SIZE];
    char key[MAX_KEY_LENGTH], value[MAX_VALUE_LENGTH];

    file_fd = open(CONFIG_FILE, O_RDONLY);
    if (file_fd < 0) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, file_fd) != NULL) {
        sscanf(buffer, "%s=%s", key, value);
        if (num_read < *num_entries) {
            strcpy(config[num_read].key, key);
            strcpy(config[num_read].value, value);
            num_read++;
        } else {
            fprintf(stderr, "Too many entries in config file\n");
            exit(EXIT_FAILURE);
        }
    }

    close(file_fd);
    *num_entries = num_read;
}

void write_config_file(ConfigEntry config[], int num_entries) {
    int file_fd, i;
    char buffer[BUFFER_SIZE];

    file_fd = open(CONFIG_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file_fd < 0) {
        perror("Failed to open or create config file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_entries; i++) {
        sprintf(buffer, "%s=%s\n", config[i].key, config[i].value);
        write(file_fd, buffer, strlen(buffer));
    }

    close(file_fd);
}

int main() {
    ConfigEntry config[128];
    int num_entries = 0;

    if (access(CONFIG_FILE, F_OK) != -1) {
        read_config_file(config, &num_entries);

        // Perform some paranoid checks on the configuration data here...

        write_config_file(config, num_entries);
    } else {
        printf("Config file does not exist, creating new one...\n");
        write_config_file(config, 0);
    }

    return EXIT_SUCCESS;
}