//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define WATERMARK_LENGTH 10

typedef struct {
    char* message;
    char* watermark;
} Data;

Data* create_data(char* message, char* watermark) {
    Data* data = (Data*) malloc(sizeof(Data));
    data->message = (char*) malloc(strlen(message) + 1);
    data->watermark = (char*) malloc(WATERMARK_LENGTH + 1);
    strcpy(data->message, message);
    strcpy(data->watermark, watermark);
    return data;
}

void print_data(Data* data) {
    printf("Message: %s\n", data->message);
    printf("Watermark: %s\n", data->watermark);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char watermark[WATERMARK_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter watermark (10 characters max): ");
    fgets(watermark, WATERMARK_LENGTH, stdin);
    Data* data = create_data(message, watermark);
    printf("\nOriginal Data:\n");
    print_data(data);

    // Insert watermark
    int watermark_position = rand() % strlen(data->message);
    for (int i = 0; i < WATERMARK_LENGTH; i++) {
        data->message[watermark_position + i] = data->watermark[i];
    }
    printf("\nData with Watermark:\n");
    print_data(data);
    
    // Extract watermark
    char extracted_watermark[WATERMARK_LENGTH + 1];
    for (int i = 0; i < WATERMARK_LENGTH; i++) {
        extracted_watermark[i] = data->message[watermark_position + i];
    }
    extracted_watermark[WATERMARK_LENGTH] = '\0';
    printf("\nExtracted Watermark: %s\n", extracted_watermark);
    free(data->message);
    free(data->watermark);
    free(data);
    return 0;
}