//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

void init_file(File *file) {
    file->lines = NULL;
    file->num_lines = 0;
}

void add_line(File *file, char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->length = strlen(line);
    file->lines = realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
    file->lines[file->num_lines] = *new_line;
    file->num_lines++;
}

void print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i].line);
    }
}

void backup_file(File *file, char *backup_file_name) {
    FILE *backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error: could not open backup file.\n");
        exit(1);
    }
    for (int i = 0; i < file->num_lines; i++) {
        fprintf(backup_file, "%s", file->lines[i].line);
    }
    fclose(backup_file);
    printf("Backup created: %s\n", backup_file_name);
}

int main() {
    char line[MAX_LINE_LENGTH];
    File file;
    init_file(&file);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(&file, line);
    }

    char backup_file_name[MAX_LINE_LENGTH];
    printf("Enter backup file name: ");
    fgets(backup_file_name, MAX_LINE_LENGTH, stdin);
    backup_file_name[strcspn(backup_file_name, "\n")] = '\0';

    backup_file(&file, backup_file_name);

    print_file(&file);

    free(file.lines);
    return 0;
}