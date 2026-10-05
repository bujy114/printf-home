#include "ft_printf.h"

int main(void)
{
	char *s = "I am bujy";
	char c = '$';
	int i = 123456;

	ft_printf("%s", s);
	ft_printf("\n");
	ft_printf("%c", c);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");
}
