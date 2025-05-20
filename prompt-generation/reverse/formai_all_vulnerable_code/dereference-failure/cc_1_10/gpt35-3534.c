//FormAI DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *inputfile, char *outputfile, char *key) {
    FILE *ifp, *ofp;
    char ch;
    int i, len;
    ifp = fopen(inputfile, "rb");
    if (ifp == NULL) {
        perror("File open error");
        exit(1);
    }
    ofp = fopen(outputfile, "wb");
    if (ofp == NULL) {
        perror("File open error");
        exit(1);
    }
    len = strlen(key);
    i = 0;
    while ((ch = fgetc(ifp)) != EOF) {
        fputc(ch ^ key[i], ofp);
        i++;
        if (i == len) {
            i = 0;
        }
    }
    printf("File encrypted successfully!\n");
    fclose(ifp);
    fclose(ofp);
}

void decrypt(char *inputfile, char *outputfile, char *key) {
    FILE *ifp, *ofp;
    char ch;
    int i, len;
    ifp = fopen(inputfile, "rb");
    if (ifp == NULL) {
        perror("File open error");
        exit(1);
    }
    ofp = fopen(outputfile, "wb");
    if (ofp == NULL) {
        perror("File open error");
        exit(1);
    }
    len = strlen(key);
    i = 0;
    while ((ch = fgetc(ifp)) != EOF) {
        fputc(ch ^ key[i], ofp);
        i++;
        if (i == len) {
            i = 0;
        }
    }
    printf("File decrypted successfully!\n");
    fclose(ifp);
    fclose(ofp);
}

int main() {
    char inputfile[100], outputfile[100], key[100];
    int choice;
    printf("Enter file name to encypt/decrypt\n");
    scanf("%s", inputfile);
    printf("Enter output file name\n");
    scanf("%s", outputfile);
    printf("Enter key\n");
    scanf("%s", key);
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter choice:\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            encrypt(inputfile, outputfile, key);
            break;
        case 2:
            decrypt(inputfile, outputfile, key);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}