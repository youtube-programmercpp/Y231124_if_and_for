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

	// '\0' は int 型の 0　【C言語の場合】
	if ('\0')
		puts("A");
	else
		puts("B");

	// NULLは 0 か (void*)0 【C言語の場合】
	if (NULL)
		puts("A");
	else
		puts("B");
}
