//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

static int sockfd;

void handle_data(char *buf)
{
	printf("Received from server: %s\n", buf);
}

void handle_error(char *msg)
{
	perror(msg);
	close(sockfd);
	exit(EXIT_FAILURE);
}

void handle_request(void)
{
	ssize_t nbytes;
	char buf[BUFSIZ];

	nbytes = recv(sockfd, buf, sizeof(buf), 0);
	if (nbytes <= 0) {
		if (nbytes == -1)
			handle_error("recv");
		if (nbytes == 0)
			handle_error("connection closed");
	}
	handle_data(buf);
	handle_request();
}

void connect_to_server(char *host, char *port)
{
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if (getaddrinfo(host, port, &hints, &res) != 0)
		handle_error("getaddrinfo");

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sockfd == -1)
		handle_error("socket");

	if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0)
		handle_error("connect");

	freeaddrinfo(res);
}

void start_server(void)
{
	int fd;
	unsigned char buf[1024];

	fd = open("/proc/net/wireless", O_RDONLY);
	if (fd == -1)
		handle_error("open");

	while (1) {
		ssize_t nbytes;

		nbytes = read(fd, buf, sizeof(buf));
		if (nbytes <= 0) {
			if (nbytes == -1)
				handle_error("read");
			if (nbytes == 0)
				continue;
		}
		buf[nbytes] = '\0';
		send(sockfd, buf, nbytes, 0);
	}

	close(fd);
}

int main(int argc, char *argv[])
{
	char *host, *port;

	if (argc != 3)
		handle_error("usage: client host port");

	host = argv[1];
	port = argv[2];

	connect_to_server(host, port);
	start_server();
}