//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

/* Function to embed watermark in the input image */
char* embed_watermark(char* input_image, char* watermark) {
    char* output_image = malloc(sizeof(char) * MAX_INPUT_SIZE);
    strcat(output_image, input_image);
    strcat(output_image, watermark);
    return output_image;
}

/* Function to extract watermark from the watermarked image */
char* extract_watermark(char* watermarked_image, int watermark_size) {
    char* extracted_watermark = malloc(sizeof(char) * (watermark_size + 1));
    int i, j; 
    for(i = strlen(watermarked_image) - 1, j = 0; j < watermark_size; i--, j++) {
        extracted_watermark[j] = watermarked_image[i];
    }
    extracted_watermark[j] = '\0';
    return extracted_watermark;
}

/* Main function */
int main() {
    char* input_image = "input.jpg";
    char* watermark = "This is a sample watermark";
    char* output_image;
    char* watermarked_image;
    char* extracted_watermark;

    /* Embedding watermark in the input image */
    output_image = embed_watermark(input_image, watermark);

    /* Displaying the watermarked image */
    printf("The watermarked image is: %s\n", output_image);

    /* Extracting watermark from the watermarked image */
    watermarked_image = output_image;
    extracted_watermark = extract_watermark(watermarked_image, strlen(watermark));

    /* Displaying the extracted watermark */
    printf("The extracted watermark is: %s\n", extracted_watermark);

    /* Cleaning up */
    free(output_image);
    free(extracted_watermark);

    return 0;
}