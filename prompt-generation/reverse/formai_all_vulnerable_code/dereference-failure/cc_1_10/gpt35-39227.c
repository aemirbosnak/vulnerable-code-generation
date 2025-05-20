//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER 1024

void error(char *msg) {
	perror(msg);
	exit(1);
}

int main() {
	int sock;
	struct sockaddr_in server;
	char buffer[MAX_BUFFER];
	char email[MAX_BUFFER];
	char password[MAX_BUFFER];
	char command[MAX_BUFFER];
	char response[MAX_BUFFER];
	char *server_response;
	int len;

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error("Could not create socket");

	// Initialize server struct
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(143);

	// Connect to server
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
		error("Could not connect to server");

	// Read welcome message
	bzero(buffer, sizeof(buffer));
	if (recv(sock, buffer, sizeof(buffer), 0) < 0)
		error("Could not read server response");

	// Enter login credentials
	printf("Enter your email address: ");
	fgets(email, MAX_BUFFER, stdin);
	email[strcspn(email, "\n")] = 0; // Remove newline character

	printf("Enter your password: ");
	fgets(password, MAX_BUFFER, stdin);
	password[strcspn(password, "\n")] = 0; // Remove newline character

	// Authenticate with server
	snprintf(command, sizeof(command), ". login %s %s\r\n", email, password);
	if (send(sock, command, strlen(command), 0) < 0)
		error("Could not send login command");

	bzero(response, sizeof(response));
	if (recv(sock, response, sizeof(response), 0) < 0)
		error("Could not read server response");

	// Check if login was successful
	server_response = strtok(response, " ");
	if (strcmp(server_response, "OK") != 0)
		error("Could not login to server");

	// List all email messages
	snprintf(command, sizeof(command), ". list \"\" \"*\"\r\n");
	if (send(sock, command, strlen(command), 0) < 0)
		error("Could not send list command");

	bzero(response, sizeof(response));
	if (recv(sock, response, sizeof(response), 0) < 0)
		error("Could not read server response");

	// Print email messages
	server_response = strtok(response, " ");
	while (server_response != NULL) {
		// Ignore response code and select mailbox name
		if (atoi(server_response) == 0) {
			server_response = strtok(NULL, " ");
			printf("%s\n", server_response);
		}

		server_response = strtok(NULL, " ");
	}

	// Close socket
	close(sock);

	return 0;
}