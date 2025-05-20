//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[100];
    char content[1000];
} file_t;

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    file_t *buffer = (file_t*)malloc(size);
    fread(buffer->content, 1, size, file);
    fclose(file);

    printf("Content of file %s:\n%s\n", filename, buffer->content);

    free(buffer);
}

void write_file(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);

    printf("File %s written successfully\n", filename);
}

void create_file(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file\n");
        return;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);

    printf("File %s created successfully\n", filename);
}

int main() {
    char filename[100];
    char content[1000];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0';

    if (strlen(filename) > 0 && strlen(content) > 0) {
        if (strstr(filename, ".txt")!= NULL) {
            read_file(filename);
        } else if (strstr(filename, ".c")!= NULL) {
            create_file(filename, content);
        } else if (strstr(filename, ".cpp")!= NULL) {
            write_file(filename, content);
        } else {
            printf("Invalid file extension\n");
        }
    } else {
        printf("Invalid input\n");
    }

    return 0;
}