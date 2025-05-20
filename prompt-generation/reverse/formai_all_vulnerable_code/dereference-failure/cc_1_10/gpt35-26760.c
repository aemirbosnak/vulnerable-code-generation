//FormAI DATASET v1.0 Category: QR code generator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main(int argc, char *argv[]) {
    char strin[1024];
    int qr_version = 0;
    int qr_level = QR_ECLEVEL_L;
    int qr_margin = 4;
    QRcode *qc;
    FILE *fp;
    char file[1024];

    if (argc > 1) {
        strcpy(strin, argv[1]);
        if (argc > 2) {
            qr_version = atoi(argv[2]);
        }
        if (argc > 3) {
            qr_level = atoi(argv[3]);
        }
        if (argc > 4) {
            qr_margin = atoi(argv[4]);
        }
    } else {
        printf("Enter string/URL to encode: ");
        fgets(strin, sizeof(strin), stdin);
        if (strin[strlen(strin) - 1] == '\n') {
            strin[strlen(strin) - 1] = '\0';
        }
    }

    qc = QRcode_encodeString(strin, qr_version, qr_level, QR_MODE_8, 1);
    if (qc == NULL) {
        fprintf(stderr, "QRcode_encodeString error\n");
        return EXIT_FAILURE;
    }

    printf("Enter file name to save (default: output.png): ");
    fgets(file, sizeof(file), stdin);
    if (file[strlen(file) - 1] == '\n') {
        file[strlen(file) - 1] = '\0';
    }
    if (strlen(file) == 0) {
        strcpy(file, "output.png");
    }

    fp = fopen(file, "wb");
    if (fp == NULL) {
        perror("fopen");
        QRcode_free(qc);
        return EXIT_FAILURE;
    }

    fwrite(qc->data, qc->width, qc->width, fp);
    QRcode_free(qc);
    fclose(fp);

    return EXIT_SUCCESS;
}