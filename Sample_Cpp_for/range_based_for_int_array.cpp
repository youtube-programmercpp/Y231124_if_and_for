#include <stdio.h>
void range_based_for_int_array()
{
	int a[] = { 1, 10, 100, 1000 };
	for (auto n : a) {
		printf("%d\n", n);
	}
}
