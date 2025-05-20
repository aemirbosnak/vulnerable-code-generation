//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_MSG_SIZE 1024 // Maximum message size

int main(int argc, char *argv[]) {
   int sockfd, n;
   char buffer[MAX_MSG_SIZE];
   struct sockaddr_in serv_addr;
   struct hostent *server;
   
   if (argc < 3) { // Check for correct number of arguments
      fprintf(stderr,"usage: %s hostname port\n", argv[0]);
      exit(0);
   }
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
   if (sockfd < 0) { 
      perror("ERROR opening socket");
      exit(1);
   }
   
   server = gethostbyname(argv[1]); // Get the server by name
   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr)); // Zero out the server address struct
   
   serv_addr.sin_family = AF_INET; // Set up the server address
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(atoi(argv[2]));
   
   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) { // Connect to the server
      perror("ERROR connecting");
      exit(1);
   }

   printf("Welcome to the POP3 client\n"); // Greet the user

   while (1) { // Loop until the user quits
      bzero(buffer,MAX_MSG_SIZE); // Zero out the buffer
      printf("> "); // Prompt the user for input
      fgets(buffer,MAX_MSG_SIZE,stdin); // Read in user input

      // Check for a puzzle command
      if (strcmp(buffer,"what is the answer to life, the universe, and everything\n") == 0) {
         printf("The answer is 42\n");
      }
      else {
         n = write(sockfd,buffer,strlen(buffer)); // Send the user's command to the server
         if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
         }
         
         bzero(buffer,MAX_MSG_SIZE); // Zero out the buffer
         n = read(sockfd,buffer,MAX_MSG_SIZE-1); // Read the server's response
         if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
         }
         
         printf("%s",buffer); // Print the server's response
      }

      // Check for a puzzle response
      if (strcmp(buffer,"what do you get when you cross a snowman and a shark\n") == 0) {
         printf("Frostbite\n");
      }
   }

   close(sockfd); // Close the connection
   return 0; // Exit the program
}