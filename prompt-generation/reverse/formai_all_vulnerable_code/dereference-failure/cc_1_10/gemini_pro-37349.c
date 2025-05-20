//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our happy little watermark!
#define WATERMARK "YayWatermarking!"

// Embed the watermark into the image.
void embed_watermark(unsigned char *image, int width, int height, char *watermark) {
  // Let's not get too carried away with our watermarking frenzy!
  if (strlen(watermark) > width * height) {
    printf("Oops! Your watermark is too big for this image. Try a smaller one.\n");
    return;
  }

  // Spread the watermark evenly throughout the image.
  int watermark_index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Hide the watermark in the least significant bits of each pixel's red channel.
      image[i * width + j] &= ~1;  // Zero out the least significant bit.
      if (watermark[watermark_index] == '1') {
        image[i * width + j] |= 1;  // Set the least significant bit to '1' if the watermark bit is '1'.
      }
      watermark_index++;
    }
  }

  printf("Hooray! Your watermark has been embedded in the image.\n");
}

// Reveal the hidden watermark from the image.
char *extract_watermark(unsigned char *image, int width, int height) {
  // Let's see what our hidden masterpiece is!
  char *watermark = malloc(width * height + 1);
  watermark[width * height] = '\0';  // Null-terminate the watermark string.

  int watermark_index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Retrieve the watermark bit from the least significant bit of each pixel's red channel.
      watermark[watermark_index++] = (image[i * width + j] & 1) ? '1' : '0';
    }
  }

  printf("Ta-da! Your hidden watermark is: %s\n", watermark);
  return watermark;
}

int main() {
  // Let's get our hands on an image!
  unsigned char *image = malloc(10000);
  int width, height;
  printf("Hey there, let's water-splash some images! Enter the image width and height (separated by a space): ");
  scanf("%d %d", &width, &height);

  // Time to add our secret message!
  char *watermark;
  printf("What's your super secret watermark message? (Keep it catchy!): ");
  scanf("%s", watermark);

  // Embed the watermark!
  embed_watermark(image, width, height, watermark);

  // Now, let's unveil the hidden treasure!
  extract_watermark(image, width, height);

  // Clean up our mess.
  free(image);
  free(watermark);

  return 0;
}