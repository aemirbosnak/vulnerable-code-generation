//FormAI DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>

int main(int argc, char *argv[]) {
   int sock;
   struct sockaddr_in target;
   unsigned char buf[1024];
   int start_port, end_port;

   // Check for proper arguments
   if(argc != 4) {
      fprintf(stderr, "Usage: %s <IP> <Start Port> <End Port>\n", argv[0]);
      return -1;
   }

   // Extract arguments 
   strncpy(buf, argv[1], strlen(argv[1])+1);
   target.sin_addr.s_addr = inet_addr(buf);
   start_port = atoi(argv[2]);
   end_port = atoi(argv[3]);

   // Create a socket
   sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(sock == -1) {
      fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
      return -1;
   }

   // Set timeout value
   struct timeval timeout;
   timeout.tv_sec = 1;
   timeout.tv_usec = 0; // Set the micro-seconds value based on your requirement

   // Set timeout for the socket
   if (setsockopt (sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,sizeof(timeout)) < 0) {
      fprintf(stderr, "Error setting timeout: %s\n", strerror(errno));
      return -1;
   }

   // Scan ports one by one
   int port;
   for(port = start_port; port <= end_port; port++) {
      target.sin_family = AF_INET;
      target.sin_port = htons(port);

      // Connect to target
      if(connect(sock,(struct sockaddr *)&target,sizeof(target)) == 0) {
         printf("Port %d is open\n", port);
         close(sock);
         sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
         if(sock == -1) {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            return -1;
         }
         if (setsockopt (sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,sizeof(timeout)) < 0) {
            fprintf(stderr, "Error setting timeout: %s\n", strerror(errno));
            return -1;
         }
      }
   }

   return 0;
}