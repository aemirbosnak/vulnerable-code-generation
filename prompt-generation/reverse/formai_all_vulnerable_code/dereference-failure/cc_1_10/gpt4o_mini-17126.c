//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(0);
}

void get_http_title(const char *url) {
    struct sockaddr_in server;
    struct hostent *host;
    int sockfd;
    char buffer[BUFFER_SIZE];
    char *title;

    // Parse the URL
    char *host_name = strtok(url, "/");
    char *path = strtok(NULL, "");

    // Resolve host
    host = gethostbyname(host_name);
    if (host == NULL) {
        error("ERROR, no such host");
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up the server structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("ERROR connecting");
    }

    // Send HTTP GET request
    sprintf(buffer, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path ? path : "", host_name);
    write(sockfd, buffer, strlen(buffer));

    // Read the response
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    
    // Look for the <title> tag in the response
    char *title_start = strstr(buffer, "<title>");
    char *title_end = strstr(buffer, "</title>");
    
    if (title_start && title_end) {
        title_start += 7; // move past the <title> tag
        size_t title_length = title_end - title_start;
        title = (char *)malloc(title_length + 1);
        strncpy(title, title_start, title_length);
        title[title_length] = '\0'; // null terminate

        printf("Page Title: %s\n", title);
        free(title);
    } else {
        printf("No title found in the response.\n");
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    get_http_title(argv[1]);

    return 0;
}