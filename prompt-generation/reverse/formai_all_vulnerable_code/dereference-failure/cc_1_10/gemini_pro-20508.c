//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style
#define error(fmt, ...) do { printf(fmt "\n", ##__VA_ARGS__); exit(1); } while (0)
#define info(fmt, ...) do { printf(fmt "\n", ##__VA_ARGS__); } while (0)
#define warn(fmt, ...) do { printf(fmt "\n", ##__VA_ARGS__); } while (0)
#define debug(fmt, ...) do { printf(fmt "\n", ##__VA_ARGS__); } while (0)

// Exam questions and answers
struct question {
	char *question;
	char *answer;
};

struct question questions[] = {
	{ "What is the capital of France?", "Paris" },
	{ "What is the largest country in the world?", "Russia" },
	{ "What is the name of the currency used in Japan?", "Yen" },
	{ "What is the chemical symbol for gold?", "Au" },
	{ "Who painted the Mona Lisa?", "Leonardo da Vinci" },
};

// Get user input
char *get_input(char *prompt) {
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("%s", prompt);
	nread = getline(&input, &len, stdin);
	if (nread == -1) {
		error("getline() failed");
	}

	// Remove trailing newline
	input[strcspn(input, "\n")] = '\0';

	return input;
}

// Check if user answer is correct
int check_answer(char *question, char *answer) {
	return strcmp(question, answer) == 0;
}

// Main function
int main() {
	int score = 0;

	for (int i = 0; i < sizeof(questions) / sizeof(struct question); i++) {
		char *question = questions[i].question;
		char *answer = questions[i].answer;

		char *user_answer = get_input(question);

		if (check_answer(user_answer, answer)) {
			score++;
			info("Correct answer!");
		} else {
			warn("Incorrect answer! Correct answer is %s", answer);
		}

		free(user_answer);
	}

	printf("Your score: %d/%d\n", score, sizeof(questions) / sizeof(struct question));

	return 0;
}