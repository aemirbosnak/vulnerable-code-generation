//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_VIRUS_DEFINITIONS 10
#define BUFFER_SIZE 1024

// Struct to hold virus signatures
typedef struct {
    char name[MAX_PATH_LENGTH];
} VirusSignature;

// Initialize some virus signatures
VirusSignature signatures[MAX_VIRUS_DEFINITIONS] = {
    {"EICAR-Test-Signature"},
    {"Win32.Broken.I"},
    {"Trojan:Win32/Wecorl.A"},
    {"W32/Bagle.F"},
    {"W32/Mytob.A"},
    {"Win32/Cryptic.A"},
    {"Trojan-Downloader.Win32.Small"},
    {"W32/Sasser.B"},
    {"W32/MyDoom.A"},
    {"W32/Rbot.gen"}
};

void scan_file(const char *file_path, FILE *logfile) {
    FILE *file = fopen(file_path, "r");
    char buffer[BUFFER_SIZE];
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    // Read file byte by byte searching for virus signatures
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < MAX_VIRUS_DEFINITIONS; i++) {
            if (strstr(buffer, signatures[i].name) != NULL) {
                fprintf(logfile, "Virus detected in: %s - Virus: %s\n", file_path, signatures[i].name);
                printf("🚨 Virus detected! 🚨 -> %s in %s\n", signatures[i].name, file_path);
                fclose(file);
                return;
            }
        }
    }
    fclose(file);
    printf("✅ No virus found in: %s\n", file_path);
}

void scan_directory(const char *dir_path, FILE *logfile) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_PATH_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            scan_file(file_path, logfile);
        }
        else if (entry->d_type == DT_DIR) { // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir_path[MAX_PATH_LENGTH];
                snprintf(sub_dir_path, sizeof(sub_dir_path), "%s/%s", dir_path, entry->d_name);
                scan_directory(sub_dir_path, logfile);
            }
        }
    }
    closedir(dp);
}

void print_welcome_message() {
    printf("🌟 Welcome to the C AntiVirus Scanner! 🌟\n");
    printf("🛡️ Protecting your system by scanning for viruses! 🛡️\n");
}

void print_goodbye_message() {
    printf("🎉 Scan completed! 🎉\n");
    printf("Stay safe and secure! 🛡️\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_welcome_message();

    // Create a log file to store results
    FILE *logfile = fopen("scan_log.txt", "w");
    if (logfile == NULL) {
        perror("Could not create log file");
        return EXIT_FAILURE;
    }

    // Start scanning
    scan_directory(argv[1], logfile);

    fclose(logfile);
    print_goodbye_message();

    return EXIT_SUCCESS;
}