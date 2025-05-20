//FormAI DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_SIZE 1024

int main(int argc, char **argv){
    QRcode *qr;
    unsigned char *data;
    int i, j, size;
    char string[MAX_SIZE];
    FILE *fp;

    printf("Enter the string you want to generate QR code for: ");
    fgets(string, MAX_SIZE, stdin);
    string[strcspn(string, "\n")] = 0;

    size = strlen(string);
    data = (unsigned char*)malloc(size + 1);

    for(i = 0; i < size; i++){
        data[i] = string[i];
    }
    data[size] = '\0';

    qr = QRcode_encodeString((char*)data, 4, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if(argc > 1){
        fp = fopen(argv[1], "w");
        if(fp != NULL){
            for(i = 0; i<qr->width; i++){
                for(j = 0; j<qr->width; j++){
                    fprintf(fp, "%c", qr->data[i*qr->width+j] ? '#' : ' ');
                }
                fprintf(fp, "\n");
            }
            fclose(fp);
        }
        else{
            printf("Error opening %s for writing.\n", argv[i]);
        }
    }
    else{
        for(i = 0; i<qr->width; i++){
            for(j = 0; j<qr->width; j++){
                printf("%c", qr->data[i*qr->width+j] ? '#' : ' ');
            }
            printf("\n");
        }
    }

    QRcode_free(qr);
    free(data);

    return 0;
}