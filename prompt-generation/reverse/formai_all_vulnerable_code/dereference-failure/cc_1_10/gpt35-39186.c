//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
    return 1;
  }

  char *server_address = argv[1];
  int portno = 80;
  struct hostent *server = gethostbyname(server_address);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    return 2;
  }

  struct sockaddr_in serv_addr;
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: couldn't open socket\n");
    return 3;
  }

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: couldn't connect to server\n");
    close(sockfd);
    return 4;
  }

  char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  int n = write(sockfd, request, strlen(request));
  if (n < 0) {
    fprintf(stderr, "Error: error writing to socket\n");
    close(sockfd);
    return 5;
  }

  char buffer[BUFFER_SIZE];
  bzero(buffer, BUFFER_SIZE);
  int total_bytes = 0;
  clock_t start = clock();
  while (1) {
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
      fprintf(stderr, "Error: error reading from socket\n");
      close(sockfd);
      return 6;
    }

    if (n == 0) {
      break;
    }

    total_bytes += n;
    bzero(buffer, BUFFER_SIZE);
  }
  clock_t end = clock();

  printf("Download speed: %.2f kbps\n", (double)total_bytes / (double)(end - start) * (double)CLOCKS_PER_SEC / 1000.0);
  close(sockfd);

  return 0;
}