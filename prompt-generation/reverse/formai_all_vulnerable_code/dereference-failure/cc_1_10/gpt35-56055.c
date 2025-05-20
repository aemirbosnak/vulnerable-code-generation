//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256
#define MAX_BIT_LEN 8

char* get_binary(int n);
char* watermark(char* message, char* watermark_str);
char* extract_watermark(char* marked_msg, int watermark_len);

int main() {
    char message[MAX_MSG_LEN];
    char watermark_str[MAX_MSG_LEN];
    char marked_msg[MAX_MSG_LEN];
    int watermark_len;

    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    printf("Enter watermark string: ");
    fgets(watermark_str, MAX_MSG_LEN, stdin);

    watermark_len = strlen(watermark_str) - 1; // exclude newline character

    strcpy(marked_msg, watermark(message, watermark_str));

    printf("Marked message: %s\n", marked_msg);
    printf("Extracted watermark: %s\n", extract_watermark(marked_msg, watermark_len));

    return 0;
}

char* get_binary(int n) {
    char* binary = (char*)malloc(MAX_BIT_LEN + 1);
    int i = MAX_BIT_LEN - 1;

    while (n > 0) {
        binary[i] = (n % 2) + '0';
        n /= 2;
        i--;
    }

    while (i >= 0) {
        binary[i] = '0';
        i--;
    }

    binary[MAX_BIT_LEN] = '\0';

    return binary;
}

char* watermark(char* message, char* watermark_str) {
    char* marked_msg = (char*)malloc(MAX_MSG_LEN);
    int watermark_len = strlen(watermark_str) - 1; // exclude newline character
    int msg_len = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < msg_len; i++) {
        if (message[i] == ' ' || message[i] == '\n' || message[i] == '\t') {
            marked_msg[j] = message[i];
            j++;
            continue;
        }

        char* binary = get_binary(message[i]);
        char* binary_with_watermark = (char*)malloc(MAX_BIT_LEN + 1);

        strncpy(binary_with_watermark, binary, watermark_len);
        strncpy(binary_with_watermark + watermark_len, watermark_str, MAX_MSG_LEN - watermark_len - 1);

        marked_msg[j] = (char)strtol(binary_with_watermark, NULL, 2);

        j++;
        free(binary);
        free(binary_with_watermark);
    }

    marked_msg[j] = '\0';
    return marked_msg;
}

char* extract_watermark(char* marked_msg, int watermark_len) {
    char* watermark_str = (char*)malloc(MAX_MSG_LEN);
    int msg_len = strlen(marked_msg);
    int i, j;

    for (i = 0, j = 0; i < msg_len; i++) {
        if (marked_msg[i] == ' ' || marked_msg[i] == '\n' || marked_msg[i] == '\t') {
            continue;
        }

        char* binary = get_binary(marked_msg[i]);

        strncpy(watermark_str + j, binary, watermark_len);
        j += watermark_len;

        free(binary);
    }

    watermark_str[j] = '\0';
    return watermark_str;
}