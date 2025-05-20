//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct watermark_packet {
    char *data;
    int size;
    struct watermark_packet *next;
} watermark_packet;

void watermark_insert( watermark_packet **head, char *data, int size ) {
     watermark_packet *new_packet = malloc( sizeof(watermark_packet) );
    new_packet->data = malloc( size );
    memcpy( new_packet->data, data, size );
    new_packet->size = size;
    new_packet->next = NULL;

    if ( *head == NULL ) {
        *head = new_packet;
    } else {
        (*head)->next = new_packet;
    }
}

int watermark_search( watermark_packet *head, char *data ) {
    while ( head ) {
        if ( strcmp( head->data, data ) == 0 ) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    char message[] = "Hello, world!";
     watermark_packet *head = NULL;

    watermark_insert( &head, message, strlen( message ) );

    if ( watermark_search( head, message ) ) {
        printf( "Message found!\n" );
    } else {
        printf( "Message not found.\n" );
    }

    return 0;
}