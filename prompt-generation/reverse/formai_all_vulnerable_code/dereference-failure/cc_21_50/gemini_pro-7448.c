//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <password>\n", argv[0]);
		return 1;
	}

	char *password = argv[1];
	int len = strlen(password);
	int score = 0;

	// Check for length
	if (len < 8) {
		score += 1;
	} else if (len < 16) {
		score += 2;
	} else {
		score += 3;
	}

	// Check for uppercase letters
	int has_upper = 0;
	for (int i = 0; i < len; i++) {
		if (isupper(password[i])) {
			has_upper = 1;
			break;
		}
	}
	if (has_upper) {
		score += 1;
	}

	// Check for lowercase letters
	int has_lower = 0;
	for (int i = 0; i < len; i++) {
		if (islower(password[i])) {
			has_lower = 1;
			break;
		}
	}
	if (has_lower) {
		score += 1;
	}

	// Check for digits
	int has_digit = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(password[i])) {
			has_digit = 1;
			break;
		}
	}
	if (has_digit) {
		score += 1;
	}

	// Check for special characters
	int has_special = 0;
	for (int i = 0; i < len; i++) {
		if (!isalnum(password[i])) {
			has_special = 1;
			break;
		}
	}
	if (has_special) {
		score += 1;
	}

	// Check for repeated characters
	int has_repeated = 0;
	for (int i = 0; i < len - 1; i++) {
		if (password[i] == password[i + 1]) {
			has_repeated = 1;
			break;
		}
	}
	if (has_repeated) {
		score -= 1;
	}

	// Check for common passwords
	char *common_passwords[] = {
		"password", "123456", "12345678", "qwerty", "abc123",
		"monkey", "letmein", "dragon", "baseball", "iloveyou"
	};
	int num_common_passwords = sizeof(common_passwords) / sizeof(char *);
	for (int i = 0; i < num_common_passwords; i++) {
		if (strcmp(password, common_passwords[i]) == 0) {
			score -= 5;
			break;
		}
	}

	// Calculate the final score
	if (score < 0) {
		score = 0;
	} else if (score > 10) {
		score = 10;
	}

	// Print the score
	printf("Password strength: %d/10\n", score);

	return 0;
}