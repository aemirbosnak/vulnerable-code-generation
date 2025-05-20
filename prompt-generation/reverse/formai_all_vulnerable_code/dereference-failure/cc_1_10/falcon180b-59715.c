//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    FILE *fp;
    char filename[1024];
    int filesize;
    int current_pos;
} FileRecovery;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FileRecovery fr = {0};

    fr.fp = fopen(filename, "rb");
    if (!fr.fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fr.fp, 0, SEEK_END);
    fr.filesize = ftell(fr.fp);
    if (fr.filesize > MAX_FILE_SIZE) {
        printf("File is too large to recover\n");
        exit(1);
    }

    rewind(fr.fp);
    strncpy(fr.filename, filename, sizeof(fr.filename));

    printf("Enter the starting position (in bytes): ");
    scanf("%d", &fr.current_pos);

    char buffer[1024];
    while (fread(buffer, sizeof(char), sizeof(buffer), fr.fp) > 0) {
        int i;
        for (i = 0; i < sizeof(buffer); i++) {
            if (fr.current_pos == 0 || buffer[i] == '\n') {
                printf("%c", buffer[i]);
            }
            fr.current_pos++;
            if (fr.current_pos >= fr.filesize) {
                break;
            }
        }
    }

    fclose(fr.fp);
    exit(0);
}