//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_VARS 50
#define MAX_LINE_LENGTH 1024
#define CONFIG_FILE "config.txt"

char *env_vars[MAX_VARS];
char line[MAX_LINE_LENGTH];
char *token;
char *delim = "=";

void read_config_file() {
    FILE *config_file = fopen(CONFIG_FILE, "r");
    if (config_file == NULL) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, config_file) != NULL) {
        token = strtok(line, delim);
        env_vars[i] = malloc(strlen(token) + 1);
        strcpy(env_vars[i], token);
        i++;
    }

    fclose(config_file);
}

void set_env_variables() {
    int i;
    for (i = 0; i < MAX_VARS; i++) {
        if (getenv(env_vars[i]) == NULL) {
            setenv(env_vars[i], "value", 1);
            printf("Setting environment variable %s\n", env_vars[i]);
        }
    }
}

void check_disk_space() {
    struct stat fs_stats;
    char *mount_point = "/";

    if (stat(mount_point, &fs_stats) == -1) {
        perror("Error getting filesystem stats for /");
        exit(EXIT_FAILURE);
    }

    long long used = fs_stats.st_size;
    long long total = fs_stats.st_blksize * fs_stats.st_blocks;
    float percentage_used = (used * 100.0) / total;

    printf("Disk usage:\n");
    printf("- Total: %lld bytes\n", total);
    printf("- Used: %lld bytes\n", used);
    printf("- Used percentage: %.2f%%\n", percentage_used);
}

int main() {
    read_config_file();
    set_env_variables();
    check_disk_space();

    int i;
    for (i = 0; i < MAX_VARS; i++) {
        free(env_vars[i]);
    }

    return EXIT_SUCCESS;
}