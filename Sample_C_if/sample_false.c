#include <stdio.h>
void sample_false()
{
	//”’l‚ª 0 ‚Å‚ ‚ê‚Î‹Uifalsej
	if (0)
		puts("A");
	else
		puts("B");

	// double Œ^‚Å‚à“¯‚¶
	if (.0)
		puts("A");
	else
		puts("B");

	// char Œ^‚Å‚à“¯‚¶
	if (*"")
		puts("A");
	else
		puts("B");

	// '\0' ‚Í int Œ^‚Ì 0@yCŒ¾Œê‚Ìê‡z
	if ('\0')
		puts("A");
	else
		puts("B");

	// NULL‚Í 0 ‚© (void*)0 yCŒ¾Œê‚Ìê‡z
	if (NULL)
		puts("A");
	else
		puts("B");
}
