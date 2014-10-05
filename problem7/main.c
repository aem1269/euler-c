/*
 * problem7/main.c
 *
 * https://projecteuler.net/problem=7
 * What is the 10 001st prime number?
 */
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"
#define NUMBER_OF_PRIMES (10001)

/*
 * Print out the 10 001st prime and then exit
 */
int main() {
	int prime = getPrime(NUMBER_OF_PRIMES);
	printf("10,001st prime: %d\n", prime);
}
