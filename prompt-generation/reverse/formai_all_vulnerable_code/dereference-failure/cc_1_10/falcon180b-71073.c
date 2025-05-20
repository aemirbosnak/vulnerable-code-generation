//Falcon-180B DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <file_path> <search_string> <replace_string>\n", argv[0]);
        exit(1);
    }

    char *file_path = argv[1];
    char *search_string = argv[2];
    char *replace_string = argv[3];

    FILE *fp = fopen(file_path, "r+");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        exit(1);
    }

    struct stat st;
    fstat(fileno(fp), &st);
    int file_size = st.st_size;
    char *file_content = malloc(file_size);

    fseek(fp, 0, SEEK_SET);
    fread(file_content, file_size, 1, fp);

    fseek(fp, 0, SEEK_SET);

    char *temp_buffer = malloc(MAX_LINE_LENGTH);
    int line_number = 1;

    while (fgets(temp_buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        char *line_content = strdup(temp_buffer);
        int line_length = strlen(line_content);

        char *pos = strstr(line_content, search_string);

        if (pos!= NULL) {
            printf("Line %d: %s\n", line_number, line_content);

            char *new_line_content = malloc(line_length + strlen(replace_string) - strlen(search_string));

            strncpy(new_line_content, line_content, pos - line_content);
            strcat(new_line_content, replace_string);
            strcat(new_line_content, pos + strlen(search_string));

            fseek(fp, -line_length, SEEK_CUR);
            fwrite(new_line_content, strlen(new_line_content), 1, fp);

            free(new_line_content);
        }

        line_number++;
    }

    fclose(fp);
    free(file_content);
    free(temp_buffer);

    printf("File modified successfully!\n");
    return 0;
}