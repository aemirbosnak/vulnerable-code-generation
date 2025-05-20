//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define DEFAULT_PORT 8080
#define MAX_CONNECTIONS 5

int main(int argc, char *argv[]) {
	// Check for valid arguments
	if (argc != 2) {
		printf("USAGE: %s <IP Address>", argv[0]);
		exit(1);
	}

	// Create socket
	int sock_fd;
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	// Set the QoS parameters for the socket
	int val = 1;
	if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) { 
		perror("ERROR setting socket options"); 
		exit(1); 
	}

	// Set up address structure
	struct sockaddr_in server_address;
	bzero((char *) &server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(DEFAULT_PORT);
	inet_aton(argv[1], &server_address.sin_addr);

	// Connect to server
	if(connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
		perror("ERROR connecting to server");
		exit(1);
	}

	// Create buffer
	char buffer[BUFFER_SIZE];
	bzero(buffer, BUFFER_SIZE);

	// Send request to server
	sprintf(buffer, "GET / HTTP/1.1\r\n\r\n");
	if(write(sock_fd, buffer, strlen(buffer)) < 0) {
		perror("ERROR writing to socket");
		exit(1);
	}

	// Read response from server
	ssize_t n;
	bzero(buffer, BUFFER_SIZE);
	n = read(sock_fd, buffer, BUFFER_SIZE);
	if (n < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}

	// Print response from server
	printf("%s", buffer);

	// Close socket
	close(sock_fd);

	return 0;
}