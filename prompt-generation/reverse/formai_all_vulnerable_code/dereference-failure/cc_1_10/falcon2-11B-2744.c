//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024

void* read_file(const char* filename, size_t* len) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return NULL;
    }

    *len = st.st_size;
    void* buffer = mmap(NULL, *len, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }

    return buffer;
}

void* extract_metadata(const char* filename, size_t* len) {
    void* buffer = read_file(filename, len);
    if (!buffer) {
        return NULL;
    }

    char* line = (char*)buffer;
    while (line < buffer + *len) {
        char* end = strchr(line, '\n');
        if (end) {
            *end = '\0';
            printf("%s", line);
            line = end + 1;
        } else {
            break;
        }
    }

    munmap(buffer, *len);
    return NULL;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    size_t len;
    void* buffer = extract_metadata(filename, &len);
    if (!buffer) {
        return 1;
    }

    printf("Metadata:\n");
    fflush(stdout);

    fclose(stdout);
    fclose(stdin);
    return 0;
}