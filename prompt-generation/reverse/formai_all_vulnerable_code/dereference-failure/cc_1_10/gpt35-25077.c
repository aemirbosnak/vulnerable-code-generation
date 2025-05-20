//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>

#define PORT 8080   // Default Port number
#define MAX_DATA_SIZE 1024  // Maximum buffer size for data

void error(char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {
	int port, src_socket, dest_socket;
	char buffer[MAX_DATA_SIZE], request_buffer[MAX_DATA_SIZE];
	struct sockaddr_in src_addr, dest_addr;
	struct hostent *server;

	if(argc<2) {
		fprintf(stderr, "usage %s hostname\n", argv[0]);
		exit(1);
	}

	// Get the host server address
	server = gethostbyname(argv[1]);
	if(server==NULL) {
		fprintf(stderr, "Error, no such host\n");
		exit(1);
	}

	// Create source socket
	src_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(src_socket<0) error("Error opening socket");
	bzero((char*) &src_addr, sizeof(src_addr));
	port = PORT;

	src_addr.sin_family = AF_INET;
	src_addr.sin_addr.s_addr = INADDR_ANY;
	src_addr.sin_port = htons(port);

	if(bind(src_socket, (struct sockaddr*)&src_addr, sizeof(src_addr))<0)
		error("Binding error");

	listen(src_socket, 5);

	while(1) {
		int data_recv, request_recv;
		socklen_t sin_size;

		printf("Proxy server is waiting\n");
		dest_socket = accept(src_socket, (struct sockaddr*)&dest_addr, &sin_size);
		if(dest_socket<0) error("Accepting error");
		printf("Connection Established\n");

		// Initialise the buffers
		bzero(buffer, MAX_DATA_SIZE);
		bzero(request_buffer, MAX_DATA_SIZE);

		request_recv = recv(dest_socket, request_buffer, MAX_DATA_SIZE-1, 0);
		if(request_recv<0) error("Error receiving from browser");

		// Connect with the host server
		bzero(&dest_addr,sizeof(dest_addr));
		dest_addr.sin_family = AF_INET;
		dest_addr.sin_port = htons(80);
		dest_addr.sin_addr = *((struct in_addr *)server->h_addr);

		dest_socket = socket(AF_INET, SOCK_STREAM, 0);
		if(dest_socket<0) error("Error opening socket for destination");

		if(connect(dest_socket, (struct sockaddr *)&dest_addr, sizeof(dest_addr))<0)
			error("Error connecting");// Connect the socket with the server to be proxified

		// Send the request string to the server
		if(send(dest_socket, request_buffer, strlen(request_buffer), 0)<0)
			error("Sending error");

		// Receive the response from the server
		while((data_recv=recv(dest_socket, buffer, MAX_DATA_SIZE-1, 0))>0) {
			if(send(src_socket, buffer, data_recv, 0)<0)
				error("Sending error");
			bzero(buffer,MAX_DATA_SIZE);
		}

		close(dest_socket);
	}

	return 0;
}