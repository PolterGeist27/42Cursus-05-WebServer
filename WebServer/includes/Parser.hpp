/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:00:15 by kfaustin          #+#    #+#             */
/*   Updated: 2024/02/07 15:47:06 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"

/*
    Block Structure:
     - The configuration is organized into blocks denoted by curly braces {}.
     - Each block typically represents a specific context or section of the server configuration.

    Directives:
     - Inside each block, there are directives that specify configuration settings for that particular context.
     	Directives are followed by values or arguments.
     - The line ends with ;

    Comments:
     - Lines starting with # are comments, and they are ignored by the configuration parser.
     - Comments are used for providing additional information or commenting out certain settings.

    Key Directives:
        listen: Specifies the port on which the server should listen.
        server_name: Specifies the server's name.
        host: Specifies the server's host IP address.
        root: Specifies the document root for the server.
        index: Specifies the default file to be served when a directory is requested.
        error_page: Specifies the error page for a given HTTP status code.

    Nested Locations:
     - The configuration includes nested location blocks, which define settings for specific URL paths.
     - Each location block can have its own set of directives.

    Conditional Directives:
        The # client_max_body_size 3000000; line is commented out, indicating it is not currently active. This is an example of a conditional setting.

    Special Directives:
        return: Specifies a redirect or return action for a specific location.
        allow_methods: Specifies the allowed HTTP methods.
        autoindex: Controls directory listing.
*/


class Parser {
	private:
	Parser(void);
	~Parser(void);
	static std::map<std::string, std::vector<std::string> >	_directives;
	static std::map<std::string, std::map<std::string, std::vector<std::string> > > _locations;

	public:
		static void parsingConfigFile(const std::string& config_file);
		static void parsingDirectives(const std::string& directive, std::vector<std::string>& vec);
		static void parsingLocationBlock(std::vector<std::string>&);
};