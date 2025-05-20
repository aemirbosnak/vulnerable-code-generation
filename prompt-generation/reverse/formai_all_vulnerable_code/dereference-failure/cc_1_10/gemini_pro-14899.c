//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BIT_SIZE (sizeof(int)*CHAR_BIT)

void bit_print(int num)
{
	int i;
	for (i = BIT_SIZE-1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
	}
}

int bit_scan(char *str)
{
	int num = 0;
	int i;

	for (i = 0; i < BIT_SIZE; i++) {
		if (str[i] == '1') {
			num |= (1 << (BIT_SIZE-1-i));
		}
	}

	return num;
}

int main(int argc, char **argv)
{
	char buf[BIT_SIZE+1];
	int num;
	int i;

	if (argc != 2) {
		printf("Usage: %s <binary string>\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (strlen(argv[1]) != BIT_SIZE) {
		printf("Error: binary string must be %d bits long\n", BIT_SIZE);
		return EXIT_FAILURE;
	}

	for (i = 0; i < BIT_SIZE; i++) {
		if (argv[1][i] != '0' && argv[1][i] != '1') {
			printf("Error: binary string must contain only 0s and 1s\n");
			return EXIT_FAILURE;
		}
	}

	num = bit_scan(argv[1]);

	printf("Original binary string: %s\n", argv[1]);
	printf("Converted integer: %d\n", num);

	printf("Bitwise representation: ");
	bit_print(num);
	printf("\n");

	return EXIT_SUCCESS;
}