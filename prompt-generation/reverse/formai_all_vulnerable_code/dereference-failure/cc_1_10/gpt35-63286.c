//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_RECV_BUFFER 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Expected URL as argument\n");
    exit(-1);
  }

  char *url = argv[1];
  char *host, *path;

  // Parse the URL to obtain the host and path
  if (strstr(url, "http://") != NULL) {
    url = url + strlen("http://");
  }

  host = strtok(url, "/");
  path = strtok(NULL, "");

  if (path == NULL) {
    path = "";
  }

  // Resolve the IP address of the host
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  inet_pton(AF_INET, host, &server_addr.sin_addr);

  // Create the socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error connecting to server\n");
    exit(-1);
  }

  // Construct the HTTP request
  char request[1024];
  sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

  // Send the HTTP request to the server
  if (send(sock, request, strlen(request), 0) < 0) {
    printf("Error sending request\n");
    exit(-1);
  }

  // Receive the HTTP response from the server
  char recv_buffer[MAX_RECV_BUFFER];
  int bytes_received = 0;
  while ((bytes_received = recv(sock, recv_buffer, MAX_RECV_BUFFER - 1, 0)) > 0) {
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);
  }

  // Close the socket
  close(sock);

  return 0;
}