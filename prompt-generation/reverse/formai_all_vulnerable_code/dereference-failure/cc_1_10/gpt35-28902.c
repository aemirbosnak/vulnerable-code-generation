//FormAI DATASET v1.0 Category: QR code generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <qrencode.h>

// Function to convert a string to QR code
bool generateQR(char* text, int size, const char* file_path) 
{
    QRcode* qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qr) {
        return false;
    }

    FILE* fp = fopen(file_path, "wb");
    if (!fp) {
        return false;
    }

    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            int point = (y * qr->width) + x;

            if (qr->data[point] & 1) {
                fprintf(fp, "#");
            } else {
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(qr);

    return true;
}

// Function to get user input and generate QR code
void generateCode() 
{
    printf("Enter text to convert to QR code: ");
    char text[500];
    scanf("%s", text);

    bool success = generateQR(text, strlen(text), "QR_Code.txt");

    if (success) {
        printf("\nQR code generated and saved to QR_Code.txt\n");
    } else {
        printf("\nError in generating QR code\n");
    }
}

int main(int argc, char* argv[]) 
{
    generateCode();

    return 0;
}