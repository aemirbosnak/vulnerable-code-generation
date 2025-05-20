//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	
	// Declare variables
	int sockfd, n, port;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[BUFSIZE];

	// Check for correct arguments
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		exit(1);
	}

	// Get the port number
	port = atoi(argv[2]);

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(1);
	}
	
	// Get the server's IP address
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		fprintf(stderr, "Error: no such host\n");
		exit(1);
	}

	// Fill in the server's address
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
	serv_addr.sin_port = htons(port);

	// Connect to the server
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("connect");
		exit(1);
	}
	
	// Send a command to the server
	strcpy(buffer, "USER anonymous\r\n");
	n = write(sockfd, buffer, strlen(buffer));
	if (n < 0) {
		perror("write");
		exit(1);
	}

	// Receive a response from the server
	n = read(sockfd, buffer, BUFSIZE);
	if (n < 0) {
		perror("read");
		exit(1);
	}
	
	// Output the response from the server
	printf("%s", buffer);
	
	// Close the socket
	close(sockfd);

	return 0;
}