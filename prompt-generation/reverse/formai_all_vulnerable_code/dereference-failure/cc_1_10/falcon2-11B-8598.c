//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void scanFile(const char* fileName, const char* virusSignature) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Failed to open file '%s'\n", fileName);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, virusSignature)!= NULL) {
            printf("Virus detected in file '%s'\n", fileName);
            return;
        }
    }

    fclose(fp);
    printf("No virus found in file '%s'\n", fileName);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_to_scan> <virus_signature>\n", argv[0]);
        return 1;
    }

    const char* fileName = argv[1];
    const char* virusSignature = argv[2];

    DIR* dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".")!= 0 && strcmp(entry->d_name, "..")!= 0) {
            scanFile(entry->d_name, virusSignature);
        }
    }

    closedir(dir);

    return 0;
}