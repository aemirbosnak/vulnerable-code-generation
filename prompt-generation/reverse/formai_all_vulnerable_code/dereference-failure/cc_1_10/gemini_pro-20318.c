//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>

struct boot_info {
	uint64_t rsvd_size;
	uint64_t kernel_start;
	uint64_t kernel_size;
	uint64_t initrd_start;
	uint64_t initrd_size;
	uint64_t cmdline_addr;
	uint64_t cmdline_size;
};

int main(int argc, char **argv) {
	int fd;
	struct boot_info *bi;
	char *buf;
	struct stat st;
	int ret;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <boot.img>\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("open");
		return 1;
	}

	ret = fstat(fd, &st);
	if (ret < 0) {
		perror("fstat");
		close(fd);
		return 1;
	}

	buf = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (buf == MAP_FAILED) {
		perror("mmap");
		close(fd);
		return 1;
	}

	bi = (struct boot_info *)buf;

	printf("Image size: %lld\n", st.st_size);
	printf("Reserved size: %lld\n", bi->rsvd_size);
	printf("Kernel start: %lld\n", bi->kernel_start);
	printf("Kernel size: %lld\n", bi->kernel_size);
	printf("Initrd start: %lld\n", bi->initrd_start);
	printf("Initrd size: %lld\n", bi->initrd_size);
	printf("Cmdline addr: %lld\n", bi->cmdline_addr);
	printf("Cmdline size: %lld\n", bi->cmdline_size);

	// Optimize boot time
	bi->rsvd_size = 0;
	bi->kernel_start = 0;
	bi->initrd_start = 0;
	bi->cmdline_addr = 0;

	ret = msync(buf, st.st_size, MS_SYNC);
	if (ret < 0) {
		perror("msync");
		munmap(buf, st.st_size);
		close(fd);
		return 1;
	}

	munmap(buf, st.st_size);
	close(fd);

	printf("Boot image optimized.\n");

	return 0;
}