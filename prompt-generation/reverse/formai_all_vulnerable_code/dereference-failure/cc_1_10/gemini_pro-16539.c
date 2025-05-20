//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
// Hark! A tale of star-cross'd lovers
// Whose love was put to the test in a digital age

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 5) {
    printf("Usage: %s <server IP> <server port> <username> <password>\n", argv[0]);
    return -1;
  }

  // Romeo, a valiant young client
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Romeo could not create a socket");
    return -1;
  }

  // Juliet, the fair server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  // Romeo's cunning attempt to reach his beloved
  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("Romeo could not connect to Juliet");
    return -1;
  }

  // The lovers' secret exchange
  char buf[BUFF_SIZE];

  // Romeo's sweet plea
  sprintf(buf, "USER %s\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("Romeo's plea was not received");
    return -1;
  }

  // Juliet's coquettish response
  if (recv(sockfd, buf, BUFF_SIZE, 0) < 0) {
    perror("Juliet's response was not received");
    return -1;
  }

  // Romeo's impassioned password
  sprintf(buf, "PASS %s\r\n", argv[4]);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("Romeo's password was not sent");
    return -1;
  }

  // Juliet's final verdict
  if (recv(sockfd, buf, BUFF_SIZE, 0) < 0) {
    perror("Juliet's verdict was not received");
    return -1;
  }

  // The lovers' tragic end
  if (strncmp(buf, "230 Login successful", 20) != 0) {
    printf("Alas, Romeo and Juliet's love was forbidden!\n");
    return -1;
  }

  printf("Romeo and Juliet's love triumphed against all odds!\n");
  return 0;
}