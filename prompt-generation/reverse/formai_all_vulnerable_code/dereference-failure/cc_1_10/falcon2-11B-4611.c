//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: introspective
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

int main() {
  struct sockaddr_in server;
  int sockfd, n;
  struct timeval start, end;
  struct hostent *serverHost;
  struct sockaddr_in serverAddr;
  char buffer[256];

  serverHost = gethostbyname("google.com");
  if (serverHost == NULL) {
    fprintf(stderr, "ERROR: Could not resolve hostname.\n");
    exit(1);
  }

  memset((char *)&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(80);
  bcopy((char *)serverHost->h_addr, (char *)&server.sin_addr.s_addr, serverHost->h_length);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "ERROR: Failed to create socket.\n");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    fprintf(stderr, "ERROR: Failed to connect.\n");
    exit(1);
  }

  gettimeofday(&start, NULL);
  read(sockfd, buffer, sizeof(buffer));
  gettimeofday(&end, NULL);

  double time_taken = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000.0;

  printf("Time taken to connect to google.com: %f seconds.\n", time_taken);

  return 0;
}