//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        return 1;
    }

    char* device = argv[1];
    int fd = open(device, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        return 1;
    }

    if (!S_ISBLK(st.st_mode)) {
        printf("Error: %s is not a block device\n", device);
        return 1;
    }

    unsigned char* buf = malloc(st.st_size);
    if (buf == NULL) {
        perror("malloc");
        return 1;
    }

    if (read(fd, buf, st.st_size) < 0) {
        perror("read");
        return 1;
    }

    close(fd);

    // Scan the buffer for deleted files
    unsigned char* ptr = buf;
    while (ptr < buf + st.st_size) {
        // Check if the file is deleted
        if (*ptr == 0xE5) {
            // Calculate the file size
            int size = *(ptr + 1);
            if (size < 0) {
                size = -size;
            }

            // Print the file name
            printf("%s\n", ptr + 2);

            // Skip to the next file
            ptr += size + 2;
        } else {
            // Skip to the next sector
            ptr += 512;
        }
    }

    free(buf);

    return 0;
}