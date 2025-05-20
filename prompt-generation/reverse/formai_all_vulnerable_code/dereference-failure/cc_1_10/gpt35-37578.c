//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef unsigned short WORD;
typedef unsigned int  DWORD;

#define PORT 143
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

  if (argc != 3) {
     printf("Invalid usage. Please use as following: %s <IMAP server hostname> <username>\n", argv[0]);
     return 1;
  }

  char buf[BUF_SIZE];
  int sockfd, bytes;
  struct sockaddr_in server_addr;
  struct hostent *he;
  char* hostname = argv[1];
  char* username = argv[2];
 
  if ((he=gethostbyname(hostname)) == NULL) {  
     printf("Error resolving hostname.");
     return 2; 
  }
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  memset(&server_addr, 0, sizeof(server_addr)); 
  server_addr.sin_family = AF_INET;    
  server_addr.sin_port = htons(PORT);  
  server_addr.sin_addr = *((struct in_addr *)he->h_addr); 
   
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
     printf("Error connecting to IMAP server.");
     return 3;
  }

  recv(sockfd, buf, BUF_SIZE, 0);
  printf("%s\n", buf);
  memset(buf, 0, BUF_SIZE); 

  // Login to server
  memset(buf, 0, BUF_SIZE);
  sprintf(buf, "1 login %s\r\n", username);
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, BUF_SIZE, 0);
  printf("%s\n", buf);
  memset(buf, 0, BUF_SIZE);

  // Check for success
  if (buf[0] != '1' || buf[1] != ' OK')
  {
    printf("Error logging in.");
    return 4;
  }

  // List mailbox
  memset(buf, 0, BUF_SIZE); 
  sprintf(buf, "2 list \"\" *\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, BUF_SIZE, 0);
  printf("%s\n", buf);
  memset(buf, 0, BUF_SIZE); 

  // Logout of server
  memset(buf, 0, BUF_SIZE);  
  sprintf(buf, "3 logout\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, BUF_SIZE, 0);
  printf("%s\n", buf);
  memset(buf, 0, BUF_SIZE); 

  // Close socket
  close(sockfd); 
  return 0;
}