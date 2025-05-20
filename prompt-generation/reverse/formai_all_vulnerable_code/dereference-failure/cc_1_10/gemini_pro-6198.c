//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

static const char *smtp_codes[] = {
	"220", "221", "250", "251", "354", "421", "450", "451", "452", "500", "501", "502", "503", "504", "535", "550", "551", "552", "553", "554",
};

#define SMTP_CODE_QUIT  "QUIT"
#define SMTP_CODE_EHLO  "EHLO ["
#define SMTP_CODE_MAIL  "MAIL FROM:<"
#define SMTP_CODE_RCPT  "RCPT TO:<"
#define SMTP_CODE_DATA  "DATA"
#define SMTP_CODE_END_DATA  ".\r\n"
#define SMTP_CODE_RSET  "RSET"

struct smtp_client {
	int sockfd;
	char *host;
	int port;
};

static int smtp_send(struct smtp_client *client, const char *msg)
{
	int ret;
	ret = send(client->sockfd, msg, strlen(msg), 0);
	if (ret < 0) {
		perror("send");
		return -1;
	}
	return ret;
}

static int smtp_recv(struct smtp_client *client, char *buf, size_t len)
{
	int ret;
	ret = recv(client->sockfd, buf, len - 1, 0);
	if (ret < 0) {
		perror("recv");
		return -1;
	}
	buf[ret] = '\0';
	return ret;
}

static int smtp_connect(struct smtp_client *client)
{
	struct sockaddr_in servaddr;

	client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (client->sockfd < 0) {
		perror("socket");
		return -1;
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(client->port);
	if (inet_pton(AF_INET, client->host, &servaddr.sin_addr) <= 0) {
		perror("inet_pton");
		return -1;
	}

	if (connect(client->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect");
		return -1;
	}

	return 0;
}

static int smtp_quit(struct smtp_client *client)
{
	if (smtp_send(client, SMTP_CODE_QUIT) < 0)
		return -1;
	return 0;
}

static int smtp_ehlo(struct smtp_client *client)
{
	char buf[256];

	if (smtp_send(client, SMTP_CODE_EHLO) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	return 0;
}

static int smtp_mail(struct smtp_client *client, const char *from)
{
	char buf[256];

	snprintf(buf, sizeof(buf), "%s %s\r\n", SMTP_CODE_MAIL, from);
	if (smtp_send(client, buf) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	return 0;
}

static int smtp_rcpt(struct smtp_client *client, const char *to)
{
	char buf[256];

	snprintf(buf, sizeof(buf), "%s %s\r\n", SMTP_CODE_RCPT, to);
	if (smtp_send(client, buf) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	return 0;
}

static int smtp_data(struct smtp_client *client, const char *msg)
{
	char buf[256];

	if (smtp_send(client, SMTP_CODE_DATA) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	if (smtp_send(client, msg) < 0)
		return -1;

	if (smtp_send(client, SMTP_CODE_END_DATA) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	return 0;
}

static int smtp_rset(struct smtp_client *client)
{
	char buf[256];

	if (smtp_send(client, SMTP_CODE_RSET) < 0)
		return -1;

	if (smtp_recv(client, buf, sizeof(buf)) < 0)
		return -1;

	return 0;
}

static void smtp_close(struct smtp_client *client)
{
	close(client->sockfd);
}

int main(int argc, char *argv[])
{
	struct smtp_client client;
	int ret;

	if (argc != 5) {
		fprintf(stderr, "Usage: %s <host> <port> <from> <to>\n", argv[0]);
		return -1;
	}

	client.host = argv[1];
	client.port = atoi(argv[2]);

	ret = smtp_connect(&client);
	if (ret < 0)
		return -1;

	ret = smtp_ehlo(&client);
	if (ret < 0)
		goto error;

	ret = smtp_mail(&client, argv[3]);
	if (ret < 0)
		goto error;

	ret = smtp_rcpt(&client, argv[4]);
	if (ret < 0)
		goto error;

	ret = smtp_data(&client, "Hello World!\n");
	if (ret < 0)
		goto error;

	ret = smtp_rset(&client);
	if (ret < 0)
		goto error;

	ret = smtp_quit(&client);
	if (ret < 0)
		goto error;

	smtp_close(&client);

	return 0;

error:
	smtp_close(&client);

	return -1;
}