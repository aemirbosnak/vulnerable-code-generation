//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

struct imap_client {
	int sock;
	char *host;
	int port;
	char *username;
	char *password;
	char *mailbox;
};

struct imap_client *imap_client_new(char *host, int port, char *username, char *password, char *mailbox) {
	struct imap_client *client = malloc(sizeof(struct imap_client));
	if (client == NULL) {
		return NULL;
	}

	client->sock = -1;
	client->host = strdup(host);
	client->port = port;
	client->username = strdup(username);
	client->password = strdup(password);
	client->mailbox = strdup(mailbox);

	return client;
}

void imap_client_free(struct imap_client *client) {
	if (client->sock != -1) {
		close(client->sock);
	}
	free(client->host);
	free(client->username);
	free(client->password);
	free(client->mailbox);
	free(client);
}

int imap_client_connect(struct imap_client *client) {
	struct sockaddr_in addr;

	client->sock = socket(AF_INET, SOCK_STREAM, 0);
	if (client->sock == -1) {
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(client->port);
	addr.sin_addr.s_addr = inet_addr(client->host);

	if (connect(client->sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		return -1;
	}

	return 0;
}

int imap_client_login(struct imap_client *client) {
	char buffer[1024];

	// Send the LOGIN command
	snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", client->username, client->password);
	if (send(client->sock, buffer, strlen(buffer), 0) == -1) {
		return -1;
	}

	// Receive the response
	if (recv(client->sock, buffer, sizeof(buffer), 0) == -1) {
		return -1;
	}

	// Check the response
	if (strncmp(buffer, "+OK", 3) != 0) {
		return -1;
	}

	return 0;
}

int imap_client_select_mailbox(struct imap_client *client) {
	char buffer[1024];

	// Send the SELECT command
	snprintf(buffer, sizeof(buffer), "SELECT %s\r\n", client->mailbox);
	if (send(client->sock, buffer, strlen(buffer), 0) == -1) {
		return -1;
	}

	// Receive the response
	if (recv(client->sock, buffer, sizeof(buffer), 0) == -1) {
		return -1;
	}

	// Check the response
	if (strncmp(buffer, "+OK", 3) != 0) {
		return -1;
	}

	return 0;
}

int imap_client_fetch_message(struct imap_client *client, int message_number) {
	char buffer[1024];

	// Send the FETCH command
	snprintf(buffer, sizeof(buffer), "FETCH %d BODY[TEXT]\r\n", message_number);
	if (send(client->sock, buffer, strlen(buffer), 0) == -1) {
		return -1;
	}

	// Receive the response
	if (recv(client->sock, buffer, sizeof(buffer), 0) == -1) {
		return -1;
	}

	// Check the response
	if (strncmp(buffer, "+OK", 3) != 0) {
		return -1;
	}

	// Print the message
	printf("%s", buffer);

	return 0;
}

int main(int argc, char **argv) {
	struct imap_client *client;
	int message_number;

	if (argc != 6) {
		fprintf(stderr, "Usage: %s host port username password mailbox\n", argv[0]);
		return 1;
	}

	client = imap_client_new(argv[1], atoi(argv[2]), argv[3], argv[4], argv[5]);
	if (client == NULL) {
		fprintf(stderr, "Error: imap_client_new() failed\n");
		return 1;
	}

	if (imap_client_connect(client) == -1) {
		fprintf(stderr, "Error: imap_client_connect() failed\n");
		imap_client_free(client);
		return 1;
	}

	if (imap_client_login(client) == -1) {
		fprintf(stderr, "Error: imap_client_login() failed\n");
		imap_client_free(client);
		return 1;
	}

	if (imap_client_select_mailbox(client) == -1) {
		fprintf(stderr, "Error: imap_client_select_mailbox() failed\n");
		imap_client_free(client);
		return 1;
	}

	printf("Enter the message number: ");
	scanf("%d", &message_number);

	if (imap_client_fetch_message(client, message_number) == -1) {
		fprintf(stderr, "Error: imap_client_fetch_message() failed\n");
		imap_client_free(client);
		return 1;
	}

	imap_client_free(client);

	return 0;
}