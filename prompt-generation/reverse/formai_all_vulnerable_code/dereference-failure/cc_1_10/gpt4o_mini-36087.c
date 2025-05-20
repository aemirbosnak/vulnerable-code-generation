//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define VIRUS_SIGNATURE "VIRUS123"
#define BUFFER_SIZE 1024

void scan_file(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Could not open file %s for scanning. Skipping...\n", filepath);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, VIRUS_SIGNATURE)) {
            printf("🚨 Virus found in file: %s\n", filepath);
            fclose(file);
            return;
        }
    }
    printf("✅ No virus found in file: %s\n", filepath);
    fclose(file);
}

void scan_directory(const char* dirpath) {
    DIR *directory = opendir(dirpath);
    if (directory == NULL) {
        printf("🛑 Unable to open directory: %s\n", dirpath);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        // Skip the special directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        char filepath[MAX_PATH_LENGTH];
        snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", dirpath, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            printf("🔍 Scanning file: %s...\n", filepath);
            scan_file(filepath);
        } else if (entry->d_type == DT_DIR) { // Directory
            printf("📂 Entering directory: %s\n", filepath);
            scan_directory(filepath); // Scan sub-directory
        }
    }
    
    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("📝 Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("🎉 Welcome to the Happy C Antivirus Scanner! 🎉\n");
    printf("🌟 Let's keep your files safe and sound! 🌟\n");

    scan_directory(argv[1]);

    printf("✅ Scanning completed! Have a virus-free day! ☀️\n");
    return EXIT_SUCCESS;
}