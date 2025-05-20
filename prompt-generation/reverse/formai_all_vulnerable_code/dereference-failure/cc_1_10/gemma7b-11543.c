//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_packet {
    char data[MAX_WATERMARK_SIZE];
    int size;
    struct watermark_packet* next;
} watermark_packet;

 watermark_packet* watermark_packet_create() {
     watermark_packet* packet = malloc(sizeof(watermark_packet));
    packet->size = 0;
    packet->next = NULL;
    return packet;
}

void watermark_packet_add(watermark_packet* packet, char* data, int size) {
    packet->data[packet->size++] = data;
    if (packet->size >= MAX_WATERMARK_SIZE) {
        packet->next = watermark_packet_create();
        packet = packet->next;
    }
    packet->data[packet->size++] = size;
}

int watermark_packet_size(watermark_packet* packet) {
    return packet->size;
}

void watermark_packet_print(watermark_packet* packet) {
    for (int i = 0; i < watermark_packet_size(packet); i++) {
        printf("%c ", packet->data[i]);
    }
    printf("\n");
}

int main() {
     watermark_packet* watermark_packets = watermark_packet_create();

    char* watermark_data = "This is a secret message";
    watermark_packet_add(watermark_packets, watermark_data, strlen(watermark_data));

    char* embedded_data = "This is a message with a secret watermark";
    watermark_packet_add(watermark_packets, embedded_data, strlen(embedded_data));

    watermark_packet_print(watermark_packets);

    return 0;
}