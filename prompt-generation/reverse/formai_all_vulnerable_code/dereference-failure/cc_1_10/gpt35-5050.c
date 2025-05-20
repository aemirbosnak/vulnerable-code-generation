//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define the initial values for the MD buffer (RFC 1321)
#define A_INIT      0x67452301U
#define B_INIT      0xEFCDAB89U
#define C_INIT      0x98BADCFEU
#define D_INIT      0x10325476U

// Define the MD constants (RFC 1321)
#define S11         7
#define S12         12
#define S13         17
#define S14         22
#define S21         5
#define S22         9
#define S23         14
#define S24         20
#define S31         4
#define S32         11
#define S33         16
#define S34         23
#define S41         6
#define S42         10
#define S43         15
#define S44         21

// Define the MD functions (RFC 1321)
#define F(x, y, z)  ((x & y) | ((~x) & z))
#define G(x, y, z)  ((x & z) | (y & (~z)))
#define H(x, y, z)  (x ^ y ^ z)
#define I(x, y, z)  (y ^ (x | (~z)))

// Define a left rotation function
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Define the MD buffer structure
typedef struct {
    uint32_t A;
    uint32_t B;
    uint32_t C;
    uint32_t D;
} MD_CTX;

// Define the MD initialization function
void MD_Init(MD_CTX *context) {
    context->A = A_INIT;
    context->B = B_INIT;
    context->C = C_INIT;
    context->D = D_INIT;
}

// Define the MD round function
void MD_Round(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    *a = ROTATE_LEFT((*a + F(b, c, d) + x + ac), s);
}

// Define the MD transformation function
void MD_Transform(MD_CTX *context, const uint8_t *block) {
    uint32_t *word = (uint32_t *)block;

    uint32_t a = context->A;
    uint32_t b = context->B;
    uint32_t c = context->C;
    uint32_t d = context->D;

    // Perform round 1
    MD_Round(&a, b, c, d, word[0], S11, 0xd76aa478U);
    MD_Round(&d, a, b, c, word[1], S12, 0xe8c7b756U);
    MD_Round(&c, d, a, b, word[2], S13, 0x242070dbU);
    MD_Round(&b, c, d, a, word[3], S14, 0xc1bdceeeU);
    MD_Round(&a, b, c, d, word[4], S11, 0xf57c0fafU);
    MD_Round(&d, a, b, c, word[5], S12, 0x4787c62aU);
    MD_Round(&c, d, a, b, word[6], S13, 0xa8304613U);
    MD_Round(&b, c, d, a, word[7], S14, 0xfd469501U);
    MD_Round(&a, b, c, d, word[8], S11, 0x698098d8U);
    MD_Round(&d, a, b, c, word[9], S12, 0x8b44f7afU);
    MD_Round(&c, d, a, b, word[10], S13, 0xffff5bb1U);
    MD_Round(&b, c, d, a, word[11], S14, 0x895cd7beU);
    MD_Round(&a, b, c, d, word[12], S11, 0x6b901122U);
    MD_Round(&d, a, b, c, word[13], S12, 0xfd987193U);
    MD_Round(&c, d, a, b, word[14], S13, 0xa679438eU);
    MD_Round(&b, c, d, a, word[15], S14, 0x49b40821U);

    // Perform round 2
    MD_Round(&a, b, c, d, word[1], S21, 0xf61e2562U);
    MD_Round(&d, a, b, c, word[6], S22, 0xc040b340U);
    MD_Round(&c, d, a, b, word[11], S23, 0x265e5a51U);
    MD_Round(&b, c, d, a, word[0], S24, 0xe9b6c7aaU);
    MD_Round(&a, b, c, d, word[5], S21, 0xd62f105dU);
    MD_Round(&d, a, b, c, word[10], S22, 0x02441453U);
    MD_Round(&c, d, a, b, word[15], S23, 0xd8a1e681U);
    MD_Round(&b, c, d, a, word[4], S24, 0xe7d3fbc8U);
    MD_Round(&a, b, c, d, word[9], S21, 0x21e1cde6U);
    MD_Round(&d, a, b, c, word[14], S22, 0xc33707d6U);
    MD_Round(&c, d, a, b, word[3], S23, 0xf4d50d87U);
    MD_Round(&b, c, d, a, word[8], S24, 0x455a14edU);
    MD_Round(&a, b, c, d, word[13], S21, 0xa9e3e905U);
    MD_Round(&d, a, b, c, word[2], S22, 0xfcefa3f8U);
    MD_Round(&c, d, a, b, word[7], S23, 0x676f02d9U);
    MD_Round(&b, c, d, a, word[12], S24, 0x8d2a4c8aU);

    // Perform round 3
    MD_Round(&a, b, c, d, word[5], S31, 0xfffa3942U);
    MD_Round(&d, a, b, c, word[8], S32, 0x8771f681U);
    MD_Round(&c, d, a, b, word[11], S33, 0x6d9d6122U);
    MD_Round(&b, c, d, a, word[14], S34, 0xfde5380cU);
    MD_Round(&a, b, c, d, word[1], S31, 0xa4beea44U);
    MD_Round(&d, a, b, c, word[4], S32, 0x4bdecfa9U);
    MD_Round(&c, d, a, b, word[7], S33, 0xf6bb4b60U);
    MD_Round(&b, c, d, a, word[10], S34, 0xbebfbc70U);
    MD_Round(&a, b, c, d, word[13], S31, 0x289b7ec6U);
    MD_Round(&d, a, b, c, word[0], S32, 0xeaa127faU);
    MD_Round(&c, d, a, b, word[3], S33, 0xd4ef3085U);
    MD_Round(&b, c, d, a, word[6], S34, 0x04881d05U);
    MD_Round(&a, b, c, d, word[9], S31, 0xd9d4d039U);
    MD_Round(&d, a, b, c, word[12], S32, 0xe6db99e5U);
    MD_Round(&c, d, a, b, word[15], S33, 0x1fa27cf8U);
    MD_Round(&b, c, d, a, word[2], S34, 0xc4ac5665U);

    // Perform round 4
    MD_Round(&a, b, c, d, word[0], S41, 0xf4292244U);
    MD_Round(&d, a, b, c, word[7], S42, 0x432aff97U);
    MD_Round(&c, d, a, b, word[14], S43, 0xab9423a7U);
    MD_Round(&b, c, d, a, word[5], S44, 0xfc93a039U);
    MD_Round(&a, b, c, d, word[12], S41, 0x655b59c3U);
    MD_Round(&d, a, b, c, word[3], S42, 0x8f0ccc92U);
    MD_Round(&c, d, a, b, word[10], S43, 0xffeff47dU);
    MD_Round(&b, c, d, a, word[1], S44, 0x85845dd1U);
    MD_Round(&a, b, c, d, word[8], S41, 0x6fa87e4fU);
    MD_Round(&d, a, b, c, word[15], S42, 0xfe2ce6e0U);
    MD_Round(&c, d, a, b, word[6], S43, 0xa3014314U);
    MD_Round(&b, c, d, a, word[13], S44, 0x4e0811a1U);
    MD_Round(&a, b, c, d, word[4], S41, 0xf7537e82U);
    MD_Round(&d, a, b, c, word[11], S42, 0xbd3af235U);
    MD_Round(&c, d, a, b, word[2], S43, 0x2ad7d2bbU);
    MD_Round(&b, c, d, a, word[9], S44, 0xeb86d391U);
    
    // Update the context buffer
    context->A += a;
    context->B += b;
    context->C += c;
    context->D += d;
}

// Define the MD padding function
void MD_Pad(MD_CTX *context, uint8_t *data, uint32_t length) {
    // Pad the data with a single 1-bit
    data[length] = 0x80;
    ++length;

    // Pad the data with zeros until the length is congruent to 448 mod 512
    uint32_t pad_length = 64 - ((length + 8) % 64);
    memset(&data[length], 0x00, pad_length);
    length += pad_length;

    // Append the length of the message as a 64-bit big-endian integer
    uint64_t bits = (((uint64_t)context->A << 32) | context->B) + length * 8;
    data[length + 7] = (bits >> 0) & 0xff;
    data[length + 6] = (bits >> 8) & 0xff;
    data[length + 5] = (bits >> 16) & 0xff;
    data[length + 4] = (bits >> 24) & 0xff;
    data[length + 3] = (bits >> 32) & 0xff;
    data[length + 2] = (bits >> 40) & 0xff;
    data[length + 1] = (bits >> 48) & 0xff;
    data[length + 0] = (bits >> 56) & 0xff;
}

// Define the main function
int main() {
    // Initialize the MD context
    MD_CTX context;
    MD_Init(&context);

    // Create the input string
    char *input = "This is a message to be hashed.";

    // Allocate memory for the padded data
    uint32_t input_length = strlen(input);
    uint32_t data_length = ((input_length + 8) / 64 + 1) * 64;
    uint8_t *data = (uint8_t *)malloc(data_length);
    memcpy(data, input, input_length);

    // Pad the data and transform it
    MD_Pad(&context, data, input_length);
    for (uint32_t i = 0; i < data_length; i += 64) {
        MD_Transform(&context, &data[i]);
    }

    // Print the MD5 hash
    printf("MD5 hash: %08x%08x%08x%08x\n", context.A, context.B, context.C, context.D);

    // Free the memory used for the padded data
    free(data);

    return 0;
}