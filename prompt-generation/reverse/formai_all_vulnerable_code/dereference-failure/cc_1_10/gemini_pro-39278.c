//GEMINI-pro DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>

typedef struct file {
    char *name;
    char *contents;
    int size;
} file;

file *open_file(char *name) {
    file *f = malloc(sizeof(file));
    f->name = name;
    f->contents = NULL;
    f->size = 0;
    return f;
}

int read_file(file *f) {
    FILE *fp = fopen(f->name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    f->size = ftell(fp);
    rewind(fp);
    f->contents = malloc(f->size + 1);
    fread(f->contents, f->size, 1, fp);
    f->contents[f->size] = '\0';
    fclose(fp);
    return 0;
}

int write_file(file *f) {
    FILE *fp = fopen(f->name, "w");
    if (fp == NULL) {
        return -1;
    }
    fwrite(f->contents, f->size, 1, fp);
    fclose(fp);
    return 0;
}

int close_file(file *f) {
    free(f->contents);
    free(f);
    return 0;
}

int main() {
    file *f = open_file("test.txt");
    if (read_file(f) == -1) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("%s", f->contents);
    if (write_file(f) == -1) {
        printf("Error writing file!\n");
        return 1;
    }
    if (close_file(f) == -1) {
        printf("Error closing file!\n");
        return 1;
    }
    return 0;
}