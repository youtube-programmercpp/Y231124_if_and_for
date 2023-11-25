#include <stdio.h>
void sample_false()
{
	//数値が 0 であれば偽（false）
	if (0)
		puts("A");
	else
		puts("B");

	// double 型でも同じ
	if (.0)
		puts("A");
	else
		puts("B");

	// char 型でも同じ
	if (*"")
		puts("A");
	else
		puts("B");

	// '\0' は char 型の 0　【C++の場合】
	if ('\0')
		puts("A");
	else
		puts("B");

	// nullptr は偽となる 【C++の場合】
	if (nullptr)
		puts("A");
	else
		puts("B");

	//メンバ変数の相対アドレス
	//メンバ関数のアドレス
	struct C {
		int d;
		void e()
		{
		}
	};
	int C::* p = nullptr; //nullptrを 0 としてしまうと &C::d と区別がつかなくなる。よって、ここでの p の内部値は非 0 となる
	if (p)
		puts("A");
	else
		puts("B");
	auto q = &C::e;
	if (q)
		puts("A");
	else
		puts("B");
}
