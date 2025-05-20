//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname filename\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  char *filename = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the FTP server
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(FTP_PORT);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the USER command
  char buf[512];
  sprintf(buf, "USER anonymous\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the PASS command
  if (send(sockfd, "PASS guest@example.com\r\n", strlen("PASS guest@example.com\r\n"),
            0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the TYPE command
  if (send(sockfd, "TYPE I\r\n", strlen("TYPE I\r\n"), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the PASV command
  if (send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Parse the response
  int ip1, ip2, ip3, ip4, port1, port2;
  if (sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n", &ip1, &ip2,
            &ip3, &ip4, &port1, &port2) != 6) {
    fprintf(stderr, "Error parsing PASV response: %s\n", buf);
    return EXIT_FAILURE;
  }

  // Create a data socket
  int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (data_sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the data port
  struct sockaddr_in data_serv_addr;
  data_serv_addr.sin_family = AF_INET;
  data_serv_addr.sin_port = htons(port1 * 256 + port2);
  data_serv_addr.sin_addr.s_addr = inet_addr(hostname);
  if (connect(data_sockfd, (struct sockaddr *)&data_serv_addr,
              sizeof(data_serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the RETR command
  sprintf(buf, "RETR %s\r\n", filename);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Open a file for writing
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Receive the data
  while (1) {
    int n = recv(data_sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
      perror("recv");
      return EXIT_FAILURE;
    } else if (n == 0) {
      break;
    }
    fwrite(buf, 1, n, fp);
  }

  // Close the file
  fclose(fp);

  // Close the data socket
  close(data_sockfd);

  // Send the QUIT command
  if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}