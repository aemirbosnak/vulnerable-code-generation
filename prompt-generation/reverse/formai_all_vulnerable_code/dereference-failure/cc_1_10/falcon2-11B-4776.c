//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main() {
  int sockfd, valread, numbytes, i, portno;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[256];
  char *filePath = "/path/to/files/directory"; // specify the directory that holds your files
  char *request; // for parsing the HTTP request
  int responseCode; // HTTP response code
  
  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }
  
  // Configure server address and port
  memset((char *)&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  
  // Bind to port
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  
  // Listen for incoming connections
  listen(sockfd, 3);
  
  printf("Web server is listening on port %d...\n", PORT);
  
  while (1) {
    // Accept a connection
    sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&numbytes);
    if (sockfd < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }
    
    printf("Connection from: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    
    // Read HTTP request
    request = (char*)malloc(1024);
    valread = read(sockfd, request, 1024);
    if (valread < 0) {
      perror("read failed");
      exit(EXIT_FAILURE);
    }
    
    // Parse request and send response
    responseCode = 200; // HTTP response code for OK
    if (request[0] == 'G') {
      responseCode = 404; // HTTP response code for Not Found
    }
    
    // Send response
    numbytes = sprintf(buffer, "HTTP/1.1 %d\r\n\r\n", responseCode);
    write(sockfd, buffer, numbytes);
    if (responseCode!= 404) {
      sprintf(buffer, "Content-Type: text/html\r\n\r\n");
      numbytes = strlen(buffer);
      write(sockfd, buffer, numbytes);
      sprintf(buffer, "<html><body><h1>Hello, world!</h1></body></html>");
      numbytes = strlen(buffer);
      write(sockfd, buffer, numbytes);
    }
    
    // Close connection
    close(sockfd);
  }
  
  return 0;
}