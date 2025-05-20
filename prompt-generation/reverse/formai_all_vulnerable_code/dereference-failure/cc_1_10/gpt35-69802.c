//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recover(char *path) {
    FILE *fp = fopen(path, "r");

    if (!fp) {
        printf("Unable to open file!\n");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    long int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = (char*) malloc(filesize);
    if (buffer == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    size_t read_size = fread(buffer, 1, filesize, fp);
    if (read_size != filesize) {
        printf("Unable to read file!\n");
        return;
    }

    char *flag_ptr = strstr(buffer, "FLAG");
    if (!flag_ptr) {
        printf("Unable to recover data!\n");
        return;
    }

    int flag_index = flag_ptr - buffer;
    int i;
    for (i = flag_index; i < filesize; i++) {
        buffer[i] ^= 0xFF; // XOR with 0xFF to decrypt
    }

    printf("Recovered Data: %s\n", buffer);
    free(buffer);
    fclose(fp);
}

void main() {
    char path[100];

    printf("Enter path of file to recover: ");
    scanf("%s", path);

    recover(path);
}