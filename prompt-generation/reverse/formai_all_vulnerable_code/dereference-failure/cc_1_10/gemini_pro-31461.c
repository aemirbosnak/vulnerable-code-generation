//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Welcome message
void welcome_message() {
  printf("\n\n** Welcome to the Post-Apocalyptic Port Scanner **\n\n");
  printf("In this desolate wasteland, we offer you a flicker of hope to find survivors.\n");
  printf("Let's venture into the darkness and scan for signs of life.\n\n");
}

// Usage instructions
void usage() {
  printf("Usage: scanner [target IP] [start port] [end port]\n");
  printf("Example: ./scanner 192.168.1.1 1 1024\n\n");
}

// Validate IP address
int validate_ip(char *ip) {
  struct sockaddr_in sa;
  return inet_pton(AF_INET, ip, &(sa.sin_addr));
}

// Create a socket
int create_socket() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(1);
  }
  return sockfd;
}

// Connect to a port
int connect_port(char *ip, int port) {
  struct sockaddr_in servaddr;
  int sockfd = create_socket();

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr(ip);

  int conn = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (conn < 0) {
    return 0;  // Port is closed
  }
  return 1;  // Port is open
}

// Scan ports in a range
void scan_ports(char *ip, int start_port, int end_port) {
  printf("[+] Scanning ports from %d to %d on IP address %s\n", start_port, end_port, ip);

  for (int port = start_port; port <= end_port; port++) {
    int is_open = connect_port(ip, port);
    if (is_open) {
      printf("[+] Port %d is OPEN\n", port);
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 4) {
    usage();
    return 1;
  }

  // Validate IP address
  if (!validate_ip(argv[1])) {
    printf("Invalid IP address\n");
    return 1;
  }

  // Convert ports to integers
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Display welcome message
  welcome_message();

  // Scan the ports
  scan_ports(argv[1], start_port, end_port);

  printf("\n\nMay the wasteland be kind to you, survivor.\n\n");

  return 0;
}