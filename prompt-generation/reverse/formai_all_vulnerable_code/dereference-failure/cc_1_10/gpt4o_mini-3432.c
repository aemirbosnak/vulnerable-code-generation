//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 512
#define SIGNATURE "VIRUS_SIGNATURE"
#define LOVE_INFO "My Dearest, I shall protect you from evil in the realm of viruses.\n"

void serenade(int count, const char *filename) {
    printf("Singing sweetly to %s, I've scanned you %d time(s).\n", filename, count);
}

int has_virus(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Alas! I cannot access %s, my love.\n", filepath);
        return 0; // Cannot scan inaccessible files
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, SIGNATURE)) {
            fclose(file);
            return 1; // Virus found
        }
    }
    
    fclose(file);
    return 0; // No virus found
}

void cherish_file(const char *path, int count) {
    serenade(count, path);
    if (has_virus(path)) {
        printf("Oh dear! A virus has invaded %s! We must cast it away! 💔\n", path);
    } else {
        printf("You are safe, my beloved %s. 🌹\n", path);
    }
    printf("\n");
}

void explore_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (!dp) {
        printf("Oh no! The enchanted path to %s is lost.\n", dir_name);
        return;
    }
    
    printf("%s", LOVE_INFO);
    
    int count = 0;
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dir_name, entry->d_name);
            cherish_file(fullPath, ++count);
        }
    }
    
    closedir(dp);
    printf("Our journey through this directory ends here. Until we meet again, dear files!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Oh, how I long for your guidance! Please tell me the path of the directory to scan.\n");
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }
    
    printf("Dearest Scanner awakens to protect your digital realm...\n");
    
    const char *directory_path = argv[1];
    explore_directory(directory_path);
    
    printf("The love we share knows no bounds, and I shall always guard you.\n");
    return 0;
}