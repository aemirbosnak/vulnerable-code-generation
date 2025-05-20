//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>

// Generate a key pair.
int generate_key_pair(BIGNUM *n, BIGNUM *e, BIGNUM *d) {
  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *phi_n = BN_new();
  BIGNUM *gcd = BN_new();
  BN_CTX *ctx = BN_CTX_new();

  if (!p || !q || !phi_n || !gcd || !ctx) {
    return -1;
  }

  // Generate two large prime numbers, p and q.
  while (1) {
    BN_generate_prime_ex(p, 256, 1, NULL, NULL, NULL);
    BN_generate_prime_ex(q, 256, 1, NULL, NULL, NULL);
    if (BN_cmp(p, q) != 0) {
      break;
    }
  }

  // Compute n = p * q.
  BN_mul(n, p, q, ctx);

  // Compute phi(n) = (p - 1) * (q - 1).
  BN_sub(p, p, BN_value_one());
  BN_sub(q, q, BN_value_one());
  BN_mul(phi_n, p, q, ctx);

  // Choose a random number e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1.
  while (1) {
    BN_rand_range(e, phi_n);
    BN_gcd(gcd, e, phi_n, ctx);
    if (BN_cmp(gcd, BN_value_one()) == 0) {
      break;
    }
  }

  // Compute d = e^-1 mod phi(n).
  BN_mod_inverse(d, e, phi_n, ctx);

  BN_free(p);
  BN_free(q);
  BN_free(phi_n);
  BN_free(gcd);
  BN_CTX_free(ctx);

  return 0;
}

// Encrypt a message using the public key.
int encrypt_message(BIGNUM *m, BIGNUM *e, BIGNUM *n, BIGNUM *c) {
  BN_CTX *ctx = BN_CTX_new();

  if (!ctx) {
    return -1;
  }

  // Compute c = m^e mod n.
  BN_mod_exp(c, m, e, n, ctx);

  BN_CTX_free(ctx);

  return 0;
}

// Decrypt a message using the private key.
int decrypt_message(BIGNUM *c, BIGNUM *d, BIGNUM *n, BIGNUM *m) {
  BN_CTX *ctx = BN_CTX_new();

  if (!ctx) {
    return -1;
  }

  // Compute m = c^d mod n.
  BN_mod_exp(m, c, d, n, ctx);

  BN_CTX_free(ctx);

  return 0;
}

int main() {
  BIGNUM *n = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *d = BN_new();
  BIGNUM *m = BN_new();
  BIGNUM *c = BN_new();

  if (!n || !e || !d || !m || !c) {
    return -1;
  }

  // Generate a key pair.
  if (generate_key_pair(n, e, d) != 0) {
    return -1;
  }

  // Print the public key.
  printf("Public key:\n");
  BN_print_fp(stdout, n);
  BN_print_fp(stdout, e);

  // Print the private key.
  printf("Private key:\n");
  BN_print_fp(stdout, n);
  BN_print_fp(stdout, d);

  // Get the message to be encrypted.
  printf("Enter the message to be encrypted: ");
  char *message = NULL;
  size_t message_length = 0;
  getline(&message, &message_length, stdin);

  // Convert the message to a BIGNUM.
  BN_hex2bn(&m, message);

  // Encrypt the message.
  if (encrypt_message(m, e, n, c) != 0) {
    return -1;
  }

  // Print the encrypted message.
  printf("Encrypted message:\n");
  BN_print_fp(stdout, c);

  // Decrypt the message.
  if (decrypt_message(c, d, n, m) != 0) {
    return -1;
  }

  // Print the decrypted message.
  printf("Decrypted message:\n");
  char *decrypted_message = BN_bn2hex(m);
  printf("%s\n", decrypted_message);

  BN_free(n);
  BN_free(e);
  BN_free(d);
  BN_free(m);
  BN_free(c);
  free(message);
  free(decrypted_message);

  return 0;
}