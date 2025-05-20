//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to get the IP address of the host
char *get_ip_address(char *hostname) {
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    return NULL;
  }

  return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// Function to create a socket
int create_socket() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    return -1;
  }

  return sockfd;
}

// Function to connect to the server
int connect_to_server(int sockfd, char *ip_address, int port) {
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip_address);

  int connect_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0) {
    return -1;
  }

  return 0;
}

// Function to send data to the server
int send_data(int sockfd, char *data, int len) {
  int sent_bytes = send(sockfd, data, len, 0);
  if (sent_bytes < 0) {
    return -1;
  }

  return sent_bytes;
}

// Function to receive data from the server
int receive_data(int sockfd, char *buffer, int len) {
  int received_bytes = recv(sockfd, buffer, len, 0);
  if (received_bytes < 0) {
    return -1;
  }

  return received_bytes;
}

// Function to close the socket
int close_socket(int sockfd) {
  int close_status = close(sockfd);
  if (close_status < 0) {
    return -1;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Get the IP address of the host
  char *ip_address = get_ip_address(hostname);
  if (ip_address == NULL) {
    printf("Error: Could not get the IP address of the host %s\n", hostname);
    return 1;
  }

  // Create a socket
  int sockfd = create_socket();
  if (sockfd < 0) {
    printf("Error: Could not create a socket\n");
    return 1;
  }

  // Connect to the server
  int connect_status = connect_to_server(sockfd, ip_address, port);
  if (connect_status < 0) {
    printf("Error: Could not connect to the server %s on port %d\n", hostname, port);
    return 1;
  }

  // Send data to the server
  char *data = "Hello from the client";
  int sent_bytes = send_data(sockfd, data, strlen(data));
  if (sent_bytes < 0) {
    printf("Error: Could not send data to the server\n");
    return 1;
  }

  // Receive data from the server
  char buffer[BUFFER_SIZE];
  int received_bytes = receive_data(sockfd, buffer, BUFFER_SIZE);
  if (received_bytes < 0) {
    printf("Error: Could not receive data from the server\n");
    return 1;
  }

  // Close the socket
  int close_status = close_socket(sockfd);
  if (close_status < 0) {
    printf("Error: Could not close the socket\n");
    return 1;
  }

  printf("Received from the server: %s\n", buffer);

  return 0;
}