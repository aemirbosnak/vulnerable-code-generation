//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generate_qr_code(const char *data, const char *filename) {
    QRcode *qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Could not generate QR Code\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    // The QR code will be saved as a simple ASCII PPM image
    fprintf(fp, "P1\n");
    fprintf(fp, "%d %d\n", qr->width, qr->width);
    
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            fputc(qr->data[y * qr->width + x] & 1 ? '1' : '0', fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
    QRcode_free(qr);
    printf("QR Code generated successfully and saved to %s\n", filename);
}

void random_facts() {
    const char *facts[] = {
        "Did you know? Honey never spoils!",
        "Cows have best friends and get stressed when separated.",
        "Bananas are berries, but strawberries aren't!",
        "Octopuses have three hearts!",
        "A group of flamingos is called a 'flamboyance.'",
        "Koalas sleep 18 hours a day!",
        "The Eiffel Tower can be 15 cm taller during the summer!",
        "An octopus has nine brains!"
    };

    int index = rand() % (sizeof(facts) / sizeof(facts[0]));
    printf("Curiosity Alert: %s\n", facts[index]);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    random_facts();  // Print a fun fact

    const char *data = "Hello, QR Code! This code holds a secret!";
    const char *filename = "qrcode.ppm";

    generate_qr_code(data, filename);

    return 0;
}