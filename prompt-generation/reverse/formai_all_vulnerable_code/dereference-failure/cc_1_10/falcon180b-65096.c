//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct metadata {
    char *filename;
    int filesize;
    char *mimetype;
};

struct metadata *extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct metadata *metadata = (struct metadata *) malloc(sizeof(struct metadata));
    metadata->filename = strdup(filename);

    fseek(file, 0, SEEK_END);
    metadata->filesize = ftell(file);
    rewind(file);

    char magic[4];
    fread(magic, 1, 4, file);
    if (strcmp(magic, "GIF8") == 0) {
        metadata->mimetype = strdup("image/gif");
    } else if (strcmp(magic, "JFIF") == 0) {
        metadata->mimetype = strdup("image/jpeg");
    } else if (strcmp(magic, "II*") == 0) {
        metadata->mimetype = strdup("image/tiff");
    } else if (strcmp(magic, "BM") == 0) {
        metadata->mimetype = strdup("image/bmp");
    } else {
        metadata->mimetype = strdup("application/octet-stream");
    }

    fclose(file);
    return metadata;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("MIME type: %s\n", metadata->mimetype);
}

int main() {
    char *filename = "example.jpg";
    struct metadata *metadata = extract_metadata(filename);
    if (metadata!= NULL) {
        print_metadata(metadata);
        free(metadata->filename);
        free(metadata->mimetype);
        free(metadata);
    }
    return 0;
}