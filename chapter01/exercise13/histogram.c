#include <stdio.h>

int
main(void)
{
	int word_length[10]; /* each digit +1 representing a word length */
	int length;
	int i, c;

	length = 0;
	for (i = 0; i < 10; ++i)
		word_length[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') 
			++length;
		else {
			if ((length - 1) >= 0)
				++word_length[length - 1];
			length = 0;
		}
	}

	printf("lengths:\n");
	for (i = 0; i < 10; i++)
		printf("%d words with %d letters\n", word_length[i], i+1);
	printf("\n");
	return 0;
}
