#include <stdio.h>

int
main(void)
{
	int word_length[10]; /* each digit +1 representing a word length */
	int length;
	int i, j, c;

	length = 0;
	for (i = 0; i < 10; ++i)
		word_length[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') 
			++length;
		else {
			if ((length - 1) >= 0) {
				if ((length-1) >= 10)
					++word_length[9]; /* 10+ characters */
				else
					++word_length[length - 1];
			}
			length = 0;
		}
	}

	/* TODO make it a graph like ### and shit */
	printf("bars horizontal:\n");

	for (i = 0; i < 10; ++i) {
		if (i == 9) {
			printf("+");
			printf("%2d|", i+1);
		}
		else {
			printf("%3d|", i+1);
		}
		for (j = 0; j < word_length[i]; j++) {
			printf("#");
		}
		printf("\n");
	}

	printf("lengths:\n");
	for (i = 0; i < 10; i++)
		printf("%d words with %d letters\n", word_length[i], i+1);
	printf("\n");
	return 0;
}
