//FormAI DATASET v1.0 Category: Data recovery tool ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recoverData(char* filename, int bytesToRecover) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error: ");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long int fileSize = ftell(fp);

    if (bytesToRecover > fileSize) {
        printf("Bytes to recover are greater than file size!\n");
        return;
    }

    fseek(fp, -bytesToRecover, SEEK_END);

    char* data = (char*) malloc(bytesToRecover);

    if (fread(data, 1, bytesToRecover, fp) != bytesToRecover) {
        printf("Error reading data!\n");
        return;
    }

    char newFileName[100];
    strcpy(newFileName, "Recovered_");
    strcat(newFileName, filename);

    FILE *newFile = fopen(newFileName, "wb");
    fwrite(data, 1, bytesToRecover, newFile);
    free(data);
    printf("%d bytes of data recovered successfully from %s and saved to %s\n", bytesToRecover, filename, newFileName);

    fclose(fp);
    fclose(newFile);
}

int main() {
    char filename[50];
    int bytesToRecover;
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter number of bytes to recover: ");
    scanf("%d", &bytesToRecover);
    recoverData(filename, bytesToRecover);
    return 0;
}