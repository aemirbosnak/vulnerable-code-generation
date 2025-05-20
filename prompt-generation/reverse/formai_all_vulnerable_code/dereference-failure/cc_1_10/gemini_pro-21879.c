//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define QR_CODE_SIZE 256
#define MAX_NUM_QR_CODES 100
#define MAX_NUM_PIXELS 10000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

typedef struct {
    Rectangle rectangle;
    char* data;
} QRCode;

typedef struct {
    QRCode qr_codes[MAX_NUM_QR_CODES];
    int num_qr_codes;
} QRCodeCollection;

QRCodeCollection* init_qr_code_collection() {
    QRCodeCollection* qr_code_collection = malloc(sizeof(QRCodeCollection));
    qr_code_collection->num_qr_codes = 0;
    return qr_code_collection;
}

void free_qr_code_collection(QRCodeCollection* qr_code_collection) {
    for (int i = 0; i < qr_code_collection->num_qr_codes; i++) {
        free(qr_code_collection->qr_codes[i].data);
    }
    free(qr_code_collection);
}

QRCode* init_qr_code(Rectangle rectangle, char* data) {
    QRCode* qr_code = malloc(sizeof(QRCode));
    qr_code->rectangle = rectangle;
    qr_code->data = malloc(strlen(data) + 1);
    strcpy(qr_code->data, data);
    return qr_code;
}

void free_qr_code(QRCode* qr_code) {
    free(qr_code->data);
    free(qr_code);
}

void add_qr_code_to_collection(QRCodeCollection* qr_code_collection, QRCode* qr_code) {
    qr_code_collection->qr_codes[qr_code_collection->num_qr_codes++] = *qr_code;
}

void print_qr_code_collection(QRCodeCollection* qr_code_collection) {
    for (int i = 0; i < qr_code_collection->num_qr_codes; i++) {
        printf("QR Code %d:\n", i + 1);
        printf("Top left corner: (%d, %d)\n", qr_code_collection->qr_codes[i].rectangle.top_left.x, qr_code_collection->qr_codes[i].rectangle.top_left.y);
        printf("Bottom right corner: (%d, %d)\n", qr_code_collection->qr_codes[i].rectangle.bottom_right.x, qr_code_collection->qr_codes[i].rectangle.bottom_right.y);
        printf("Data: %s\n", qr_code_collection->qr_codes[i].data);
        printf("\n");
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a QR code collection
    QRCodeCollection* qr_code_collection = init_qr_code_collection();

    // Generate a random number of QR codes
    int num_qr_codes = rand() % MAX_NUM_QR_CODES;

    // Generate a random QR code for each number
    for (int i = 0; i < num_qr_codes; i++) {
        // Generate a random rectangle for the QR code
        Rectangle rectangle;
        rectangle.top_left.x = rand() % QR_CODE_SIZE;
        rectangle.top_left.y = rand() % QR_CODE_SIZE;
        rectangle.bottom_right.x = rectangle.top_left.x + rand() % (QR_CODE_SIZE - rectangle.top_left.x);
        rectangle.bottom_right.y = rectangle.top_left.y + rand() % (QR_CODE_SIZE - rectangle.top_left.y);

        // Generate a random data string for the QR code
        int data_length = rand() % MAX_NUM_PIXELS;
        char* data = malloc(data_length + 1);
        for (int j = 0; j < data_length; j++) {
            data[j] = rand() % 256;
        }
        data[data_length] = '\0';

        // Create a QR code and add it to the collection
        QRCode* qr_code = init_qr_code(rectangle, data);
        add_qr_code_to_collection(qr_code_collection, qr_code);
    }

    // Print the QR code collection
    print_qr_code_collection(qr_code_collection);

    // Free the QR code collection
    free_qr_code_collection(qr_code_collection);

    return 0;
}