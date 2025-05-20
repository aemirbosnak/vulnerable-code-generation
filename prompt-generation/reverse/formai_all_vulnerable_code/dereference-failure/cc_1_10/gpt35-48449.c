//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

void hide(char *filename, char *msg, char *output_filename) {
    FILE *fptr = fopen(filename, "rb");
    FILE *fout = fopen(output_filename, "wb");

    if (fptr == NULL || fout == NULL)
        return;

    char *image_data = (char *)malloc(MAX_SIZE);
    int num_bytes_read = fread(image_data, sizeof(char), MAX_SIZE, fptr);

    if (num_bytes_read < strlen(msg) * 8) {
        printf("Message too large to hide.\n");
        return;
    }

    int msg_length = strlen(msg);
    char *bin_msg = (char *)malloc(msg_length * 8);
    for (int i = 0; i < msg_length; i++) {
        int tmp = msg[i];
        for (int j = i * 8 + 7; j >= i * 8; j--) {
            bin_msg[j] = tmp % 2;
            tmp /= 2;
        }
    }

    int bin_msg_idx = 0;
    for (int i = 0; i < num_bytes_read; i++) {
        if (bin_msg_idx >= strlen(bin_msg)) {
            fwrite(&image_data[i], sizeof(char), 1, fout);
            continue;
        }

        char tmp = image_data[i];
        for (int j = 7; j >= 0; j--) {
            tmp = (tmp & ~(1 << j)) | (bin_msg[bin_msg_idx++] << j);
            if (bin_msg_idx >= strlen(bin_msg))
                break;
        }

        fwrite(&tmp, sizeof(char), 1, fout);
    }

    fclose(fptr);
    fclose(fout);

    printf("Message hidden.\n");
}

void extract(char *filename) {
    FILE *fptr = fopen(filename, "rb");

    if (fptr == NULL)
        return;

    char *image_data = (char *)malloc(MAX_SIZE);
    int num_bytes_read = fread(image_data, sizeof(char), MAX_SIZE, fptr);

    int msg_length = 0;
    char *bin_msg = (char *)malloc(MAX_SIZE);
    for (int i = 0; i < num_bytes_read; i++) {
        char tmp = image_data[i];
        for (int j = 7; j >= 0; j--) {
            bin_msg[msg_length++] = ((tmp & (1 << j)) ? 1 : 0);
        }
    }

    char *msg = (char *)malloc(msg_length / 8);
    for (int i = 0; i < msg_length / 8; i++) {
        int tmp = 0;
        for (int j = i * 8; j < (i + 1) * 8; j++) {
            tmp = (tmp << 1) | bin_msg[j];
        }
        msg[i] = (char)tmp;
    }

    printf("Extracted message: %s\n", msg);
    fclose(fptr);
}

int main() {
    char *filename = "sample.jpg";
    char *msg = "This is a secret message.";
    char *output_filename = "output.jpg";

    hide(filename, msg, output_filename);
    extract(output_filename);

    return 0;
}