//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

static char *encode(char *buf, int len, int *outlen) {
	int i, j, k;
	char *out = malloc(len * 2 + 1);
	for (i = 0, j = 0, k = 0; i < len; i++) {
		if (i == 0 || buf[i] != buf[i - 1]) {
			k = 1;
			out[j++] = buf[i];
		}
		else if (k < 2 || buf[i] != buf[i + 1]) {
			out[j++] = buf[i];
			k++;
		}
		else {
			out[j++] = buf[i];
			k++;
		}
	}
	*outlen = j;
	return out;
}

static char *decode(char *buf, int len, int *outlen) {
	int i, j, k;
	char *out = malloc(len * 2 + 1);
	for (i = 0, j = 0, k = 0; i < len; i++) {
		if (i == 0 || buf[i] != buf[i - 1]) {
			k = 1;
			out[j++] = buf[i];
		}
		else if (k < 2 || buf[i] != buf[i + 1]) {
			out[j++] = buf[i];
			k++;
		}
		else {
			while (buf[i + 1] == buf[i] && i < len) i++;
			k = i - j + 1;
			while (k--) out[j++] = buf[i];
		}
	}
	*outlen = j;
	return out;
}

int main(void) {
	char *buf = "aabcccccaaa";
	int len, outlen;
	char *out = encode(buf, strlen(buf), &outlen);
	printf("%s\n", out);
	free(out);
	out = decode(buf, strlen(buf), &outlen);
	printf("%s\n", out);
	free(out);
	return 0;
}