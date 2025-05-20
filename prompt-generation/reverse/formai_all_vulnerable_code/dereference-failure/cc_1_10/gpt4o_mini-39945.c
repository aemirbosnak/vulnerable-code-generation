//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char) *str)) str++;
    if (*str == 0) return; 

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    *(end + 1) = '\0';
}

void build_request(const char *host, const char *path, char *request_buffer) {
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *url) {
    char method[] = "GET";
    char host[256], path[256];
    int port = 80;
    struct sockaddr_in server_address;
    struct hostent *server;

    char *url_copy = strdup(url);
    char *protocol = strtok(url_copy, "://");
    char *address = strtok(NULL, "/");
    char *query_string = strtok(NULL, "");

    if (!address) {
        fprintf(stderr, "Invalid URL: No host specified.\n");
        free(url_copy);
        return;
    }
    
    if (query_string) {
        snprintf(path, sizeof(path), "/%s", query_string);
    } else {
        snprintf(path, sizeof(path), "/");
    }

    // Separate host and port if port is specified in ULR
    char *port_str = strchr(address, ':');
    if (port_str) {
        *port_str = '\0';
        port = atoi(port_str + 1);
    }
    
    strcpy(host, address);
    free(url_copy);
    
    // Get the server's DNS entry
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host: %s\n", host);
        return;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("ERROR opening socket");
    }

    // Setup the server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        handle_error("ERROR connecting");
    }

    // Building HTTP request
    char request_buffer[BUFFER_SIZE];
    build_request(host, path, request_buffer);

    // Send HTTP request to the server
    write(sockfd, request_buffer, strlen(request_buffer));
    
    // Reading server's response
    char response_buffer[BUFFER_SIZE];
    memset(response_buffer, 0, sizeof(response_buffer));
    while (read(sockfd, response_buffer, sizeof(response_buffer) - 1) > 0) {
        printf("%s", response_buffer);
        memset(response_buffer, 0, sizeof(response_buffer));
    }

    // Closing the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http://example.com/path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Intervention: Strip trailing whitespace and transform URL to lower case
    char *url = strdup(argv[1]);
    trim_whitespace(url);
    to_lower(url);

    // Initiating GET request to a mystical endpoint
    printf("Initiating GET request to: %s\n", url);
    http_get(url);

    // Free allocated URL memory
    free(url);
    return EXIT_SUCCESS;
}