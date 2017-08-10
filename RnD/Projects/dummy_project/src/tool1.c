#include <stdio.h>
#include <stdlib.h>

#include "libtest1.h"
#include "libtest2.h"

int main(int argc, char *argv[])
{
	int i = 5, j = 10;

	printf("%s: Started\n", argv[0]);

	printf ("ltest1_func1() check:\t%d + %d = %d\n", i, j, ltest1_func1(i, j));
	printf ("ltest2_func1() check:\t%d + %d = %d\n", i, j, ltest2_func1(i, j));
	return 0;
}
