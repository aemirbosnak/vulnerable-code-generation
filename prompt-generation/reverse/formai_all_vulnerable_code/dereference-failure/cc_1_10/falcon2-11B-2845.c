//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
   if (argc!= 2) {
       fprintf(stderr, "Usage: %s port\n", argv[0]);
       exit(1);
   }

   int listen_fd, conn_fd;
   struct sockaddr_in server, client;
   int addrlen;
   char buffer[1024];
   char message[] = "Welcome to my TCP/IP server!";

   // Set up the server socket
   listen_fd = socket(AF_INET, SOCK_STREAM, 0);
   if (listen_fd == -1) {
       perror("Failed to create socket");
       exit(1);
   }

   memset(&server, 0, sizeof(server));
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = htonl(INADDR_ANY);
   server.sin_port = htons((unsigned short)atoi(argv[1]));

   if (bind(listen_fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
       perror("Failed to bind socket");
       exit(1);
   }

   if (listen(listen_fd, 5) == -1) {
       perror("Failed to listen on socket");
       exit(1);
   }

   while (1) {
       addrlen = sizeof(client);
       conn_fd = accept(listen_fd, (struct sockaddr *)&client, &addrlen);
       if (conn_fd == -1) {
           perror("Failed to accept connection");
           continue;
       }

       printf("Accepted connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

       send(conn_fd, message, sizeof(message), 0);
   }

   return 0;
}