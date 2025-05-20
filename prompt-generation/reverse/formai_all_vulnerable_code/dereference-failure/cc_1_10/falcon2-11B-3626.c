//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <string.h>

#define KEY 3

void encrypt(char* str, int key) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A' + key;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a' + key;
        }
    }
}

void decrypt(char* str, int key) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'A' + 'a' - key;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'a' + 'A' - key;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (!input ||!output) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input)) {
        char* str = strdup(buffer);
        encrypt(str, KEY);
        decrypt(str, KEY);
        fputs(str, output);
        free(str);
    }

    fclose(input);
    fclose(output);

    return 0;
}