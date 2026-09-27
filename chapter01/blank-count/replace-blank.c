#include <stdio.h>

/* turn multiple blank characters into one blank */
int
main(void)
{
	int c, is_blank;

	is_blank = 0;
	while ((c = getchar()) != EOF) {
		/* if normal char print */
		if (c != ' ') {
			printf("%c", c);
			/* and if blank, set is_blank to 0 */
			if (is_blank == 1) {
				is_blank = 0;
			}
		}

		/* if char blank and not already blank, mark blank and print */
		if (c == ' ' && is_blank == 0) {
			is_blank = 1;
			printf("%c", c);
		}
	}
}
