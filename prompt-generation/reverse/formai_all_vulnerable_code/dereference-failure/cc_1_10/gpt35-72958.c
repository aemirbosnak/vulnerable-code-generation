//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_BUFFER_SIZE 1024

void ftpClient(char *ipAddress, int portNumber) {
  struct sockaddr_in server_addr;
  int clientFD = 0, bytesRead = 0, totalBytes = 0;
  char *buffer = (char*) malloc(DEFAULT_BUFFER_SIZE);
  char input[DEFAULT_BUFFER_SIZE];
  char *token;

  clientFD = socket(AF_INET, SOCK_STREAM, 0);
  if (clientFD < 0) {
    printf("Error: Could not create socket\n");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, '0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(portNumber);

  if (inet_pton(AF_INET, ipAddress, &server_addr.sin_addr) <= 0) {
    printf("Error: Invalid IP Address\n");
    exit(EXIT_FAILURE);
  }

  if (connect(clientFD, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error: Could not connect to Server\n");
    exit(EXIT_FAILURE);
  }

  printf("Connected to server at %s:%d.\n", ipAddress, portNumber);

  while(1) {
    printf("Enter FTP command: ");
    fgets(input, DEFAULT_BUFFER_SIZE, stdin);
    token = strtok(input, " \n");

    if (strcasecmp(token, "exit") == 0) {
      printf("Exiting FTP.\n");
      send(clientFD, "quit\n", 5, 0);
      break;
    } else if (strcasecmp(token, "list") == 0) {
      send(clientFD, "list\n", 5, 0);
    } else if (strcasecmp(token, "get") == 0) {
      token = strtok(NULL, " \n");
      if (token != NULL) {
        send(clientFD, input, strlen(input), 0);

        bytesRead = read(clientFD, buffer, DEFAULT_BUFFER_SIZE);
        while (bytesRead > 0) {
          printf("%.*s", bytesRead, buffer);
          totalBytes += bytesRead;
          bytesRead = read(clientFD, buffer, DEFAULT_BUFFER_SIZE);

          if (totalBytes > 0 && totalBytes % DEFAULT_BUFFER_SIZE == 0) {
            printf("\n");
          }
        }
      } else {
        printf("Error: Please enter file name.\n");
      }
    } else if (strcasecmp(token, "put") == 0) {
      token = strtok(NULL, " \n");
      if (token != NULL) {
        FILE *fp;
        fp = fopen(token, "r");

        if (fp != NULL) {
          send(clientFD, input, strlen(input), 0);

          while(fgets(buffer, DEFAULT_BUFFER_SIZE, fp) != NULL) {
            send(clientFD, buffer, strlen(buffer), 0);
          }

          fclose(fp);
          printf("File uploaded successfully.\n");
        } else {
          printf("Error: File not found.\n");
        }
      } else {
        printf("Error: Please enter file name.\n");
      }
    } else {
      printf("Invalid command. Try 'list', 'get', 'put', or 'exit'.\n");
    }
  }

  free(buffer);
  close(clientFD);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
    return(EXIT_FAILURE);
  }

  ftpClient(argv[1], atoi(argv[2]));
  return(EXIT_SUCCESS);
}