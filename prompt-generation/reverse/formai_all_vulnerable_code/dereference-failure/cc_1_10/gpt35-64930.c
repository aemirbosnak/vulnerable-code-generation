//FormAI DATASET v1.0 Category: Simple Web Server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080

void serve(int conn)
{
    char buffer[1024] = {0};
    char *response;
     
    recv(conn, buffer, 1024, 0);
    printf("%s", buffer);
     
    char *method = strtok(buffer, " \t\r\n");
    char *path = strtok(NULL, " \t\r\n");

    if (strcmp(path, "/") == 0)
        path = "/index.html";

    char *full_path = malloc(strlen(path) + 2);
    sprintf(full_path, ".%s", path);

    int fd = open(full_path, O_RDONLY);
    if (fd == -1) {
        response = "HTTP/1.1 404 NOT FOUND\n"
                   "Content-Type: text/html\n"
                   "\n"
                   "<html><body>404 Not Found</body></html>";
        send(conn, response, strlen(response), 0);
    } else {
        struct stat file_stat;
        fstat(fd, &file_stat);

        response = "HTTP/1.1 200 OK\n"
                   "Content-Type: text/html\n"
                   "\n";
        send(conn, response, strlen(response), 0);

        if (method != NULL && strcmp(method, "HEAD") == 0) {
            send(conn, "", 0, 0);
        } else {
            while (1) {
                int len = read(fd, buffer, 1024);
                if (len == 0)
                    break;
                send(conn, buffer, len, 0);
            }
        }

        close(fd);
    }

    close(conn);
}

int main()
{
    int server_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started, listening on port %d...\n", PORT);

    while (1) {
        client_len = sizeof(client_addr);
        conn_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            close(conn_fd);
            continue;
        } else if (pid == 0) {
            close(server_fd);
            serve(conn_fd);
            exit(EXIT_SUCCESS);
        } else {
            close(conn_fd);
            continue;
        }
    }
}