//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char filename[50];
    char key[50];
    char input_text[500];
    char output_text[500];
    int i, j, k, n, len;
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter key: ");
    scanf("%s", key);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    fread(input_text, len, 1, fp);
    fclose(fp);

    n = strlen(key);
    for (i = 0; i < len; i++) {
        if (isalpha(input_text[i])) {
            output_text[i] = input_text[i] + toupper(key[i % n]) - 'A';
        } else if (isdigit(input_text[i])) {
            output_text[i] = input_text[i] + key[i % n] - '0';
        } else {
            output_text[i] = input_text[i];
        }
    }

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fwrite(output_text, len, 1, fp);
    fclose(fp);

    printf("File encrypted successfully.\n");
    return 0;
}