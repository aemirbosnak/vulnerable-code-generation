//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

struct folder {
    char name[MAXLINE];
    int size;
    int num_files;
    struct folder **subfolders;
};

typedef struct folder Folder;

void add_size(Folder *f, int size) {
    f->size += size;
    if (f->subfolders) {
        for (int i = 0; i < f->num_files; i++) {
            add_size(f->subfolders[i], size);
        }
    }
}

Folder *new_folder(char *name) {
    Folder *f = malloc(sizeof(Folder));
    if (f == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(1);
    }
    strcpy(f->name, name);
    f->size = 0;
    f->num_files = 0;
    f->subfolders = NULL;
    return f;
}

void add_file_to_folder(Folder *f, int size) {
    add_size(f, size);
    f->num_files++;
}

void add_subfolder_to_folder(Folder *f, Folder *subfolder) {
    if (f->subfolders == NULL) {
        f->subfolders = malloc(sizeof(Folder *));
        if (f->subfolders == NULL) {
            fprintf(stderr, "Error: could not allocate memory\n");
            exit(1);
        }
    } else {
        f->subfolders = realloc(f->subfolders, (f->num_files + 1) * sizeof(Folder *));
        if (f->subfolders == NULL) {
            fprintf(stderr, "Error: could not allocate memory\n");
            exit(1);
        }
    }
    f->subfolders[f->num_files] = subfolder;
    f->num_files++;
}

void print_folder(Folder *f, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s (%d bytes, %d file%c)\n", f->name, f->size, f->num_files, f->num_files == 1 ? ' ' : 's');
    if (f->subfolders) {
        for (int i = 0; i < f->num_files; i++) {
            print_folder(f->subfolders[i], depth + 1);
        }
    }
}

void free_folder(Folder *f) {
    if (f->subfolders) {
        for (int i = 0; i < f->num_files; i++) {
            free_folder(f->subfolders[i]);
        }
        free(f->subfolders);
    }
    free(f);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char cmd[MAXLINE], path[MAXLINE];
    sprintf(cmd, "du -ah %s", argv[1]);

    Folder *root = new_folder(argv[1]);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not execute command\n");
        exit(1);
    }

    while (fgets(path, MAXLINE, fp) != NULL) {
        path[strcspn(path, "\r\n")] = '\0'; // remove newline character
        char *size_str = strtok(path, "\t");
        int size = atoi(size_str);
        char *name = strtok(NULL, "\t");
        char *type = strtok(name, ".");
        if (type != NULL) {
            add_file_to_folder(root, size);
        } else {
            char *subfolder_name = strtok(NULL, "\t");
            Folder *subfolder = new_folder(subfolder_name);
            add_subfolder_to_folder(root, subfolder);
            add_file_to_folder(subfolder, size);
        }
    }

    pclose(fp);

    print_folder(root, 0);

    free_folder(root);

    return 0;
}