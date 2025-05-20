//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LEN 255

typedef struct watermark_packet {
  char *data;
  int size;
  struct watermark_packet *next;
} watermark_packet;

void watermark_insert( watermark_packet **head, char *data, int size ) {
  watermark_packet *new_packet = malloc( sizeof( watermark_packet ) );
  new_packet->data = malloc( size );
  memcpy( new_packet->data, data, size );
  new_packet->size = size;
  new_packet->next = NULL;

  if ( *head ) {
    (*head)->next = new_packet;
  } else {
    *head = new_packet;
  }
}

int watermark_search( watermark_packet *head, char *data ) {
  for ( watermark_packet *packet = head; packet; packet = packet->next ) {
    if ( memcmp( packet->data, data, packet->size ) == 0 ) {
      return 1;
    }
  }

  return 0;
}

int main() {

  char watermark_data[] = "This is a secret watermark";
  int watermark_len = strlen( watermark_data ) + 1;
  watermark_packet *watermark_head = NULL;

  // Insert watermark into the head
  watermark_insert( &watermark_head, watermark_data, watermark_len );

  // Search for the watermark
  if ( watermark_search( watermark_head, watermark_data ) ) {
    printf("Watermark found!\n");
  } else {
    printf("Watermark not found.\n");
  }

  return 0;
}