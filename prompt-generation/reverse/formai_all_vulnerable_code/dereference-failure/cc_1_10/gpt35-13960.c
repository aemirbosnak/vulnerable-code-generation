//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_SIZE 1048576 // 1MB
#define SIGNATURE_SIZE 64 // 64 bytes signatures
#define MAX_SIGNATURES 1024 // Maximum signatures

struct virus_signature {
    unsigned char signature[SIGNATURE_SIZE];
    char name[256];
    int length;
};

struct virus_signature signature_list[MAX_SIGNATURES];
int num_signatures = 0;

void load_signatures(char *sig_path) {
    FILE *sig_file = fopen(sig_path, "rb");
    if (sig_file == NULL) {
        printf("Error opening signature file!\n");
        exit(1);
    }

    while (!feof(sig_file) && num_signatures < MAX_SIGNATURES) {
        struct virus_signature *sig = &signature_list[num_signatures];

        sig->length = fread(sig->signature, sizeof(char), SIGNATURE_SIZE, sig_file);

        if (sig->length == 0) {
            break;
        }

        fscanf(sig_file, "%s", sig->name);
        num_signatures++;
    }

    fclose(sig_file);
}

int scan_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s!\n", filename);
        return 0;
    }

    unsigned char buffer[MAX_FILE_SIZE];
    int file_size = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    int scanned = 0;

    for (int i = 0; i < num_signatures; i++) {
        struct virus_signature *sig = &signature_list[i];

        if (file_size < sig->length) {
            continue;
        }

        for (int j = 0; j <= file_size - sig->length; j++) {
            if (memcmp(&buffer[j], sig->signature, sig->length) == 0) {
                printf("Virus Found! %s in file %s\n", sig->name, filename);
                scanned = 1;
                break;
            }
        }

        if (scanned) {
            break;
        }
    }

    return scanned;
}

void scan_directory(char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error opening directory %s!\n", dir_path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char path[256];
        sprintf(path, "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
            scan_directory(path);
        } else if (entry->d_type == DT_REG) {
            scan_file(path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <signature_file> <directory_to_scan>\n", argv[0]);
        return 1;
    }

    load_signatures(argv[1]);
    scan_directory(argv[2]);

    printf("Scan complete.\n");

    return 0;
}