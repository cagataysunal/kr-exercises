#include <stdio.h>

#define OUT 0 /* outside word */
#define IN  1 /* inside word */

/* a program for counting words in a file */
int
main(void)
{
	int c;
	int char_count;
	int state;
	int word_count;

	char_count = word_count = 0;
	state = OUT; /* assume outside word */
	while ((c = getchar()) != EOF) {
		++char_count; /* always increase char_count */ 
		/* if encounter space set state to out */
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) { /* or if it is not space and it was already out */
			/* increase word count */ 
			++word_count;
			state = IN;
		}
	}
	printf("word count: %d; char count: %d\n", word_count, char_count);
	return 0;
}
