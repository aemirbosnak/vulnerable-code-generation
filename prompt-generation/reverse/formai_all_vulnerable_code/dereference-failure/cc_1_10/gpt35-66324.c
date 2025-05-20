//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct virus {
    char* name;
    char* signature;
    int length;
} Virus;

void scan_file(char* path, Virus* virus_list, int num_of_viruses) {
    FILE* f = fopen(path, "rb");
    if (f == NULL) {
        return;
    }
    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    rewind(f);

    char* buffer = malloc(file_size);
    if (buffer == NULL) {
        return;
    }
    fread(buffer, file_size, 1, f);
    fclose(f);

    for (int i = 0; i < num_of_viruses; i++) {
        Virus virus = virus_list[i];
        if (file_size >= virus.length) {
            for (int j = 0; j <= file_size - virus.length; j++) {
                if (memcmp(buffer + j, virus.signature, virus.length) == 0) {
                    printf("Virus %s found in file %s\n", virus.name, path);
                    break;
                }
            }
        }
    }

    free(buffer);
}

void scan_directory(char* path, Virus* virus_list, int num_of_viruses) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        int path_length = strlen(path);
        int name_length = strlen(entry->d_name);
        char* file_path = malloc(path_length + 1 + name_length + 1);
        if (file_path == NULL) {
            continue;
        }
        strcpy(file_path, path);
        strcpy(file_path + path_length, "/");
        strcpy(file_path + path_length + 1, entry->d_name);
        scan_file(file_path, virus_list, num_of_viruses);
        free(file_path);
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    Virus virus_list[] = {
        {"LoveLetter", "LOVE-LETTER-FOR-YOU", 20},
        {"Melissa", "MAIL FROM", 10},
        {"ILOVEYOU", "i love you", 10},
        {"CodeRed", "zX", 2}
    };
    int num_of_viruses = sizeof(virus_list) / sizeof(Virus);

    if (argc == 1) {
        char path[1000];
        printf("Enter a directory path to scan: ");
        scanf("%s", path);
        scan_directory(path, virus_list, num_of_viruses);
    } else {
        for (int i = 1; i < argc; i++) {
            scan_file(argv[i], virus_list, num_of_viruses);
        }
    }

    return 0;
}