//FormAI DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about a text message
typedef struct {
  char* sender;
  char* recipient;
  char* message;
} Message;

// Define a function to parse a line of text and create a Message struct
Message* parse_message(char* line) {
  char* sender = strtok(line, ";");
  char* recipient = strtok(NULL, ";");
  char* message = strtok(NULL, ";");

  // Allocate memory for the Message struct
  Message* m = malloc(sizeof(Message));
  m->sender = malloc(strlen(sender) + 1);
  m->recipient = malloc(strlen(recipient) + 1);
  m->message = malloc(strlen(message) + 1);

  // Copy strings into the Message struct
  strcpy(m->sender, sender);
  strcpy(m->recipient, recipient);
  strcpy(m->message, message);

  return m;
}

int main() {
  // Open a file for reading
  FILE* fp = fopen("messages.txt", "r");

  if (fp == NULL) {
    printf("Error: could not open file.");
    return 1;
  }

  // Define variables to hold message information
  char line[256];
  Message* current_message;

  // Loop through each line in the file
  while (fgets(line, sizeof(line), fp)) {
    // Parse the line and create a Message struct
    current_message = parse_message(line);

    // Print the message to the console
    printf("From: %s\n", current_message->sender);
    printf("To: %s\n", current_message->recipient);
    printf("Message: %s\n", current_message->message);

    // Free memory allocated for the Message struct
    free(current_message->sender);
    free(current_message->recipient);
    free(current_message->message);
    free(current_message);
  }

  // Close the file
  fclose(fp);

  return 0;
}