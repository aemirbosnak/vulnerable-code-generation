//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10
#define LISTEN_PORT 8080
#define MAX_PACKET_SIZE 1024

typedef struct packet {
  char data[MAX_PACKET_SIZE];
  struct packet* next;
} packet_t;

packet_t* packet_queue = NULL;

void add_packet_to_queue(packet_t* packet) {
  if (packet_queue == NULL) {
    packet_queue = packet;
  } else {
    packet_queue->next = packet;
    packet_queue = packet;
  }
}

void send_packet(packet_t* packet) {
  int sockfd, port, len;
  struct sockaddr_in server_addr;

  sockfd = socket(AF_INET, SOCK_DGRAM, htons(LISTEN_PORT));
  server_addr.sin_port = htons(LISTEN_PORT);
  server_addr.sin_family = AF_INET;

  len = sendto(sockfd, packet->data, MAX_PACKET_SIZE, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

  close(sockfd);
}

int main() {
  packet_t* packet = malloc(sizeof(packet_t));
  packet->data[0] = 'H';
  packet->data[1] = 'E';
  packet->data[2] = 'L';
  packet->data[3] = 'L';
  packet->next = NULL;

  add_packet_to_queue(packet);

  packet = malloc(sizeof(packet_t));
  packet->data[0] = 'A';
  packet->data[1] = 'R';
  packet->data[2] = 'C';
  packet->data[3] = 'H';
  packet->next = NULL;

  add_packet_to_queue(packet);

  packet = malloc(sizeof(packet_t));
  packet->data[0] = 'B';
  packet->data[1] = 'E';
  packet->data[2] = 'R';
  packet->data[3] = 'T';
  packet->next = NULL;

  add_packet_to_queue(packet);

  send_packet(packet_queue);

  return 0;
}