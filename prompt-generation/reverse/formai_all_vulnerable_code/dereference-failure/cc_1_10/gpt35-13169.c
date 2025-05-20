//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int scan_file(char *filename);

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int result = scan_file(argv[1]);

    if(result) {
        printf("%s is infected with a virus.\n", argv[1]);
    } else {
        printf("%s is clean.\n", argv[1]);
    }

    return 0;
}

int scan_file(char *filename)
{
    FILE *fp;
    long file_size;
    char *buffer;

    fp = fopen(filename, "r");
    if(!fp) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    buffer = malloc(sizeof(char) * MAX_FILE_SIZE);
    if(!buffer) {
        printf("Error: could not allocate memory for buffer\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    /* scan for viruses */
    if(strstr(buffer, "virus") != NULL) {
        return 1;
    }

    free(buffer);
    return 0;
}