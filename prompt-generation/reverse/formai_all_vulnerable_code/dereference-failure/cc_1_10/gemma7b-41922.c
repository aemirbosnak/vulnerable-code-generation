//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct watermark_packet {
    char data[MAX_WATERMARK_LENGTH];
    int sequence_number;
    struct watermark_packet* next;
} watermark_packet;

 watermark_packet* watermark_packet_create(char* data, int sequence_number) {
    watermark_packet* packet = (watermark_packet*)malloc(sizeof(watermark_packet));

    packet->sequence_number = sequence_number;
    memcpy(packet->data, data, MAX_WATERMARK_LENGTH);

    packet->next = NULL;

    return packet;
}

int watermark_packet_insert(watermark_packet* packet_head, char* data, int sequence_number) {
    watermark_packet* new_packet = watermark_packet_create(data, sequence_number);

    if (packet_head == NULL) {
        packet_head = new_packet;
    } else {
        packet_head->next = new_packet;
        packet_head = new_packet;
    }

    return 0;
}

void watermark_packet_print(watermark_packet* packet) {
    printf("Sequence number: %d\n", packet->sequence_number);
    printf("Data: %s\n", packet->data);
}

int main() {
    // Create a watermark packet
    watermark_packet* packet = watermark_packet_create("This is a secret message.", 1);

    // Insert the packet into a list
    watermark_packet_insert(packet, "Another secret message.", 2);

    // Print the packets
     watermark_packet_print(packet);

    return 0;
}