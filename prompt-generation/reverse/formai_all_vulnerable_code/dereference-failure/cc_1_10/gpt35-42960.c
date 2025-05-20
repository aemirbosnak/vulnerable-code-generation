//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int socket_desc, portno, n;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];

  if(argc != 3) {
     printf("Usage: %s <Server IP Address> <Port Number>\n", argv[0]);
     return 1;
  }

  portno = atoi(argv[2]);
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1)
      printf("Could not create socket");

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(portno);

  if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {       
      printf("Connection failed\n");
      return 1;
  }

  printf("Connection established\n");

  while(1) {
      printf("ftp> ");
      bzero(buffer, BUFFER_SIZE);
      fgets(buffer, BUFFER_SIZE, stdin);

      if(strncmp(buffer, "quit", 4) == 0) {
        printf("Closing connection\n");
        close(socket_desc);
        return 0;
      }

      n = write(socket_desc, buffer, strlen(buffer));

      if (n < 0) {
        printf("Error sending command to server\n");
        continue;
      }

      bzero(buffer, BUFFER_SIZE);

      n = read(socket_desc, buffer, BUFFER_SIZE);

      if (n < 0) {
        printf("Error receiving response from server\n");
        continue;
      }

      printf("%s\n", buffer);
  }

  return 0;
}