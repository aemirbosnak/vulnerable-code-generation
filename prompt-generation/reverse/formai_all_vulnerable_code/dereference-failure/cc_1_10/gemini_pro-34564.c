//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define CRYPTO_KEY (0xabcd)
#define CRYPTO_VEC (0x1234)
#define CRYPTO_BS  (16)

char *bootsector;
int bootsector_size;

int decrypt_bootsector(char *key, char *vec)
{
	char *iv = vec;
	long long *key_dec = (long long *)key;
	unsigned long long data_dec;
	char *data_enc = bootsector;
	for (;
		data_enc <= bootsector + bootsector_size - CRYPTO_BS;
		data_enc += CRYPTO_BS) {
		data_dec = *(unsigned long long *)data_enc;
		data_dec ^= *iv;
		data_dec ^= *key_dec;
		*iv = *(unsigned long long *)data_enc;
		*(unsigned long long *)data_enc = data_dec;
		key_dec++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: %s bootsector.bin\n", argv[0]);
		exit(1);
	}

	FILE *fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	bootsector_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	bootsector = malloc(bootsector_size);
	if (bootsector == NULL) {
		perror("malloc");
		exit(1);
	}
	if (fread(bootsector, bootsector_size, 1, fp) != 1) {
		perror("fread");
		exit(1);
	}
	fclose(fp);

	char key[CRYPTO_BS];
	char vec[CRYPTO_BS];
	memset(key, CRYPTO_KEY, CRYPTO_BS);
	memset(vec, CRYPTO_VEC, CRYPTO_BS);

	int err = decrypt_bootsector(key, vec);
	if (err) {
		fprintf(stderr, "decryption error: %s\n", strerror(err));
		exit(1);
	}

	// optimize bootsector

	fp = fopen("bootsector.opt", "wb");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}
	if (fwrite(bootsector, bootsector_size, 1, fp) != 1) {
		perror("fwrite");
		exit(1);
	}
	fclose(fp);

	free(bootsector);

	return 0;
}