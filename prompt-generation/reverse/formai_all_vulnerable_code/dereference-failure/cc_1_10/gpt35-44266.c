//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 256

void *generate_qr_code(void *args);
char *get_string_from_user();

int main(int argc, char *argv[]) {

    // Initialize variables
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    char *qr_strings[MAX_THREADS];
    
    // Get user input
    char *input_string;
    input_string = get_string_from_user();

    // Generate QR codes
    for (int i = 0; i < strlen(input_string); i++) {

        // Create thread
        if (thread_count < MAX_THREADS) {
            qr_strings[thread_count] = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
            strcpy(qr_strings[thread_count], "");
            pthread_create(&threads[thread_count], NULL, generate_qr_code, (void *)qr_strings[thread_count]);
            thread_count++;
        }

        // Wait for thread to finish and print QR code
        if (thread_count == MAX_THREADS || i == strlen(input_string) - 1) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
                printf("%s\n", qr_strings[j]);
                free(qr_strings[j]);
            }
            thread_count = 0;
        }
    }

    return 0;
}

void *generate_qr_code(void *args) {

    // Get string from args
    char *qr_string = (char *)args;

    // Generate QR code
    QRcode *qr;
    char *binary_buffer;
    qr = QRcode_encodeString(qr_string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    binary_buffer = (char *)malloc(sizeof(char) * (qr->width * qr->width));

    // Convert QR code to binary format
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            int pos = (y * qr->width) + x;
            binary_buffer[pos] = qr->data[pos] & 1 ? '#' : ' ';
        }
        binary_buffer[(y * qr->width) + qr->width] = '\n';
    }

    // Store QR code as string in args
    strcpy(qr_string, binary_buffer);

    // Free memory
    QRcode_free(qr);
    free(binary_buffer);

    return NULL;
}

char *get_string_from_user() {

    // Initialize variables
    char *input_string = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
    int input_index = 0;
    char input_char;

    // Read input character by character until a newline character is found
    while ((input_char = getchar()) != '\n') {
        input_string[input_index] = input_char;
        input_index++;
    }
    input_string[input_index] = '\0';

    return input_string;
}