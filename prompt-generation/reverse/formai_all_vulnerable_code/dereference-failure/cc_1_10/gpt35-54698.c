//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ROTL(x,n) (((x)<<(n))|((x)>>(32-(n))))

typedef unsigned int uint32_t;

uint32_t F(uint32_t x,uint32_t y,uint32_t z){
    return (x&y)|((~x)&z);
}

uint32_t G(uint32_t x,uint32_t y,uint32_t z){
    return (x&z)|(y&(~z));
}

uint32_t H(uint32_t x,uint32_t y,uint32_t z){
    return x^y^z;
}

uint32_t I(uint32_t x,uint32_t y,uint32_t z){
    return y^(x|(~z));
}

uint32_t FF(uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t m,uint32_t s,uint32_t t){
    a+=F(b,c,d)+m+t;
    a=ROTL(a,s);
    a+=b;
    return a;
}

uint32_t GG(uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t m,uint32_t s,uint32_t t){
    a+=G(b,c,d)+m+t;
    a=ROTL(a,s);
    a+=b;
    return a;
}

uint32_t HH(uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t m,uint32_t s,uint32_t t){
    a+=H(b,c,d)+m+t;
    a=ROTL(a,s);
    a+=b;
    return a;
}

uint32_t II(uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t m,uint32_t s,uint32_t t){
    a+=I(b,c,d)+m+t;
    a=ROTL(a,s);
    a+=b;
    return a;
}

void md5_hash(uint32_t *hash,const char *msg,size_t len){
    uint32_t a=hash[0],b=hash[1],c=hash[2],d=hash[3];
    uint32_t buf[16];
    size_t i,j;

    for(i=0;i<len;i+=64){
        for(j=0;j<16;j++){
            buf[j]=((uint32_t)msg[i+j*4])|\
                (((uint32_t)msg[i+j*4+1])<<8)|\
                (((uint32_t)msg[i+j*4+2])<<16)|\
                (((uint32_t)msg[i+j*4+3])<<24);
        }

        uint32_t aa=a,bb=b,cc=c,dd=d;

        a=FF(a,b,c,d,buf[0],7,0xd76aa478);
        d=FF(d,a,b,c,buf[1],12,0xe8c7b756);
        c=FF(c,d,a,b,buf[2],17,0x242070db);
        b=FF(b,c,d,a,buf[3],22,0xc1bdceee);
        a=FF(a,b,c,d,buf[4],7,0xf57c0faf);
        d=FF(d,a,b,c,buf[5],12,0x4787c62a);
        c=FF(c,d,a,b,buf[6],17,0xa8304613);
        b=FF(b,c,d,a,buf[7],22,0xfd469501);
        a=FF(a,b,c,d,buf[8],7,0x698098d8);
        d=FF(d,a,b,c,buf[9],12,0x8b44f7af);
        c=FF(c,d,a,b,buf[10],17,0xffff5bb1);
        b=FF(b,c,d,a,buf[11],22,0x895cd7be);
        a=FF(a,b,c,d,buf[12],7,0x6b901122);
        d=FF(d,a,b,c,buf[13],12,0xfd987193);
        c=FF(c,d,a,b,buf[14],17,0xa679438e);
        b=FF(b,c,d,a,buf[15],22,0x49b40821);

        a=GG(a,b,c,d,buf[1],5,0xf61e2562);
        d=GG(d,a,b,c,buf[6],9,0xc040b340);
        c=GG(c,d,a,b,buf[11],14,0x265e5a51);
        b=GG(b,c,d,a,buf[0],20,0xe9b6c7aa);
        a=GG(a,b,c,d,buf[5],5,0xd62f105d);
        d=GG(d,a,b,c,buf[10],9,0x02441453);
        c=GG(c,d,a,b,buf[15],14,0xd8a1e681);
        b=GG(b,c,d,a,buf[4],20,0xe7d3fbc8);
        a=GG(a,b,c,d,buf[9],5,0x21e1cde6);
        d=GG(d,a,b,c,buf[14],9,0xc33707d6);
        c=GG(c,d,a,b,buf[3],14,0xf4d50d87);
        b=GG(b,c,d,a,buf[8],20,0x455a14ed);
        a=GG(a,b,c,d,buf[13],5,0xa9e3e905);
        d=GG(d,a,b,c,buf[2],9,0xfcefa3f8);
        c=GG(c,d,a,b,buf[7],14,0x676f02d9);
        b=GG(b,c,d,a,buf[12],20,0x8d2a4c8a);

        a=HH(a,b,c,d,buf[5],4,0xfffa3942);
        d=HH(d,a,b,c,buf[8],11,0x8771f681);
        c=HH(c,d,a,b,buf[11],16,0x6d9d6122);
        b=HH(b,c,d,a,buf[14],23,0xfde5380c);
        a=HH(a,b,c,d,buf[1],4,0xa4beea44);
        d=HH(d,a,b,c,buf[4],11,0x4bdecfa9);
        c=HH(c,d,a,b,buf[7],16,0xf6bb4b60);
        b=HH(b,c,d,a,buf[10],23,0xbebfbc70);
        a=HH(a,b,c,d,buf[13],4,0x289b7ec6);
        d=HH(d,a,b,c,buf[0],11,0xeaa127fa);
        c=HH(c,d,a,b,buf[3],16,0xd4ef3085);
        b=HH(b,c,d,a,buf[6],23,0x04881d05);
        a=HH(a,b,c,d,buf[9],4,0xd9d4d039);
        d=HH(d,a,b,c,buf[12],11,0xe6db99e5);
        c=HH(c,d,a,b,buf[15],16,0x1fa27cf8);
        b=HH(b,c,d,a,buf[2],23,0xc4ac5665);

        a=II(a,b,c,d,buf[0],6,0xf4292244);
        d=II(d,a,b,c,buf[7],10,0x432aff97);
        c=II(c,d,a,b,buf[14],15,0xab9423a7);
        b=II(b,c,d,a,buf[5],21,0xfc93a039);
        a=II(a,b,c,d,buf[12],6,0x655b59c3);
        d=II(d,a,b,c,buf[3],10,0x8f0ccc92);
        c=II(c,d,a,b,buf[10],15,0xffeff47d);
        b=II(b,c,d,a,buf[1],21,0x85845dd1);
        a=II(a,b,c,d,buf[8],6,0x6fa87e4f);
        d=II(d,a,b,c,buf[15],10,0xfe2ce6e0);
        c=II(c,d,a,b,buf[6],15,0xa3014314);
        b=II(b,c,d,a,buf[13],21,0x4e0811a1);
        a=II(a,b,c,d,buf[4],6,0xf7537e82);
        d=II(d,a,b,c,buf[11],10,0xbd3af235);
        c=II(c,d,a,b,buf[2],15,0x2ad7d2bb);
        b=II(b,c,d,a,buf[9],21,0xeb86d391);

        a+=aa;
        b+=bb;
        c+=cc;
        d+=dd;
    }

    hash[0]=a;
    hash[1]=b;
    hash[2]=c;
    hash[3]=d;
}

void print_md5_hash(uint32_t *hash){
    printf("%08x%08x%08x%08x\n",hash[0],hash[1],hash[2],hash[3]);
}

void string_to_md5_hash(const char *msg,size_t len){
    uint32_t hash[4]={ 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 };
    md5_hash(hash,msg,len);
    print_md5_hash(hash);
}

int main(){
    string_to_md5_hash("The quick brown fox jumps over the lazy dog",43);
    return 0;
}