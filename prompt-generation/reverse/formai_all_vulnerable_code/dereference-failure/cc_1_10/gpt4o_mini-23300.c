//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>

#define LOG_FILE "system_admin.log"
#define MAX_LOG_SIZE 512

void log_action(const char *action) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        time_t now;
        time(&now);
        fprintf(log_file, "[%s] %s\n", ctime(&now), action);
        fclose(log_file);
    } else {
        perror("Could not open log file");
    }
}

void display_directory_contents(const char *dir_name) {
    struct dirent *de;
    DIR *dr = opendir(dir_name);
    
    if (dr == NULL) {
        log_action("Failed to open directory");
        perror("Could not open directory");
        return;
    }

    printf("Contents of directory '%s':\n", dir_name);
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    log_action("Displayed directory contents");
}

void create_file(const char *file_name, const char *content) {
    FILE *file = fopen(file_name, "w");
    
    if (!file) {
        log_action("Failed to create file");
        perror("Could not create file");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
    log_action("File created successfully");
}

void read_file(const char *file_name) {
    char buffer[MAX_LOG_SIZE];
    FILE *file = fopen(file_name, "r");
    
    if (!file) {
        log_action("Failed to read file");
        perror("Could not read file");
        return;
    }

    printf("Contents of '%s':\n", file_name);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
    log_action("File read successfully");
}

void delete_file(const char *file_name) {
    if (remove(file_name) == 0) {
        log_action("File deleted successfully");
    } else {
        log_action("Failed to delete file");
        perror("Could not delete file");
    }
}

void create_directory(const char *dir_name) {
    if (mkdir(dir_name, 0755) == 0) {
        log_action("Directory created successfully");
    } else {
        log_action("Failed to create directory");
        perror("Could not create directory");
    }
}

void display_system_info() {
    printf("System Information:\n");
    printf("Hostname: ");
    system("hostname");
    log_action("Displayed system information");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [options]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "listdir") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s listdir <directory_name>\n", argv[0]);
            return 1;
        }
        display_directory_contents(argv[2]);
    } 
    else if (strcmp(argv[1], "createfile") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s createfile <file_name> <content>\n", argv[0]);
            return 1;
        }
        create_file(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "readfile") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s readfile <file_name>\n", argv[0]);
            return 1;
        }
        read_file(argv[2]);
    }
    else if (strcmp(argv[1], "deletefile") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s deletefile <file_name>\n", argv[0]);
            return 1;
        }
        delete_file(argv[2]);
    }
    else if (strcmp(argv[1], "createdir") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s createdir <directory_name>\n", argv[0]);
            return 1;
        }
        create_directory(argv[2]);
    }
    else if (strcmp(argv[1], "sysinfo") == 0) {
        display_system_info();
    } 
    else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}