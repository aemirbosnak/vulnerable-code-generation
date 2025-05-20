//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define HASH_TABLE_SIZE 10000
#define HASH_TABLE_MASK (HASH_TABLE_SIZE - 1)

typedef struct hash_entry {
    unsigned char signature[32];
    unsigned int hash;
    struct hash_entry *next;
} hash_entry;

hash_entry *hash_table[HASH_TABLE_SIZE];

unsigned int calculate_adler32(unsigned char *buffer, size_t size) {
    unsigned long s1, s2, i;

    s1 = 1;
    s2 = 1;

    for (i = 0; i < size; i++) {
        s1 = (s1 + buffer[i]) % 65521;
        s2 = (s2 + s1) % 65521;
    }

    return (unsigned int)(s2 << 16 | s1);
}

void add_signature(unsigned char *signature, unsigned int hash) {
    unsigned int index = hash % HASH_TABLE_SIZE;
    hash_entry *entry = mmap(NULL, sizeof(hash_entry), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);

    entry->signature[0] = '\0';
    strncpy((char *)entry->signature, (char *)signature, 32);
    entry->hash = hash;
    entry->next = hash_table[index];
    hash_table[index] = entry;
    munmap(entry, sizeof(hash_entry));
}

int scan_file(char *path) {
    int fd, ret = 1;
    struct stat st;
    unsigned char *buffer;
    unsigned int file_size, file_hash;

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return ret;
    }

    fstat(fd, &st);
    file_size = st.st_size;
    buffer = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);

    file_hash = calculate_adler32(buffer, file_size);

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_entry *entry = hash_table[i];

        while (entry != NULL) {
            if (entry->hash == file_hash) {
                printf("%s: Malware detected - %s\n", path, entry->signature);
                ret = 0;
                break;
            }
            entry = entry->next;
        }
    }

    munmap(buffer, file_size);
    close(fd);

    return ret;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path to file>\n", argv[0]);
        return 1;
    }

    unsigned char *signature = "Danger:Win32/Conficker";
    unsigned int signature_hash = calculate_adler32(signature, 17);
    add_signature(signature, signature_hash);

    int ret = scan_file(argv[1]);

    return ret;
}