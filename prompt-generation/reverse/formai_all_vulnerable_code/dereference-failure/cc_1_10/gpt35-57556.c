//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
	struct hostent *server;
	struct sockaddr_in server_address;
	int socket_fd, status;
	char buffer[MAX_BUFFER];

	// Ensure server provided in command line arguments
	if (argc < 2) {
		fprintf(stderr, "Error: server address not provided.\n");
		exit(1);
	}

	// Get server information
	server = gethostbyname(argv[1]);

	// Create socket
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0) {
		perror("Error creating socket");
		exit(1);
	}

	// Build server address
	bzero((char*)&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
	server_address.sin_port = htons(25); // SMTP port

	// Connect to server
	if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
		perror("Error connecting to server");
		exit(1);
	}

	// Read server greeting
	bzero(buffer, MAX_BUFFER);
	status = read(socket_fd, buffer, MAX_BUFFER);
	if (status < 0) {
		perror("Error reading from server");
		exit(1);
	}
	printf("%s", buffer);

	// Send HELO command
	sprintf(buffer, "HELO %s\r\n", argv[1]);
	status = write(socket_fd, buffer, strlen(buffer));
	if (status < 0) {
		perror("Error writing to server");
		exit(1);
	}

	// Read server response
	bzero(buffer, MAX_BUFFER);
	status = read(socket_fd, buffer, MAX_BUFFER);
	if (status < 0) {
		perror("Error reading from server");
		exit(1);
	}
	printf("%s", buffer);

	// Send QUIT command
	sprintf(buffer, "QUIT\r\n");
	status = write(socket_fd, buffer, strlen(buffer));
	if (status < 0) {
		perror("Error writing to server");
		exit(1);
	}

	// Read server response
	bzero(buffer, MAX_BUFFER);
	status = read(socket_fd, buffer, MAX_BUFFER);
	if (status < 0) {
		perror("Error reading from server");
		exit(1);
	}
	printf("%s", buffer);

	// Close socket
	close(socket_fd);

	return 0;
}