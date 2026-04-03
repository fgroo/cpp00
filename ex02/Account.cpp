// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United       		          //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : fgroo <student@42.eu>            			      //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"
#include <cstdio>
#include <sstream>

void Account::_displayTimestamp(void) {

	char	timestamp[18];
	std::time_t	time = std::time(NULL);

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", std::localtime(&time));

	std::string logfile(timestamp, 1, 15);
	logfile += ".log";
	std::FILE *fd = fopen(logfile.c_str(), "w");
	std::size_t wb = fwrite(timestamp, 1, 17, fd);
	(void)wb;
	fclose(fd);

}

int main(void) {
	Account::_displayTimestamp();
	return (0);
 }
