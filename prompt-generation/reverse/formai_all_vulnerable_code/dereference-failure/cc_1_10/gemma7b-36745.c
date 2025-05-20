//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet {
  char data[MAX_PACKET_SIZE];
  int length;
  struct Packet* next;
} Packet;

Packet* createPacket() {
  Packet* packet = (Packet*)malloc(sizeof(Packet));
  packet->length = 0;
  packet->next = NULL;
  return packet;
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in servaddr, cliaddr;
  char buffer[MAX_PACKET_SIZE];
  int packetSize, totalPackets = 0, receivedPackets = 0;
  Packet* packetList = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, NULL);
  if (newsockfd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Receive packets
  while (1) {
    packetSize = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0);
    if (packetSize < 0) {
      perror("Error receiving packet");
      break;
    }

    // Create a new packet
    Packet* newPacket = createPacket();
    newPacket->length = packetSize;
    memcpy(newPacket->data, buffer, packetSize);

    // Add the new packet to the list
    if (packetList == NULL) {
      packetList = newPacket;
    } else {
      packetList->next = newPacket;
      packetList = newPacket;
    }

    // Increment the total number of packets received
    receivedPackets++;
  }

  // Close the socket
  close(sockfd);

  // Print the results
  printf("Total packets received: %d\n", receivedPackets);
  printf("Total packets sent: %d\n", totalPackets);

  return 0;
}