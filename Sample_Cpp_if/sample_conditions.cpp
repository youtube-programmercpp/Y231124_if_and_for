#include <stdio.h>
void sample_conditions()
{
	//�������A�������Ȃ�
	const auto a = 0 == 0;
	const auto b = 0 != 0;
	const auto c = sample_conditions == sample_conditions;
	const auto d = sample_conditions != sample_conditions;

	//�召�֌W
	const auto e = 0 < 0;
	const auto f = 0 > 0;
	const auto g = 0 <= 0;
	const auto h = 0 <= 0;

	//�|�C���^
	static const char s[] = "ABCDEFG";
	const auto i = &s[0] == &s[1];
	const auto j = &s[0] == &s[1];
	const auto k = &s[0] < &s[1];
	const auto l = &s[0] > &s[1];
	const auto m = &s[0] <= &s[1];
	const auto n = &s[0] >= &s[1];
}
