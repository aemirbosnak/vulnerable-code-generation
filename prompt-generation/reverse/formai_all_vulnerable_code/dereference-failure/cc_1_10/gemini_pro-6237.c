//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"
#define COLOR_BLACK "\x1b[30m"
#define COLOR_RESET "\x1b[0m"

typedef struct {
	int socket;
	struct sockaddr_in addr;
} client_t;

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <host>\n", argv[0]);
		return EXIT_FAILURE;
	}

	client_t client;

	client.socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client.socket == -1) {
		perror("socket");
		return EXIT_FAILURE;
	}

	client.addr.sin_family = AF_INET;
	client.addr.sin_port = htons(atoi(argv[1]));
	client.addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(client.socket, (struct sockaddr *)&client.addr, sizeof(client.addr)) == -1) {
		perror("connect");
		return EXIT_FAILURE;
	}

	char buffer[1024];
	int n;

	while ((n = read(client.socket, buffer, sizeof(buffer))) > 0) {
		buffer[n] = '\0';

		if (strcmp(buffer, "ping") == 0) {
			printf(COLOR_GREEN "pong\n" COLOR_RESET);
		} else if (strcmp(buffer, "pong") == 0) {
			printf(COLOR_RED "ping\n" COLOR_RESET);
		} else {
			printf(COLOR_YELLOW "%s\n" COLOR_RESET, buffer);
		}
	}

	if (n == -1) {
		perror("read");
		return EXIT_FAILURE;
	}

	close(client.socket);

	return EXIT_SUCCESS;
}