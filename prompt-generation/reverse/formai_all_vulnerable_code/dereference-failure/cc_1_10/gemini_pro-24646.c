//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		return EXIT_FAILURE;
	}

	const char *hostname = argv[1];
	int port = atoi(argv[2]);

	struct hostent *host = gethostbyname(hostname);
	if (host == NULL) {
		fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
		return EXIT_FAILURE;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	memcpy(&addr.sin_addr, host->h_addr, host->h_length);
	addr.sin_port = htons(port);

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return EXIT_FAILURE;
	}

	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("connect");
		return EXIT_FAILURE;
	}

	char buffer[4096];
	int len = recv(sock, buffer, sizeof(buffer), 0);
	if (len == -1) {
		perror("recv");
		return EXIT_FAILURE;
	}

	printf("%s", buffer);

	close(sock);

	return EXIT_SUCCESS;
}