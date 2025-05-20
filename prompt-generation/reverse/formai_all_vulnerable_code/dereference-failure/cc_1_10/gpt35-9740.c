//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void send_credentials(int socket_fd);
void receive_messages(int socket_fd);

int main(int argc, char *argv[]) {
   int socket_fd;
   struct sockaddr_in server_addr;

   if (argc != 3) {
       printf("usage: %s <server_ip_address> <port_number>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   // create socket
   if ((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
       perror("socket");
       exit(EXIT_FAILURE);
   }

   // set up server address
   memset(&server_addr, '\0', sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(atoi(argv[2]));
   if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
       perror("inet_pton");
       exit(EXIT_FAILURE);
   }

   // connect to server
   if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
       perror("connect");
       exit(EXIT_FAILURE);
   }

   // send credentials to server
   send_credentials(socket_fd);

   // receive and display messages from server
   receive_messages(socket_fd);

   // close connection
   close(socket_fd);

   return 0;
}

void send_credentials(int socket_fd) {
   char buffer[BUFFER_SIZE];
   char username[BUFFER_SIZE];
   char password[BUFFER_SIZE];

   // get username and password from user
   printf("Enter username: ");
   fgets(username, BUFFER_SIZE, stdin);
   printf("Enter password: ");
   fgets(password, BUFFER_SIZE, stdin);

   // send username to server
   snprintf(buffer, BUFFER_SIZE, "USER %s", username);
   send(socket_fd, buffer, strlen(buffer), 0);

   // receive server response
   memset(buffer, '\0', BUFFER_SIZE);
   recv(socket_fd, buffer, BUFFER_SIZE, 0);
   printf("%s", buffer);

   // send password to server
   snprintf(buffer, BUFFER_SIZE, "PASS %s", password);
   send(socket_fd, buffer, strlen(buffer), 0);

   // receive server response
   memset(buffer, '\0', BUFFER_SIZE);
   recv(socket_fd, buffer, BUFFER_SIZE, 0);
   printf("%s", buffer);
}

void receive_messages(int socket_fd) {
   char buffer[BUFFER_SIZE];
   char command[BUFFER_SIZE];
   int bytes_received;

   // receive server welcome message
   memset(buffer, '\0', BUFFER_SIZE);
   recv(socket_fd, buffer, BUFFER_SIZE, 0);
   printf("%s", buffer);

   while (1) {
       // get user command
       printf("Enter command (QUIT to exit): ");
       fgets(command, BUFFER_SIZE, stdin);

       // send command to server
       send(socket_fd, command, strlen(command), 0);

       // exit loop if quit command received
       if (strncmp(command, "QUIT", 4) == 0) {
           break;
       }

       // receive and display server response
       memset(buffer, '\0', BUFFER_SIZE);
       bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
       printf("%s", buffer);
       if (bytes_received <= 0) {
           break;
       }
   }
}