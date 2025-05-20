//FormAI DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Packet {
    char header[100];
    char content[1000];
};

struct Packet* create_packet(char*, char*);
void destroy_packet(struct Packet*);

int main() {
    struct Packet* packets[10];
    int packet_count = 0;
    char allow_list[100][100] = {"www.google.com", "www.facebook.com", "www.stackoverflow.com"};

    while (1) {
        printf("Enter packet header: ");
        char header[100];
        fgets(header, 100, stdin);

        printf("Enter packet content: ");
        char content[1000];
        fgets(content, 1000, stdin);

        struct Packet* packet = create_packet(header, content);
        int is_allowed = 0;
        
        for (int i = 0; i < 100; i++) {
            if (strcmp(header, allow_list[i]) == 0) {
                is_allowed = 1;
                break;
            }
        }

        if (is_allowed) {
            printf("Packet allowed!\n");
        } else {
            printf("Packet blocked!\n");
            destroy_packet(packet);
        }

        packets[packet_count] = packet;
        packet_count++;

        if (packet_count == 10) {
            break;
        }
    }

    for (int i = 0; i < packet_count; i++) {
        destroy_packet(packets[i]);
    }

    return 0;
}

struct Packet* create_packet(char* header, char* content) {
    struct Packet* packet = (struct Packet*) malloc(sizeof(struct Packet));
    strcpy(packet->header, header);
    strcpy(packet->content, content);
    return packet;
}

void destroy_packet(struct Packet* packet) {
    free(packet);
}