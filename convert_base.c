#include "ft_printf.h"

char	*ft_convert_base(unsigned long n, char *base)
{
	char	buffer[65];
	char	*converted_n;
	size_t	i;

	if (base == NULL || !is_valid_base(base))
		return (NULL);
	if (n == 0)
	{
		converted_n = (char *)malloc(sizeof(char) * 2);
		if (converted_n == NULL)
			return (NULL);
		return (converted_n[0] = base[0], converted_n[1] = '\0', converted_n);
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	buffer[i++] = '\0';
	converted_n = (char *)malloc(sizeof(char) * i);
	if (converted_n == NULL)
		return (NULL);
	ft_strlcpy_reverse(converted_n, buffer, i);
	return (converted_n);
}

bool	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == NULL)
		return (false);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (false);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
