//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 6000
#define BUFFER_SIZE 1024

// Function to handle SIGINT signal (Ctrl+C)
void sigintHandler(int sig) {
  printf("Received SIGINT signal. Exiting...\n");
  exit(0);
}

int main() {
  // Register SIGINT signal handler
  signal(SIGINT, sigintHandler);

  // Create a UDP socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket() failed");
    return -1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind() failed");
    return -1;
  }

  // Main loop
  while (1) {
    // Receive data from the client
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
    if (recv_len < 0) {
      perror("recvfrom() failed");
      continue;
    }

    // Process the data
    char *command = strtok(buffer, " ");
    if (!strcmp(command, "takeoff")) {
      printf("收到起飛指令\n");
      // Send a takeoff command to the drone
      char takeoff_command[] = "takeoff";
      sendto(sockfd, takeoff_command, strlen(takeoff_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "land")) {
      printf("收到降落指令\n");
      // Send a land command to the drone
      char land_command[] = "land";
      sendto(sockfd, land_command, strlen(land_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "forward")) {
      char *distance = strtok(NULL, " ");
      printf("收到前進指令, 距離: %s\n", distance);
      // Send a forward command to the drone with the specified distance
      char forward_command[BUFFER_SIZE];
      snprintf(forward_command, BUFFER_SIZE, "forward %s", distance);
      sendto(sockfd, forward_command, strlen(forward_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "backward")) {
      char *distance = strtok(NULL, " ");
      printf("收到後退指令, 距離: %s\n", distance);
      // Send a backward command to the drone with the specified distance
      char backward_command[BUFFER_SIZE];
      snprintf(backward_command, BUFFER_SIZE, "backward %s", distance);
      sendto(sockfd, backward_command, strlen(backward_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "left")) {
      char *angle = strtok(NULL, " ");
      printf("收到左轉指令, 角度: %s\n", angle);
      // Send a left turn command to the drone with the specified angle
      char left_command[BUFFER_SIZE];
      snprintf(left_command, BUFFER_SIZE, "left %s", angle);
      sendto(sockfd, left_command, strlen(left_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "right")) {
      char *angle = strtok(NULL, " ");
      printf("收到右轉指令, 角度: %s\n", angle);
      // Send a right turn command to the drone with the specified angle
      char right_command[BUFFER_SIZE];
      snprintf(right_command, BUFFER_SIZE, "right %s", angle);
      sendto(sockfd, right_command, strlen(right_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "up")) {
      char *distance = strtok(NULL, " ");
      printf("收到上升指令, 距離: %s\n", distance);
      // Send an up command to the drone with the specified distance
      char up_command[BUFFER_SIZE];
      snprintf(up_command, BUFFER_SIZE, "up %s", distance);
      sendto(sockfd, up_command, strlen(up_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else if (!strcmp(command, "down")) {
      char *distance = strtok(NULL, " ");
      printf("收到下降指令, 距離: %s\n", distance);
      // Send a down command to the drone with the specified distance
      char down_command[BUFFER_SIZE];
      snprintf(down_command, BUFFER_SIZE, "down %s", distance);
      sendto(sockfd, down_command, strlen(down_command), 0, (struct sockaddr *)&client_addr, client_addr_len);
    } else {
      printf("收到未知指令: %s\n", command);
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}