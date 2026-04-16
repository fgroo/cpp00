/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:57:49 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/16 22:33:10 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

	contacts[0].setFirstName(get_input("first name: "));
	contacts[0].setLastName(get_input("last name: "));
	contacts[0].setNickname(get_input("nickname: "));
	contacts[0].setPhoneNumber(get_input("phone number: "));
	if (contacts[0].getPhoneNumber().find_first_not_of("+ 0123456789") != std::string::npos)
		std::cout << "interesting phone number :-O" << std::endl;
	contacts[0].setDarkestSecret(get_input("darkest secret: "));
	if (count < 8)
		++count;
}

void	PhoneBook::SEARCH(void) {
	std::string	input;
	int			err_count = 0;

	if (!count)
		return (std::cout << "no contacts yet" << std::endl, void());
	std::cout << "index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << std::setw(5) << i + 1;
		std::cout << '|';
		stream_trunc(contacts[i].getFirstName());
		std::cout << '|';
		stream_trunc(contacts[i].getLastName());
		std::cout << '|';
		stream_trunc(contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "type a number from 1 to " << count << std::endl;
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
	std::cout << "first name:" << contacts[i].getFirstName() << std::endl;
	std::cout << "last name:" << contacts[i].getLastName() << std::endl;
	std::cout << "nickname:" << contacts[i].getNickname() << std::endl;
	std::cout << "phone number:" << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "darkest secret:" << contacts[i].getDarkestSecret() << std::endl;
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
