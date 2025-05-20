//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert integer to binary string
char* int2bin(int num, int bit_count) {
    char* bin_str = (char*)calloc(bit_count + 1, sizeof(char));
    for (int i = bit_count-1; i >= 0; i--, num >>= 1) 
        bin_str[i] = (num & 1) + '0';
    return bin_str;
}

// Function to convert binary string to integer
int bin2int(char* bin_str) {
    int num = 0, len = strlen(bin_str);
    for (int i = 0; i < len; i++)
        num += (bin_str[i] - '0') * (1 << (len - i - 1));
    return num;
}

// Function to hide a message in the given image
void embed_message(const char* img_path, const char* msg, const char* out_path) {
    FILE* img_fp = fopen(img_path, "rb");
    fseek(img_fp, 0, SEEK_END);
    long img_size = ftell(img_fp);
    rewind(img_fp);
    char* img_data = (char*)malloc(img_size);
    fread(img_data, 1, img_size, img_fp);
    fclose(img_fp);

    char* msg_bin = (char*)malloc(strlen(msg) * 8 + 1);
    int msg_len = strlen(msg);
    for (int i = 0, j = 0; i < msg_len; i++, j+=8)
        strcpy(msg_bin + j, int2bin(msg[i], 8));
    sprintf(msg_bin + strlen(msg_bin), "%08d", msg_len * 8); // adding length info

    if (strlen(msg_bin) > (img_size - 54) * 4) {
        printf("Image too small to hide the message!");
        return;
    }

    for (int i = 0, j = 54; i < strlen(msg_bin); i+=4, j++) {
        int r = (int)img_data[j], g = (int)img_data[j+1], b = (int)img_data[j+2], a = (int)img_data[j+3];
        char r_bin[9], g_bin[9], b_bin[9], a_bin[9];
        strcpy(r_bin, int2bin(r, 8));
        strcpy(g_bin, int2bin(g, 8));
        strcpy(b_bin, int2bin(b, 8));
        strcpy(a_bin, int2bin(a, 8));
        r_bin[7] = msg_bin[i];
        g_bin[7] = msg_bin[i+1];
        b_bin[7] = msg_bin[i+2];
        a_bin[7] = msg_bin[i+3];
        r = bin2int(r_bin);
        g = bin2int(g_bin);
        b = bin2int(b_bin);
        a = bin2int(a_bin);
        img_data[j] = (char)r;
        img_data[j+1] = (char)g;
        img_data[j+2] = (char)b;
        img_data[j+3] = (char)a;
    }

    FILE* out_fp = fopen(out_path, "wb");
    fwrite(img_data, 1, img_size, out_fp);
    fclose(out_fp);

    free(img_data);
    free(msg_bin);
    printf("Message embedded successfully!\n");
}

// Function to extract message from the given image
void extract_message(const char* img_path) {
    FILE* img_fp = fopen(img_path, "rb");
    fseek(img_fp, 0, SEEK_END);
    long img_size = ftell(img_fp);
    rewind(img_fp);
    char* img_data = (char*)malloc(img_size);
    fread(img_data, 1, img_size, img_fp);
    fclose(img_fp);

    char msg_bin[img_size * 4];
    int j = 0;
    for (int i = 54; i < img_size; i+=4, j++) {
        int r = (int)img_data[i], g = (int)img_data[i+1], b = (int)img_data[i+2], a = (int)img_data[i+3];
        char r_bin[9], g_bin[9], b_bin[9], a_bin[9];
        strcpy(r_bin, int2bin(r, 8));
        strcpy(g_bin, int2bin(g, 8));
        strcpy(b_bin, int2bin(b, 8));
        strcpy(a_bin, int2bin(a, 8));
        msg_bin[j] = r_bin[7];
        msg_bin[j+1] = g_bin[7];
        msg_bin[j+2] = b_bin[7];
        msg_bin[j+3] = a_bin[7];
    }

    int msg_len = bin2int(msg_bin + strlen(msg_bin) - 8) / 8;
    char* msg = (char*)malloc(msg_len + 1);
    for (int i = 0, j = 0; i < msg_len; i++, j+=8)
        msg[i] = bin2int(msg_bin + j);
    msg[msg_len] = '\0';

    free(img_data);
    printf("Message extracted successfully: %s\n", msg);
}

int main() {
    char img_path[100], out_path[100], msg[100];
    printf("Welcome to the Image Steganography program!\n");

    printf("Enter the path of the image file to process:\n");
    scanf("%s", img_path);

    printf("Do you want to embed or extract a message? (e/x)\n");
    char option;
    scanf(" %c", &option);

    switch (option) {
        case 'e':
            extract_message(img_path);
            break;
        case 'x':
            printf("Enter the message to embed (max. 100 chars):\n");
            scanf(" %[^\n]s", msg);
            printf("Enter the path to save the output image:\n");
            scanf("%s", out_path);
            embed_message(img_path, msg, out_path);
            break;
        default:
            printf("Invalid option selected!\n");
    }

    return 0;
}