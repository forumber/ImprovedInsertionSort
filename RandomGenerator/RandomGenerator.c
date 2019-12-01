#pragma warning(disable:4996) // remove security warnings on VS
#pragma warning(disable:6031) // remove return is ignored warnings on VS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	int n;
	int i;

	if (argc != 2) {
		printf("Usage: RandomGenerator <size of array>\n");
		return 0;
	}

	srand(time(NULL));

	sscanf(argv[1], "%d", &n);

	printf("%d\n", n);

	for (i = 0; i < n; i++)
		printf("%d\n", rand());

}