//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Neopixel-like color codes
#define CYAN    "\033[36m"
#define PURPLE  "\033[35m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define NC      "\033[0m"

// Commands
#define LIST    "LIST"
#define GET     "GET "
#define PUT     "PUT "
#define QUIT    "QUIT"

// Cyber-punk-like welcome message
void welcome() {
  printf(CYAN "Welcome to the Neon Cyber FTP Client!\n");
  printf(PURPLE "Where the data flows like a digital river!\n");
  printf(GREEN "Type 'help' for a list of commands.\n" NC);
}

// Display the help message
void help() {
  printf(YELLOW "\nAvailable commands:\n" NC);
  printf("  LIST    - List files on the server\n");
  printf("  GET <file> - Download a file from the server\n");
  printf("  PUT <file> - Upload a file to the server\n");
  printf("  QUIT    - Exit the FTP client\n");
}

// Connect to the FTP server
int connect_to_server(char *hostname, int port) {
  struct sockaddr_in server_addr;
  struct hostent *host_info;

  // Get the host information
  host_info = gethostbyname(hostname);
  if (host_info == NULL) {
    printf(RED "Error: Could not resolve hostname '%s'\n" NC, hostname);
    return -1;
  }

  // Create the socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf(RED "Error: Could not create socket\n" NC);
    return -1;
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf(RED "Error: Could not connect to server\n" NC);
    return -1;
  }

  return sock;
}

// Send a command to the FTP server
int send_command(int sock, char *command) {
  // Send the command
  int len = strlen(command);
  if (send(sock, command, len, 0) != len) {
    printf(RED "Error: Could not send command '%s'\n" NC, command);
    return -1;
  }

  return 0;
}

// Receive a response from the FTP server
int receive_response(int sock) {
  char buffer[1024];
  int len;

  // Receive the response
  while ((len = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
    buffer[len] = '\0';

    // Print the response
    printf("%s", buffer);
  }

  if (len == -1) {
    printf(RED "Error: Could not receive response from server\n" NC);
    return -1;
  }

  return 0;
}

// List the files on the FTP server
int list_files(int sock) {
  // Send the LIST command
  if (send_command(sock, LIST) == -1) {
    return -1;
  }

  // Receive the response
  if (receive_response(sock) == -1) {
    return -1;
  }

  return 0;
}

// Download a file from the FTP server
int get_file(int sock, char *filename) {
  // Send the GET command
  char command[strlen(GET) + strlen(filename) + 1];
  sprintf(command, "%s %s", GET, filename);
  if (send_command(sock, command) == -1) {
    return -1;
  }

  // Receive the response
  if (receive_response(sock) == -1) {
    return -1;
  }

  // Open the file for writing
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf(RED "Error: Could not open file '%s'\n" NC, filename);
    return -1;
  }

  // Receive the file data
  char buffer[1024];
  int len;
  while ((len = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
    fwrite(buffer, 1, len, fp);
  }

  if (len == -1) {
    printf(RED "Error: Could not receive file data\n" NC);
    return -1;
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Upload a file to the FTP server
int put_file(int sock, char *filename) {
  // Send the PUT command
  char command[strlen(PUT) + strlen(filename) + 1];
  sprintf(command, "%s %s", PUT, filename);
  if (send_command(sock, command) == -1) {
    return -1;
  }

  // Open the file for reading
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf(RED "Error: Could not open file '%s'\n" NC, filename);
    return -1;
  }

  // Send the file data
  char buffer[1024];
  int len;
  while ((len = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
    if (send(sock, buffer, len, 0) != len) {
      printf(RED "Error: Could not send file data\n" NC);
      return -1;
    }
  }

  if (ferror(fp)) {
    printf(RED "Error: Could not read file data\n" NC);
    return -1;
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Main function
int main(int argc, char **argv) {
  // Check the arguments
  if (argc != 3) {
    printf(RED "Usage: %s <hostname> <port>\n" NC, argv[0]);
    return -1;
  }

  // Connect to the FTP server
  int sock = connect_to_server(argv[1], atoi(argv[2]));
  if (sock == -1) {
    return -1;
  }

  // Welcome the user
  welcome();

  // Main loop
  while (1) {
    // Get the command from the user
    char command[1024];
    printf("> ");
    fgets(command, sizeof(command), stdin);

    // Remove the newline character
    command[strcspn(command, "\n")] = '\0';

    // Process the command
    if (strcmp(command, LIST) == 0) {
      list_files(sock);
    } else if (strncmp(command, GET, strlen(GET)) == 0) {
      get_file(sock, command + strlen(GET));
    } else if (strncmp(command, PUT, strlen(PUT)) == 0) {
      put_file(sock, command + strlen(PUT));
    } else if (strcmp(command, QUIT) == 0) {
      break;
    } else {
      help();
    }
  }

  // Close the socket
  close(sock);

  return 0;
}