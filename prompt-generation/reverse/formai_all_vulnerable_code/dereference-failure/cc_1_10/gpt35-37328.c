//FormAI DATASET v1.0 Category: QR code generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

int main(int argc, char **argv) {
    QRcode *qrcode = NULL;
    unsigned char *p, *q;
    int x, y, margin;
    FILE *fp;
    char filename[40], content[200];

    //Prompt user to enter data for QR code
    printf("Enter data (max 200 characters): ");
    scanf("%[^\n]%*c", content);

    //Create QR code using libqrencode library
    qrcode = QRcode_encodeString(content,0,QR_ECLEVEL_L,QR_MODE_8,1);

    //Check if QR code is generated or not
    if(qrcode) {
        margin = 4;
        p = qrcode->data;

        //Create file name using first 10 characters of content
        strncpy(filename, content, 10);
        filename[10] = '\0';
        strcat(filename, ".png");

        //Open file in binary write mode
        fp = fopen(filename, "wb");

        if(fp != NULL) {
            //Write PNG file header
            fwrite("\x89PNG\r\n\x1a\n", 1, 8, fp);
            //Write IHDR chunk
            fwrite("\0\0\0\x0dIHDR", 1, 8, fp);
            fwrite(&(qrcode->width), 4, 1, fp);
            fwrite(&(qrcode->width), 4, 1, fp);
            fwrite("\x01\x00\x00\x00\x00", 1, 5, fp);

            //Calculate number of bytes required to store data
            int size = (qrcode->width + margin * 2) * 3;

            //Allocate memory for buffer to store row of pixels
            unsigned char *row = (unsigned char*)calloc(size, sizeof(unsigned char));

            //Write IDAT chunk
            fwrite("\0\0\0\x0eIDAT", 1, 8, fp);

            //Loop through each row of QR code
            for(y=0; y<qrcode->width; y++) {
                memset(row, 0xff, size);

                //Loop through each pixel of QR code
                for(x=0; x<qrcode->width; x++) {
                    if(*p & 1) {
                        q = row + margin * 3 + x * 3;
                        q[0] = 0;
                        q[1] = 0;
                        q[2] = 0;
                    }
                    p++;
                }
                fwrite(row, 1, size, fp);
            }
            fwrite("\x00\x00\x00\x00\x00\x00\x00\x00\xbe\x7f\x1c\x06\x00\x00\x00\x00", 1, 16, fp);
            fclose(fp);

            //Free memory allocated for buffer
            free(row);
        } else {
            printf("Error: Could not open file for writing!\n");
            //Free memory allocated for QR code
            QRcode_free(qrcode);
            return -1;
        }
    } else {
        printf("Error: Could not create QR code!\n");
        return -2;
    }

    //Free memory allocated for QR code
    QRcode_free(qrcode);

    printf("QR code created successfully!\n");

    return 0;
}