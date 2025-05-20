//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE_LENGTH 1024
#define MAX_MESSAGE_LENGTH 10240

struct client_state {
	int sockfd;
	char *username;
	char *password;
	char *server;
	int port;
	int is_authenticated;
};

int connect_to_server(struct client_state *state) {
	struct sockaddr_in servaddr;

	// Create a socket
	state->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (state->sockfd == -1) {
		perror("socket");
		return -1;
	}

	// Resolve the server's address
	struct hostent *host = gethostbyname(state->server);
	if (host == NULL) {
		fprintf(stderr, "gethostbyname: %s\n", strerror(errno));
		return -1;
	}

	// Fill in the server's address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(state->port);
	memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

	// Connect to the server
	if (connect(state->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		perror("connect");
		return -1;
	}

	return 0;
}

int authenticate(struct client_state *state) {
	char buffer[MAX_LINE_LENGTH];

	// Send the username
	snprintf(buffer, sizeof(buffer), "USER %s\r\n", state->username);
	if (send(state->sockfd, buffer, strlen(buffer), 0) == -1) {
		perror("send");
		return -1;
	}

	// Receive the server's response
	if (recv(state->sockfd, buffer, sizeof(buffer), 0) == -1) {
		perror("recv");
		return -1;
	}

	// Check if the server accepted the username
	if (strncmp(buffer, "331", 3) != 0) {
		fprintf(stderr, "Server rejected the username: %s\n", buffer);
		return -1;
	}

	// Send the password
	snprintf(buffer, sizeof(buffer), "PASS %s\r\n", state->password);
	if (send(state->sockfd, buffer, strlen(buffer), 0) == -1) {
		perror("send");
		return -1;
	}

	// Receive the server's response
	if (recv(state->sockfd, buffer, sizeof(buffer), 0) == -1) {
		perror("recv");
		return -1;
	}

	// Check if the server accepted the password
	if (strncmp(buffer, "235", 3) != 0) {
		fprintf(stderr, "Server rejected the password: %s\n", buffer);
		return -1;
	}

	// Authentication successful
	state->is_authenticated = 1;

	return 0;
}

int send_message(struct client_state *state, char *message) {
	char buffer[MAX_LINE_LENGTH];

	// Send the message
	snprintf(buffer, sizeof(buffer), "DATA\r\n%s\r\n.\r\n", message);
	if (send(state->sockfd, buffer, strlen(buffer), 0) == -1) {
		perror("send");
		return -1;
	}

	// Receive the server's response
	if (recv(state->sockfd, buffer, sizeof(buffer), 0) == -1) {
		perror("recv");
		return -1;
	}

	// Check if the server accepted the message
	if (strncmp(buffer, "250", 3) != 0) {
		fprintf(stderr, "Server rejected the message: %s\n", buffer);
		return -1;
	}

	return 0;
}

int main(int argc, char **argv) {
	struct client_state state;

	// Parse the command-line arguments
	if (argc != 5) {
		fprintf(stderr, "Usage: %s username password server port\n", argv[0]);
		return 1;
	}
	state.username = argv[1];
	state.password = argv[2];
	state.server = argv[3];
	state.port = atoi(argv[4]);

	// Connect to the server
	if (connect_to_server(&state) == -1) {
		return 1;
	}

	// Authenticate with the server
	if (authenticate(&state) == -1) {
		return 1;
	}

	// Send a message to the server
	char message[MAX_MESSAGE_LENGTH];
	printf("Enter your message: ");
	fgets(message, sizeof(message), stdin);

	if (send_message(&state, message) == -1) {
		return 1;
	}

	// Close the connection to the server
	close(state.sockfd);

	return 0;
}