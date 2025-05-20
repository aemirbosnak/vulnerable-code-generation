//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char *filename, char *output) {
    FILE *file, *out;
    char ch, temp;
    int i, j;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    out = fopen(output, "wb");
    if (out == NULL) {
        printf("Error: Could not create output file.\n");
        exit(2);
    }

    while ((ch = fgetc(file))!= EOF) {
        temp = ch ^ KEY[i % strlen(KEY)];
        for (j = 0; j < strlen(KEY); j++) {
            if (temp == KEY[j]) {
                i++;
                break;
            }
        }
        fputc(temp, out);
    }

    fclose(file);
    fclose(out);
}

void decrypt(char *filename, char *output) {
    FILE *file, *out;
    char ch, temp;
    int i, j;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    out = fopen(output, "wb");
    if (out == NULL) {
        printf("Error: Could not create output file.\n");
        exit(2);
    }

    while ((ch = fgetc(file))!= EOF) {
        for (i = 0; i < strlen(KEY); i++) {
            temp = ch ^ KEY[i];
            for (j = 0; j < strlen(KEY); j++) {
                if (temp == KEY[j]) {
                    fputc(ch, out);
                    break;
                }
            }
        }
    }

    fclose(file);
    fclose(out);
}

int main() {
    char filename[100], output[100];
    int choice;

    printf("Enter the name of the file to be encrypted/decrypted: ");
    scanf("%s", filename);

    printf("Enter the output file name: ");
    scanf("%s", output);

    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(filename, output);
    } else if (choice == 2) {
        decrypt(filename, output);
    } else {
        printf("Invalid choice.\n");
        exit(3);
    }

    printf("File encrypted/decrypted successfully.\n");

    return 0;
}