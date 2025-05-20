//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Neon glow constants
#define BLACKLIST_SIZE 5
#define BUFFER_SIZE 1024

// Simulated malware signatures
const char *blacklist[BLACKLIST_SIZE] = {
    "malware.exe",
    "virus.payload",
    "trojan.bin",
    "ransomware.sh",
    "spyware.pkg"
};

// Function to check if a file name matches the blacklist
int is_malicious(const char *filename) {
    for (int i = 0; i < BLACKLIST_SIZE; i++) {
        if (strcmp(filename, blacklist[i]) == 0) {
            return 1; // Malicious
        }
    }
    return 0; // Safe
}

// Function to scan a directory for malicious files
void scan_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory, illuminating its dark corners
    dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "☣️ Unable to open directory: %s\n", directory);
        exit(EXIT_FAILURE);
    }
    
    printf("🔍 Scanning directory: %s\n", directory);
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        // Check for malicious content lurking in the shadows
        if (is_malicious(entry->d_name)) {
            printf("🚨 Threat detected: %s\n", entry->d_name);
            printf("❌ Deleting %s...\n", entry->d_name);
            // Simulating deletion
            // Uncomment the line below in real application:
            // remove(entry->d_name); 
        } else {
            printf("🟢 File is safe: %s\n", entry->d_name);
        }
    }

    closedir(dir);
    printf("✔️ Scan complete. Stay safe in the underworld!\n");
}

// Main function to execute the scanner
int main(int argc, char *argv[]) {
    // Check for correct invocation
    if (argc != 2) {
        fprintf(stderr, "🔧 Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initiating scan in the neon-lit alley of the file system
    scan_directory(argv[1]);
    return 0;
}