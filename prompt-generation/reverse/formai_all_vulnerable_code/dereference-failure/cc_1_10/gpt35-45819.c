//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILENAME_SIZE 1000
#define MAX_MSG_SIZE 1000

void hideMessage(char *filename, char *message);
char *retrieveMessage(char *filename);

int main() {
  char filename[MAX_FILENAME_SIZE];
  char message[MAX_MSG_SIZE];

  printf("Enter the name of the image file (including extension): ");
  fgets(filename, MAX_FILENAME_SIZE, stdin);
  filename[strcspn(filename, "\n")] = 0; // remove trailing newline character

  printf("Enter the message to hide: ");
  fgets(message, MAX_MSG_SIZE, stdin);
  message[strcspn(message, "\n")] = 0; // remove trailing newline character

  hideMessage(filename, message);

  printf("Message hidden successfully!\n");

  // Retrieve hidden message from the image
  char *msg = retrieveMessage(filename);
  if (msg != NULL) {
    printf("Retrieved message: %s\n", msg);
    free(msg); // Free memory allocated for retrieved message
  } else {
    printf("No message found in the image\n");
  }

  return 0;
}

void hideMessage(char *filename, char *message) {
  FILE *fp = fopen(filename, "r+b");

  if (fp == NULL) {
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  }

  // Get file size
  fseek(fp, 0L, SEEK_END);
  long filesize = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  // Calculate maximum message size that can be hidden
  int maxMsgSize = (int)(floor(filesize * 0.1)); // Can hide message up to 10% of the file size

  int msgLength = strlen(message);
  if (msgLength > maxMsgSize) {
    printf("Error: message too large to hide in the image\n");
    exit(EXIT_FAILURE);
  }

  // Write the message length to the first 4 bytes of the file
  fwrite(&msgLength, sizeof(int), 1, fp);

  // Write the message to the file
  fwrite(message, sizeof(char), msgLength, fp);

  fclose(fp);
}

char *retrieveMessage(char *filename) {
  FILE *fp = fopen(filename, "rb");

  if (fp == NULL) {
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  }

  // Get file size
  fseek(fp, 0L, SEEK_END);
  long filesize = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  // Read the message length from the first 4 bytes of the file
  int msgLength;
  fread(&msgLength, sizeof(int), 1, fp);

  // Allocate memory for the message
  char *message = (char *)malloc((msgLength+1) * sizeof(char));
  if (message == NULL) {
    printf("Error allocating memory\n");
    exit(EXIT_FAILURE);
  }

  // Read the message from the file
  fread(message, sizeof(char), msgLength, fp);
  message[msgLength] = '\0';

  fclose(fp);

  return message;
}