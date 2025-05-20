//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LEN 1024

typedef struct watermark_packet {
  char *data;
  int size;
  struct watermark_packet *next;
} watermark_packet;

void watermark_add(watermark_packet **head, char *data, int size) {
  watermark_packet *new_packet = malloc(sizeof(watermark_packet));
  new_packet->data = malloc(size);
  memcpy(new_packet->data, data, size);
  new_packet->size = size;
  new_packet->next = NULL;

  if (*head) {
    (*head)->next = new_packet;
  } else {
    *head = new_packet;
  }
}

int watermark_detect( watermark_packet *head, char *data, int size) {
  for (watermark_packet *packet = head; packet; packet = packet->next) {
    if (packet->size == size && memcmp(packet->data, data, size) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
   watermark_packet *head = NULL;

  char *watermarked_data = "This is the watermarked data";
   watermark_add(&head, watermarked_data, strlen(watermarked_data));

  char *search_data = "This is the data to be searched";
  int result = watermark_detect(head, search_data, strlen(search_data));

  if (result) {
    printf("Watermarked data found!\n");
  } else {
    printf("Watermarked data not found.\n");
  }

  return 0;
}