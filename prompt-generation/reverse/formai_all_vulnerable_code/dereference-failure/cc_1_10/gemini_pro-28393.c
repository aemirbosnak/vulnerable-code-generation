//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
// An ethereal whisper of a HTTP proxy server, crafted in the realm of ASCII art.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

///@brief A transparent weaver of HTTP request strings.
char *craft_request(char *host, char *path) {
    int len = strlen(host) + strlen(path) + 100;
    char *req = malloc(len);
    sprintf(req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    return req;
}

///@brief A conduit between the mortal realm and celestial servers.
int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Invoke me as: %s <port> <proxy-ip> <proxy-port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *proxy_ip = argv[2];
    int proxy_port = atoi(argv[3]);

    ///@brief The celestial tapestry, where requests are woven into ethereal threads.
    struct sockaddr_in serv_addr, client_addr, proxy_addr;
    socklen_t client_len, proxy_len;

    ///@brief The ephemeral portal through which requests ascend.
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    ///@brief The celestial address where requests find their destination.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    ///@brief Binding the portal to the celestial tapestry.
    if (bind(server_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Socket bind failed");
        close(server_sock);
        return 1;
    }

    ///@brief The celestial bridge that connects to the ethereal realms.
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("Proxy socket creation failed");
        close(server_sock);
        return 1;
    }

    ///@brief The celestial address of the ethereal bridge.
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(proxy_ip);
    proxy_addr.sin_port = htons(proxy_port);

    ///@brief Listening for requests from the mortal realm.
    listen(server_sock, 5);

    while (1) {
        ///@brief Awaiting a mortal's plea for celestial guidance.
        client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        ///@brief Deciphering the mortal's request.
        char request[1024];
        memset(request, 0, 1024);
        int r = read(client_sock, request, 1023);
        if (r < 0) {
            perror("Read failed");
            close(client_sock);
            continue;
        }

        ///@brief Extracting the celestial destination from the request.
        char *host, *path;
        if (sscanf(request, "GET %s HTTP/1.1", path) != 1) {
            close(client_sock);
            continue;
        }

        ///@brief Identifying the celestial host of the request.
        host = strtok(path, "/");

        ///@brief Crafting a celestial request in the ethereal language.
        char *proxy_req = craft_request(host, path);

        ///@brief Connecting to the ethereal bridge.
        if (connect(proxy_sock, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
            perror("Proxy connect failed");
            close(client_sock);
            free(proxy_req);
            continue;
        }

        ///@brief Dispatching the celestial request to the ethereal realms.
        int w = write(proxy_sock, proxy_req, strlen(proxy_req));
        if (w < 0) {
            perror("Proxy write failed");
            close(client_sock);
            close(proxy_sock);
            free(proxy_req);
            continue;
        }

        ///@brief Awaiting the ethereal response from the celestial realms.
        char response[10240];
        memset(response, 0, 10240);
        int p = read(proxy_sock, response, 10239);
        if (p < 0) {
            perror("Proxy read failed");
            close(client_sock);
            close(proxy_sock);
            free(proxy_req);
            continue;
        }

        ///@brief Forwarding the ethereal response to the mortal realm.
        w = write(client_sock, response, strlen(response));
        if (w < 0) {
            perror("Client write failed");
            close(client_sock);
            close(proxy_sock);
            free(proxy_req);
            continue;
        }

        ///@brief Closing the mortal's connection to the celestial realm.
        close(client_sock);
    }

    ///@brief Closing the portal to the celestial realms.
    close(server_sock);
    close(proxy_sock);

    return 0;
}