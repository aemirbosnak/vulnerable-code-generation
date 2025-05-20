//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genius
// A whimsical wonderland of public-key cryptography, where logic pirouettes like a jester and algorithms dance with ethereal grace.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A celestial dance of prime numbers, where Euclid's algorithm serenades us with its elegance.
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// The enchanting aura of Fermat's Little Theorem, illuminating the mysteries of modular arithmetic.
long long modpow(long long base, long long exponent, long long modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exponent /= 2;
  }
  return result;
}

// The enigmatic Rabin-Karp rolling hash algorithm, painting words with numeric hues.
long long hash(char *string, long long length, long long prime, long long modulus) {
  long long hashValue = 0;
  for (long long i = 0; i < length; i++) {
    hashValue = (hashValue * prime + string[i]) % modulus;
  }
  return hashValue;
}

// The cosmic RSA key pair generator, unlocking the secrets of communication through a celestial pact.
void generateRSAKeyPair(long long *publicKey, long long *privateKey, long long p, long long q) {
  long long n = p * q;
  long long phiN = (p - 1) * (q - 1);
  long long e = 3;
  while (gcd(e, phiN) != 1) {
    e++;
  }
  long long d = modpow(e, -1, phiN);
  *publicKey = e;
  *privateKey = d;
}

// The celestial encryption ritual, where messages transform under the veil of public keys.
char *encryptRSA(char *message, long long length, long long publicKey, long long modulus) {
  char *encryptedMessage = malloc(length * sizeof(char));
  for (long long i = 0; i < length; i++) {
    encryptedMessage[i] = modpow(message[i], publicKey, modulus);
  }
  return encryptedMessage;
}

// The ethereal decryption ritual, where encrypted whispers unveil their secrets through private keys.
char *decryptRSA(char *encryptedMessage, long long length, long long privateKey, long long modulus) {
  char *decryptedMessage = malloc(length * sizeof(char));
  for (long long i = 0; i < length; i++) {
    decryptedMessage[i] = modpow(encryptedMessage[i], privateKey, modulus);
  }
  return decryptedMessage;
}

int main() {
  // The cosmic stage is set. A secret message awaits its celestial journey.
  char *message = "Behold, the secrets of the stars.";
  long long length = strlen(message);

  // The celestial dance begins. Two prime numbers emerge from the cosmic void.
  long long p = 23;
  long long q = 37;

  // The RSA key pair, the ethereal guardians of communication.
  long long publicKey, privateKey;
  generateRSAKeyPair(&publicKey, &privateKey, p, q);

  // Encrypting the message, casting it into the celestial stream.
  char *encryptedMessage = encryptRSA(message, length, publicKey, p * q);

  // Decrypting the celestial stream, revealing the secrets it carries.
  char *decryptedMessage = decryptRSA(encryptedMessage, length, privateKey, p * q);

  // The celestial journey ends. The secret whispers are revealed.
  printf("Original Message: %s\n", message);
  printf("Encrypted Message: %s\n", encryptedMessage);
  printf("Decrypted Message: %s\n", decryptedMessage);

  // The cosmos applauds, marveling at the elegance of public-key cryptography.
  return 0;
}