int sub_eq(int a, int b);// a == b
int sub_ne(int a, int b);// a != b

int sub_ge(int a, int b);// a >= b
int sub_le(int a, int b);// a <= b
int sub_gt(int a, int b);// a >  b
int sub_lt(int a, int b);// a <  b

#include <stdio.h>
int sub()
{
	printf("a = ");
	int a;
	if (scanf_s("%d", &a) == 1) {
		printf("b = ");
		int b;
		if (scanf_s("%d", &b) == 1) {
#define	Macro(name)	                         \
			printf(#name ":%d\n", name(a, b));
			Macro(sub_eq)// a == b
			Macro(sub_ne)// a != b
			Macro(sub_ge)// a >= b
			Macro(sub_le)// a <= b
			Macro(sub_gt)// a >  b
			Macro(sub_lt)// a <  b
#undef	Macro
			return 1;
		}
	}
	return 0;
}
int main()
{
	while (sub())
		;
}
