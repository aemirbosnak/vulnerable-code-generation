//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
// In the realm of ethereal bytes, where bits dance and data flows,
// we embark on a journey to construct a HTTP client of our own.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// The enigmatic 'send_request' function, a conjurer of HTTP spells.
int send_request(const char *host, const char *path, const char *method) {
  // Divining the host's digital address from its ethereal name.
  struct hostent *host_info = gethostbyname(host);
  if (!host_info) {
    printf("Host not found: %s\n", host);
    return -1;
  }

  // Establishing a connection to the host's port, a gateway to the digital realm.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    return -1;
  }

  // Preparing the server's address, a beacon guiding our HTTP request.
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

  // Connecting to the server, a handshake in the digital void.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Connection failed");
    return -1;
  }

  // Crafting the HTTP request, a tapestry of text woven from arcane protocols.
  char request[1024];
  sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", method, path, host);

  // Sending the request, a whisper into the digital wind.
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("Send failed");
    return -1;
  }

  // Awaiting the server's response, an oracle's decree from the digital ether.
  char response[4096];
  int bytes_received = recv(sockfd, response, sizeof(response), 0);
  if (bytes_received == -1) {
    perror("Receive failed");
    return -1;
  }

  // Parsing the response, deciphering the server's wisdom.
  printf("Response:\n%s\n", response);

  // Closing the connection, a farewell to the digital realm.
  close(sockfd);
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <host> <path> <method>\n", argv[0]);
    return -1;
  }

  // Invoking the 'send_request' function, a conduit to the digital abyss.
  return send_request(argv[1], argv[2], argv[3]);
}