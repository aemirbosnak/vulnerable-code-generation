//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[100];
    char contents[MAX_FILE_SIZE];
    int size;
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void add_file(char *name, char *contents) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: Too many files");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].contents, contents);
    files[num_files].size = strlen(contents);

    num_files++;
}

void remove_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_files) {
        fprintf(stderr, "Error: File not found");
        return;
    }

    for (; i < num_files - 1; i++) {
        files[i] = files[i + 1];
    }

    num_files--;
}

void print_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void save_files(char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file");
        return;
    }

    for (i = 0; i < num_files; i++) {
        fprintf(fp, "%s %d %s\n", files[i].name, files[i].size, files[i].contents);
    }

    fclose(fp);
}

void load_files(char *filename) {
    FILE *fp;
    char line[1024];
    char name[100];
    int size;
    char contents[MAX_FILE_SIZE];
    int i;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file");
        return;
    }

    while (fgets(line, 1024, fp) != NULL) {
        sscanf(line, "%s %d %s", name, &size, contents);
        add_file(name, contents);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [<args>]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s add <name> <contents>\n", argv[0]);
            return 1;
        }

        add_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s remove <name>\n", argv[0]);
            return 1;
        }

        remove_file(argv[2]);
    } else if (strcmp(argv[1], "print") == 0) {
        print_files();
    } else if (strcmp(argv[1], "save") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s save <filename>\n", argv[0]);
            return 1;
        }

        save_files(argv[2]);
    } else if (strcmp(argv[1], "load") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s load <filename>\n", argv[0]);
            return 1;
        }

        load_files(argv[2]);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}