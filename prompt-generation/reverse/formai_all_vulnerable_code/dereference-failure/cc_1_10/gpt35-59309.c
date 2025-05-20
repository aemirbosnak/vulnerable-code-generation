//FormAI DATASET v1.0 Category: Client Server Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 8080
#define MAX_BUFFER 1024

void sigchld_handler(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[])
{
    int server_socket_fd, new_socket_fd, status, yes = 1;
    struct addrinfo hints, *server_info, *p;
    struct sockaddr_storage client_addr;
    socklen_t sin_size;
    char buffer[MAX_BUFFER];
    char s[INET_ADDRSTRLEN];
    int child_pid;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "8080", &hints, &server_info)) != 0) 
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for(p = server_info; p != NULL; p = p->ai_next) 
    {
        if ((server_socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) 
        {
            perror("Server: socket failed");
            continue;
        }

        if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) 
        {
            perror("Server: setsockopt failed");
            exit(1);
        }

        if (bind(server_socket_fd, p->ai_addr, p->ai_addrlen) == -1) 
        {
            close(server_socket_fd);
            perror("Server: bind failed");
            continue;
        }

        break;
    }

    freeaddrinfo(server_info);

    if (p == NULL)  
    {
        fprintf(stderr, "Server: failed to bind\n");
        exit(1);
    }

    if (listen(server_socket_fd, 10) == -1) 
    {
        perror("listen");
        exit(1);
    }

    printf("Server: waiting for connections...\n");

    signal(SIGCHLD, sigchld_handler);

    while(1) 
    {  
        sin_size = sizeof client_addr;
        new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &sin_size);

        if (new_socket_fd == -1) 
        {
            perror("Server: accept failed");
            continue;
        }

        inet_ntop(client_addr.ss_family, &(((struct sockaddr_in *)&client_addr)->sin_addr), s, sizeof s);

        printf("Server: got connection from %s\n", s);

        if ((child_pid = fork()) == 0) 
        {
            close(server_socket_fd);

            if (send(new_socket_fd, "Welcome to the server!", 22, 0) == -1)
            perror("Server: send failed");

            int num_bytes_received = 0;

            while(1) 
            {
                memset(buffer, 0, MAX_BUFFER);

                if ((num_bytes_received = recv(new_socket_fd, buffer, MAX_BUFFER-1, 0)) == -1)
                perror("Server: recv failed");

                if (num_bytes_received == 0) 
                {
                    printf("Server: Client disconnected\n");
                    break;
                }

                printf("Server: received \"%s\"\n", buffer);

                if (send(new_socket_fd, "Message received!", 17, 0) == -1)
                perror("Server: send failed");
            }
            close(new_socket_fd);
            exit(0);
        }

        close(new_socket_fd);
    }

    return 0;
}