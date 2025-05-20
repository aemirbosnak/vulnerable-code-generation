//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_MAGIC "Ada'sEnchantedFile"
#define BUFFER_SIZE 1024

typedef struct {
    char name[256];
    int size;
    time_t last_modified;
    struct stat st;
} File;

void print_file_stats(File file) {
    printf("Name: %s\n", file.name);
    printf("Size: %d bytes\n", file.size);
    printf("Last Modified: %s\n", ctime(&file.last_modified));
}

void cast_file_spell(const char* file_path) {
    int fd;
    char buffer[BUFFER_SIZE];
    char spell_casted[32];
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    while ((read = getline(&line, &len, fd)) != -1) {
        strcpy(spell_casted, line);
        if (strlen(spell_casted) > 31) {
            spell_casted[31] = '\0';
        }
        printf("Spell Casted: %s\n", spell_casted);
        free(line);
    }

    free(line);
    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    File file;
    strcpy(file.name, argv[1]);

    if (stat(argv[1], &file.st) < 0) {
        perror("Error getting file stats");
        return 1;
    }

    file.size = file.st.st_size;
    file.last_modified = file.st.st_mtime;

    print_file_stats(file);
    cast_file_spell(argv[1]);

    return 0;
}