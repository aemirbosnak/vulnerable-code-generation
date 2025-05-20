//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 65536
#define BUFFER_SIZE 4096

unsigned char *dictionary[MAX_DICT_SIZE];
int dict_size = 0;

int find_match(unsigned char buffer[], int start, int end) {
    int i, match_len = 0;
    for (i = 0; i < dict_size; i++) {
        int len = 0;
        while (buffer[start + len] == dictionary[i][len] && start + len < end) {
            len++;
            if (len > match_len && len == dict_size) {
                match_len = len;
                memcpy(dictionary[dict_size], &buffer[start], len);
                dict_size++;
                if (dict_size >= MAX_DICT_SIZE) {
                    dict_size = 0;
                }
                break;
            }
        }
    }
    return match_len;
}

int compress(unsigned char buffer[], int buffer_size, unsigned char compressed[]) {
    int i = 0, j = 0, pos = 0;
    while (i < buffer_size) {
        int end = i + BUFFER_SIZE - 1;
        if (end >= buffer_size) {
            end = buffer_size - 1;
        }
        int match_len = find_match(buffer, i, end);
        if (match_len > 0) {
            int offset = MAX_DICT_SIZE - dict_size;
            compressed[pos++] = (unsigned char)(offset >> 8);
            compressed[pos++] = (unsigned char)(offset & 0xFF);
            compressed[pos++] = (unsigned char)match_len;
            i += match_len;
            j = 0;
        } else {
            dictionary[dict_size][j++] = buffer[i++];
            if (j == MAX_DICT_SIZE) {
                j = 0;
            }
            compressed[pos++] = dictionary[dict_size - 1][0];
        }
        if (dict_size == 0) {
            dict_size = MAX_DICT_SIZE;
        }
    }
    return pos;
}

int decompress(unsigned char compressed[], int compressed_size, unsigned char buffer[]) {
    int i = 0, j = 0, pos = 0;
    while (i < compressed_size) {
        int offset = (compressed[i] << 8) | compressed[i + 1];
        int match_len = compressed[i + 2];
        i += 3;
        if (offset == 0) {
            dictionary[dict_size][j++] = compressed[i - 1];
            if (j == MAX_DICT_SIZE) {
                j = 0;
            }
            buffer[pos++] = compressed[i - 1];
        } else {
            int start = dict_size - offset;
            for (int k = 0; k < match_len; k++) {
                dictionary[dict_size][j++] = dictionary[start][k];
                if (j == MAX_DICT_SIZE) {
                    j = 0;
                }
                buffer[pos++] = dictionary[start][k];
            }
        }
        if (dict_size == 0) {
            dict_size = MAX_DICT_SIZE;
        }
    }
    return pos;
}

int main() {
    unsigned char buffer[] = "This is a test string to see if the compression algorithm works. If it works, the compressed data should be smaller than the original data.";
    unsigned char compressed[1024], decompressed[1024];
    int compressed_size = compress(buffer, sizeof(buffer), compressed);
    printf("Compressed size = %d\n", compressed_size);
    int decompressed_size = decompress(compressed, compressed_size, decompressed);
    printf("Decompressed size = %d\n", decompressed_size);
    printf("Decompressed data:\n");
    printf("%s\n", decompressed);
    return 0;
}