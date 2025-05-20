//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>
#include <stddef.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>

#if defined(__linux__)
#include <sys/auxv.h>
#endif

#if defined(__FreeBSD__)
#include <sys/user.h>
#endif

#if defined(__OpenBSD__)
#include <sys/sysctl.h>
#endif

#if defined(__NetBSD__)
#include <sys/param.h>
#endif

#if defined(__SunOS__)
#include <sys/procfs.h>
#endif

typedef struct {
    const char *name;
    size_t size;
    char *data;
} metadata_entry_t;

static void *
mmap_file(const char *path, size_t *size)
{
    int fd;
    struct stat st;
    void *data;

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return NULL;
    }

    if (fstat(fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    data = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }

    close(fd);

    *size = st.st_size;

    return data;
}

static void
munmap_file(void *data, size_t size)
{
    munmap(data, size);
}

static metadata_entry_t *
get_metadata_entries(const char *path, size_t *count)
{
    size_t size;
    void *data;
    metadata_entry_t *entries;
    char *p;
    size_t i;

    data = mmap_file(path, &size);
    if (data == NULL) {
        return NULL;
    }

    entries = malloc(sizeof(*entries) * 100);
    if (entries == NULL) {
        munmap_file(data, size);
        return NULL;
    }

    *count = 0;

    p = data;
    while (p < data + size) {
        entries[*count].name = p;
        while (*p != '\n') {
            p++;
        }
        entries[*count].size = p - entries[*count].name;
        p++;
        entries[*count].data = p;
        while (*p != '\n') {
            p++;
        }
        p++;
        (*count)++;
    }

    munmap_file(data, size);

    return entries;
}

static void
free_metadata_entries(metadata_entry_t *entries, size_t count)
{
    free(entries);
}

static void
print_metadata_entry(const metadata_entry_t *entry)
{
    printf("%s: %s\n", entry->name, entry->data);
}

static void
print_metadata_entries(const metadata_entry_t *entries, size_t count)
{
    size_t i;

    for (i = 0; i < count; i++) {
        print_metadata_entry(&entries[i]);
    }
}

int
main(int argc, char **argv)
{
    const char *path;
    size_t count;
    metadata_entry_t *entries;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    path = argv[1];

    entries = get_metadata_entries(path, &count);
    if (entries == NULL) {
        return EXIT_FAILURE;
    }

    print_metadata_entries(entries, count);

    free_metadata_entries(entries, count);

    return EXIT_SUCCESS;
}