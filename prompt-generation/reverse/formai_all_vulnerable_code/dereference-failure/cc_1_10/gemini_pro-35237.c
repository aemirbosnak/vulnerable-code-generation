//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static char *enc_key = "0123456789ABCDEF";
static char *dec_key = NULL;

static int enc_decrypt(char *buf, int sz, int mode)
{
	int i;
	char *p;

	if (mode) {
		p = dec_key;
		for (i = 0; i < sz; i++) {
			buf[i] = p[buf[i]];
		}
	} else {
		p = enc_key;
		for (i = 0; i < sz; i++) {
			buf[i] = p[buf[i]];
		}
	}
	return 0;
}

static int dec_image(char *fn)
{
	int fd;
	char buf[1024];

	if ((fd = open(fn, O_RDWR)) < 0)
		return -1;

	while (read(fd, buf, 1024) > 0) {
		enc_decrypt(buf, 1024, 1);
		if (write(fd, buf, 1024) < 0)
			break;
	}
	close(fd);
	return 0;
}

int main(int argc, char **argv)
{
	int i;

	dec_key = malloc(strlen(enc_key));
	if (!dec_key)
		return -1;

	for (i = 0; i < strlen(enc_key); i++) {
		dec_key[enc_key[i]] = i;
	}

	for (i = 1; i < argc; i++) {
		if (dec_image(argv[i]) < 0) {
			perror("dec_image");
			return -1;
		}
	}

	free(dec_key);
	return 0;
}