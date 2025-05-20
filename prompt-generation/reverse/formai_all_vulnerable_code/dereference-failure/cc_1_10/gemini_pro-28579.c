//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char name[100];
    size_t size;
    time_t timestamp;
    char data[MAX_FILE_SIZE];
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void backup_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    if (size > MAX_FILE_SIZE) {
        fprintf(stderr, "File too large: %s\n", filename);
        fclose(fp);
        return;
    }

    file_t *file = &files[num_files++];
    strcpy(file->name, filename);
    file->size = size;
    file->timestamp = time(NULL);
    fread(file->data, 1, size, fp);

    fclose(fp);
}

void restore_file(const char *filename) {
    file_t *file = NULL;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            file = &files[i];
            break;
        }
    }

    if (!file) {
        fprintf(stderr, "File not found: %s\n", filename);
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(file->data, 1, file->size, fp);

    fclose(fp);
}

void list_files() {
    for (int i = 0; i < num_files; i++) {
        file_t *file = &files[i];
        printf("%s (%lu bytes, %s)\n", file->name, file->size, ctime(&file->timestamp));
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [filename]\n", argv[0]);
        return 1;
    }

    const char *command = argv[1];

    if (strcmp(command, "backup") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s backup <filename>\n", argv[0]);
            return 1;
        }

        backup_file(argv[2]);
    } else if (strcmp(command, "restore") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s restore <filename>\n", argv[0]);
            return 1;
        }

        restore_file(argv[2]);
    } else if (strcmp(command, "list") == 0) {
        list_files();
    } else {
        fprintf(stderr, "Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}