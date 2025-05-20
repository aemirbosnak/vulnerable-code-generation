//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024

char *read_file(const char *filename) {
    FILE *fp;
    char *buf = NULL;
    size_t len = 0;

    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: failed to open file %s\n", filename);
        exit(1);
    }

    buf = malloc(MAX_LINE_LEN);
    if (!buf) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        exit(1);
    }

    while (fgets(buf, MAX_LINE_LEN, fp)) {
        len += strlen(buf);
        buf = realloc(buf, len + MAX_LINE_LEN);
    }

    fclose(fp);
    return buf;
}

int main(int argc, char **argv) {
    char *config_file;
    char *boot_script;
    char *boot_cmd;
    int rc;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <config_file> <boot_script>\n", argv[0]);
        exit(1);
    }

    config_file = argv[1];
    boot_script = argv[2];

    config_file = realpath(config_file, NULL);
    boot_script = realpath(boot_script, NULL);

    rc = access(config_file, R_OK);
    if (rc!= 0) {
        fprintf(stderr, "Error: failed to access config file %s\n", config_file);
        exit(1);
    }

    rc = access(boot_script, X_OK);
    if (rc!= 0) {
        fprintf(stderr, "Error: failed to access boot script %s\n", boot_script);
        exit(1);
    }

    char *config_buf = read_file(config_file);
    char *boot_cmd_buf = strstr(config_buf, "BOOT_CMD=");
    if (!boot_cmd_buf) {
        fprintf(stderr, "Error: failed to find BOOT_CMD in config file %s\n", config_file);
        exit(1);
    }

    boot_cmd = strdup(boot_cmd_buf + strlen("BOOT_CMD="));

    printf("Config file: %s\n", config_file);
    printf("Boot script: %s\n", boot_script);
    printf("Boot command: %s\n", boot_cmd);

    rc = system(boot_cmd);
    if (rc!= 0) {
        fprintf(stderr, "Error: failed to execute boot command\n");
        exit(1);
    }

    return 0;
}