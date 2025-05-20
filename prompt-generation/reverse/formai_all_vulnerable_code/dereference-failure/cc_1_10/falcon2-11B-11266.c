//Falcon2-11B DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function prototypes
int create_socket(int domain, int type, int protocol);
int connect_to_server(const char* server_name, int port);
int send_message(int sockfd, char* message);
int close_connection(int sockfd);

// Global variables
int sockfd;
char message[256];

int main() {
  // Create socket
  if (create_socket(AF_INET, SOCK_STREAM, 0) < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to server
  if (connect_to_server("localhost", 8080) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send message
  sprintf(message, "Hello, server!");
  if (send_message(sockfd, message) < 0) {
    perror("Error sending message");
    exit(1);
  }

  // Close connection
  close_connection(sockfd);

  return 0;
}

int create_socket(int domain, int type, int protocol) {
  int sockfd;

  if ((sockfd = socket(domain, type, protocol)) < 0) {
    perror("Error creating socket");
    exit(1);
  }

  return sockfd;
}

int connect_to_server(const char* server_name, int port) {
  struct hostent* server_address;
  struct sockaddr_in server_address_in;

  if ((server_address = gethostbyname(server_name)) == NULL) {
    perror("Error getting host by name");
    exit(1);
  }

  bzero((char*)&server_address_in, sizeof(server_address_in));
  server_address_in.sin_family = AF_INET;
  server_address_in.sin_port = htons(port);
  bcopy((char*)server_address->h_addr,
       (char*)&server_address_in.sin_addr.s_addr,
       server_address->h_length);

  if (connect(sockfd, (struct sockaddr*)&server_address_in,
           sizeof(server_address_in)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  return 1;
}

int send_message(int sockfd, char* message) {
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("Error sending message");
    exit(1);
  }

  return 1;
}

int close_connection(int sockfd) {
  close(sockfd);
  return 1;
}