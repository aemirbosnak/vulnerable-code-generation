//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  char buffer[MAXLINE];
  struct sockaddr_in servaddr;

  if(argc != 3) {
    printf("\nInvalid Arguments!\nUsage: %s <Server IP Addr> <Port Number>\n",argv[0]);
    exit(0);
  }

  // Create Socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Clear memory
  bzero(&servaddr, sizeof(servaddr));

  // Set family and port
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));

  // Convert server address to binary format
  if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    printf("\nInvalid IP Address!\n");
    exit(0);
  }

  // Connect to server
  if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    printf("\nUnable to Connect to Server!\n");
    exit(0);
  }

  // Receive response from server
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  // Send email details to server
  char *email = "MAIL FROM:<sender@example.com>\r\n";
  char *rcpt = "RCPT TO:<receiver@example.com>\r\n";
  char *data = "DATA\r\n";
  char *body = "Subject: Test Message\r\nThis is a test email.\r\n.\r\n";

  send(sockfd, email, strlen(email), 0);
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  send(sockfd, rcpt, strlen(rcpt), 0);
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  send(sockfd, data, strlen(data), 0);
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  send(sockfd, body, strlen(body), 0);
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  // Close socket
  close(sockfd);

  return 0;
}