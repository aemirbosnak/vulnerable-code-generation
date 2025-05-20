//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100

typedef struct _File {
    char name[100];
    long size;
    time_t timestamp;
} File;

void backup_file(char* source, char* destination) {
    FILE* src_file = fopen(source, "rb");
    FILE* dest_file = fopen(destination, "wb");

    if (src_file == NULL || dest_file == NULL) {
        printf("Error: Could not open file(s).\n");
        exit(1);
    }

    fseek(src_file, 0, SEEK_END);
    long file_size = ftell(src_file);
    fseek(src_file, 0, SEEK_SET);

    char buffer[1024];
    long bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, 1024, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [source_file] [destination_file]\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* dest_file = argv[2];

    backup_file(source_file, dest_file);

    printf("Backup successful!\n");

    return 0;
}