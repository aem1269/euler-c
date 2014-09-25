/*
 * problem4/main.c
 *
 * https://projecteuler.net/problem=4
 * Find the largest palindrome made from the product of two 3-digit numbers
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Determines if a given integer is a palindrome
 *
 * Parameter: num
 * 	The potential palindrome
 * Returns:
 * 	0 if the number is not a palindrome
 * 	A non-zero value otherwise.
 */
int isPalindrome(int num) {
	char* s = malloc(sizeof(char) * 7); /*6 digits and a null terminator*/
	char* front = s;
	char* back = s + 6;
	sprintf(s, "%d", num);

	/* move to the last character */
	while (!(*(--back)));
	while (*front) {
		if (*(front++) != *(back--)) {
			return 0;
		}
	}
	return 1;


}

/*
 * Finds the largest such palindrome and exits successfully
 */
int main() {
	int palindrome = 0;
	printf("Largest palindrome found: %d\n", palindrome);
	exit(EXIT_SUCCESS);
}
