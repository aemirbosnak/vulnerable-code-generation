//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUF_SIZE];
  char *hostname;
  char *filename;
  double start_time, end_time;
  long file_size;

  if (argc < 4) {
    fprintf(stderr, "Usage: %s hostname port filename\n", argv[0]);
    exit(1);
  }

  hostname = argv[1];
  portno = atoi(argv[2]);
  filename = argv[3];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send the filename to the server
  n = write(sockfd, filename, strlen(filename));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive the file size from the server
  n = read(sockfd, buffer, BUF_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  file_size = atol(buffer);

  // Start the timer
  start_time = clock();

  // Receive the file from the server
  while (file_size > 0) {
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }
    file_size -= n;
  }

  // Stop the timer
  end_time = clock();

  // Calculate the download speed
  double download_speed = (file_size / 1024) / ((end_time - start_time) / CLOCKS_PER_SEC);

  // Print the download speed
  printf("Download speed: %.2f KB/s\n", download_speed);

  close(sockfd);
  return 0;
}