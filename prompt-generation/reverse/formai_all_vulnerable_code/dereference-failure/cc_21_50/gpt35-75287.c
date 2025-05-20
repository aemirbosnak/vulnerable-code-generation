//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

// maximum number of pending connections in the queue
#define BACKLOG 10

// maximum length of HTTP request message
#define REQUEST_MAX_LEN 8192

/**
 * Main program that creates a simple HTTP proxy server and listens for incoming connections.
 */
int main(int argc, char **argv) {
  // the default port number to listen on is 8080
  int port = 8080; 

  // create the sockaddr_in struct for the proxy server
  struct sockaddr_in proxyServerAddr;
  memset(&proxyServerAddr, 0, sizeof(proxyServerAddr));
  proxyServerAddr.sin_family = AF_INET;
  proxyServerAddr.sin_port = htons(port);
  proxyServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); 

  // create a socket for the proxy server
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // bind the socket to the proxy server's address
  int bindResult = bind(serverSocket, (struct sockaddr *)&proxyServerAddr, sizeof(proxyServerAddr));
  if (bindResult < 0) {
    perror("Error binding socket to port");
    exit(1);
  }

  // listen for incoming connections
  int listenResult = listen(serverSocket, BACKLOG);
  if (listenResult < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  while (1) {
    // accept a new client connection
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
    if (clientSocket < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // receive the client's HTTP request message
    char request[REQUEST_MAX_LEN];
    memset(request, 0, REQUEST_MAX_LEN);
    int receivedBytes = recv(clientSocket, request, REQUEST_MAX_LEN, 0);
    if (receivedBytes < 0) {
      perror("Error receiving request from client");
      close(clientSocket);
      continue;
    }

    // parse the HTTP request message to obtain the requested host and port information
    char *host = NULL;
    char *portStr = NULL;
    char *path = NULL;

    char *ptr = strtok(request, " ");
    if (ptr != NULL && strcmp(ptr, "GET") == 0) {
      // extract path to resource being requested
      ptr = strtok(NULL, " ");
      if (ptr != NULL) {
        path = strdup(ptr);
      }
    }

    ptr = strtok(NULL, " ");
    if (ptr != NULL && strcmp(ptr, "HTTP/1.0\r\n") == 0) {
      // extract hostname and optional port number
      ptr = strtok(NULL, "\r\n");
      while (ptr != NULL) {
        if (strncmp(ptr, "Host: ", 6) == 0) {
          char *colonPtr = strchr(ptr, ':');
          if (colonPtr != NULL) {
            // port number specified in HTTP request
            host = strndup(ptr + 6, colonPtr - ptr - 6);
            portStr = strdup(colonPtr + 1);
          } else {
            // no port number specified in HTTP request
            host = strdup(ptr + 6);
            portStr = strdup("80");
          }
          break;
        }
        ptr = strtok(NULL, "\r\n");
      }
    }

    // connect to the requested host and port
    struct addrinfo hints, *serverInfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int getaddrinfoResult = getaddrinfo(host, portStr, &hints, &serverInfo);
    if (getaddrinfoResult != 0) {
      fprintf(stderr, "Could not get address information: %s\n", gai_strerror(getaddrinfoResult));
      free(host);
      free(portStr);
      free(path);
      close(clientSocket);
      continue;
    }

    int serverSocket = -1;
    char s[INET6_ADDRSTRLEN];
    struct addrinfo *serverAddr;
    for (serverAddr = serverInfo; serverAddr != NULL; serverAddr = serverAddr->ai_next) {
      serverSocket = socket(serverAddr->ai_family, serverAddr->ai_socktype, serverAddr->ai_protocol);
      if (serverSocket < 0) {
        perror("Error creating socket to server");
        continue;
      }

      inet_ntop(serverAddr->ai_family, &(((struct sockaddr_in *)serverAddr->ai_addr)->sin_addr), s, sizeof(s));
      printf("Connecting to %s:%s ...\n", s, portStr);

      int connectResult = connect(serverSocket, serverAddr->ai_addr, serverAddr->ai_addrlen);
      if (connectResult < 0) {
        perror("Error connecting to server");
        close(serverSocket);
        serverSocket = -1;
        continue;
      }

      // successfully connected to the server
      break;
    }
    freeaddrinfo(serverInfo);

    if (serverSocket < 0) {
      // could not connect to any server address
      fprintf(stderr, "Could not connect to any server address\n");
      free(host);
      free(portStr);
      free(path);
      close(clientSocket);
      continue;
    }

    // construct the HTTP request message to send to the server
    char requestToServer[REQUEST_MAX_LEN];
    snprintf(requestToServer, REQUEST_MAX_LEN, "GET %s HTTP/1.0\r\n"
                                                "Host: %s:%s\r\n"
                                                "\r\n", path, host, portStr);

    // send the HTTP request message to the server
    int sentBytes = send(serverSocket, requestToServer, strlen(requestToServer), 0);
    if (sentBytes < 0) {
      perror("Error sending request to server");
      free(host);
      free(portStr);
      free(path);
      close(serverSocket);
      close(clientSocket);
      continue;
    }

    // receive the server's response message
    char response[REQUEST_MAX_LEN];
    memset(response, 0, REQUEST_MAX_LEN);
    receivedBytes = recv(serverSocket, response, REQUEST_MAX_LEN, 0);
    if (receivedBytes < 0) {
      perror("Error receiving response from server");
      free(host);
      free(portStr);
      free(path);
      close(serverSocket);
      close(clientSocket);
      continue;
    }

    // send the server's response message to the client
    sentBytes = send(clientSocket, response, strlen(response), 0);
    if (sentBytes < 0) {
      perror("Error sending response to client");
    }

    // clean up allocated memory and close sockets
    free(host);
    free(portStr);
    free(path);
    close(serverSocket);
    close(clientSocket);
  }

  return 0;
}