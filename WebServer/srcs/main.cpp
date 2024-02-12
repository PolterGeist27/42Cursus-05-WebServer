/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:36:33 by kfaustin          #+#    #+#             */
/*   Updated: 2024/02/09 12:28:53 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"
#include "Parser.hpp"
#include "TcpServer.hpp"
#include "Config.hpp"

int	main(int argc, char* argv[]) {	
	MLOG("DEBUG"); // Tell us if we are in debug mode
	
	if (argc > 2) {
		MERROR("wrong number of arguments.\nTry: \"./webserv [configuration file]\"");
	}
	
	const std::string config_file(argc == 1 ? "../conf/default.conf" : argv[1]);
	MLOG("Config file path " + config_file);

	Config::initDirectivesVec();

	try {
		Parser::parsingConfigFile(config_file);
	}
	catch (const std::runtime_error& except) {
		std::cerr << except.what() << std::endl;
	}
	
	return (0);
}