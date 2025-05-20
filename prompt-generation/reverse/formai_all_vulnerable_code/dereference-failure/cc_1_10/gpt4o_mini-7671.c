//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define MAX_PATH 1024

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s - %s\n", msg, strerror(errno));
}

void list_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        print_error("Unable to open directory");
        return;
    }

    printf("Listing files in directory: %s\n", path);
    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        print_error("Failed to create file");
        return;
    }
    fprintf(file, "This is a test file: %s\n", filename);
    fclose(file);
    printf("File created: %s\n", filename);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted: %s\n", filename);
    } else {
        print_error("Failed to delete file");
    }
}

void monitor_directory(const char *path) {
    printf("\nMonitoring directory: %s\nPress Ctrl+C to stop.\n", path);
    while (1) {
        list_directory(path);
        sleep(2); // Sleep before next listing to avoid flooding
    }
}

void display_help() {
    printf("Welcome to the Simple File Manager.\n");
    printf("Available commands:\n");
    printf("1. list <path> - Lists all files in a directory.\n");
    printf("2. create <filename> - Creates a new file with example content.\n");
    printf("3. delete <filename> - Deletes a specified file.\n");
    printf("4. monitor <path> - Monitors and lists a directory continuously.\n");
    printf("5. help - Displays this help information.\n");
    printf("6. exit - Exits the program.\n");
}

int main() {
    char command[128];
    char arg[MAX_PATH];

    printf("=== Simple File Manager ===\n");

    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        
        if (sscanf(command, "list %s", arg) == 1) {
            list_directory(arg);
        } else if (sscanf(command, "create %s", arg) == 1) {
            create_file(arg);
        } else if (sscanf(command, "delete %s", arg) == 1) {
            delete_file(arg);
        } else if (sscanf(command, "monitor %s", arg) == 1) {
            monitor_directory(arg);
            break;  // Exit after monitor command (infinite loop)
        } else if (strcmp(command, "help\n") == 0) {
            display_help();
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting Simple File Manager. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    return 0;
}