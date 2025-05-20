//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct qrcode {
    int size;
    int data[MAX_LEN];
};

int get_qrcode_size(struct qrcode *qrcode) {
    return qrcode->size;
}

int get_qrcode_data(struct qrcode *qrcode, int index) {
    return qrcode->data[index];
}

int main() {
    struct qrcode qrcode;
    int size = 0;
    int data[MAX_LEN];

    // read QR code from file
    FILE *f = fopen("qrcode.txt", "r");
    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, f)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[0] == '#') {
            size = atoi(line + 1);
            break;
        }
    }

    fclose(f);

    // read QR code data
    f = fopen("qrcode.txt", "r");
    int i = 0;
    while (fgets(line, MAX_LEN, f)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[0] == '#') {
            continue;
        }

        for (int j = 0; j < len; j++) {
            data[i++] = line[j];
        }

        if (i >= size) {
            break;
        }
    }

    fclose(f);

    // display QR code
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i * size + j] == 0) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }

    return 0;
}