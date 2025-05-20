//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define HIDDEN_SIZE 1024

void hide_data(char* cover_file, char* stego_file, char* message) {
    FILE* cover_fp = fopen(cover_file, "rb");
    FILE* stego_fp = fopen(stego_file, "wb");
    int cover_size = 0;
    int message_size = strlen(message);
    char* cover_buffer = malloc(MAX_SIZE);
    char* stego_buffer = malloc(MAX_SIZE);
    int hidden_size = 0;

    while (fread(cover_buffer, 1, MAX_SIZE, cover_fp) > 0) {
        cover_size += fwrite(cover_buffer, 1, MAX_SIZE, stego_fp);
        hidden_size += fwrite(message, 1, message_size, stego_fp);
        if (hidden_size >= HIDDEN_SIZE) {
            break;
        }
    }

    fclose(cover_fp);
    fclose(stego_fp);
    free(cover_buffer);
    free(stego_buffer);
}

void extract_data(char* stego_file, char* message) {
    FILE* stego_fp = fopen(stego_file, "rb");
    int message_size = strlen(message);
    char* stego_buffer = malloc(MAX_SIZE);

    while (fread(stego_buffer, 1, MAX_SIZE, stego_fp) > 0) {
        int i = 0;
        while (i < message_size && stego_buffer[i] == message[i]) {
            i++;
        }
        if (i == message_size) {
            printf("Message found!\n");
        }
    }

    fclose(stego_fp);
    free(stego_buffer);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <cover_file> <stego_file> <message> <hide/extract>\n", argv[0]);
        return 1;
    }

    char* cover_file = argv[1];
    char* stego_file = argv[2];
    char* message = argv[3];
    char* operation = argv[4];

    if (strcmp(operation, "hide") == 0) {
        hide_data(cover_file, stego_file, message);
    } else if (strcmp(operation, "extract") == 0) {
        extract_data(stego_file, message);
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    return 0;
}