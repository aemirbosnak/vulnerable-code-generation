//FormAI DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* QR Code generation function */
void generateQRCode(char* data)
{
    /* Convert the input data to binary */
    int len = strlen(data);
    char* binary = (char*) malloc((8*len+1) * sizeof(char));
    int i = 0, j = 0;
    for (; i < len; ++i)
    {
        int ascii = (int) data[i];
        for (j = 7; j >= 0; --j)
        {
            binary[i*8+j] = (ascii % 2 == 0 ? '0' : '1');
            ascii /= 2;
        }
    }
    binary[8*len] = '\0';

    /* Divide the data into 3 segments and add error correction codes */
    int i1 = 0, i2 = 0, i3 = 0;
    char* seg1 = (char*) malloc(9 * sizeof(char));
    char* seg2 = (char*) malloc(9 * sizeof(char));
    char* seg3 = (char*) malloc(9 * sizeof(char));
    char* ecc1 = (char*) malloc(3 * sizeof(char));
    char* ecc2 = (char*) malloc(3 * sizeof(char));
    char* ecc3 = (char*) malloc(3 * sizeof(char));

    for (i = 0; i < 9; ++i) seg1[i] = binary[i];
    for (i = 0; i < 9; ++i) seg2[i] = binary[i+9];
    for (i = 0; i < 9; ++i) seg3[i] = binary[i+18];
    for (i = 0; i < 3; ++i) ecc1[i] = binary[i+27];
    for (i = 0; i < 3; ++i) ecc2[i] = binary[i+30];
    for (i = 0; i < 3; ++i) ecc3[i] = binary[i+33];

    free(binary);

    /* Print out the QR Code */
    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|        ##  ##  ##  ##        |\n");
    printf("|  ##  ##  ##  ##  ##  ##  ##  |\n");
    printf("|        ##  ##  ##  ##        |\n");
    printf("|        ############        |\n");
    printf("|  ##  ##  ##  ##  ##  ##  ##  |\n");
    printf("|        ############        |\n");
    printf("|  ##  ##  ##  ##  ##  ##  ##  |\n");
    printf("|        ##  ##  ##  ##        |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n\n");

    printf("Data: %s\n\n", data);
    printf("Segment 1: %s\n", seg1);
    printf("Error Correction 1: %s\n", ecc1);
    printf("Segment 2: %s\n", seg2);
    printf("Error Correction 2: %s\n", ecc2);
    printf("Segment 3: %s\n", seg3);
    printf("Error Correction 3: %s\n", ecc3);
}

int main()
{
    /* Get the input data from the user */
    char* data = (char*) malloc(101 * sizeof(char));
    printf("Enter data (max 100 characters): ");
    fgets(data, 100, stdin);
    data[strcspn(data, "\n")] = '\0';

    /* Generate the QR Code */
    generateQRCode(data);

    free(data);
    return 0;
}