//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main()
{
    char *original_image, *watermarked_image, *payload, *recovered_payload;
    int original_size, watermarked_size, payload_size;

    printf("Elementary, my dear Watson! Enter the path to the original image (e.g., /path/to/image.jpg): ");
    original_image = malloc(MAX_LEN);
    scanf("%s", original_image);

    FILE *original_file = fopen(original_image, "rb");
    if (original_file == NULL)
    {
        fprintf(stderr, "Error: Unable to open the original image. Please check the path.\n");
        return 1;
    }

    fseek(original_file, 0, SEEK_END);
    original_size = ftell(original_file);
    rewind(original_file);

    printf("Excellent! Now, give me the secret payload (e.g., \"The game is afoot\"): ");
    payload = malloc(MAX_LEN);
    scanf("%s", payload);

    payload_size = strlen(payload);

    printf("Admirable! Let us hide the payload within the image. Enter the path to save the watermarked image (e.g., /path/to/watermarked.jpg): ");
    watermarked_image = malloc(MAX_LEN);
    scanf("%s", watermarked_image);

    FILE *watermarked_file = fopen(watermarked_image, "wb");
    if (watermarked_file == NULL)
    {
        fprintf(stderr, "Error: Unable to open the watermarked image. Please check the path.\n");
        return 1;
    }

    unsigned char *buffer = malloc(original_size + payload_size);
    fread(buffer, 1, original_size, original_file);
    memcpy(buffer + original_size, payload, payload_size);
    fwrite(buffer, 1, original_size + payload_size, watermarked_file);

    printf("Magnificent! The image is now watermarked with the payload. Let us extract it and verify our brilliance.\n");

    fseek(watermarked_file, 0, SEEK_END);
    watermarked_size = ftell(watermarked_file);
    rewind(watermarked_file);

    unsigned char *buffer2 = malloc(watermarked_size);
    fread(buffer2, 1, watermarked_size, watermarked_file);
    recovered_payload = malloc(payload_size + 1);
    memcpy(recovered_payload, buffer2 + original_size, payload_size);
    recovered_payload[payload_size] = '\0';

    printf("Voilà! The recovered payload is: %s\n", recovered_payload);

    printf("Elementary, my dear Watson! The payload has been successfully recovered. The game is indeed afoot.\n");

    fclose(original_file);
    fclose(watermarked_file);
    free(original_image);
    free(watermarked_image);
    free(payload);
    free(recovered_payload);
    free(buffer);
    free(buffer2);

    return 0;
}