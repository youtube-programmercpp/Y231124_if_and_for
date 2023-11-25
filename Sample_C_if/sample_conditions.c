#include <stdio.h>
void sample_conditions()
{
	//等しい、等しくない
	const int a = 0 == 0;
	const int b = 0 != 0;
	const int c = sample_conditions == sample_conditions;
	const int d = sample_conditions != sample_conditions;

	//大小関係
	const int e = 0 < 0;
	const int f = 0 > 0;
	const int g = 0 <= 0;
	const int h = 0 >= 0;

	//ポインタ
	static const char s[] = "ABCDEFG";
	const int i = &s[0] == &s[1];
	const int j = &s[0] != &s[1];
	const int k = &s[0] <  &s[1];
	const int l = &s[0] >  &s[1];
	const int m = &s[0] <= &s[1];
	const int n = &s[0] >= &s[1];
}
