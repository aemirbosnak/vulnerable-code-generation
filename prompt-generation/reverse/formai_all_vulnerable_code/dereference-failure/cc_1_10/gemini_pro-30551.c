//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  char *data;
  size_t len;
  size_t cap;
}SBuf;

void sbuf_init(SBuf *sb) {
  sb->len = 0;
  sb->cap = 1024;
  sb->data = malloc(sb->cap);
}

void sbuf_free(SBuf *sb) {
  free(sb->data);
}

void sbuf_append(SBuf *sb, const char *s, size_t n) {
  if(sb->len + n + 1 > sb->cap){
    sb->data = realloc(sb->data, sb->cap * 2);
    sb->cap *= 2;
  }
  memcpy(sb->data + sb->len, s, n);
  sb->len += n;
  sb->data[sb->len] = 0;
}

typedef struct{
  SBuf buf;
  const char *ptr;
  const char *start;
  const char *end;
}CBuf;

void cbuf_init(CBuf *cb, const char *s){
  sbuf_init(&cb->buf);
  cb->ptr = cb->start = cb->end = s;
}

void cbuf_free(CBuf *cb) {
  sbuf_free(&cb->buf);
}

const char *cbuf_next(CBuf *cb) {
  cb->start = cb->ptr;
  while(*cb->ptr != 0 && *cb->ptr != ','){
    cb->ptr++;
  }
  cb->end = cb->ptr;
  if(*cb->ptr == ','){
    cb->ptr++;
  }
  return cb->start;
}

char *cbuf_get(CBuf *cb){
  char *ret = malloc(cb->end - cb->start + 1);
  memcpy(ret, cb->start, cb->end - cb->start);
  ret[cb->end - cb->start] = 0;
  return ret;
}

void test() {
  const char *s = "a,b,c,d,e\n1,2,3,4,5\n6,7,8,9,10";
  CBuf cb;
  cbuf_init(&cb, s);
  while(*cb.ptr != 0){
    const char *line = cbuf_next(&cb);
    printf("Line: %s\n", line);
    CBuf lb;
    cbuf_init(&lb, line);
    while(*lb.ptr != 0){
      const char *col = cbuf_get(&lb);
      printf("\tCol: %s\n", col);
      free(col);
    }
    cbuf_free(&lb);
  }
}

int main() {
  test();
  return 0;
}