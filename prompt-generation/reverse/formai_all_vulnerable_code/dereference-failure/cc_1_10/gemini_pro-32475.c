//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <unistd.h>

// Define the QoS parameters
#define TOS_LOW_DELAY 16
#define TOS_THROUGHPUT 8
#define TOS_RELIABILITY 4
#define TOS_MIN_COST 2

// Define the socket types
#define SOCK_STREAM 1
#define SOCK_DGRAM 2

// Define the thread function
void *thread_function(void *arg);

// Main function
int main(int argc, char *argv[]) {
  // Check the command line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <host> <port> <qos>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the host name and port number
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Get the QoS parameter
  int qos = atoi(argv[3]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the QoS parameter
  int tos = qos;
  if (setsockopt(sock, IPPROTO_IP, IP_TOS, &tos, sizeof(tos)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &addr.sin_addr) != 1) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Create a thread to send data to the server
  pthread_t thread;
  if (pthread_create(&thread, NULL, thread_function, (void *)sock) != 0) {
    perror("pthread_create");
    exit(EXIT_FAILURE);
  }

  // Receive data from the server
  char buffer[1024];
  while (1) {
    int n = recv(sock, buffer, sizeof(buffer), 0);
    if (n == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    } else if (n == 0) {
      break;
    } else {
      printf("Received: %s\n", buffer);
    }
  }

  // Close the socket
  close(sock);

  // Wait for the thread to finish
  if (pthread_join(thread, NULL) != 0) {
    perror("pthread_join");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}

// Thread function
void *thread_function(void *arg) {
  // Get the socket
  int sock = (int)arg;

  // Send data to the server
  char buffer[1024];
  while (1) {
    printf("Enter a message: ");
    fgets(buffer, sizeof(buffer), stdin);
    int n = send(sock, buffer, strlen(buffer), 0);
    if (n == -1) {
      perror("send");
      exit(EXIT_FAILURE);
    }
  }

  // Close the socket
  close(sock);

  return NULL;
}