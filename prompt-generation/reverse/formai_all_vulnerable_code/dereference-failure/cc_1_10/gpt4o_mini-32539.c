//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_SIG 5

const char *malware_signatures[MAX_SIG] = {
    "malware_signature_1",
    "malware_signature_2",
    "malware_signature_3",
    "malware_signature_4",
    "malware_signature_5"
};

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    int found = 0;
    
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < MAX_SIG; i++) {
            if (strstr(line, malware_signatures[i])) {
                printf("WARNING! Malware signature '%s' found in file: %s\n", malware_signatures[i], filename);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);
    if (!found) {
        printf("File '%s' is safe!\n", filename);
    }
}

void scan_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dir = opendir(dir_name);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

            struct stat path_stat;
            stat(path, &path_stat);
            if (S_ISDIR(path_stat.st_mode)) {
                printf("Entering directory: %s\n", path);
                scan_directory(path); // Recursive call!
            } else {
                printf("Scanning file: %s\n", path);
                scan_file(path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting the exciting antivirus scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Antivirus scan finished!😄\n");

    return EXIT_SUCCESS;
}