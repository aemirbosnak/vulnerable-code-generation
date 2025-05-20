//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_LENGTH 256
#define VIRUS_COUNT 3

// The viruses are akin to star-crossed lovers, forever entwined in tragedy
const char *viruses[VIRUS_COUNT] = {
    "Virulent Virus",
    "Corrupting Code",
    "Bad Data"
};

// Functions declarations
void scan_file(const char *filepath);
void search_for_viruses(FILE *file, const char *filename);
void announce_result(const char *filename, int infected);
void explore_directory(const char *dirpath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("O, sweet distraught! Specify one directory to scan.\n");
        return 1;
    }
    
    printf("Thus I venture forth to scan the realm: %s\n", argv[1]);
    explore_directory(argv[1]);
    
    return 0;
}

void explore_directory(const char *dirpath) {
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(dirpath);
    if (!dir) {
        printf("Alas, fair moon! I could not open the directory.\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filepath[MAX_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            
            if (entry->d_type == DT_REG) {
                printf("Hark! Scanning the file: %s...\n", filepath);
                scan_file(filepath);
            }
        }
    }
    
    closedir(dir);
}

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Oh, sweet angel! I could not read the file: %s\n", filepath);
        return;
    }
    
    search_for_viruses(file, filepath);
    fclose(file);
}

void search_for_viruses(FILE *file, const char *filename) {
    char line[MAX_LENGTH];
    int infected = 0;

    // Scan through each line as if seeking the heart of a lover
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < VIRUS_COUNT; i++) {
            if (strstr(line, viruses[i]) != NULL) {
                printf("Oh woe! The sign of '%s' discovered in: %s\n", viruses[i], filename);
                infected = 1;
                break; // No need to search this line further once found
            }
        }
    }

    announce_result(filename, infected);
}

void announce_result(const char *filename, int infected) {
    if (infected) {
        printf("A tragedy unfolds! The file '%s' is infected!\n", filename);
    } else {
        printf("O, happy day! The file '%s' is pure as the driven snow!\n", filename);
    }
}