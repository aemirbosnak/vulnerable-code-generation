//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct QRCodeReader {
    unsigned char* buffer;
    int bufferSize;
    int readPos;
    int writePos;
    int state;
} QRCodeReader;

void qrReaderInit(QRCodeReader* reader) {
    reader->buffer = (unsigned char*)malloc(MAX_BUFFER_SIZE);
    reader->bufferSize = MAX_BUFFER_SIZE;
    reader->readPos = 0;
    reader->writePos = 0;
    reader->state = 0;
}

void qrReaderRead(QRCodeReader* reader, unsigned char data) {
    reader->buffer[reader->writePos++] = data;
    if (reader->writePos == reader->bufferSize) {
        reader->writePos = 0;
    }

    if (reader->state == 0) {
        if (reader->readPos == reader->writePos) {
            reader->state = 1;
        }
    } else if (reader->state == 1) {
        if (reader->readPos == reader->writePos) {
            reader->state = 2;
        }
    } else if (reader->state == 2) {
        if (reader->readPos == reader->writePos) {
            reader->state = 0;
            printf("QR code read: %s\n", reader->buffer);
        }
    }
}

int main() {
    QRCodeReader reader;
    qrReaderInit(&reader);

    qrReaderRead(&reader, 0x12);
    qrReaderRead(&reader, 0x34);
    qrReaderRead(&reader, 0x56);
    qrReaderRead(&reader, 0x78);
    qrReaderRead(&reader, 0x9A);

    return 0;
}