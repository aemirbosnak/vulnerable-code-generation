//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "1.0"
#define MAX_STRING_LENGTH 32

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char *message = argv[1];
    int messageLength = strlen(message);

    if (messageLength > MAX_STRING_LENGTH) {
        fprintf(stderr, "Message too long (max length: %d)\n", MAX_STRING_LENGTH);
        return 1;
    }

    char *qrCode = malloc(messageLength + 3);
    qrCode[0] = '\0';

    int row = 0;
    int col = 0;

    for (int i = 0; i < messageLength; i++) {
        switch (message[i]) {
            case 'Q':
                qrCode[row] = 'Q';
                row++;
                break;
            case 'R':
                qrCode[row] = 'R';
                row++;
                break;
            case 'O':
                qrCode[row] = 'O';
                row++;
                break;
            case 'C':
                qrCode[row] = 'C';
                row++;
                break;
            case 'L':
                qrCode[row] = 'L';
                row++;
                break;
            case 'A':
                qrCode[row] = 'A';
                row++;
                break;
            case 'M':
                qrCode[row] = 'M';
                row++;
                break;
            case 'E':
                qrCode[row] = 'E';
                row++;
                break;
            case 'T':
                qrCode[row] = 'T';
                row++;
                break;
            case 'P':
                qrCode[row] = 'P';
                row++;
                break;
            case 'S':
                qrCode[row] = 'S';
                row++;
                break;
            case 'X':
                qrCode[row] = 'X';
                row++;
                break;
            case 'N':
                qrCode[row] = 'N';
                row++;
                break;
            case 'F':
                qrCode[row] = 'F';
                row++;
                break;
            case 'G':
                qrCode[row] = 'G';
                row++;
                break;
            case 'I':
                qrCode[row] = 'I';
                row++;
                break;
            case 'H':
                qrCode[row] = 'H';
                row++;
                break;
            case 'V':
                qrCode[row] = 'V';
                row++;
                break;
            case 'U':
                qrCode[row] = 'U';
                row++;
                break;
            case 'D':
                qrCode[row] = 'D';
                row++;
                break;
            case 'W':
                qrCode[row] = 'W';
                row++;
                break;
            case 'Y':
                qrCode[row] = 'Y';
                row++;
                break;
            case 'B':
                qrCode[row] = 'B';
                row++;
                break;
            case 'K':
                qrCode[row] = 'K';
                row++;
                break;
            case 'J':
                qrCode[row] = 'J';
                row++;
                break;
            case 'Z':
                qrCode[row] = 'Z';
                row++;
                break;
            case '0':
                qrCode[row] = '0';
                row++;
                break;
            case '1':
                qrCode[row] = '1';
                row++;
                break;
            case '2':
                qrCode[row] = '2';
                row++;
                break;
            case '3':
                qrCode[row] = '3';
                row++;
                break;
            case '4':
                qrCode[row] = '4';
                row++;
                break;
            case '5':
                qrCode[row] = '5';
                row++;
                break;
            case '6':
                qrCode[row] = '6';
                row++;
                break;
            case '7':
                qrCode[row] = '7';
                row++;
                break;
            case '8':
                qrCode[row] = '8';
                row++;
                break;
            case '9':
                qrCode[row] = '9';
                row++;
                break;
            default:
                fprintf(stderr, "Invalid character: %c\n", message[i]);
                return 1;
        }
    }

    qrCode[row] = '\0';

    printf("QR code: %s\n", qrCode);

    free(qrCode);

    return 0;
}