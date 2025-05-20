//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

struct Virus {
    char *name;
    char *signature;
    size_t signature_len;
};

#define MAX_VIRUSES 100
struct Virus viruses[MAX_VIRUSES];
int num_viruses = 0;

void load_viruses() {
    FILE *f = fopen("viruses.txt", "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    char line[512];
    while (fgets(line, sizeof(line), f)) {
        if (line[0] == '#') {
            continue;
        }

        char *name = strtok(line, ",");
        char *signature = strtok(NULL, "\n");

        struct Virus virus;
        virus.name = strdup(name);
        virus.signature = strdup(signature);
        virus.signature_len = strlen(signature);

        viruses[num_viruses++] = virus;
    }

    fclose(f);
}

void scan_directory(char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_REG) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

            FILE *f = fopen(path, "rb");
            if (f == NULL) {
                perror("fopen");
                continue;
            }

            fseek(f, 0, SEEK_END);
            size_t file_size = ftell(f);
            fseek(f, 0, SEEK_SET);

            char *buffer = malloc(file_size);
            if (buffer == NULL) {
                perror("malloc");
                fclose(f);
                continue;
            }

            fread(buffer, file_size, 1, f);
            fclose(f);

            for (int i = 0; i < num_viruses; i++) {
                char *start_of_match = strstr(buffer, viruses[i].signature);
                if (start_of_match != NULL) {
                    printf("Found %s in %s\n", viruses[i].name, path);
                    break;
                }
            }

            free(buffer);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    load_viruses();

    scan_directory(argv[1]);

    return 0;
}