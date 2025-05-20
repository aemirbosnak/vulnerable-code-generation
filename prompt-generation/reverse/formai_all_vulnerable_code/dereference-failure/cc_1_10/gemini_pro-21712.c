//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
	int listenfd, connfd, n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen;
	char buf[BUFSIZE];

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		return 1;
	}

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		perror("socket");
		return 1;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind");
		return 1;
	}

	if (listen(listenfd, 10) < 0) {
		perror("listen");
		return 1;
	}

	for (;;) {
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		if (connfd < 0) {
			perror("accept");
			continue;
		}

		while ((n = read(connfd, buf, BUFSIZE)) > 0) {
			if (write(connfd, buf, n) < 0) {
				perror("write");
				break;
			}
		}

		if (n < 0) {
			perror("read");
		}

		close(connfd);
	}

	return 0;
}