#include <stdio.h>

int
main(void)
{
	int c, i, j, max_count; /* our good old character slot */

	/* I am too lazy so I will just do it for digits */
	int ndigits[10];
	
	for (i = 0; i < 10; ++i) {
		ndigits[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigits[c - '0'];
		} 
	}

	max_count = 0;
	for (i = 0; i < 10; ++i) {
		if (ndigits[i] > max_count) {
			max_count = ndigits[i];
		}
	}

	printf("bars vertical:\n");
	for (i = max_count; i > 0; --i) {
		for (j = 0; j < 10; ++j) {
			if (i <= ndigits[j]) 
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}

	/* print the number labels */
	for (i = 0; i < 10; ++i) {
		printf("%d", i);
	}

	printf("\n");
	return 0;
}
