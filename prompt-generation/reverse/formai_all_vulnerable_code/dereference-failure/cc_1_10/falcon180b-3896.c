//Falcon-180B DATASET v1.0 Category: Firewall ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUFF_SIZE 1024
#define IP_ADDR_LEN 16

typedef struct {
    char ip[IP_ADDR_LEN];
    int port;
} IP_PORT;

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char buffer[BUFF_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == 0) {
        printf("socket failed\n");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_socket, 5) < 0) {
        printf("listen failed\n");
        exit(1);
    }

    while (TRUE) {
        printf("Waiting for connection...\n");
        addrlen = sizeof(cli_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&cli_addr, &addrlen);
        if (client_socket < 0) {
            printf("accept failed\n");
            exit(1);
        }
        printf("Connection accepted\n");

        sd = fork();
        if (sd == 0) {
            close(listen_socket);
            while (TRUE) {
                valread = read(client_socket, buffer, BUFF_SIZE);
                if (valread <= 0) {
                    printf("Disconnected\n");
                    exit(0);
                }
                write(STDOUT_FILENO, buffer, valread);
            }
        } else {
            close(client_socket);
        }
    }

    return 0;
}