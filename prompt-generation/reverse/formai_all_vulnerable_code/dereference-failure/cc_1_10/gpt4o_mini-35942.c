//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define SIGNATURE_COUNT 3

const char* signatures[SIGNATURE_COUNT] = {
    "malware_signature_1",
    "malware_signature_2",
    "virus_signature_3"
};

void scan_file(const char *file_name);
void report(const char *file_name, const char *signature);
int is_suspected_file(const char *buffer);

int main(void) {
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            scan_file(entry->d_name);
        }
    }

    closedir(dp);
    return EXIT_SUCCESS;
}

void scan_file(const char *file_name) {
    FILE *file = fopen(file_name, "rb");
    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;
    int suspected = 0;

    if (file == NULL) {
        perror("fopen");
        return;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (is_suspected_file(buffer)) {
            suspected = 1;
            break;
        }
    }

    fclose(file);
    
    if (suspected) {
        printf("Warning: Potential malicious content found in: %s\n", file_name);
    }
}

int is_suspected_file(const char *buffer) {
    for (int i = 0; i < SIGNATURE_COUNT; i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            report(buffer, signatures[i]);
            return 1;
        }
    }
    return 0;
}

void report(const char *file_name, const char *signature) {
    printf("Detected signature '%s' in file: %s\n", signature, file_name);
}