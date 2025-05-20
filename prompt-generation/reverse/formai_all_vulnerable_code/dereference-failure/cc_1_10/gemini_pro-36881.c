//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

// Error handling function
void error(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

// Signal handler for SIGINT
void sigint_handler(int signum) {
  printf("\nExiting program...\n");
  exit(EXIT_SUCCESS);
}

// Drone remote control program
int main(int argc, char *argv[]) {
  // Declarations
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[256];
  char command[32];
  int n;
  int i;
  int keep_alive = 1;
  time_t start, end;

  // Parse arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get IP address and port number
  char *ip_address = argv[1];
  portno = atoi(argv[2]);

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("Error opening socket");
  }

  // Set socket options
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &keep_alive, sizeof(keep_alive));

  // Set server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
    error("Error converting IP address");
  }

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("Error connecting to server");
  }

  // Set up signal handler for SIGINT
  signal(SIGINT, sigint_handler);

  // Main loop
  while (1) {
    // Get command from user
    printf("Enter command (takeoff, land, up, down, left, right, forward, backward, quit): ");
    scanf("%s", command);

    // Send command to drone
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
      error("Error sending command");
    }

    // Receive confirmation from drone
    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
      error("Error receiving confirmation");
    }

    // Print confirmation message
    printf("Confirmation from drone: %s\n", buffer);

    // Check for quit command
    if (strcmp(command, "quit") == 0) {
      break;
    }

    // Sleep for 1 second
    sleep(1);
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}