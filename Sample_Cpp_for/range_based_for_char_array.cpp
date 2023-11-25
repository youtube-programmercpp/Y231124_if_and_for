#include <stdio.h>
#include <ctype.h>
void range_based_for_char_array()
{
	for (char ch : "ABC\0DEF") {
		printf
		( "%c\t%d\n"
		, isgraph(ch)
			? ch
			: ' '
		, ch
		);
	}
}
