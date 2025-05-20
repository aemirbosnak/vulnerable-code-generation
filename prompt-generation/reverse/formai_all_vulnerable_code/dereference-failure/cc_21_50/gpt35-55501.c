//FormAI DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./shapeshift <port>\n");
    return EXIT_FAILURE;
  }

  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char message[] = "You have entered the shapeshifting realm.\n\n";

  // Creating a socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket failed");
    return EXIT_FAILURE;
  }

  // Forcefully attaching socket to the port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Setsockopt failed");
    return EXIT_FAILURE;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(atoi(argv[1]));

  // Forcefully attaching socket to the port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("Bind failed");
    return EXIT_FAILURE;
  }

  if (listen(server_fd, 3) < 0) {
    perror("Listen failed");
    return EXIT_FAILURE;
  }

  printf("Listening on port %d...\n", atoi(argv[1]));

  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("Accept failed");
      return EXIT_FAILURE;
    }

    send(new_socket, message, strlen(message), 0 );

    while (valread = read(new_socket, buffer, sizeof(buffer))) {
      if (valread < 0) {
        perror("Read failed");
        return EXIT_FAILURE;
      }

      if (valread == 0) {
        break;
      }

      if (strncmp(buffer, "shift shape to square", strlen("shift shape to square")) == 0) {
        printf("Shifting to square...\n");

        char square[13][13];
        memset(square, ' ', sizeof(square));

        int i, j;
        for (i = 0; i < 13; i++) {
          square[i][0] = '|';
          square[i][12] = '|';
        }

        for (j = 0; j < 13; j++) {
          square[0][j] = '-';
          square[12][j] = '-';
        }

        square[0][0] = '+';
        square[0][12] = '+';
        square[12][0] = '+';
        square[12][12] = '+';

        for (i = 0; i < 13; i++) {
          for (j = 0; j < 13; j++) {
            printf("%c", square[i][j]);
          }
          printf("\n");
        }

        send(new_socket, square, sizeof(square), 0);
      }

      if (strncmp(buffer, "shift shape to circle", strlen("shift shape to circle")) == 0) {
        printf("Shifting to circle...\n");

        char circle[13][13];
        memset(circle, ' ', sizeof(circle));

        int x, y, r;
        x = y = r = 6;

        int i, j;
        for (i = 0; i < 13; i++) {
          for (j = 0; j < 13; j++) {
            double distance = ((i - x) * (i - x)) + ((j - y) * (j - y));
            if (distance <= (r * r)) {
              circle[i][j] = '*';
            }
          }
        }

        for (i = 0; i < 13; i++) {
          for (j = 0; j < 13; j++) {
            printf("%c", circle[i][j]);
          }
          printf("\n");
        }

        send(new_socket, circle, sizeof(circle), 0);
      }

      if (strncmp(buffer, "exit", strlen("exit")) == 0) {
        printf("Exiting...\n");
        close(new_socket);
        break;
      }

      memset(buffer, 0, sizeof(buffer));
    }
  }

  return EXIT_SUCCESS;
}