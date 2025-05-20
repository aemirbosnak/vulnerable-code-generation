//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	uint8_t *data;
	size_t size;
} buffer;

buffer *load_file(const char *filename) {
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
		perror("fopen");
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer *buf = malloc(sizeof(buffer));
	if (buf == NULL) {
		perror("malloc");
		fclose(file);
		return NULL;
	}

	buf->data = malloc(size);
	if (buf->data == NULL) {
		perror("malloc");
		free(buf);
		fclose(file);
		return NULL;
	}

	size_t nread = fread(buf->data, 1, size, file);
	if (nread < size) {
		perror("fread");
		free(buf->data);
		free(buf);
		fclose(file);
		return NULL;
	}

	buf->size = size;
	fclose(file);
	return buf;
}

void hide_message(buffer *buf, const char *message) {
	size_t message_len = strlen(message);
	if (message_len > buf->size) {
		printf("Message too long.\n");
		return;
	}

	for (size_t i = 0; i < message_len; i++) {
		for (size_t j = 0; j < 8; j++) {
			if ((message[i] >> j) & 1) {
				buf->data[i * 8 + j] |= 1;
			} else {
				buf->data[i * 8 + j] &= ~1;
			}
		}
	}
}

void extract_message(buffer *buf) {
	char *message = malloc(buf->size / 8 + 1);
	if (message == NULL) {
		perror("malloc");
		return;
	}

	for (size_t i = 0; i < buf->size / 8; i++) {
		uint8_t byte = 0;
		for (size_t j = 0; j < 8; j++) {
			if (buf->data[i * 8 + j] & 1) {
				byte |= (1 << j);
			}
		}
		message[i] = byte;
	}
	message[buf->size / 8] = '\0';

	printf("Extracted message: %s\n", message);
	free(message);
}

void save_file(const char *filename, buffer *buf) {
	FILE *file = fopen(filename, "wb");
	if (file == NULL) {
		perror("fopen");
		return;
	}

	size_t nwritten = fwrite(buf->data, 1, buf->size, file);
	if (nwritten < buf->size) {
		perror("fwrite");
		fclose(file);
		return;
	}

	fclose(file);
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Usage: %s <input_image> <message> <output_image>\n", argv[0]);
		return 1;
	}

	buffer *buf = load_file(argv[1]);
	if (buf == NULL) {
		printf("Could not load input image.\n");
		return 1;
	}

	hide_message(buf, argv[2]);
	save_file(argv[3], buf);
	free(buf->data);
	free(buf);

	printf("Message hidden successfully.\n");
	return 0;
}