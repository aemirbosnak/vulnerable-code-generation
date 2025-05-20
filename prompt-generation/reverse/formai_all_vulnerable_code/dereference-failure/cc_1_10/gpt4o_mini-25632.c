//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void createQRCode(const char *data, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Alas! The QR code could not be encoded!\n");
        return;
    }
    
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Alas! The noble parchment could not be opened!\n");
        QRcode_free(qrcode);
        return;
    }

    fprintf(fp, "P1\n%d %d\n", qrcode->width, qrcode->width);
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            fputc((qrcode->data[y * qrcode->width + x] & 1) ? '1' : '0', fp);
        }
        fputs("\n", fp);
    }

    fclose(fp);
    QRcode_free(qrcode);
    printf("Huzzah! The QR code hath been inscribed onto parchment: %s\n", filename);
}

int main() {
    printf("Welcome, noble seeker of knowledge, to the QR Code Generator!\n");
    char data[256];
    char filename[256];

    printf("Pray, enter the message thou wishest to encode (or type 'exit' to depart): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // Strip the newline character
    
    if (strcmp(data, "exit") == 0) {
        printf("Farewell, brave traveler! May fortune favor thee on thy journey.\n");
        return 0;
    }

    printf("What name dost thou wish to bestow upon the parchment (include .pbm)? ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Strip the newline character

    createQRCode(data, filename);
    
    printf("Wouldst thou like to create another QR code? (yes/no): ");
    char answer[4];
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0'; // Strip the newline character

    while (strcmp(answer, "yes") == 0) {
        printf("Pray, enter the message thou wishest to encode: ");
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0'; // Strip the newline character
        
        if (strcmp(data, "exit") == 0) {
            printf("Farewell, brave traveler! May fortune favor thee on thy journey.\n");
            return 0;
        }

        printf("What name dost thou wish to bestow upon the parchment (include .pbm)? ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0'; // Strip the newline character

        createQRCode(data, filename);
        
        printf("Wouldst thou like to create another QR code? (yes/no): ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0'; // Strip the newline character
    }

    printf("The quest hath ended! Until next we meet!\n");
    return 0;
}