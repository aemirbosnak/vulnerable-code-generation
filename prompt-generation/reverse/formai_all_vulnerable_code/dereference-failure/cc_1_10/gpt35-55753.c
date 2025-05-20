//FormAI DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    bool configurable = true;  // Set to false to use default values
    int port = 8080;
    char message[] = "Hello, World!";  // Default message if not entered in arguments

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-p") == 0 && argc > i+1) {
                port = atoi(argv[i+1]);
            } else if (strcmp(argv[i], "-m") == 0 && argc > i+1) {
                strncpy(message, argv[i+1], BUF_SIZE-1);
            } else if (strcmp(argv[i], "-default") == 0) {
                configurable = false;
            }
        }
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (configurable) {
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(port);

        if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
            error_handling("bind() error");
    } else {
        if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
            error_handling("bind() error");
    }

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");

    write(clnt_sock, message, strlen(message));
    read(clnt_sock, buf, BUF_SIZE-1);
    printf("Message from client: %s\n", buf);

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}