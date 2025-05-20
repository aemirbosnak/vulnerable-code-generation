//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define MAX_MSG_SIZE 256

typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

void encode_msg_in_bmp(const char *img_path, const char *msg, const char *out_path);
void decode_msg_from_bmp(const char *img_path);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image.bmp> <message> <output_image.bmp>\n", argv[0]);
        return 1;
    }
    encode_msg_in_bmp(argv[1], argv[2], argv[3]);
    decode_msg_from_bmp(argv[3]);
    
    return 0;
}

void encode_msg_in_bmp(const char *img_path, const char *msg, const char *out_path) {
    FILE *fp = fopen(img_path, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open %s\n", img_path);
        exit(1);
    }
    
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, fp);

    int img_size = header.bfSize - header.bfOffBits;
    unsigned char *img_data = (unsigned char *)malloc(img_size);
    fseek(fp, header.bfOffBits, SEEK_SET);
    fread(img_data, 1, img_size, fp);
    fclose(fp);

    size_t msg_len = strlen(msg);
    if (msg_len > MAX_MSG_SIZE) {
        fprintf(stderr, "Error: Message too long!\n");
        free(img_data);
        exit(1);
    }
    
    for (size_t i = 0; i < msg_len; ++i) {
        for (int j = 0; j < 8; ++j) {
            img_data[i * 8 + j] = (img_data[i * 8 + j] & 0xFE) | ((msg[i] >> (7 - j)) & 1);
        }
    }

    FILE *out_fp = fopen(out_path, "wb");
    fwrite(&header, sizeof(BMPHeader), 1, out_fp);
    fwrite(img_data, 1, img_size, out_fp);
    fclose(out_fp);
    free(img_data);
}

void decode_msg_from_bmp(const char *img_path) {
    FILE *fp = fopen(img_path, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open %s\n", img_path);
        exit(1);
    }
    
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, fp);
    
    int img_size = header.bfSize - header.bfOffBits;
    unsigned char *img_data = (unsigned char *)malloc(img_size);
    fseek(fp, header.bfOffBits, SEEK_SET);
    fread(img_data, 1, img_size, fp);
    fclose(fp);

    char msg[MAX_MSG_SIZE];
    size_t msg_len = 0;
    
    for (size_t i = 0; ; ++i) {
        if (msg_len >= MAX_MSG_SIZE - 1) {
            break;
        }
        
        char ch = 0;
        for (int j = 0; j < 8; ++j) {
            ch = (ch << 1) | (img_data[i * 8 + j] & 1);
        }
        msg[msg_len++] = ch;

        if (ch == '\0') {
            break;
        }
    }
    
    printf("Decoded Message: %s\n", msg);
    free(img_data);
}