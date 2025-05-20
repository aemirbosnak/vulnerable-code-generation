//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define STDIN		0
#define MAXLINE		1024

static int Socket, Port;
static char Hostname[MAXLINE];
static char User[MAXLINE];
static char Pass[MAXLINE];
static char *Hello, *Quit;

static void
recvline(int fd, char *line, int size)
{
	while (size > 0) {
		ssize_t nr = read(fd, line, size);
		if (nr < 0) {
			fprintf(stderr, "recvline: %s\n", strerror(errno));
			return;
		} else if (nr == 0)
			break;
		size -= nr;
		line += nr;
	}
	*line = '\0';
}

static void
sendline(int fd, char *line)
{
	char crlf[] = "\r\n";
	ssize_t nw = write(fd, line, strlen(line));
	if (nw < 0) {
		fprintf(stderr, "sendline: %s\n", strerror(errno));
		return;
	}
	nw = write(fd, crlf, 2);
	if (nw < 0) {
		fprintf(stderr, "sendline: %s\n", strerror(errno));
		return;
	}
}

static void
recvresp(int fd, char *line, size_t size)
{
	recvline(fd, line, size);
	if (line[3] != ' ') {
		fprintf(stderr, "recvresp: invalid response '%s'\n", line);
		return;
	}
}

static void
usage(void)
{
	fprintf(stderr, "usage: pop hostname port user pass\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	struct hostent *he;
	struct sockaddr_in sin;
	char line[MAXLINE];
	int i;

	if (argc != 6)
		usage();

	strncpy(Hostname, argv[1], MAXLINE - 1);
	Port = atoi(argv[2]);
	strncpy(User, argv[3], MAXLINE - 1);
	strncpy(Pass, argv[4], MAXLINE - 1);

	Hello = malloc(strlen("HELO ") + strlen(Hostname) + 3);
	if (!Hello) {
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		return 1;
	}
	sprintf(Hello, "HELO %s\r\n", Hostname);

	Quit = malloc(strlen("QUIT\r\n") + 1);
	if (!Quit) {
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		free(Hello);
		return 1;
	}
	strcpy(Quit, "QUIT\r\n");

	he = gethostbyname(Hostname);
	if (!he) {
		fprintf(stderr, "gethostbyname: %s\n", strerror(errno));
		free(Hello);
		free(Quit);
		return 1;
	}

	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket < 0) {
		fprintf(stderr, "socket: %s\n", strerror(errno));
		free(Hello);
		free(Quit);
		return 1;
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = he->h_addr_list[0];
	sin.sin_port = htons(Port);

	if (connect(Socket, (struct sockaddr *)&sin, sizeof sin) < 0) {
		fprintf(stderr, "connect: %s\n", strerror(errno));
		free(Hello);
		free(Quit);
		close(Socket);
		return 1;
	}

	recvresp(Socket, line, sizeof line);
	sendline(Socket, Hello);
	recvresp(Socket, line, sizeof line);
	sendline(Socket, sprintf(line, "USER %s\r\n", User));
	recvresp(Socket, line, sizeof line);
	sendline(Socket, sprintf(line, "PASS %s\r\n", Pass));
	recvresp(Socket, line, sizeof line);
	sendline(Socket, "LIST\r\n");
	recvline(Socket, line, sizeof line);
	if (!strncmp(line, "-ERR", 4)) {
		fprintf(stderr, "LIST command failed: %s\n", line);
	} else {
		printf("Messages:\n");
		for (i = 1; ; i++) {
			recvline(Socket, line, sizeof line);
			if (!strcmp(line, ".")) {
				recvline(Socket, line, sizeof line);
				break;
			}
			printf("\t%d\t%s\n", i, line);
		}
	}
	sendline(Socket, Quit);
	free(Hello);
	free(Quit);
	close(Socket);
	return 0;
}