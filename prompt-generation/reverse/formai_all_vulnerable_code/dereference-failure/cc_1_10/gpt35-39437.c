//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_SIZE 1000
#define WATERMARK_SIZE 50

char* generate_watermark() {
    char* watermark = (char*) malloc(sizeof(char) * (WATERMARK_SIZE + 1));
    srand(time(NULL));
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = (char) (rand() % 26 + 'a');
    }
    watermark[WATERMARK_SIZE] = '\0';
    return watermark;
}

char* embed_watermark(char* message, char* watermark) {
    int message_len = strlen(message);
    int watermark_len = strlen(watermark);
    int index = rand() % (message_len - watermark_len);
    char* with_watermark = (char*) malloc(sizeof(char) * (message_len + 1));
    strncpy(with_watermark, message, index);
    strncpy(with_watermark + index, watermark, watermark_len);
    strncpy(with_watermark + index + watermark_len, message + index + watermark_len, message_len - index - watermark_len);
    with_watermark[message_len] = '\0';
    return with_watermark;
}

int extract_watermark(char* message, char** watermark_ptr) {
    int message_len = strlen(message);
    int watermark_len = strlen(*watermark_ptr);
    for (int i = 0; i <= message_len - watermark_len; i++) {
        if (strncmp(message + i, *watermark_ptr, watermark_len) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    printf("Enter message:\n");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    char* watermark = generate_watermark();
    printf("Watermark generated: %s\n", watermark);
    char* with_watermark = embed_watermark(message, watermark);
    printf("Message with watermark: %s", with_watermark);
    char* extracted_watermark_ptr = watermark;
    int watermark_index = extract_watermark(with_watermark, &extracted_watermark_ptr);
    if (watermark_index == -1) {
        printf("Watermark not found.\n");
    }
    else {
        printf("Watermark found at index %d.\n", watermark_index);
    }
    free(watermark);
    free(with_watermark);
    return 0;
}