//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct URL {
    char* protocol;
    char* host;
    char* port;
    char* path;
};

void parse_url(char* full_url, struct URL* url) {
    char* protocol_end = strstr(full_url, "://");
    if (protocol_end == NULL) {
        fprintf(stderr, "Invalid URL format\n");
        exit(1);
    }

    url->protocol = strndup(full_url, protocol_end - full_url);
    char* rest = protocol_end + 3;

    char* path_start = strstr(rest, "/");
    if (path_start != NULL) {
        url->path = strdup(path_start);
        *path_start = '\0';
    } else {
        url->path = strdup("/");
    }

    char* port_start = strstr(rest, ":");
    if (port_start != NULL) {
        url->port = strdup(port_start + 1);
        *port_start = '\0';
    } else {
        url->port = strdup("80");
    }

    url->host = strdup(rest);
}

void skip_headers(FILE* fp) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strcmp(buffer, "\r\n") == 0) {
            return;
        }
    }
}

int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./client <url>\n");
        exit(1);
    }

    struct URL url;
    parse_url(argv[1], &url);

    printf("Protocol: %s\n", url.protocol);
    printf("Host: %s\n", url.host);
    printf("Port: %s\n", url.port);
    printf("Path: %s\n", url.path);

    struct hostent* server = gethostbyname(url.host);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", url.host);
        exit(1);
    }

    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(url.port));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server\n");
        exit(1);
    }

    char buffer[1024];
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url.path, url.host);
    printf("Request:\n%s", buffer);

    int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending request\n");
        exit(1);
    }

    printf("Response:\n");

    FILE* stream = fdopen(sockfd, "r");
    skip_headers(stream);

    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), stream)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(stream);
    close(sockfd);

    return 0;
}