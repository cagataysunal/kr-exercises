#include <stdio.h>

int
main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		/* replace each char with equivalent */
		if (c == '\t') {
			printf("\\t");
		} else if (c == '\n') {
			printf("\\n");
		} else if (c == '\b') {
			printf("\\b");
		} else {
			printf("%c", c);
		}
	}
	return 0;
}
