//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h>

#define MAX_THREADS  4
#define BLOCK_SIZE   64
#define HASH_SIZE    32

typedef struct {
    uint8_t *data;
    uint32_t length;
} message_t;

typedef struct {
    pthread_t thread;
    uint8_t  *data;
    uint32_t length;
    uint8_t  hash[HASH_SIZE];
} job_t;

job_t job_queue[MAX_THREADS];
pthread_mutex_t queue_mutex;
uint32_t job_count;

void sha256(const uint8_t *data, uint32_t length, uint8_t *hash);
void sha256_block(const uint8_t *block, uint32_t *hash_values);
void sha256_transform(const uint8_t *block, uint32_t *hash_values);

void *worker_thread(void *param) {
    job_t *job;
    uint8_t hash[HASH_SIZE];

    while (1) {
        pthread_mutex_lock(&queue_mutex);

        while (job_count == 0) {
            pthread_mutex_unlock(&queue_mutex);
            sleep(1);
            pthread_mutex_lock(&queue_mutex);
        }

        job = &job_queue[--job_count];
        memcpy(hash, job->hash, HASH_SIZE);
        pthread_mutex_unlock(&queue_mutex);

        sha256(job->data, job->length, hash);

        printf("Thread #%lu: Hash = ", pthread_self());
        for (int i = 0; i < HASH_SIZE; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");

        free(job->data);
    }

    return NULL;
}

void add_job(uint8_t *data, uint32_t length) {
    pthread_mutex_lock(&queue_mutex);

    if (job_count >= MAX_THREADS) {
        printf("ERROR: Job queue full.\n");
        exit(EXIT_FAILURE);
    }

    job_t *job = &job_queue[job_count++];

    job->data = data;
    job->length = length;

    pthread_mutex_unlock(&queue_mutex);
}

int main() {
    pthread_t threads[MAX_THREADS];
    message_t messages[] = {
        (message_t) {.data = "Hello world", .length = 11},
        (message_t) {.data = "Lorem ipsum dolor sit amet", .length = 26},
        (message_t) {.data = "1234567890abcdefghijklmnopqrstuvwxyz", .length = 36},
        (message_t) {.data = "The quick brown fox jumps over the lazy dog", .length = 43},
        (message_t) {.data = "A", .length = 1},
        (message_t) {.data = "AB", .length = 2},
        (message_t) {.data = "ABCDE", .length = 5},
        (message_t) {.data = "ABCDEFGHIJKLMNOPQRSTUVWX", .length = 24},
    };

    pthread_mutex_init(&queue_mutex, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker_thread, NULL);
    }

    for (int i = 0; i < sizeof(messages) / sizeof(message_t); i++) {
        uint8_t *data = (uint8_t *) malloc(messages[i].length + 1);

        memcpy(data, messages[i].data, messages[i].length);
        data[messages[i].length] = '\0';

        add_job(data, messages[i].length);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&queue_mutex);

    return 0;
}

void sha256(const uint8_t *data, uint32_t length, uint8_t *hash) {
    uint32_t hash_values[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint32_t block[BLOCK_SIZE / 4];
    uint32_t num_blocks = (length + 9 + BLOCK_SIZE - 1) / BLOCK_SIZE;
    uint32_t last_block_size = length % BLOCK_SIZE;
    uint32_t t1, t2;
    int i, j;

    for (i = 0; i < num_blocks; i++) {
        if (i == num_blocks - 1) {
            block[BLOCK_SIZE / 4 - 1] = length * 8;
        } else {
            for (j = 0; j < BLOCK_SIZE / 4; j++) {
                if (i == num_blocks - 2 && j == last_block_size / 4) {
                    block[j] = 0x80;
                } else if (i == num_blocks - 1 && j == BLOCK_SIZE / 4 - 2) {
                    block[j] = 0x00;
                } else if (i == num_blocks - 1 && j == BLOCK_SIZE / 4 - 1) {
                    block[j] = length * 8;
                } else {
                    block[j] = (i * BLOCK_SIZE + j * 4 < length) ?
                        (data[i * BLOCK_SIZE + j * 4] << 24) |
                        (data[i * BLOCK_SIZE + j * 4 + 1] << 16) |
                        (data[i * BLOCK_SIZE + j * 4 + 2] << 8) |
                        (data[i * BLOCK_SIZE + j * 4 + 3]) :
                        0;
                }
            }
        }

        sha256_transform((uint8_t *) block, hash_values);
    }

    for (i = 0; i < HASH_SIZE; i += 4) {
        hash[i] = (hash_values[i / 4] >> 24) & 0xff;
        hash[i + 1] = (hash_values[i / 4] >> 16) & 0xff;
        hash[i + 2] = (hash_values[i / 4] >> 8) & 0xff;
        hash[i + 3] = (hash_values[i / 4]) & 0xff;
    }
}

static const uint32_t k[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_block(const uint8_t *block, uint32_t *hash_values) {
    uint32_t w[64], a, b, c, d, e, f, g, h, i, j, t1, t2;

    for (i = 0; i < 16; i++) {
        w[i] = (block[i * 4] << 24) | (block[i * 4 + 1] << 16) |
               (block[i * 4 + 2] << 8) | (block[i * 4 + 3]);
    }

    for (i = 16; i < 64; i++) {
        w[i] = w[i - 16] + w[i - 7] + ((w[i - 15] >> 7) |
               (w[i - 15] << 25)) + ((w[i - 15] >> 18) |
               (w[i - 15] << 14)) ^ (w[i - 15] >> 3) ^
               ((w[i - 16] >> 17) | (w[i - 16] << 15)) ^
               ((w[i - 16] >> 19) | (w[i - 16] << 13));
    }

    a = hash_values[0];
    b = hash_values[1];
    c = hash_values[2];
    d = hash_values[3];
    e = hash_values[4];
    f = hash_values[5];
    g = hash_values[6];
    h = hash_values[7];

    for (i = 0; i < 64; i++) {
        t1 = h + ((e >> 6) | (e << 26)) ^ ((e >> 11) | (e << 21)) ^
             ((e >> 25) | (e << 7)) + ((e & f) ^ (~e & g)) + k[i] + w[i];
        t2 = ((a >> 2) | (a << 30)) ^ ((a >> 13) | (a << 19)) ^
             ((a >> 22) | (a << 10)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    hash_values[0] += a;
    hash_values[1] += b;
    hash_values[2] += c;
    hash_values[3] += d;
    hash_values[4] += e;
    hash_values[5] += f;
    hash_values[6] += g;
    hash_values[7] += h;
}

void sha256_transform(const uint8_t *block, uint32_t *hash_values) {
    uint8_t padded_block[BLOCK_SIZE];
    int i;

    memcpy(padded_block, block, BLOCK_SIZE);

    for (i = 0; i < BLOCK_SIZE / 4; i++) {
        padded_block[i] = (padded_block[i] >> 24) & 0xff;
        padded_block[i + BLOCK_SIZE / 4] = (padded_block[i] >> 16) & 0xff;
        padded_block[i + BLOCK_SIZE / 2] = (padded_block[i] >> 8) & 0xff;
        padded_block[i + BLOCK_SIZE * 3 / 4] = padded_block[i] & 0xff;
    }

    sha256_block(padded_block, hash_values);
}