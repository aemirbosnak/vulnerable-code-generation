//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments is provided
  if (argc!= 2) {
    printf("Usage: %s <target_ip>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket failed");
    return 1;
  }

  // Set up the target IP address and port number
  struct sockaddr_in serv_addr;
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[1]));
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Connect to the target
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect failed");
    return 1;
  }

  // Send a SYN packet to the target
  char buf[1024];
  bzero(buf, 1024);
  if (send(sockfd, buf, 1024, 0) < 0) {
    perror("send failed");
    return 1;
  }

  // Receive and display the SYN-ACK packet
  char ack[1024];
  bzero(ack, 1024);
  if (recv(sockfd, ack, 1024, 0) < 0) {
    perror("recv failed");
    return 1;
  }
  printf("SYN-ACK received from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

  // Close the socket
  close(sockfd);

  return 0;
}