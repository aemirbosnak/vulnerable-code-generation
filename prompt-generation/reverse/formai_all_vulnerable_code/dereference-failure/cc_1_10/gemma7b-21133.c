//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct watermark_t {
    int watermarked_size;
    char *data;
    struct watermark_t *next;
} watermark_t;

void watermark_insert( watermark_t **head, char *data, int size ) {
     watermark_t *new_node = malloc( sizeof(watermark_t) );
    new_node->watermarked_size = size;
    new_node->data = malloc( size );
    memcpy( new_node->data, data, size );
    new_node->next = NULL;

    if ( *head == NULL ) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

int watermark_search( watermark_t *head, char *data, int size ) {
    while ( head ) {
        if ( head->watermarked_size == size && memcmp( data, head->data, size ) == 0 ) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
     watermark_t *head = NULL;

    char *data = "This is a secret message";
    int size = strlen( data );

    watermark_insert( &head, data, size );

    char *search_data = "This is the secret message";

    if ( watermark_search( head, search_data, size ) ) {
        printf("Secret message found!\n");
    } else {
        printf("Secret message not found.\n");
    }

    return 0;
}