//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[256];

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up server address struct
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(atoi(argv[1]));

  // Bind to port
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for incoming connections
  listen(sockfd, 5);

  while (1) {
    socklen_t clilen = sizeof(struct sockaddr_in);
    int newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    // Read data from client
    n = read(newsockfd, buffer, sizeof(buffer));
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }
    printf("Received: %s\n", buffer);

    // Send data to client
    n = write(newsockfd, "Hello, world!", sizeof("Hello, world!"));
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }

    // Close connection
    close(newsockfd);
  }

  close(sockfd);
  return 0;
}