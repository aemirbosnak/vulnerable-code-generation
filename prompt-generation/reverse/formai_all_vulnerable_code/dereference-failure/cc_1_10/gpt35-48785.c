//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hide_secret_data(FILE *orig_fp, FILE *msg_fp, FILE *encoded_fp);
void extract_secret_data(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("USAGE: stegano <original_image> <message_file> <encoded_image>\n");
        return 1;
    }

    FILE *orig_fp, *msg_fp, *encoded_fp;
    orig_fp = fopen(argv[1], "rb");
    msg_fp = fopen(argv[2], "r");
    encoded_fp = fopen(argv[3], "wb");

    if (orig_fp == NULL || msg_fp == NULL || encoded_fp == NULL) {
        printf("ERROR: Could not open file.\n");
        return 1;
    }

    hide_secret_data(orig_fp, msg_fp, encoded_fp);

    fclose(orig_fp);
    fclose(msg_fp);
    fclose(encoded_fp);

    extract_secret_data(encoded_fp);

    return 0;
}

void hide_secret_data(FILE *orig_fp, FILE *msg_fp, FILE *encoded_fp) {
    unsigned char pixel[3];
    char msg_char = 0;
    int bit_cnt = 0;

    while (fread(pixel, 3, 1, orig_fp)) {
        if (bit_cnt >= 8) {
            fwrite(&msg_char, 1, 1, encoded_fp);
            if (msg_char == '\0') {
                break;
            }
            msg_char = 0;
            bit_cnt = 0;
        }
        if (!feof(msg_fp)) {
            char msg = fgetc(msg_fp);
            for (int i = 7; i >= 0; i--) {
                if ((msg >> i) & 1) {
                    pixel[2] &= ~1;
                    pixel[2] |= 1;
                } else {
                    pixel[2] &= ~1;
                }
                fwrite(pixel, 3, 1, encoded_fp);
                bit_cnt++;
                if (bit_cnt >= 8) {
                    break;
                }
            }
        }
        if (feof(msg_fp)) {
            fwrite(pixel, 3, 1, encoded_fp);
        }
    }
}

void extract_secret_data(FILE *fp) {
    unsigned char pixel[3];
    char msg_char = 0;
    int bit_cnt = 0;

    while (fread(pixel, 3, 1, fp)) {
        if (bit_cnt >= 8) {
            if (msg_char == '\0') {
                break;
            }
            printf("%c", msg_char);
            msg_char = 0;
            bit_cnt = 0;
        }
        if ((pixel[2] & 1) == 1) {
            msg_char |= 1 << (7 - bit_cnt);
        } else {
            msg_char &= ~(1 << (7 - bit_cnt));
        }
        bit_cnt++;
    }
}