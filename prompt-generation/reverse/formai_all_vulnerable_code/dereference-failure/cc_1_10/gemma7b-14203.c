//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 1024

typedef struct watermark_packet {
  char data[MAX_WATERMARK_LENGTH];
  int length;
  struct watermark_packet* next;
} watermark_packet;

 watermark_packet* watermark_packet_create(int length) {
  watermark_packet* packet = malloc(sizeof(watermark_packet));
  packet->length = length;
  packet->next = NULL;
  return packet;
}

int watermark_packet_add_data(watermark_packet* packet, char* data, int data_length) {
  if (packet->length < data_length) {
    return -1;
  }
  memcpy(packet->data, data, data_length);
  packet->length = data_length;
  return 0;
}

void watermark_packet_print(watermark_packet* packet) {
  printf("Data: ");
  for (int i = 0; i < packet->length; i++) {
    printf("%c ", packet->data[i]);
  }
  printf("\n");
  printf("Length: %d\n", packet->length);
  printf("Next: %p\n", packet->next);
}

int main() {
   watermark_packet* watermark_packets = NULL;

  // Create a watermark packet
  watermark_packet* packet = watermark_packet_create(10);

  // Add data to the packet
  watermark_packet_add_data(packet, "Hello, world!", 13);

  // Add the packet to the watermark packets list
  watermark_packets = packet;

  // Print the packet
  watermark_packet_print(packet);

  // Add another packet to the list
  packet = watermark_packet_create(20);

  // Add data to the packet
  watermark_packet_add_data(packet, "Secret message!", 14);

  // Add the packet to the watermark packets list
  packet->next = watermark_packets;

  // Print the packets
  watermark_packet_print(watermark_packets);

  return 0;
}