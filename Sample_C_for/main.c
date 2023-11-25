#include <stdio.h>
#include <ctype.h>
int f()
{
	printf("続けますか? Y/N : ");
	for (;;) {
		switch (toupper(getchar())) {
		case 'Y':
			return 1;
		case 'N':
			return 0;
		default:
			continue;
		}
	}
}
int main()
{
	//comma operator
	// sequential evaluation operator
	// 順次評価演算子
	// A, B
	for (puts("１"); puts("２"), f(); puts("３"))
		puts("４");
}
