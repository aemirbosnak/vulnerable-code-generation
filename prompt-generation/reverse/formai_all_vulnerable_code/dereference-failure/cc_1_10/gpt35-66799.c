//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256
#define MAX_VIRUS_LEN 32
#define MAX_SCAN_LEN 1024
#define MAX_SCAN_DEPTH 16

/* Define the list of known viruses */
const char *VIRUSES[] = {"Trojan", "Ransomware", "Worm", "Spyware"};

/* Check if a file name contains a known virus */
int is_infected(const char *filename) {
    int i;
    for (i = 0; i < sizeof(VIRUSES) / sizeof(VIRUSES[0]); i++) {
        if (strstr(filename, VIRUSES[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

/* Scan a file or directory recursively */
int scan(const char *path, int depth) {
    DIR *dir;
    struct dirent *entry;
    char subpath[MAX_PATH_LEN];
    int infected = 0;

    /* Open the directory */
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    /* Read each entry in the directory */
    while ((entry = readdir(dir)) != NULL) {
        /* Skip special directories */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Build the subpath */
        snprintf(subpath, MAX_PATH_LEN, "%s/%s", path, entry->d_name);

        /* Scan the subpath */
        if (entry->d_type == DT_DIR && depth < MAX_SCAN_DEPTH) {
            infected |= scan(subpath, depth + 1);
        } else if (entry->d_type == DT_REG) {
            printf("Scanning file: %s\n", subpath);
            if (is_infected(entry->d_name)) {
                printf("Found virus: %s\n", subpath);
                infected = 1;
            }
        }
    }

    /* Close the directory */
    closedir(dir);

    return infected;
}

/* Main function */
int main(int argc, char *argv[]) {
    char path[MAX_PATH_LEN];
    int infected;

    /* Get the path to scan from the command line */
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strncpy(path, argv[1], MAX_PATH_LEN);

    /* Scan the directory */
    printf("Scanning directory: %s\n", path);
    infected = scan(path, 0);

    /* Report the result */
    if (infected) {
        printf("Scan complete: %d infected files found\n", infected);
    } else {
        printf("Scan complete: no viruses detected\n");
    }

    return 0;
}