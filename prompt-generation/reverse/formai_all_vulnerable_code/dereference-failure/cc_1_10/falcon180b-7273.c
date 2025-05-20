//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80

char* to_ascii(char* input_file, int width) {
    FILE* fp = fopen(input_file, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", input_file);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    rewind(fp);

    unsigned char* buffer = (unsigned char*) malloc(file_size);
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    char* ascii_art = (char*) malloc((file_size * 3) + 1); // 3 characters for each byte
    int i = 0;
    for (int j = 0; j < file_size; j++) {
        sprintf(&ascii_art[i], "%02X ", buffer[j]);
        i += 3;
        if (i >= MAX_WIDTH) {
            ascii_art[i-3] = '\0';
            printf("%s\n", ascii_art);
            i = 0;
        }
    }
    ascii_art[i-3] = '\0';
    printf("%s\n", ascii_art);

    free(buffer);
    free(ascii_art);

    return ascii_art;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <width>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    int width = atoi(argv[2]);

    char* ascii_art = to_ascii(input_file, width);

    return 0;
}