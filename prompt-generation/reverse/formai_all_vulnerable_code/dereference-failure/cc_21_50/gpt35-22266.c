//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#define PORT 8080
#define MAX_CLIENTS 100

int main(){
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "Hello from chat server";
  int client_sockets[MAX_CLIENTS] = {0};
  fd_set read_fds;

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }

  while(1){
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &read_fds);
    for(int i = 0; i < MAX_CLIENTS; i++){
        if(client_sockets[i] > 0){
            FD_SET(client_sockets[i], &read_fds);
        }
    }

    int max_sd = server_fd;
    for(int i = 0; i < MAX_CLIENTS; i++){
        if(client_sockets[i] > 0){
            if(client_sockets[i] > max_sd){
                max_sd = client_sockets[i];
            }
        }
    }

    int activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);

    if(FD_ISSET(server_fd, &read_fds)){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection, socket fd is %d, ip is: %s, port is: %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        for(int i = 0; i < MAX_CLIENTS; i++){
            if(client_sockets[i] == 0){
                client_sockets[i] = new_socket;
                break;
            }
        }
    }

    for(int i = 0; i < MAX_CLIENTS; i++){
        int sd = client_sockets[i];
        if(FD_ISSET(sd, &read_fds)){
            if ((valread = read(sd, buffer, 1024)) == 0) {
                getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
                printf("Host disconnected, ip %s, port %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                client_sockets[i] = 0;
            }
            else{
                for(int j = 0; j < MAX_CLIENTS; j++){
                    if(j != i && client_sockets[j] > 0){
                        send(client_sockets[j], buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }
  }

  return 0;
}