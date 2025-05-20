//FormAI DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 3

bool isPortOpen(char* host, int port) {
   struct sockaddr_in serverAddr;
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("Socket Error");
      return false;
   }

   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(port);
   serverAddr.sin_addr.s_addr = inet_addr(host);

   fd_set fileDescriptors;
   FD_ZERO(&fileDescriptors);
   FD_SET(sockfd, &fileDescriptors);

   struct timeval timeout = { TIMEOUT, 0 };
   int connectionStatus = connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

   if (connectionStatus < 0) {
      printf("Port %d closed\n", port);
      close(sockfd);
      return false;
   }
   
   printf("Port %d opened on %s\n", port, host);
   close(sockfd);
   return true;
}

int main(int argc, char* argv[]) {
   int startPort = 1, endPort = 65535;
   char* host = "localhost";

   if (argc == 4) {
      host = argv[1];
      startPort = atoi(argv[2]);
      endPort = atoi(argv[3]);
   } else {
      printf("Usage: %s [host] [startport] [endport]\n", argv[0]);
      printf("Using default values: localhost 1 65535\n");
   }

   for (int port = startPort; port <= endPort; port++) {
      isPortOpen(host, port);
   }

   return 0;
}