//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 5555
#define BUFF_SIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  pthread_t thread;
} DroneControl;

static DroneControl **drones;
static int num_drones = 0;

void *handle_drone(void *arg) {
  DroneControl *drone = (DroneControl *)arg;
  char buff[BUFF_SIZE];
  int rc;

  while (1) {
    // Receive data from the drone
    rc = recv(drone->sockfd, buff, BUFF_SIZE, 0);
    if (rc < 0) {
      perror("recv");
      break;
    } else if (rc == 0) {
      // Drone disconnected
      printf("Drone disconnected\n");
      break;
    }

    // TODO: Process data from the drone

    // Send data to the drone
    rc = send(drone->sockfd, buff, rc, 0);
    if (rc < 0) {
      perror("send");
      break;
    }
  }

  // Close the socket
  close(drone->sockfd);

  // Remove the drone from the list of active drones
  for (int i = 0; i < num_drones; i++) {
    if (drones[i] == drone) {
      num_drones--;
      drones[i] = drones[num_drones];
      break;
    }
  }

  // Free the memory allocated for the drone
  free(drone);

  return NULL;
}

int main(int argc, char *argv[]) {
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;
  int rc;

  // Create the server socket
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    return -1;
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the server socket to the address
  rc = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (rc < 0) {
    perror("bind");
    return -1;
  }

  // Listen for incoming connections
  rc = listen(server_sock, 5);
  if (rc < 0) {
    perror("listen");
    return -1;
  }

  // Accept incoming connections
  while (1) {
    client_addr_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Create a new DroneControl object
    DroneControl *drone = malloc(sizeof(DroneControl));
    if (drone == NULL) {
      perror("malloc");
      close(client_sock);
      continue;
    }

    // Set the DroneControl object's fields
    drone->sockfd = client_sock;
    drone->addr = client_addr;

    // Create a new thread to handle the drone
    rc = pthread_create(&drone->thread, NULL, handle_drone, (void *)drone);
    if (rc != 0) {
      perror("pthread_create");
      free(drone);
      close(client_sock);
      continue;
    }

    // Add the drone to the list of active drones
    drones[num_drones++] = drone;
  }

  // Close the server socket
  close(server_sock);

  return 0;
}