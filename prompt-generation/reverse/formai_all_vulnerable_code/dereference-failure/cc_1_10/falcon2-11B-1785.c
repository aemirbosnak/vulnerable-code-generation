//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[100];
    int n;

    // Server socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the server address struct
    memset((char *) &serv_addr, '\0', sizeof(serv_addr));
    portno = htons(atoi(argv[1]));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = portno;

    // Bind the server socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Accept incoming connection
    printf("Waiting for a connection...\n");
    while (1) {
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        int new_socket = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (new_socket < 0) {
            perror("accept failed");
            exit(1);
        }
        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Handle the incoming connection
        int flag = 1;
        while (flag) {
            memset(buffer, '\0', sizeof(buffer));
            n = recv(new_socket, buffer, sizeof(buffer), 0);
            if (n < 0) {
                perror("recv failed");
                flag = 0;
            } else {
                printf("%s", buffer);
            }
            if (strncmp(buffer, "end", 3) == 0) {
                flag = 0;
            } else {
                n = send(new_socket, buffer, sizeof(buffer), 0);
                if (n < 0) {
                    perror("send failed");
                    flag = 0;
                }
            }
        }
        close(new_socket);
    }
    close(sockfd);
    return 0;
}