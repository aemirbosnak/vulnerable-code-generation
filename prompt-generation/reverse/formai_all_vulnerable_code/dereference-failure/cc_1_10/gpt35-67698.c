//FormAI DATASET v1.0 Category: System boot optimizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100

char **get_boot_opts() {
    FILE *fp = fopen("/proc/cmdline", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/cmdline\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1) {
        fprintf(stderr, "Error reading /proc/cmdline\n");
        exit(EXIT_FAILURE);
    }

    char **tokens;
    const char delim[] = " ";
    int num_tokens = 0;
    char *token = strtok(line, delim);
    while (token != NULL) {
        num_tokens++;
        token = strtok(NULL, delim);
    }

    tokens = (char **) malloc(sizeof(char *) * (num_tokens + 1));
    memset(tokens, 0, sizeof(char *) * (num_tokens + 1));

    token = strtok(line, delim);
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    free(line);
    fclose(fp);

    return tokens;
}

void optimize_boot() {
    char **boot_opts = get_boot_opts();

    // Remove unnecessary options
    int i = 0;
    while (boot_opts[i] != NULL) {
        if (strstr(boot_opts[i], "quiet") != NULL) {
            boot_opts[i] = NULL;
        } else if (strstr(boot_opts[i], "splash") != NULL) {
            boot_opts[i] = NULL;
        } else if (strstr(boot_opts[i], "rhgb") != NULL) {
            boot_opts[i] = NULL;
        } else if (strstr(boot_opts[i], "quiet") != NULL) {
            boot_opts[i] = NULL;
        }
        i++;
    }

    // Rebuild new command line string
    char cmd_line[MAX_LINE_LENGTH] = "";
    i = 0;
    while (boot_opts[i] != NULL) {
        strcat(cmd_line, boot_opts[i]);
        strcat(cmd_line, " ");
        i++;
    }

    // Write new command line to bootloader config
    FILE *fp = fopen("/boot/grub/grub.cfg", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /boot/grub/grub.cfg for writing\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "set cmdline=\"%s\"\n", cmd_line);
    fclose(fp);

    // Reboot to apply changes
    printf("System optimized. Rebooting...\n");
    sleep(5);
    system("reboot");
}

int main() {
    printf("Beginning system boot optimization\n");
    optimize_boot();
    return 0;
}