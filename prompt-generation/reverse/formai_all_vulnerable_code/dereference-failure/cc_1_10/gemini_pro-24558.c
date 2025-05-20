//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SZ (8)
#define TAIL_SZ (16)

typedef unsigned char uchar;

typedef struct {
  int key_len;
  uchar key[KEY_SZ];
  uchar tail[TAIL_SZ];
} t_data;

void rotl(uchar* buf, int n) {
  int len = *buf++;
  uchar r = (uchar)((uchar)(*buf++) << n) >> (8 - n);
  memmove(buf, buf + 1, len);
  buf[len - 1] = r;
}

void rotr(uchar* buf, int n) {
  int len = *buf++;
  uchar r = (uchar)((uchar)(buf[len - 1]) << n) >> (8 - n);
  memmove(buf + 1, buf, len);
  buf[0] = r;
}

void xor(uchar* buf, uchar* key, int len) {
  while (len--) { *buf++ ^= *key++; }
}

void xor_tail(t_data* data, uchar* buf, int len) {
  int i;
  for (i = 0; i < data->key_len; i++) { *buf++ ^= data->tail[i]; }
  xor(buf, data->key, len);
  for (i = 0; i < data->key_len; i++) { *buf++ ^= data->tail[i]; }
}

void encrypt(t_data* data, uchar* buf, int len) {
  int i;
  *buf++ = (uchar)len;
  xor_tail(data, buf, len);
  for (i = 0; i < 100; i++) { rotl(buf, 1); }
  for (i = 0; i < 100; i++) { rotr(buf, 2); }
  xor_tail(data, buf, len);
  *buf++ = 0;
}

void decrypt(t_data* data, uchar* buf, int* len) {
  int i;
  if (*buf != 0) return;
  *len = *buf++ - 1;
  xor_tail(data, buf, *len);
  for (i = 0; i < 100; i++) { rotr(buf, 2); }
  for (i = 0; i < 100; i++) { rotl(buf, 1); }
  xor_tail(data, buf, *len);
  *buf++ = 0;
}

int main(int ac, char** av) {
  uchar* buf = (uchar*)malloc(4096);
  uchar* s = (uchar*)fgets((char*)buf, 4096, stdin);
  t_data data;
  srand(time(NULL));
  data.key_len = rand() % KEY_SZ + 1;
  for (int i = 0; i < data.key_len; i++) { data.key[i] = rand() % 256; }
  for (int i = 0; i < TAIL_SZ; i++) { data.tail[i] = rand() % 256; }
  printf("Encrypted: ");
  encrypt(&data, buf, strlen((char*)s));
  printf("%s\n", buf);
  decrypt(&data, buf, &data.key_len);
  printf("Decrypted: %s", buf);
  return 0;
}