#include <iostream>
#include <string>	

int main (int ac, char **av)
{
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);

	for (int i = 1; i < ac; i++)
	{
		std::string	s = av[i];
		for (size_t j = 0; j < s.length(); j++)
		{
			if (s[j] >= 'a' && s[j] <= 'z')
				s[j] -= 32;
		}
		std::cout << s;
	}
	return (std::cout << std::endl, 0);
}

