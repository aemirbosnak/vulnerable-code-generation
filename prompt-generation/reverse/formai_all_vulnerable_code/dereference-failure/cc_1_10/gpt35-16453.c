//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) (((x)<<(n))|((x)>>(32-(n))))
#define ROTR(x,n) (((x)>>(n))|((x)<<(32-(n))))

#define Ch(x,y,z) ((x&y)^(~x&z))
#define Maj(x,y,z) ((x&y)^(x&z)^(y&z))
#define Sigma0(x) (ROTR(x,2)^ROTR(x,13)^ROTR(x,22))
#define Sigma1(x) (ROTR(x,6)^ROTR(x,11)^ROTR(x,25))
#define sigma0(x) (ROTR(x,7)^ROTR(x,18)^((x)>>3))
#define sigma1(x) (ROTR(x,17)^ROTR(x,19)^((x)>>10))

const uint32_t K[]={
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2
};

uint32_t h[8]={
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

typedef struct{
    uint8_t *data;
    uint32_t datalen;
    uint32_t bitlen[2];
    uint32_t state[8];
} SHA256_CTX;

void sha256_transform(SHA256_CTX *ctx, uint8_t data[]){
    uint32_t a,b,c,d,e,f,g,h,i,j,t1,t2,m[64];

    for(i=0,j=0;i<16;++i, j+=4){
        m[i]=((uint32_t)data[j]<<24)|((uint32_t)data[j+1]<<16)|((uint32_t)data[j+2]<<8)|((uint32_t)data[j+3]);
    }

    for(;i<64;++i){
        m[i]=sigma1(m[i-2])+m[i-7]+sigma0(m[i-15])+m[i-16];
    }

    a=ctx->state[0];
    b=ctx->state[1];
    c=ctx->state[2];
    d=ctx->state[3];
    e=ctx->state[4];
    f=ctx->state[5];
    g=ctx->state[6];
    h=ctx->state[7];

    for(i=0;i<64;++i){
        t1=h+Sigma1(e)+Ch(e,f,g)+K[i]+m[i];
        t2=Sigma0(a)+Maj(a,b,c);
        h=g;
        g=f;
        f=e;
        e=d+t1;
        d=c;
        c=b;
        b=a;
        a=t1+t2;
    }

    ctx->state[0]+=a;
    ctx->state[1]+=b;
    ctx->state[2]+=c;
    ctx->state[3]+=d;
    ctx->state[4]+=e;
    ctx->state[5]+=f;
    ctx->state[6]+=g;
    ctx->state[7]+=h;
}

void sha256_init(SHA256_CTX *ctx){
    ctx->datalen=0;
    ctx->bitlen[0]=0;
    ctx->bitlen[1]=0;
    ctx->state[0]=h[0];
    ctx->state[1]=h[1];
    ctx->state[2]=h[2];
    ctx->state[3]=h[3];
    ctx->state[4]=h[4];
    ctx->state[5]=h[5];
    ctx->state[6]=h[6];
    ctx->state[7]=h[7];
}

void sha256_update(SHA256_CTX *ctx, uint8_t data[], uint32_t len){
    uint32_t i;

    for(i=0;i<len;++i){
        ctx->data[ctx->datalen]=data[i];
        ctx->datalen++;

        if(ctx->datalen==64){
            sha256_transform(ctx,ctx->data);
            ctx->bitlen[0]+=512;
            ctx->datalen=0;
        }
    }
}

void sha256_final(SHA256_CTX *ctx, uint8_t hash[]){
    uint32_t i;

    i=ctx->datalen;

    if(ctx->datalen<56){
        ctx->data[i++]=0x80;

        while(i<56){
            ctx->data[i++]=0x00;
        }
    }
    else{
        ctx->data[i++]=0x80;

        while(i<64){
            ctx->data[i++]=0x00;
        }

        sha256_transform(ctx,ctx->data);
        memset(ctx->data,0,56);
    }

    ctx->bitlen[0]+=ctx->datalen*8;
    ctx->bitlen[1]+=ctx->bitlen[0]<(ctx->datalen*8);
    memcpy(&ctx->data[56],&ctx->bitlen[0],4);
    memcpy(&ctx->data[60],&ctx->bitlen[1],4);
    sha256_transform(ctx,ctx->data);

    for(i=0;i<4;++i){
        hash[i]=(ctx->state[0]>>24)&0xff;
        hash[i+4]=(ctx->state[1]>>24)&0xff;
        hash[i+8]=(ctx->state[2]>>24)&0xff;
        hash[i+12]=(ctx->state[3]>>24)&0xff;
        hash[i+16]=(ctx->state[4]>>24)&0xff;
        hash[i+20]=(ctx->state[5]>>24)&0xff;
        hash[i+24]=(ctx->state[6]>>24)&0xff;
        hash[i+28]=(ctx->state[7]>>24)&0xff;
        ctx->state[0]<<=8;
        ctx->state[1]<<=8;
        ctx->state[2]<<=8;
        ctx->state[3]<<=8;
        ctx->state[4]<<=8;
        ctx->state[5]<<=8;
        ctx->state[6]<<=8;
        ctx->state[7]<<=8;
    }
}

int main(){
    char input[1024];
    uint8_t *output=(uint8_t*)malloc(32);
    SHA256_CTX ctx;

    while(fgets(input,1024,stdin)){
        sha256_init(&ctx);
        sha256_update(&ctx,(uint8_t*)input,strlen(input));
        sha256_final(&ctx,output);

        for(int i=0;i<32;++i){
            printf("%02x",output[i]);
        }

        putchar('\n');
    }

    free(output);

    return 0;
}