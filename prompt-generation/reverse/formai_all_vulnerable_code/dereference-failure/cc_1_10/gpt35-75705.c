//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define HTTP_PORT 80
#define MAX_HTTP_RESPONSE_SIZE 1024 * 1024

// Helper function to display an error message and exit the program
void exitWithError(char *errorMessage) {
    perror(errorMessage);
    exit(1);
}

int main(int argc, char *argv[]) {
    
    // Validate command line arguments
    if (argc != 2) {
        printf("Usage: %s <HTTP URL>\n", argv[0]);
        exit(1);
    }
    
    // Parse the URL
    char *url = argv[1];
    char protocol[10], hostname[128], path[1024];
    int port = HTTP_PORT;
    
    if (sscanf(url, "%9[^:]://%127[^/]/%1023s", protocol, hostname, path) != 3) {
        printf("Invalid URL format. Must be in the format <Protocol>://<Hostname>/<Path>\n");
        exit(1);
    }
    
    // Determine if a custom port has been specified in the URL
    char *portPtr = strchr(hostname, ':');
    
    if (portPtr != NULL) {
        port = atoi(portPtr + 1);
        *portPtr = '\0';
    }
    
    // Print the parsed URL components
    printf("Protocol: %s\n", protocol);
    printf("Hostname: %s\n", hostname);
    printf("Port: %d\n", port);
    printf("Path: %s\n", path);
    
    // Resolve the hostname to an IP address
    struct hostent *hostInfo = gethostbyname(hostname);
    
    if (hostInfo == NULL) {
        printf("Could not resolve hostname: %s\n", hostname);
        exit(1);
    }
    
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (clientSocket < 0) {
        exitWithError("Could not create socket");
    }
    
    // Configure the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    memcpy(&serverAddress.sin_addr.s_addr, hostInfo->h_addr, hostInfo->h_length);
    
    // Connect to the server
    if (connect(clientSocket, (const struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        exitWithError("Could not connect to server");
    }
    
    // Construct the HTTP request
    char httpRequest[1024];
    snprintf(httpRequest, sizeof(httpRequest), "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    
    // Send the HTTP request
    if (send(clientSocket, httpRequest, strlen(httpRequest), 0) < 0) {
        exitWithError("Could not send HTTP request");
    }
    
    // Receive the HTTP response
    char httpRespBuffer[MAX_HTTP_RESPONSE_SIZE];
    int httpRespLength = recv(clientSocket, httpRespBuffer, sizeof(httpRespBuffer), 0);
    
    if (httpRespLength < 0) {
        exitWithError("Could not receive HTTP response");
    }
    
    // Parse the HTTP response
    char *httpRespHeaderEnd = strstr(httpRespBuffer, "\r\n\r\n");
    *httpRespHeaderEnd = '\0';
    
    printf("HTTP Response Headers:\n%s\n", httpRespBuffer);
    
    char *httpRespBody = httpRespHeaderEnd + 4;
    
    printf("HTTP Response Body:\n%s\n", httpRespBody);
    
    // Close the socket
    close(clientSocket);
    
    return 0;
}