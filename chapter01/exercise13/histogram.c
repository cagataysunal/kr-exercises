#include <stdio.h>

#define CUTOFF 9

int
main(void)
{
	int word_length[CUTOFF+1]; /* each digit representing a word length */
	int length;
	int i, j, c;
	int max_count;

	length = 0;
	for (i = 0; i < CUTOFF+1; ++i)
		word_length[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') 
			++length;
		else {
			if (length > 0) {
				if (length > CUTOFF)
					++word_length[CUTOFF]; /* CUTOFF or more characters */
				else
					++word_length[length];
			}
			length = 0;
		}
	}

	/* if encounter EOF before another whitespace, count the word as well */
	if (length > 0) 
		++word_length[length];

	max_count = 0;
	for (i = 1; i <= CUTOFF; ++i) {
		if (word_length[i] > max_count) 
			max_count = word_length[i];
	}

	printf("bars horizontal:\n");
	for (i = 1; i <= CUTOFF; ++i) {
		if (i == CUTOFF) {
			printf("+");
			printf("%2d|", i);
		}
		else {
			printf("%3d|", i);
		}
		for (j = 0; j < word_length[i]; j++) {
			printf("#");
		}
		printf("\n");
	}

	printf("bars vertical:\n");
	for (i = max_count; i > 0; --i) {
		for (j = 1; j <= CUTOFF; ++j) {
			if (word_length[j] >= i)
				printf("#");
			else 
				printf(" ");
			printf(" ");
		}
		printf("\n");
	}

	/* labels */
	for (i = 1; i <= CUTOFF; ++i) {
		if (i == CUTOFF) 
			printf("--");
		else 
			printf("-");
		printf(" ");
	}
	printf("\n");
	for (i = 1; i <= CUTOFF; ++i) {
		printf("%d", i);
		printf(" ");
	}
	printf("\n");


	printf("lengths:\n");
	for (i = 1; i <= CUTOFF; i++)
		if (i == CUTOFF)
			printf("%d words with %d or more chars\n", word_length[i], i);
		else
			printf("%d words with %d chars\n", word_length[i], i);
	printf("\n");
	return 0;
}
