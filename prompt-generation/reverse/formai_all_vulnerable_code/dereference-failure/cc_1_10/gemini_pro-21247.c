//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} QRCode;

QRCode *create_qrcode(char *data) {
    // Initialize the QR code
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->points = malloc(sizeof(Point) * WIDTH * HEIGHT);
    qrcode->num_points = 0;

    // Generate the QR code data
    int data_length = strlen(data);
    unsigned char *data_bytes = malloc(data_length);
    for (int i = 0; i < data_length; i++) {
        data_bytes[i] = data[i];
    }

    // Create the QR code matrix
    int matrix[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = 0;
        }
    }

    // Place the finder patterns
    for (int i = 0; i < 7; i++) {
        matrix[i][i] = 1;
        matrix[i][WIDTH - 1 - i] = 1;
        matrix[HEIGHT - 1 - i][i] = 1;
        matrix[HEIGHT - 1 - i][WIDTH - 1 - i] = 1;
    }

    // Place the timing patterns
    for (int i = 2; i < WIDTH - 2; i++) {
        matrix[i][6] = 1;
        matrix[6][i] = 1;
    }

    // Place the alignment patterns
    for (int i = 1; i < WIDTH - 1; i++) {
        if (i % 2 == 0) {
            matrix[i][i] = 1;
            matrix[WIDTH - 1 - i][i] = 1;
            matrix[i][WIDTH - 1 - i] = 1;
        }
    }

    // Place the version information
    int version = 1;
    for (int i = 0; i < 6; i++) {
        matrix[8][i] = (version >> i) & 1;
        matrix[i][8] = (version >> i) & 1;
    }

    // Place the data
    int data_index = 0;
    for (int i = 9; i < WIDTH - 1; i++) {
        for (int j = 9; j < HEIGHT - 1; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = data_bytes[data_index] >> (7 - (i + j) % 8) & 1;
                data_index++;
            }
        }
    }

    // Add the points to the QR code
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (matrix[i][j] == 1) {
                qrcode->points[qrcode->num_points].x = i;
                qrcode->points[qrcode->num_points].y = j;
                qrcode->num_points++;
            }
        }
    }

    // Free the data bytes
    free(data_bytes);

    return qrcode;
}

void print_qrcode(QRCode *qrcode) {
    // Print the QR code
    for (int i = 0; i < qrcode->num_points; i++) {
        printf("%d %d\n", qrcode->points[i].x, qrcode->points[i].y);
    }
}

void free_qrcode(QRCode *qrcode) {
    // Free the QR code
    free(qrcode->points);
    free(qrcode);
}

int main() {
    // Get the input data
    char *data = "Hello, world!";

    // Create the QR code
    QRCode *qrcode = create_qrcode(data);

    // Print the QR code
    print_qrcode(qrcode);

    // Free the QR code
    free_qrcode(qrcode);

    return 0;
}