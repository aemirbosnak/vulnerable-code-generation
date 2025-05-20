//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    return 1;
  }

  int sockfd;
  struct sockaddr_in servaddr;
  char *input, *output;
  int input_len, output_len;

  // Create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return 1;
  }

  // Configure server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    return 1;
  }

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  while (1) {
    // Get input from user
    printf("Enter message: ");
    input = malloc(256);
    fgets(input, 256, stdin);
    input_len = strlen(input);

    // Send input to server
    if (send(sockfd, input, input_len, 0) == -1) {
      perror("send");
      break;
    }

    // Receive output from server
    output = malloc(256);
    if ((output_len = recv(sockfd, output, 256, 0)) == -1) {
      perror("recv");
      break;
    }

    // Print output
    printf("Server response: %s\n", output);

    // Free buffers
    free(input);
    free(output);

    // Check if exit command was sent
    if (strcmp(input, "exit\n") == 0) {
      break;
    }
  }

  // Close socket
  close(sockfd);

  return 0;
}