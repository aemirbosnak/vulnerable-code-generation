//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the image
#define WIDTH 512
#define HEIGHT 512

// Define the size of the watermark
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64

// Define the number of bits in the watermark
#define NUM_BITS 1024

// Define the strength of the watermark
#define STRENGTH 0.5

// Define the minimum and maximum values for the pixel values
#define MIN_VALUE 0
#define MAX_VALUE 255

// Define the number of bins for the histogram
#define NUM_BINS 256

// Read the image from a file
unsigned char *read_image(char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Allocate memory for the image
  unsigned char *image = malloc(WIDTH * HEIGHT);
  if (image == NULL) {
    perror("Error allocating memory for image");
    exit(1);
  }

  // Read the image data from the file
  fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
  fclose(file);

  return image;
}

// Write the image to a file
void write_image(char *filename, unsigned char *image) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Write the image data to the file
  fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
  fclose(file);
}

// Create a watermark
unsigned char *create_watermark(char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Allocate memory for the watermark
  unsigned char *watermark = malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT);
  if (watermark == NULL) {
    perror("Error allocating memory for watermark");
    exit(1);
  }

  // Read the watermark data from the file
  fread(watermark, sizeof(unsigned char), WATERMARK_WIDTH * WATERMARK_HEIGHT, file);
  fclose(file);

  return watermark;
}

// Embed the watermark in the image
void embed_watermark(unsigned char *image, unsigned char *watermark) {
  // Convert the watermark to a binary string
  char *binary_watermark = malloc(NUM_BITS);
  if (binary_watermark == NULL) {
    perror("Error allocating memory for binary watermark");
    exit(1);
  }

  for (int i = 0; i < NUM_BITS; i++) {
    binary_watermark[i] = (watermark[i / 8] >> (i % 8)) & 1;
  }

  // Embed the watermark in the image
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    if (binary_watermark[i] == 1) {
      image[i] += STRENGTH * (MAX_VALUE - image[i]);
    } else {
      image[i] -= STRENGTH * image[i];
    }
  }

  free(binary_watermark);
}

// Extract the watermark from the image
unsigned char *extract_watermark(unsigned char *image) {
  // Create a histogram of the pixel values
  int histogram[NUM_BINS];
  for (int i = 0; i < NUM_BINS; i++) {
    histogram[i] = 0;
  }

  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    histogram[image[i]]++;
  }

  // Find the mean and standard deviation of the histogram
  double mean = 0;
  double stddev = 0;

  for (int i = 0; i < NUM_BINS; i++) {
    mean += i * histogram[i];
    stddev += pow(i - mean, 2) * histogram[i];
  }

  mean /= WIDTH * HEIGHT;
  stddev = sqrt(stddev / (WIDTH * HEIGHT));

  // Create a binary string for the watermark
  char *binary_watermark = malloc(NUM_BITS);
  if (binary_watermark == NULL) {
    perror("Error allocating memory for binary watermark");
    exit(1);
  }

  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    if (image[i] > mean + STRENGTH * stddev) {
      binary_watermark[i] = 1;
    } else {
      binary_watermark[i] = 0;
    }
  }

  // Convert the binary string to a watermark
  unsigned char *watermark = malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT);
  if (watermark == NULL) {
    perror("Error allocating memory for watermark");
    exit(1);
  }

  for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT; i++) {
    watermark[i] = 0;
    for (int j = 0; j < 8; j++) {
      watermark[i] |= binary_watermark[i * 8 + j] << j;
    }
  }

  free(binary_watermark);

  return watermark;
}

// Compare the original watermark to the extracted watermark
int compare_watermarks(unsigned char *original_watermark, unsigned char *extracted_watermark) {
  int num_differences = 0;

  for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT; i++) {
    if (original_watermark[i] != extracted_watermark[i]) {
      num_differences++;
    }
  }

  return num_differences;
}

// Main function
int main(int argc, char *argv[]) {
  // Check the command line arguments
  if (argc != 4) {
    printf("Usage: %s <image_file> <watermark_file> <output_file>\n", argv[0]);
    exit(1);
  }

  // Read the image and watermark
  unsigned char *image = read_image(argv[1]);
  unsigned char *watermark = create_watermark(argv[2]);

  // Embed the watermark in the image
  embed_watermark(image, watermark);

  // Extract the watermark from the image
  unsigned char *extracted_watermark = extract_watermark(image);

  // Compare the original watermark to the extracted watermark
  int num_differences = compare_watermarks(watermark, extracted_watermark);

  // Print the number of differences
  printf("Number of differences: %d\n", num_differences);

  // Write the watermarked image to a file
  write_image(argv[3], image);

  // Free the memory
  free(image);
  free(watermark);
  free(extracted_watermark);

  return 0;
}