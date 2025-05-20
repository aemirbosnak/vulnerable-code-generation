//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        fprintf(stderr, "Usage: %s source_file destination_file sync_mode\n", argv[0]);
        return 1;
    }

    char sync_mode = argv[3][0];
    FILE *source_file = fopen(argv[1], "r");
    FILE *destination_file = fopen(argv[2], "r+");

    if(source_file == NULL || destination_file == NULL) {
        fprintf(stderr, "Error: Cannot open file.\n");
        return 1;
    }

    struct stat source_stat, dest_stat;
    fstat(fileno(source_file), &source_stat);
    fstat(fileno(destination_file), &dest_stat);

    if(source_stat.st_size > dest_stat.st_size) {
        if(sync_mode == 'a') {
            char buffer[BUFFER_SIZE];
            off_t offset = dest_stat.st_size;

            while(fgets(buffer, BUFFER_SIZE, source_file)!= NULL) {
                fseek(destination_file, offset, SEEK_SET);
                fwrite(buffer, strlen(buffer), 1, destination_file);
                offset += strlen(buffer);
            }
        } else {
            fprintf(stderr, "Error: Invalid sync mode.\n");
            return 1;
        }
    } else if(source_stat.st_size < dest_stat.st_size) {
        if(sync_mode == 'd') {
            char buffer[BUFFER_SIZE];
            off_t offset = dest_stat.st_size - source_stat.st_size;

            while(fgets(buffer, BUFFER_SIZE, destination_file)!= NULL) {
                fseek(destination_file, -strlen(buffer), SEEK_CUR);
                fwrite("\0", 1, 1, destination_file);
            }
        } else {
            fprintf(stderr, "Error: Invalid sync mode.\n");
            return 1;
        }
    } else {
        fprintf(stdout, "Files are already synchronized.\n");
    }

    fclose(source_file);
    fclose(destination_file);

    return 0;
}