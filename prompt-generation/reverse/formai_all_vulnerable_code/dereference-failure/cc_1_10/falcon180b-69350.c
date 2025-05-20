//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if(file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 2;
    }

    char line[MAX_LINE_LENGTH];
    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t line_count = 0;

    while((fgets(line, MAX_LINE_LENGTH, file))!= NULL) {
        line_count++;
        if(line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }

        if(buffer == NULL) {
            buffer = strdup(line);
            buffer_size = strlen(buffer);
        } else {
            size_t new_buffer_size = buffer_size + strlen(line);
            buffer = realloc(buffer, new_buffer_size + 1);
            strcat(buffer, line);
            buffer_size = new_buffer_size;
        }
    }

    if(buffer == NULL) {
        printf("Error: File is empty\n");
        return 3;
    }

    unsigned int checksum = 0;
    for(int i = 0; i < buffer_size; i++) {
        checksum += buffer[i];
    }

    printf("Checksum for file '%s': %08X\n", argv[1], checksum);

    free(buffer);
    fclose(file);

    return 0;
}