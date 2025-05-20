//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

/* 
  In the days of yore, we artisans of code sought 
  to forge mystical symbols to link the realms of 
  knowledge. Behold! A program that conjures a 
  QR code, heralding information to distant lands.
*/

void create_qr_code(const char *data, const char *file_name) {
    int version = 1; // QR Code version to wield
    QRecLevel level = QR_ECLEVEL_L; // Error correction level
    QRcode *qrcode;

    // Summon the QR code spell
    qrcode = QRcode_encodeString(data, version, level, QR_MODE_8, 1);
    
    if(!qrcode) {
        fprintf(stderr, "Alas! The QR code could not be forged.\n");
        return;
    }
    
    // Crafting the sacred image
    FILE *f = fopen(file_name, "wb");
    if(!f) {
        fprintf(stderr, "The scroll could not be etched. Check your path!\n");
        QRcode_free(qrcode);
        return;
    }
    
    // Write the pixelated essence into the file
    for(int y = 0; y < qrcode->width; y++) {
        for(int x = 0; x < qrcode->width; x++) {
            if(qrcode->data[y * qrcode->width + x] & 1) {
                fputc(0, f); // Black pixel
            } else {
                fputc(255, f); // White pixel
            }
        }
    }

    fclose(f);
    QRcode_free(qrcode);
    printf("The QR code hath been successfully crafted into the scroll '%s'.\n", file_name);
}

void about() {
    printf("============================================\n");
    printf("   Welcome to the QR Code Crafting Chamber  \n");
    printf("       A medieval program for crafting       \n");
    printf("       mystical QR codes from knowledge!     \n");
    printf("============================================\n");
}

int main(int argc, char *argv[]) {
    // Greet the noble seekers of knowledge
    about();

    if(argc < 3) {
        fprintf(stderr, "Usage: %s <data_to_encode> <output_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *data_to_encode = argv[1];
    const char *output_file = argv[2];

    // Invoke the powers of QR code crafting
    create_qr_code(data_to_encode, output_file);
    
    return EXIT_SUCCESS;
}