//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

// Define the FTP commands
#define USER "USER"
#define PASS "PASS"
#define CWD "CWD"
#define LIST "LIST"
#define RETR "RETR"
#define QUIT "QUIT"

// Define the FTP server information
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21

// Define the thread function
void *ftp_thread(void *args);

// Main function
int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the FTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error connecting to server");
    exit(1);
  }

  // Receive the welcome message from the FTP server
  char welcome_msg[512];
  int n = recv(sock, welcome_msg, sizeof(welcome_msg), 0);
  if (n == -1) {
    perror("Error receiving welcome message");
    exit(1);
  }
  printf("%s\n", welcome_msg);

  // Create a thread to handle the FTP commands
  pthread_t ftp_thread_id;
  pthread_create(&ftp_thread_id, NULL, ftp_thread, (void *)&sock);

  // Join the thread
  pthread_join(ftp_thread_id, NULL);

  // Close the socket
  close(sock);

  return 0;
}

// Thread function to handle the FTP commands
void *ftp_thread(void *args) {
  // Get the socket from the arguments
  int *sock = (int *)args;

  // Loop until the user quits
  while (1) {
    // Prompt the user for a command
    printf("Enter an FTP command: ");
    char command[512];
    fgets(command, sizeof(command), stdin);

    // Parse the command
    char *cmd = strtok(command, " ");
    char *arg = strtok(NULL, " ");

    // Send the command to the FTP server
    if (strcmp(cmd, USER) == 0) {
      char user_cmd[512];
      sprintf(user_cmd, "USER %s\r\n", arg);
      send(*sock, user_cmd, strlen(user_cmd), 0);
    } else if (strcmp(cmd, PASS) == 0) {
      char pass_cmd[512];
      sprintf(pass_cmd, "PASS %s\r\n", arg);
      send(*sock, pass_cmd, strlen(pass_cmd), 0);
    } else if (strcmp(cmd, CWD) == 0) {
      char cwd_cmd[512];
      sprintf(cwd_cmd, "CWD %s\r\n", arg);
      send(*sock, cwd_cmd, strlen(cwd_cmd), 0);
    } else if (strcmp(cmd, LIST) == 0) {
      char list_cmd[512];
      sprintf(list_cmd, "LIST\r\n");
      send(*sock, list_cmd, strlen(list_cmd), 0);
    } else if (strcmp(cmd, RETR) == 0) {
      char retr_cmd[512];
      sprintf(retr_cmd, "RETR %s\r\n", arg);
      send(*sock, retr_cmd, strlen(retr_cmd), 0);
    } else if (strcmp(cmd, QUIT) == 0) {
      char quit_cmd[512];
      sprintf(quit_cmd, "QUIT\r\n");
      send(*sock, quit_cmd, strlen(quit_cmd), 0);
      break;
    } else {
      printf("Invalid command\n");
    }

    // Receive the response from the FTP server
    char response[512];
    int n = recv(*sock, response, sizeof(response), 0);
    if (n == -1) {
      perror("Error receiving response");
      exit(1);
    }
    printf("%s\n", response);
  }

  return NULL;
}