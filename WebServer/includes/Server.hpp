/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:39 by kfaustin          #+#    #+#             */
/*   Updated: 2024/02/14 12:09:39 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERVER_HPP
# define SERVER_HPP

#include "webserv.hpp"

/*
	This class should contain all basic configuration needed to start a server,
	the point is that a TcpServer object can be created by passing an instance of
	this class.
*/
class Server {
	
	private:
		Server(void); // Preventing the compiler from creating a default constructor.

		std::map<std::string, std::vector<std::string> > _serverDirectives;
		std::map<std::string, std::map<std::string, std::vector<std::string> > > _locationDirectives;
//		// Variables to store data from the config file
//        std::string m_listen;               // Will give us the port (and protocols ??)
//        std::string m_server_name;          // Server domain name
//        std::string m_host;                 // IP
//        std::string m_root;                 // Root repository for the server files
//        std::string m_index;                // Index page
//        std::string m_charset;              // charset to be used, eg. uft-8
//        std::string m_access_log;           // Where to log accesses
//        std::string m_error_log;            // Where to log errors
//        std::string m_error_page;           // Default error page
//        std::string m_location;             // Where to look for requested files
//        std::string m_client_max_body_size; // Max allowed size of a client request body

	public:
		Server(std::map<std::string, std::vector<std::string> >&,
		        std::map<std::string, std::map<std::string, std::vector<std::string> > >&);
		std::map<std::string, std::vector<std::string> > &getServerDirectives(void);
		std::map<std::string, std::map<std::string, std::vector<std::string> > > &getLocationDirectives(void);
};

#endif //SERVER_HPP