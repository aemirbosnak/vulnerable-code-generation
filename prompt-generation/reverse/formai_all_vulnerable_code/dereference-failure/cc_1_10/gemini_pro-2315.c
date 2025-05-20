//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Define the FTP commands
#define USER "USER"
#define PASS "PASS"
#define CWD  "CWD"
#define LIST "LIST"
#define RETR "RETR"
#define QUIT "QUIT"


char* command;
char* param;

// Print usage information
void usage() {
  printf("Usage: ftp <hostname> <port>\n");
  printf("Example: ftp ftp.example.com 21\n");
}

// Connect to the FTP server
int connect_to_server(char* hostname, int port) {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return -1;
  }

  // Resolve the hostname
  struct hostent* host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return -1;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr = *(struct in_addr*)host->h_addr;

  // Connect to the server
  if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return -1;
  }

  return sock;
}

// Send a command to the FTP server
int send_command(int sock, char* command) {
  // Send the command to the server
  if (send(sock, command, strlen(command), 0) == -1) {
    perror("send");
    return -1;
  }

  // Receive the response from the server
  char response[1024];
  if (recv(sock, response, sizeof(response), 0) == -1) {
    perror("recv");
    return -1;
  }

  // Print the response
  printf("%s", response);

  return 0;
}

// Fetch a file from the FTP server
int get_file(int sock, char* filename) {
  // Send the RETR command
  char command[1024];
  sprintf(command, "RETR %s", filename);
  if (send_command(sock, command) == -1) {
    return -1;
  }

  // Receive the file
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  char buffer[1024];
  int bytes_received;
  while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
    fwrite(buffer, 1, bytes_received, fp);
  }

  fclose(fp);

  return 0;
}

// Quit the FTP server
int quit(int sock) {
  // Send the QUIT command
  if (send_command(sock, QUIT) == -1) {
    return -1;
  }

  // Close the socket
  close(sock);

  return 0;
}

// Main function
int main(int argc, char** argv) {
  // Check the number of arguments
  if (argc != 3) {
    usage();
    return -1;
  }

  // Get the hostname and port
  char* hostname = argv[1];
  int port = atoi(argv[2]);

  // Connect to the FTP server
  int sock = connect_to_server(hostname, port);
  if (sock == -1) {
    return -1;
  }

  // Get the user input
  char input[1024];
  while (1) {
    printf("ftp> ");
    fgets(input, sizeof(input), stdin);

    // Parse the input
    command = strtok(input, " ");
    param = strtok(NULL, " ");

    // Handle the command
    if (strcmp(command, USER) == 0) {
      // Send the USER command
      if (send_command(sock, USER) == -1) {
        return -1;
      }

      // Send the username
      if (send_command(sock, param) == -1) {
        return -1;
      }
    } else if (strcmp(command, PASS) == 0) {
      // Send the PASS command
      if (send_command(sock, PASS) == -1) {
        return -1;
      }

      // Send the password
      if (send_command(sock, param) == -1) {
        return -1;
      }
    } else if (strcmp(command, CWD) == 0) {
      // Send the CWD command
      if (send_command(sock, CWD) == -1) {
        return -1;
      }

      // Send the directory path
      if (send_command(sock, param) == -1) {
        return -1;
      }
    } else if (strcmp(command, LIST) == 0) {
      // Send the LIST command
      if (send_command(sock, LIST) == -1) {
        return -1;
      }
    } else if (strcmp(command, RETR) == 0) {
      // Get the file
      if (get_file(sock, param) == -1) {
        return -1;
      }
    } else if (strcmp(command, QUIT) == 0) {
      // Quit the FTP server
      if (quit(sock) == -1) {
        return -1;
      }

      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}