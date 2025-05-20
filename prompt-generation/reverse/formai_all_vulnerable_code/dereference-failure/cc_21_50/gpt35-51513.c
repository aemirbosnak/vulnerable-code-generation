//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];

   if (argc < 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }

   portno = atoi(argv[2]);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0)
      perror("Error opening socket");

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      fprintf(stderr,"Error, no such host\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
      perror("Error connecting");

   printf("Connected to server %s:%d\n", argv[1], portno);

   // Send username to server
   printf("Enter username: ");
   bzero(buffer, 256);
   fgets(buffer, 255, stdin);
   n = send(sockfd, buffer, strlen(buffer), 0);
   if (n < 0)
      perror("Error sending username");

   // Wait for server response
   bzero(buffer, 256);
   n = recv(sockfd, buffer, 255, 0);
   if (n < 0)
      perror("Error receiving response");

   // If server accepts username, prompt for password
   if (strstr(buffer, "+OK")) {
      printf("Enter password: ");
      bzero(buffer, 256);
      fgets(buffer, 255, stdin);
      n = send(sockfd, buffer, strlen(buffer), 0);
      if (n < 0)
         perror("Error sending password");

      // Wait for server response
      bzero(buffer, 256);
      n = recv(sockfd, buffer, 255, 0);
      if (n < 0)
         perror("Error receiving response");

      // If server accepts password, retrieve mail
      if (strstr(buffer, "+OK")) {
         printf("Retrieving mail...\n");

         // Send LIST command to server
         n = send(sockfd, "LIST\n", 5, 0);
         if (n < 0)
            perror("Error sending LIST command");

         // Wait for server response
         bzero(buffer, 256);
         n = recv(sockfd, buffer, 255, 0);
         if (n < 0)
            perror("Error receiving response");

         // If server sends list of messages, display them
         if (strstr(buffer, "+OK")) {
            printf("Messages:\n%s\n", buffer);

            // Use strtok to parse list of messages
            char *token = strtok(buffer, "\n");
            while (token != NULL) {
               if (isdigit(token[0])) {
                  // Send RETR command to server
                  char command[15];
                  sprintf(command, "RETR %s\n", token);
                  n = send(sockfd, command, strlen(command), 0);
                  if (n < 0)
                     perror("Error sending RETR command");

                  // Wait for server response
                  bzero(buffer, 256);
                  n = recv(sockfd, buffer, 255, 0);
                  if (n < 0)
                     perror("Error receiving response");

                  // If server sends message, display it
                  if (strstr(buffer, "+OK")) {
                     printf("Message %s:\n%s\n", token, buffer);

                     // Send DELE command to server
                     char command[15];
                     sprintf(command, "DELE %s\n", token);
                     n = send(sockfd, command, strlen(command), 0);
                     if (n < 0)
                        perror("Error sending DELE command");
                  }
               }
               token = strtok(NULL, "\n");
            }

            // Send QUIT command to server
            n = send(sockfd, "QUIT\n", 5, 0);
            if (n < 0)
               perror("Error sending QUIT command");

            printf("Mail successfully retrieved and marked for deletion.\n");
         }
      }
   }

   // Close socket and exit
   close(sockfd);
   return 0;
}