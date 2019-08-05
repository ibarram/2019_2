#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10, b = -5;
	printf("%-d\t%-d\n", a, b);	
	printf("%+d\t%+d\n", a, b);
	printf("% d\t% d\n", a, b);
	printf("%#d\t%#d\n", a, b);
	printf("%03d\t%03d\n", a, b);
	return 0;
}