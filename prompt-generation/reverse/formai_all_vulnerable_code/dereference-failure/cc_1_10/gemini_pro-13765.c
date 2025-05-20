//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFF 65536

// Test the speed of a specific server
int test_server(char *hostname, int port) {
  // Resolve the hostname and get the IP address
  struct addrinfo *addrinfo;
  int ret = getaddrinfo(hostname, NULL, NULL, &addrinfo);
  if (ret != 0) {
    fprintf(stderr, "Error resolving hostname: %s\n", hostname);
    return -1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return -1;
  }

  // Connect to the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr = ((struct sockaddr_in *)addrinfo->ai_addr)->sin_addr;

  ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    perror("Error connecting to server");
    return -1;
  }

  // Freely the addrinfo
  freeaddrinfo(addrinfo);

  // Create a buffer for sending and receiving data
  char *buff = malloc(MAX_BUFF);
  if (!buff) {
    perror("Error allocating buffer");
    return -1;
  }

  // Test the upload speed
  int start = time(NULL);

  for (int i = 0; i < 10; i++) {
    // Send data to the server
    ret = send(sockfd, buff, MAX_BUFF, 0);
    if (ret == -1) {
      perror("Error sending data");
      return -1;
    }
  }

  int end = time(NULL);

  // Calculate the upload speed
  double upload_speed = (MAX_BUFF * 10) / (end - start);

  // Test the download speed
  start = time(NULL);

  for (int i = 0; i < 10; i++) {
    // Receive data from the server
    ret = recv(sockfd, buff, MAX_BUFF, 0);
    if (ret == -1) {
      perror("Error receiving data");
      return -1;
    }
  }

  end = time(NULL);

  // Calculate the download speed
  double download_speed = (MAX_BUFF * 10) / (end - start);

  // Free the buffer
  free(buff);

  // Close the socket
  close(sockfd);

  // Print the results
  printf("Results for server %s:%d\n", hostname, port);
  printf("Upload speed: %f Mbps\n", upload_speed);
  printf("Download speed: %f Mbps\n", download_speed);

  return 0;
}

int main(int argc, char *argv[]) {
  // Usage: ./internet_speed_test <hostname> <port>

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  int ret = test_server(hostname, port);
  if (ret != 0) {
    return 1;
  }

  return 0;
}