//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

// Define the maximum size of the message to be encrypted/decrypted
#define MAX_MESSAGE_SIZE 1024

// Define the OpenSSL error handling function
void openssl_error(const char *func, int ret) {
  printf("Error in %s: %d\n", func, ret);
  ERR_print_errors_fp(stderr);
  exit(EXIT_FAILURE);
}

// Define the thread function for generating the public/private key pair
void *generate_key_pair(void *args) {
  // Get the arguments
  char *password = (char *)args;

  // Generate the RSA key pair
  RSA *rsa = RSA_new();
  if (!RSA_generate_key_ex(rsa, 2048, RSA_F4, NULL)) {
    openssl_error("RSA_generate_key_ex", ERR_get_error());
  }

  // Write the public key to a file
  BIO *bio_pub = BIO_new_file("public.pem", "w");
  if (!PEM_write_RSAPublicKey(bio_pub, rsa)) {
    openssl_error("PEM_write_RSAPublicKey", ERR_get_error());
  }
  BIO_free(bio_pub);

  // Write the private key to a file
  BIO *bio_priv = BIO_new_file("private.pem", "w");
  if (!PEM_write_RSAPrivateKey(bio_priv, rsa, EVP_des_ede3_cbc(), (unsigned char *)password, strlen(password), NULL, NULL)) {
    openssl_error("PEM_write_RSAPrivateKey", ERR_get_error());
  }
  BIO_free(bio_priv);

  // Clean up
  RSA_free(rsa);

  return NULL;
}

// Define the thread function for encrypting the message
void *encrypt_message(void *args) {
  // Get the arguments
  char *message = (char *)args;
  RSA *public_key = RSA_new();

  // Read the public key from a file
  BIO *bio_pub = BIO_new_file("public.pem", "r");
  if (!PEM_read_RSA_PUBKEY(bio_pub, &public_key, NULL, NULL)) {
    openssl_error("PEM_read_RSA_PUBKEY", ERR_get_error());
  }
  BIO_free(bio_pub);

  // Encrypt the message
  int encrypted_length = RSA_size(public_key);
  unsigned char *encrypted_message = (unsigned char *)malloc(encrypted_length);
  if (!RSA_public_encrypt(strlen(message), (unsigned char *)message, encrypted_message, public_key, RSA_PKCS1_OAEP_PADDING)) {
    openssl_error("RSA_public_encrypt", ERR_get_error());
  }

  // Print the encrypted message
  printf("Encrypted message: ");
  for (int i = 0; i < encrypted_length; i++) {
    printf("%02X", encrypted_message[i]);
  }
  printf("\n");

  // Clean up
  RSA_free(public_key);
  free(encrypted_message);

  return NULL;
}

// Define the thread function for decrypting the message
void *decrypt_message(void *args) {
  // Get the arguments
  char *password = (char *)args;
  unsigned char *encrypted_message = (unsigned char *)args;

  // Read the private key from a file
  RSA *private_key = RSA_new();
  BIO *bio_priv = BIO_new_file("private.pem", "r");
  if (!PEM_read_RSAPrivateKey(bio_priv, &private_key, NULL, (unsigned char *)password)) {
    openssl_error("PEM_read_RSAPrivateKey", ERR_get_error());
  }
  BIO_free(bio_priv);

  // Decrypt the message
  int decrypted_length = RSA_size(private_key);
  unsigned char *decrypted_message = (unsigned char *)malloc(decrypted_length);
  if (!RSA_private_decrypt(RSA_size(private_key), encrypted_message, decrypted_message, private_key, RSA_PKCS1_OAEP_PADDING)) {
    openssl_error("RSA_private_decrypt", ERR_get_error());
  }

  // Print the decrypted message
  printf("Decrypted message: %s\n", decrypted_message);

  // Clean up
  RSA_free(private_key);
  free(decrypted_message);

  return NULL;
}

// Define the main function
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 3) {
    printf("Usage: %s message password\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the arguments
  char *message = argv[1];
  char *password = argv[2];

  // Create the threads
  pthread_t generate_key_pair_thread;
  pthread_t encrypt_message_thread;
  pthread_t decrypt_message_thread;

  // Start the threads
  if (pthread_create(&generate_key_pair_thread, NULL, generate_key_pair, (void *)password) != 0) {
    printf("Error creating generate_key_pair thread\n");
    return EXIT_FAILURE;
  }
  if (pthread_create(&encrypt_message_thread, NULL, encrypt_message, (void *)message) != 0) {
    printf("Error creating encrypt_message thread\n");
    return EXIT_FAILURE;
  }
  if (pthread_create(&decrypt_message_thread, NULL, decrypt_message, (void *)password) != 0) {
    printf("Error creating decrypt_message thread\n");
    return EXIT_FAILURE;
  }

  // Wait for the threads to finish
  pthread_join(generate_key_pair_thread, NULL);
  pthread_join(encrypt_message_thread, NULL);
  pthread_join(decrypt_message_thread, NULL);

  // Exit the program
  return EXIT_SUCCESS;
}