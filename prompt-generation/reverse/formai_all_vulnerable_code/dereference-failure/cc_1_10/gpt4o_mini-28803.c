//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define PASSIONATE "In the name of love, I scan thee!"
#define MALICIOUS "Oh! What treachery lies within!"
#define PURE "Alas, the heart is pure and free."

// Function declaration
void search_files(const char *path);
int is_malicious(const char *content);
void reveal_truth(const char *filename, int isMalicious);

int main(void) {
    printf("%s\n", PASSIONATE);
    search_files(".");

    return 0;
}

void search_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("Could not open the directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filepath[1024] = {0};
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

            struct stat buf;
            if (stat(filepath, &buf) == -1) {
                perror("Stat error");
                continue;
            }
            
            // If it's a directory, recurse into it
            if (S_ISDIR(buf.st_mode)) {
                search_files(filepath);
            } else {
                // If it's a file, check its contents
                FILE *file = fopen(filepath, "r");
                if (file != NULL) {
                    char buffer[BUFFER_SIZE];
                    fread(buffer, sizeof(char), BUFFER_SIZE, file);
                    fclose(file);

                    int isMalicious = is_malicious(buffer);
                    reveal_truth(filepath, isMalicious);
                } else {
                    perror("Unable to open file");
                }
            }
        }
    }
    closedir(dp);
}

int is_malicious(const char *content) {
    // A simple example of 'malicious' code detection
    if (strstr(content, "virus") || strstr(content, "malware")) {
        return 1; // It's malicious
    }
    return 0; // It's not malicious
}

void reveal_truth(const char *filename, int isMalicious) {
    if (isMalicious) {
        printf("%s: %s\n", filename, MALICIOUS);
    } else {
        printf("%s: %s\n", filename, PURE);
    }
}