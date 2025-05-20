//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct {
  char flag;
  char *image;
  int imageSize;
  char *secretMessage;
  int secretMessageSize;
} romeo, juliet;

int main() {
  romeo.flag = 'R';
  romeo.image = "Romeo.jpg";
  romeo.imageSize = 100000;
  romeo.secretMessage = "My dearest Juliet, I love you more than words can say.";
  romeo.secretMessageSize = 100;

  juliet.flag = 'J';
  juliet.image = "Juliet.jpg";
  juliet.imageSize = 100000;
  juliet.secretMessage = "My dearest Romeo, I love you too.";
  juliet.secretMessageSize = 100;

  // Romeo sends a secret message to Juliet
  for (int i = 0; i < romeo.secretMessageSize; i++) {
    int bit = romeo.secretMessage[i] & 1;
    if (bit) {
      romeo.image[i] |= 1;
    } else {
      romeo.image[i] &= ~1;
    }
  }

  // Juliet receives the secret message from Romeo
  for (int i = 0; i < juliet.secretMessageSize; i++) {
    int bit = juliet.image[i] & 1;
    if (bit) {
      juliet.secretMessage[i] |= 1;
    } else {
      juliet.secretMessage[i] &= ~1;
    }
  }

  // Juliet replies to Romeo
  for (int i = 0; i < juliet.secretMessageSize; i++) {
    int bit = juliet.secretMessage[i] & 1;
    if (bit) {
      juliet.image[i] |= 1;
    } else {
      juliet.image[i] &= ~1;
    }
  }

  // Romeo receives the reply from Juliet
  for (int i = 0; i < romeo.secretMessageSize; i++) {
    int bit = juliet.image[i] & 1;
    if (bit) {
      romeo.secretMessage[i] |= 1;
    } else {
      romeo.secretMessage[i] &= ~1;
    }
  }

  printf("%s\n", romeo.secretMessage);
  printf("%s\n", juliet.secretMessage);
  return 0;
}