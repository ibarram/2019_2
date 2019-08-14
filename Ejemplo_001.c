#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10;
	int b = -250;
	int n = 4;
	printf("%d\t%d\n", a, b);
	printf("%+d\t%+d\n", a, b);
	printf("%05d\t%05d\n", a, b);
	printf("%0*d\t%0*d\n", 5, a, 5, b);
	printf("%0*d\t%0*d\n", n, a, n, b);
	printf("%0*d\t%0*d\n", n-2, a, n-2, b);
	printf("%d%+di\n", a, b);
	printf("%d%+di\n", b, a);
	return 0;
}