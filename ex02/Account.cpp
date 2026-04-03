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
	std::time_t arg;
	time(&arg);
	std::tm *local = localtime(&arg);
	std::stringstream ss;
	std::string timestamp;

	ss << "[" << local->tm_year + 1900 << ((local->tm_mon + 1) < 10 ? "0" : "") << (local->tm_mon + 1)
				<< (local->tm_mday < 10 ? "0" : "") << local->tm_mday << "_"
				<< (local->tm_hour < 10 ? "0" : "") << local->tm_hour
				<< (local->tm_min < 10 ? "0" : "") << local->tm_min
				<< (local->tm_sec < 10 ? "0" : "") << local->tm_sec << "]";
	timestamp = ss.str();
	std::string logfile(timestamp, 1, 15);
	logfile += ".log";
	std::FILE *fd = fopen(logfile.c_str(), "w");
	std::size_t wb = fwrite(timestamp.c_str(), 1, timestamp.length(), fd);
	(void)wb;
	fclose(fd);
	

}

int main(void) {
	Account::_displayTimestamp();
	return (0);
 }
