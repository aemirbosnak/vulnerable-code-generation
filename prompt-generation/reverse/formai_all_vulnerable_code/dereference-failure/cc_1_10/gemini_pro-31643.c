//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

//Custom Datatype to hold client session data
typedef struct client_session
{
    int client_fd;
    int server_fd;
} client_session;

//Custom function to handle errors,
void error(char *msg)
{
    perror(msg);
    exit(1);
}

//Custom function to send 404 Not Found response
void send_404(int client_fd)
{
    char *response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\nContent-Length: 13\r\n\r\n404 Not Found\n";
    write(client_fd, response, strlen(response));
}

//Custom function to send 500 Internal Server Error response
void send_500(int client_fd)
{
    char *response = "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/plain\r\nContent-Length: 27\r\n\r\n500 Internal Server Error\n";
    write(client_fd, response, strlen(response));
}

//Custom function to handle client requests
void *handle_client(void *arg)
{
    //Unpack the client session data
    client_session *session = (client_session *)arg;

    char request[1024];
    char *url;

    //Read client request
    int n = read(session->client_fd, request, 1023);
    if (n < 0)
        error("Error reading client request");

    request[n] = '\0';

    //Extract URL from request
    url = strstr(request, "GET");
    if (url == NULL)
    {
        send_404(session->client_fd);
        goto end;
    }
    url = strtok(url, " ");
    if (url == NULL)
    {
        send_404(session->client_fd);
        goto end;
    }

    //Parse URL
    char *hostname;
    char *port;
    char *path;

    hostname = strtok(url + 7, "/");
    if (hostname == NULL)
    {
        send_404(session->client_fd);
        goto end;
    }

    port = strtok(NULL, "/");
    if (port == NULL)
        port = "80"; //Default port

    path = strtok(NULL, " ");
    if (path == NULL)
        path = "/"; //Default path

    //Create a socket to connect to the server
    struct sockaddr_in server_addr;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        error("Error creating server socket");

    //Resolve hostname to IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL)
    {
        send_500(session->client_fd);
        goto end;
    }

    //Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(atoi(port));

    //Connect to server
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        send_500(session->client_fd);
        goto end;
    }

    //Send request to server
    char modified_request[1024];
    sprintf(modified_request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    write(server_fd, modified_request, strlen(modified_request));

    //Receive response from server
    char server_response[1024];
    while ((n = read(server_fd, server_response, 1023)) > 0)
    {
        server_response[n] = '\0';
        write(session->client_fd, server_response, n);
    }

    if (n < 0)
    {
        send_500(session->client_fd);
    }

end:
    //Close connections
    close(session->client_fd);
    close(session->server_fd);

    //Free memory
    free(session);

    return NULL;
}

int main(int argc, char *argv[])
{
    //Check usage
    if (argc < 3)
    {
        printf("Usage: %s <port> <backlog>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int backlog = atoi(argv[2]);

    //Create a socket to listen for client connections
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
        error("Error creating listen socket");

    //Set socket options
    int opt = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
        error("Error setting socket options");

    //Set server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    //Bind socket to address
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error binding socket to address");

    //Listen for client connections
    if (listen(listen_fd, backlog) < 0)
        error("Error listening for client connections");

    while (1)
    {
        //Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0)
            error("Error accepting client connection");

        //Create a new thread to handle the client request
        pthread_t thread;
        client_session *session = (client_session *)malloc(sizeof(client_session));
        session->client_fd = client_fd;
        if (pthread_create(&thread, NULL, handle_client, (void *)session) != 0)
            error("Error creating thread");
    }

    //Close listen socket
    close(listen_fd);

    return 0;
}