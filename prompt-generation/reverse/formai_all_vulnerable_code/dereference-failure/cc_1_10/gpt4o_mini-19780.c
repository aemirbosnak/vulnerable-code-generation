//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_KEYWORDS 5
#define MAX_FILENAME 256
#define MAX_BUFFER 512

// Define a list of potentially malicious keywords
const char *malicious_keywords[MAX_KEYWORDS] = {
    "virus",
    "malware",
    "trojan",
    "ransomware",
    "worm"
};

// Function to perform scanning of a file
int scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_BUFFER];

    if (file == NULL) {
        perror("Unable to open file");
        return 0;
    }

    while (fgets(buffer, MAX_BUFFER, file)) {
        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (strstr(buffer, malicious_keywords[i]) != NULL) {
                fclose(file);
                return 1; // Indicator of a potential threat
            }
        }
    }

    fclose(file);
    return 0; // No threat found
}

// Function to scan a directory
void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("🧙‍♂️ The Great Wizard of the Code is scanning the enchanted files in '%s'...\n\n", directory);

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[MAX_FILENAME];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            
            printf("🔍 Scanning file: %s", filepath);
            // "Magical" pause before each scan
            sleep(1);
            int result = scan_file(filepath);
            if (result) {
                printf(" ⚠️ Warning! Detected malicious content in: %s\n", filepath);
            } else {
                printf(" ✔️ Clean file: %s\n", filepath);
            }
        }
    }

    closedir(dp);
    printf("\n✨ The scanning wand has completed its mighty work! ✨\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory-to-scan>\n", argv[0]);
        return 1;
    }

    printf("🔮 Welcome to the Enchanted Antivirus Scanner! 🛡️\n");
    printf("🌌 Prepare to uncover hidden threats in the magical realm of files...\n\n");

    scan_directory(argv[1]);

    printf("🌕 May your files remain untainted by dark magic! 🧙‍♂️\n");
    return 0;
}