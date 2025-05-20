//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define ROTL(x,y) (((x)<<(y))|((x)>>(32-(y))))
#define ROTR(x,y) (((x)>>(y))|((x)<<(32-(y))))

uint64_t mix(uint64_t a, uint64_t b, uint64_t c)
{
  a=a-b;  a=a-c;  a=a^(c>>43);
  b=b-c;  b=b-a;  b=b^(a<<9);
  c=c-a;  c=c-b;  c=c^(b>>8);
  a=a-b;  a=a-c;  a=a^(c>>38);
  b=b-c;  b=b-a;  b=b^(a<<23);
  c=c-a;  c=c-b;  c=c^(b>>5);
  a=a-b;  a=a-c;  a=a^(c>>35);
  b=b-c;  b=b-a;  b=b^(a<<49);
  c=c-a;  c=c-b;  c=c^(b>>11);
  a=a-b;  a=a-c;  a=a^(c>>12);
  b=b-c;  b=b-a;  b=b^(a<<18);
  c=c-a;  c=c-b;  c=c^(b>>22);
  return c;
}

uint64_t hash(const void *key, size_t len, uint64_t seed)
{
  const uint64_t *data=(const uint64_t *)key;
  const uint64_t *end=data+len/8;
  const uint8_t  *data2=(const uint8_t*)end;
  uint64_t h1=seed;
  static const uint64_t c1=0x87c37b91114253d5;
  static const uint64_t c2=0x4cf5ad432745937f;
  while(data!=end)
  {
    uint64_t k=*data++;
    k=k*c1;
    k=ROTL(k,31);
    k=k*c2;
    h1^=k;
    h1=ROTL(h1,27);
    h1=h1*5+0x52dce729;
  }
  uint64_t k1=0;
  switch(len&7)
  {
    case 7: k1^=(uint64_t)data2[6]<<48;
    case 6: k1^=(uint64_t)data2[5]<<40;
    case 5: k1^=(uint64_t)data2[4]<<32;
    case 4: k1^=(uint64_t)data2[3]<<24;
    case 3: k1^=(uint64_t)data2[2]<<16;
    case 2: k1^=(uint64_t)data2[1]<<8;
    case 1: k1^=(uint64_t)data2[0]<<0;
    k1*=c1;
    k1=ROTL(k1,31);
    k1*=c2;
    h1^=k1;
  }
  h1^=len;
  return mix(h1,0,0);
}

int main(int argc, char **argv)
{
  if(argc!=2)
  {
    fprintf(stderr, "USAGE: %s 'string'\n", argv[0]);
    return 1;
  }
  const char *input=argv[1];
  printf("Hash of input: %llx\n", hash(input, strlen(input), 0xDEADBEEF));
  return 0;
}