//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Romeo's secret key
char *romeo_key = "My mistress' eyes are nothing like the sun";

// Juliet's secret key
char *juliet_key = "Honey, your breath smells like garlic";

// Embed Romeo's watermark into Juliet's message
char *embed_watermark(char *message, char *key) {
  int message_len = strlen(message);
  int key_len = strlen(key);

  char *watermarked_message = malloc(message_len + 1);
  strcpy(watermarked_message, message);

  for (int i = 0; i < message_len; i++) {
    watermarked_message[i] ^= key[i % key_len];
  }

  return watermarked_message;
}

// Extract Romeo's watermark from Juliet's message
char *extract_watermark(char *watermarked_message, char *key) {
  int message_len = strlen(watermarked_message);
  int key_len = strlen(key);

  char *watermark = malloc(message_len + 1);
  strcpy(watermark, watermarked_message);

  for (int i = 0; i < message_len; i++) {
    watermark[i] ^= key[i % key_len];
  }

  return watermark;
}

int main() {
  // Juliet's message to Romeo
  char *juliet_message = "O Romeo, Romeo! Wherefore art thou Romeo?";

  // Romeo embeds his watermark into Juliet's message
  char *watermarked_message = embed_watermark(juliet_message, romeo_key);

  // Juliet sends the watermarked message to Romeo
  printf("Juliet: %s\n", watermarked_message);

  // Romeo extracts his watermark from Juliet's message
  char *watermark = extract_watermark(watermarked_message, romeo_key);

  // Romeo checks if the extracted watermark matches his secret key
  if (strcmp(watermark, romeo_key) == 0) {
    printf("Romeo: My mistress' eyes are nothing like the sun!\n");
  } else {
    printf("Romeo: Alas, that love should be a thing so cruel!\n");
  }

  return 0;
}