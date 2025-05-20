//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Our trusty Watson, a buffer for the data
char buffer[1024];

int main(int argc, char **argv) {
  // Elementary, my dear Watson!
  if (argc < 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // The game is afoot!
  int sockfd;
  struct sockaddr_in server_addr;

  // Request the server's whereabouts from the great Oracle of DNS
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Could not resolve hostname: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Set up the socket, the doorway to our adventure
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Could not create socket\n");
    return EXIT_FAILURE;
  }

  // Prepare the server's address, our destination
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to the server, entering its lair
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    printf("Could not connect to server: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // The chase is on!
  while (1) {
    // What does our astute Watson have to say?
    printf("> ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the pesky newline character
    buffer[strcspn(buffer, "\n")] = '\0';

    // Send Watson's deductions to the server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      printf("Could not send data to server\n");
      return EXIT_FAILURE;
    }

    // Watson has spoken, now it's the server's turn
    if (strcmp(buffer, "QUIT") == 0) {
      // The game is up!
      break;
    }

    // Read the server's response, hopefully it's not a red herring
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      printf("Could not receive data from server\n");
      return EXIT_FAILURE;
    }

    // Print the server's response, could it be the solution?
    printf("%s", buffer);
  }

  // The case is closed!
  close(sockfd);
  return EXIT_SUCCESS;
}