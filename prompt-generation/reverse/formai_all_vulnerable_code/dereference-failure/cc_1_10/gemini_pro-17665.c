//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: retro
// Hack the Planet!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/times.h>
#include <arpa/inet.h>

// ASCII art
#define ASCII "    .__                                     .__ \n   |  |__   ____   ____   _____   _______  |  | \n   |  |  \_/ __ \\ /  _ \\ /     \_/ __   \\ |  | \n   |   Y  \\  ___/ (  <_> )  Y Y  \\  ___/  \\|  |__\n   |___|  /\\___  >  \\____/|__|_|  /\\___  / |____/\n        \\/     \\/               \\/     \\/     \n"

// Terminal colors
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// Function prototypes
void print_ascii();
void print_usage();
void sighandler(int);
int setup_socket(const char *, const char *);

// Global variables
int sockfd;
char *ip_address;
char *port;

int main(int argc, char *argv[]) {
  // Print ASCII art
  print_ascii();

  // Check arguments
  if (argc != 3) {
    print_usage();
    exit(1);
  }
  ip_address = argv[1];
  port = argv[2];

  // Setup socket
  sockfd = setup_socket(ip_address, port);

  // Signal handler
  signal(SIGINT, sighandler);

  // Main loop
  while (1) {
    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd < 0) {
      perror("accept() failed");
      exit(1);
    }

    // Get client IP address
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

    // Print client information
    printf(GREEN "Incoming connection from: " RESET "%s\n", client_ip);

    // Receive data from client
    char buffer[1024];
    int n = read(client_sockfd, buffer, sizeof(buffer));
    if (n < 0) {
      perror("read() failed");
      exit(1);
    }

    // Process data
    printf(YELLOW "Received data: " RESET "%s\n", buffer);

    // Send data to client
    char *response = "Unauthorized access detected. Connection terminated.";
    n = write(client_sockfd, response, strlen(response));
    if (n < 0) {
      perror("write() failed");
      exit(1);
    }

    // Close client socket
    close(client_sockfd);
  }

  // Close socket
  close(sockfd);

  return 0;
}

// Print ASCII art
void print_ascii() {
  printf("%s", ASCII);
}

// Print usage
void print_usage() {
  printf("Usage: %s <ip_address> <port>\n", __FILE__);
}

// Signal handler
void sighandler(int signo) {
  printf(RED "\nExiting...\n" RESET);
  close(sockfd);
  exit(0);
}

// Setup socket
int setup_socket(const char *ip_address, const char *port) {
  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket() failed");
    exit(1);
  }

  // Set socket options
  int optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

  // Bind socket to IP address and port
  struct sockaddr_in serv_addr;
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(ip_address);
  serv_addr.sin_port = htons(atoi(port));
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind() failed");
    exit(1);
  }

  // Listen on socket
  if (listen(sockfd, 5) < 0) {
    perror("listen() failed");
    exit(1);
  }

  return sockfd;
}