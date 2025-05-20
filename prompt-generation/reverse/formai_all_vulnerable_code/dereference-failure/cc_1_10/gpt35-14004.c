//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1MB

typedef struct {
    char name[50];
    char value[50];
} Metadata;

void read_metadata(char *file_content, Metadata *metadata_list, int *metadata_count) {
    char *token, *line;
    int i = 0;

    line = strtok(file_content, "\n");

    while (line != NULL && i < *metadata_count) {
        token = strtok(line, ":");
        snprintf(metadata_list[i].name, sizeof(metadata_list[i].name), "%s", token);
        token = strtok(NULL, ":");
        snprintf(metadata_list[i].value, sizeof(metadata_list[i].value), "%s", token);
        i++;
        line = strtok(NULL, "\n");
    }
    *metadata_count = i;
}

void print_metadata(Metadata *metadata_list, int metadata_count) {
    int i;
    for (i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata_list[i].name, metadata_list[i].value);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *file_content;
    int metadata_count = 10, file_size, i;

    Metadata metadata_list[10] = {{"title", ""}, {"artist", ""}, {"album", ""}, {"year", ""}, {"genre", ""}, {"publisher", ""}, {"track_number", ""}, {"composer", ""}, {"duration", ""}, {"bitrate", ""}};

    if (argc < 2) {
        printf("Please specify a file name\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Failed to open file %s\n", argv[1]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size >= MAX_FILE_SIZE) {
        printf("File size is too large!\n");
        exit(1);
    }

    file_content = (char*)malloc(sizeof(char) * file_size);
    fread(file_content, 1, file_size, fp);

    read_metadata(file_content, metadata_list, &metadata_count);

    print_metadata(metadata_list, metadata_count);

    free(file_content);
    fclose(fp);

    return 0;
}