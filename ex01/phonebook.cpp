/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:57:49 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/03 18:24:26 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) : count(0) {}

void	PhoneBook::MENU(void) {
	std::string input;

	std::cout << "welcome, available commands are: ADD, SEARCH, EXIT" << std::endl;
	while (true) {
		std::getline(std::cin, input);
		if (input == "ADD")
			ADD();
		else if (input == "SEARCH")
			SEARCH();
		else if (input == "EXIT")
		{
			std::cout << "exiting program" << std::endl;
			return ;
		}
		else
			std::cout << "available commands: ADD, SEARCH, EXIT" << std::endl;
	}
}

void	PhoneBook::ADD(void) {
	int		i = 8;

	while (--i)
		contacts[i] = contacts[i - 1];

	contacts[0].first_name = get_input("first name: ");
	contacts[0].last_name = get_input("last name: ");
	contacts[0].nickname = get_input("nickname: ");
	contacts[0].phone_number = get_input("phone number: ");
	if (contacts[0].phone_number.find_first_not_of("+ 0123456789") != std::string::npos)
		std::cout << "interesting phone number :-O" << std::endl;
	contacts[0].darkest_secret = get_input("darkest secret: ");
	if (count < 8)
		++count;
}

void	PhoneBook::SEARCH(void) {
	std::string	input;
	int			err_count = 0;

	std::cout << "index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << std::setw(5) << i + 1;
		std::cout << '|';
		stream_trunc(contacts[i].first_name);
		std::cout << '|';
		stream_trunc(contacts[i].last_name);
		std::cout << '|';
		stream_trunc(contacts[i].nickname);
		std::cout << std::endl;
	}
	std::cout << "type a number from 1 to 8" << std::endl;
	std::getline(std::cin, input);
	while (input.length() != 1 || (input[0] < '1' || input[0] > count + '0'))
	{
		++err_count;
		if (err_count == 3)
		{
			std::cout << "too many fails, return back to menu" << std::endl;
			return ;
		}
		std::cout << "invalid! please retry" << std::endl;
		std::getline(std::cin, input);
	}
	int i = input[0] - 1 - '0';
	std::cout << "first name:" << contacts[i].first_name << std::endl;
	std::cout << "last name:" << contacts[i].last_name << std::endl;
	std::cout << "nickname:" << contacts[i].nickname << std::endl;
	std::cout << "phone number:" << contacts[i].phone_number << std::endl;
	std::cout << "darkest secret:" << contacts[i].darkest_secret << std::endl;
}

void	PhoneBook::stream_trunc(const std::string &s) {

	if (s.length() > 10)
		std::cout.write(s.data(), 9),  std::cout.put('.');
	else
		std::cout.write("          ", 10 - s.length()), std::cout.write(s.data(), s.length());
}

std::string	PhoneBook::get_input(const std::string &prompt) {
	std::string input;

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
	}
}

int	main(void) {
	PhoneBook	pb;

	pb.MENU();
	return (0);
}
