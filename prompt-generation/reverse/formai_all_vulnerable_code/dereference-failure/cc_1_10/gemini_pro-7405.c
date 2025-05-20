//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Generate a random permutation of size n.
int *random_permutation(int n) {
    int *p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }
    return p;
}

// Encrypt a message m using a permutation p.
int *encrypt(int *m, int m_len, int *p, int p_len) {
    assert(m_len == p_len);
    int *c = malloc(sizeof(int) * m_len);
    for (int i = 0; i < m_len; i++) {
        c[i] = m[p[i]];
    }
    return c;
}

// Decrypt a message c using a permutation p.
int *decrypt(int *c, int c_len, int *p, int p_len) {
    assert(c_len == p_len);
    int *m = malloc(sizeof(int) * c_len);
    for (int i = 0; i < c_len; i++) {
        for (int j = 0; j < p_len; j++) {
            if (p[j] == i) {
                m[j] = c[i];
                break;
            }
        }
    }
    return m;
}

// Test the encryption and decryption functions.
int main() {
    int m[] = {1, 2, 3, 4, 5};
    int m_len = sizeof(m) / sizeof(int);
    int *p = random_permutation(m_len);
    int *c = encrypt(m, m_len, p, m_len);
    int *d = decrypt(c, m_len, p, m_len);
    for (int i = 0; i < m_len; i++) {
        assert(m[i] == d[i]);
    }
    free(p);
    free(c);
    free(d);
    return 0;
}