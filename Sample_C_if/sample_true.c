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
}
