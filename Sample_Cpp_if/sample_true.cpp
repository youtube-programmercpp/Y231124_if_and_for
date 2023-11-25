#include <stdio.h>
void sample_true()
{
	//数値が 0 以外 であれば真（true）
	if (12345)
		puts("A");
	else
		puts("B");

	// double 型でも同じ
	if (3 / 2.)
		puts("A");
	else
		puts("B");

	// char 型でも同じ
	if (*"X")
		puts("A");
	else
		puts("B");

	//ポインタでも同じ（0番地は有効なアドレスではないものとしている）
	//文字列
	if ("")
		puts("A");
	else
		puts("B");
	//関数アドレス
	if (sample_true)
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
	if (&C::d) //相対アドレスとしては 0 となるが非nullptr、つまり真となる
		puts("A");
	else
		puts("B");
	if (&C::e)
		puts("A");
	else
		puts("B");

	//演算子のオーバーロード
	struct X {
		int a;
		int b;
		explicit operator bool() const noexcept
		{
			return a || b;
		}
	};
	if (X{ 0, 1 })
		puts("A");
	else
		puts("B");

	//古いスタイル
	struct Y {
		int a;
		int b;
		operator const void* () const /*noexcept*/
		{
			return a || b ? this : NULL;
		}
	};
	if (Y{ 2, 3 })
		puts("A");
	else
		puts("B");
}
