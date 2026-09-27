#include <stdio.h>

int
main(void)
{
	int blank_count, c;

	blank_count = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++blank_count;
		}
	}
	printf("blank count: %d\n", blank_count);
	return 0;
}
