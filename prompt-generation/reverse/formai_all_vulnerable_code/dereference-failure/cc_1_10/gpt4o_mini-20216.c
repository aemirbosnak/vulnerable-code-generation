//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void serenade(const char *message) {
    printf("%s\n", message);
}

int is_file_infected(const char *file_path) {
    // In a romantic twist, love letters can be our metaphor for infections.
    const char *love_letter = "dear_love.txt";
    return strstr(file_path, love_letter) != NULL;
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        serenade("Alas! My heart aches; I cannot access this directory.");
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        stat(path, &statbuf);
        
        if (S_ISDIR(statbuf.st_mode)) {
            serenade("Oh, what treasure awaits in this enchanting directory...");
            scan_directory(path);
        } else {
            serenade("I open your heart, dear file, to check for hidden whispers...");
            if (is_file_infected(path)) {
                serenade("Oh dear! I have found a love letter in the depths of your soul!");
                serenade(path);
                serenade("But worry not; I will save you from this tempestuous affair.");
            } else {
                serenade("No love letters found; you are pure, my dear.");
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        serenade("Oh, fairest user, please provide a path to your beloved directory.");
        return EXIT_FAILURE;
    }

    serenade("Welcome to the heart of the Antivirus Scanner.");
    serenade("As I embark on a journey through your files, let love guide my way...");

    scan_directory(argv[1]);

    serenade("My quest has ended, and I leave you with a heart full of hope.");
    return EXIT_SUCCESS;
}