//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <string.h>

void medieval_encrypt(char *data, int length, char key) {
    for(int i = 0; i < length; i++) {
        data[i] = (data[i] + key) % 127;
        if(data[i] < 32) data[i] += 32;
    }
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s [input file] [key] [output file]\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if(!input) {
        printf("Error: cannot open input file %s\n", argv[1]);
        return 1;
    }

    char key = argv[2][0];

    FILE *output = fopen(argv[3], "wb");
    if(!output) {
        printf("Error: cannot open output file %s\n", argv[3]);
        fclose(input);
        return 1;
    }

    fseek(input, 0, SEEK_END);
    int length = ftell(input);
    rewind(input);

    char *buffer = malloc(length);
    fread(buffer, length, 1, input);

    medieval_encrypt(buffer, length, key);

    fwrite(buffer, length, 1, output);

    fclose(input);
    fclose(output);

    free(buffer);

    printf("File %s encrypted with key '%c' and saved to %s\n", argv[1], key, argv[3]);

    return 0;
}