//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Structure for holding intermediate hash value
typedef struct{
    uint32_t A, B, C, D;
} MD5_HASH;

//Constants values for the MD5 algorithm
#define MD5_A 0x67452301
#define MD5_B 0xEFCDAB89
#define MD5_C 0x98BADCFE
#define MD5_D 0x10325476

//Rotate left macro
#define ROTL(x,n) ((x << n) | (x >> (32 - n)))

//MD5 round functions
#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x ^ y ^ z)
#define I(x,y,z) (y ^ (x | ~z))

//MD5 round shifts
const uint32_t MD5_S[] = {
    7, 12, 17, 22,
    5,  9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21
};

//MD5 constants
const uint32_t MD5_T[] = {
    0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE,
    0xF57C0FAF, 0x4787C62A, 0xA8304613, 0xFD469501,
    0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE,
    0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821,
    0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA,
    0xD62F105D, 0x2441453,  0xD8A1E681, 0xE7D3FBC8,
    0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED,
    0xA9E3E905, 0xFCEFA3F8, 0x676F02D9, 0x8D2A4C8A,
    0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C,
    0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
    0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x4881D05,
    0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665,
    0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039,
    0x655B59C3, 0x8F0CCC92, 0xFFEFF47D, 0x85845DD1,
    0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1,
    0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
};

//MD5 helper functions
void md5_transform(MD5_HASH *hash, const uint32_t *data);
void md5_pad_message(uint8_t *msg, size_t length, uint64_t *msg_len);
void md5_hash_to_string(const MD5_HASH *hash, char *str);

//Main function
int main(){
    const char *message = "Hello, World!";
    char hash_str[33];
    MD5_HASH hash = {MD5_A, MD5_B, MD5_C, MD5_D};

    //Convert message into 512-bit blocks and process them
    uint64_t msg_len = strlen(message) * 8;
    uint8_t *msg = calloc(((msg_len + 512 + 64) / 512) * 64, sizeof(uint8_t));
    memcpy(msg, message, strlen(message));
    md5_pad_message(msg, strlen(message), &msg_len);

    //Process each 512-bit block of the padded message
    for(size_t i = 0; i < msg_len / 512; i++){
        md5_transform(&hash, (const uint32_t *)(msg + (i * 64)));
    }

    //Convert the final hash value to a string
    md5_hash_to_string(&hash, hash_str);
    printf("Message: %s\nMD5 Hash: %s\n", message, hash_str);

    //Free dynamically allocated memory
    free(msg);
    msg = NULL;

    return 0;
}

//Transforms a 512-bit block of data according to the MD5 algorithm
void md5_transform(MD5_HASH *hash, const uint32_t *data){
    uint32_t a = hash->A, b = hash->B, c = hash->C, d = hash->D;

    for(size_t i = 0; i < 64; i++){
        uint32_t f = 0, g = i;

        if(i < 16){
            f = F(b, c, d);
            g = i;
        }
        else if(i < 32){
            f = G(b, c, d);
            g = ((5 * i) + 1) % 16;
        }
        else if(i < 48){
            f = H(b, c, d);
            g = ((3 * i) + 5) % 16;
        }
        else{
            f = I(b, c, d);
            g = (7 * i) % 16;
        }

        f += a + MD5_T[i] + data[g];
        a = d;
        d = c;
        c = b;
        b += ROTL(f, MD5_S[i % 4]);
    }

    //Update intermediate hash value
    hash->A += a;
    hash->B += b;
    hash->C += c;
    hash->D += d;
}

//Pads a message with the MD5 padding scheme
void md5_pad_message(uint8_t *msg, size_t length, uint64_t *msg_len){
    //Append a single bit "1" to the message
    msg[length] = 0x80;
    //Pad message with zeros until it is congruent to 448 (mod 512) bytes
    while(((*msg_len + 8) % 512) != 448){
        (*msg_len)++;
        length++;
        msg[length] = 0;
    }
    //Append the length of the original message in bits as a 64-bit integer
    (*msg_len) += length * 8;
    *((uint64_t *)(msg + length + 1)) = (*msg_len);
}

//Converts an MD5 hash value to a hexadecimal string
void md5_hash_to_string(const MD5_HASH *hash, char *str){
    sprintf(str, "%08x%08x%08x%08x", hash->A, hash->B, hash->C, hash->D);
}