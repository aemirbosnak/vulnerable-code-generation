//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

void check_file(char* filepath);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: scanner <directory>\n");
        exit(EXIT_FAILURE);
    }

    DIR* dir = opendir(argv[1]);
    struct dirent* entry;
    char filepath[256];

    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], entry->d_name);

        check_file(filepath);
    }

    closedir(dir);
    return 0;
}

void check_file(char* filepath) {
    FILE* file = fopen(filepath, "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening file at %s: %s\n", filepath, strerror(errno));
        return;
    }

    // perform virus scan
    char c;
    while(c = fgetc(file)) {
        if(c == EOF) {
            break;
        }

        // hypothetical virus detection
        if(c == 'x' && fgetc(file) == 'y') {
            printf("Found virus in file at %s\n", filepath);
            break;
        }
    }

    fclose(file);
}