//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define CONFIG_FILE "/etc/myconfig.txt"

void print_usage() {
    printf("Usage: sysadmin_tool [options]\n");
    printf("Options:\n");
    printf("  -l               List all files in the config directory\n");
    printf("  -c [command]     Execute a system command\n");
    printf("  -r [filename]    Read a specified file\n");
    printf("  -w [filename]    Write to a specified file\n");
    printf("  -h               Show this help message\n");
}

void list_config_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void execute_command(const char *command) {
    int status = system(command);
    if (status == -1) {
        perror("system");
    }
}

void read_file(const char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_file(const char *filename) {
    char input[BUFFER_SIZE];
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    printf("Enter text to write to the file (CTRL+D to finish):\n");

    while (fgets(input, BUFFER_SIZE, stdin) != NULL) {
        fputs(input, file);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "-l") == 0) {
        printf("Listing configuration files:\n");
        list_config_files("/etc/");
    } else if (strcmp(argv[1], "-c") == 0 && argc == 3) {
        printf("Executing command: %s\n", argv[2]);
        execute_command(argv[2]);
    } else if (strcmp(argv[1], "-r") == 0 && argc == 3) {
        printf("Reading file: %s\n", argv[2]);
        read_file(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0 && argc == 3) {
        printf("Writing to file: %s\n", argv[2]);
        write_file(argv[2]);
    } else if (strcmp(argv[1], "-h") == 0) {
        print_usage();
    } else {
        fprintf(stderr, "Invalid option or missing argument.\n");
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}