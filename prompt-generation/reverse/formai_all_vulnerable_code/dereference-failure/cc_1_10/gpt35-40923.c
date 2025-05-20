//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_SIZE 100
#define MAX_WATERMARK_SIZE 20

char* random_string(int len) {
    char* str = malloc(len);
    for (int i = 0; i < len-1; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[len-1] = '\0';
    return str;
}

void generate_watermark(char* watermark) {
    srand(time(NULL));  
    int len = rand() % (MAX_WATERMARK_SIZE-1) + 1;
    char* str = random_string(len);
    strcpy(watermark, str);
    free(str);
}

int main() {
    char text[MAX_TEXT_SIZE];
    char watermark[MAX_WATERMARK_SIZE];
    printf("Enter text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    generate_watermark(watermark);
    printf("Watermark: %s\n", watermark);

    // Watermarking
    int text_len = strlen(text);
    int watermark_len = strlen(watermark);
    for (int i = 0; i < text_len && i+watermark_len <= MAX_TEXT_SIZE-1; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            continue;
        }
        for (int j = 0; j < watermark_len; j++) {
            if (watermark[j] == ' ') {
                continue;
            }
            int pos = (i+j) % text_len;
            text[pos] ^= watermark[j];
        }
    }
    printf("Watermarked text: %s", text);
    return 0;
}