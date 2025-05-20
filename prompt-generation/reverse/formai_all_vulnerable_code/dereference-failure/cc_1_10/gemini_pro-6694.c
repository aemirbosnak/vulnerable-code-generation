//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PI 3.14159265
#define SIZE 256

int main() {
	// Open the image file
	int fd = open("image.jpg", O_RDONLY);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	// Get the file size
	struct stat st;
	if (fstat(fd, &st) == -1) {
		perror("fstat");
		return 1;
	}

	// Read the image data
	unsigned char *data = malloc(st.st_size);
	if (data == NULL) {
		perror("malloc");
		return 1;
	}

	if (read(fd, data, st.st_size) != st.st_size) {
		perror("read");
		return 1;
	}

	// Close the image file
	close(fd);

	// Embed the watermark
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			// Get the pixel value
			unsigned char pixel = data[i * SIZE + j];

			// Calculate the new pixel value
			unsigned char new_pixel = pixel + (unsigned char)(128 * sin(2 * PI * i / SIZE) * cos(2 * PI * j / SIZE));

			// Set the new pixel value
			data[i * SIZE + j] = new_pixel;
		}
	}

	// Open the watermarked image file
	fd = open("image_watermarked.jpg", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	// Write the watermarked image data
	if (write(fd, data, st.st_size) != st.st_size) {
		perror("write");
		return 1;
	}

	// Close the watermarked image file
	close(fd);

	// Free the memory
	free(data);

	return 0;
}