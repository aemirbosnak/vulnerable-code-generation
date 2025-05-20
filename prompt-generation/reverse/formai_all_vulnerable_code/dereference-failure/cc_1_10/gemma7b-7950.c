//Gemma-7B DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define PORT 8080

int main() {
  int sockfd, newsockfd, clientlen, n;
  char buffer[1024], filename[256], msg[256];
  struct sockaddr_in server_addr, client_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  clientlen = sizeof(client_addr);

  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
  if (newsockfd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  n = read(newsockfd, buffer, 1024);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }

  printf("Client: %s\n", buffer);

  sprintf(filename, "received_%d.txt", rand());
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "%s", buffer);
  fclose(fp);

  sprintf(msg, "File received: %s", filename);
  write(newsockfd, msg, strlen(msg));

  close(newsockfd);
  close(sockfd);

  return 0;
}