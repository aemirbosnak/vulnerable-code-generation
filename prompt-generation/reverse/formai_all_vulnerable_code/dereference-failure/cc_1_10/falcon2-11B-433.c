//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
   if (argc!= 3) {
      fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
      exit(1);
   }

   int sockfd, new_socket, valread;
   struct sockaddr_in servaddr, cliaddr;
   char buffer[1024];

   // Create socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("socket failed");
      exit(1);
   }

   // Assign server IP and port number
   bzero((char *) &servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(atoi(argv[2]));
   servaddr.sin_addr.s_addr = inet_addr(argv[1]);

   // Connect to server
   if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
      perror("connect failed");
      exit(1);
   }

   // Send data to server
   new_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (new_socket < 0) {
      perror("socket failed");
      exit(1);
   }

   bzero((char *) &servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(atoi(argv[2]));
   servaddr.sin_addr.s_addr = inet_addr(argv[1]);

   if (connect(new_socket, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
      perror("connect failed");
      exit(1);
   }

   send(new_socket, buffer, strlen(buffer), 0);

   close(new_socket);

   while ((valread = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
      printf("%s\n", buffer);
   }

   close(sockfd);
   return 0;
}