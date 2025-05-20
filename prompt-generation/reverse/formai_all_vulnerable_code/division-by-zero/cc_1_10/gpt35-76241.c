//FormAI DATASET v1.0 Category: modern Encryption ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// This is a simple program demonstrating how to use the XOR encryption technique in C!
int main() {
	printf("Welcome to the joyful XOR encryption program!\n");

	// First, we ask the user for a secret message to encrypt
	char message[100];
	printf("Please enter your secret message to encrypt: ");
	fgets(message, 100, stdin);

	// Next, we ask the user for a secret key to use for the encryption
	char key[100];
	printf("Please enter your secret key to use for the encryption: ");
	fgets(key, 100, stdin);

	// We need to remove the newline character that fgets() adds to our strings
	strtok(message, "\n");
	strtok(key, "\n");

	// Let's print the original message and key
	printf("\nYour original message is: %s\n", message);
	printf("Your secret key is: %s\n", key);

	// Now, let's encrypt the message using the XOR technique
	int message_length = strlen(message);
	int key_length = strlen(key);
	char encrypted_message[100];

	for (int i = 0; i < message_length; i++) {
		encrypted_message[i] = message[i] ^ key[i % key_length];
	}
	encrypted_message[message_length] = '\0';

	// Print the encrypted message!
	printf("\nYour encrypted message is: %s\n", encrypted_message);

	// Let's decrypt the encrypted message to ensure it works
	char decrypted_message[100];
	for (int i = 0; i < message_length; i++) {
		decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
	}
	decrypted_message[message_length] = '\0';

	// Print the decrypted message!
	printf("\nYour decrypted message is: %s\n", decrypted_message);

	// Happiness check!
	printf("\nYAY! Your message has been successfully encrypted and decrypted!\n");

	return 0;
}