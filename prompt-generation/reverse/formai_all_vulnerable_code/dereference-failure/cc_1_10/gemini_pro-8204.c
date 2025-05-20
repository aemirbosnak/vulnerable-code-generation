//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  unsigned char byte;
  struct node *next;
} node;

node *create_list(unsigned char *data, int size) {
  node *head = NULL, *current = NULL;
  for (int i = 0; i < size; i++) {
    if (head == NULL)
      head = current = malloc(sizeof(node));
    else
      current = current->next = malloc(sizeof(node));
    current->byte = data[i];
    current->next = NULL;
  }
  return head;
}

void free_list(node *head) {
  while (head) {
    node *next = head->next;
    free(head);
    head = next;
  }
}

void print_list(node *head) {
  while (head) {
    printf("%02x", head->byte);
    head = head->next;
  }
  puts("");
}

void embed_message(node *head, unsigned char *message, int size) {
  node *current = head;
  for (int i = 0; i < size; i++) {
    current->byte ^= message[i];
    current = current->next;
  }
}

void extract_message(node *head, unsigned char *message, int size) {
  node *current = head;
  for (int i = 0; i < size; i++) {
    message[i] = current->byte ^ message[i];
    current = current->next;
  }
}

int main() {
  unsigned char data[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
  int size = sizeof(data) / sizeof(unsigned char);
  node *head = create_list(data, size);

  unsigned char message[] = {0xab, 0xcd, 0xef};
  int message_size = sizeof(message) / sizeof(unsigned char);
  embed_message(head, message, message_size);

  unsigned char extracted_message[message_size];
  extract_message(head, extracted_message, message_size);

  print_list(head);
  printf("Extracted message: ");
  print_list(create_list(extracted_message, message_size));

  free_list(head);
  return 0;
}