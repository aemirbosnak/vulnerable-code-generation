//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>

#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int PORT = 8080; // Default port

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int n;

    // Read the request
    n = read(sock, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        close(sock);
        return NULL;
    }

    buffer[n] = '\0'; // Null terminate the string
    printf("Received request:\n%s\n", buffer);

    // Simple HTTP response
    const char *response_header = "HTTP/1.1 200 OK\r\n"
                                  "Content-Type: text/html\r\n"
                                  "Connection: close\r\n\r\n";
    const char *response_body = "<html><body><h1>Hello, World!</h1></body></html>";
    char response[BUFFER_SIZE];

    // Construct full response
    snprintf(response, sizeof(response), "%s%s", response_header, response_body);
    
    // Send the response
    write(sock, response, strlen(response));

    close(sock);
    return NULL;
}

void configure_server(int argc, char *argv[]) {
    if (argc > 1) {
        PORT = atoi(argv[1]);
        if (PORT <= 0 || PORT > 65535) {
            fprintf(stderr, "Invalid port number. Using default port 8080.\n");
            PORT = 8080;
        }
    }
}

int main(int argc, char *argv[]) {
    configure_server(argc, argv);
    
    int sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    listen(sockfd, MAX_CONNECTIONS);
    printf("Server running on port %d...\n", PORT);

    while(1) {
        int *client_socket = malloc(sizeof(int));
        clilen = sizeof(cli_addr);
        *client_socket = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (*client_socket < 0) {
            perror("Error on accept");
            free(client_socket);
            continue;
        }
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_socket) != 0) {
            perror("Error creating thread");
            close(*client_socket);
            free(client_socket);
        } else {
            pthread_detach(thread_id); // Detach thread for auto cleanup
        }
    }

    close(sockfd);
    return 0;
}