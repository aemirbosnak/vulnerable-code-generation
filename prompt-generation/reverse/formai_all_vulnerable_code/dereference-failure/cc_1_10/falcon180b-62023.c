//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000000

char key[MAX_KEY_LEN];

void generate_key(char *filename) {
    FILE *fp;
    int i, j;
    char c;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    i = 0;
    while ((c = fgetc(fp))!= EOF) {
        if (isalpha(c)) {
            key[i] = tolower(c);
            i++;
        }
    }
    key[i] = '\0';
    fclose(fp);
}

void encrypt_file(char *filename, char *key) {
    FILE *fp_in, *fp_out;
    char c, d;

    fp_in = fopen(filename, "r");
    if (fp_in == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fp_out = fopen("encrypted.txt", "w");
    if (fp_out == NULL) {
        printf("Error: Cannot create output file.\n");
        exit(1);
    }

    while ((c = fgetc(fp_in))!= EOF) {
        if (isalpha(c)) {
            d = tolower(c) - tolower(key[0]);
            if (d < 0) {
                d = d + 26;
            }
            fprintf(fp_out, "%c", d);
        } else {
            fprintf(fp_out, "%c", c);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_name> <key>\n", argv[0]);
        exit(1);
    }

    strcpy(key, argv[2]);
    generate_key(argv[1]);
    encrypt_file(argv[1], key);

    printf("File encrypted successfully.\n");
    return 0;
}