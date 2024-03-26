/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cluster.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:35:52 by diogmart          #+#    #+#             */
/*   Updated: 2024/03/26 11:43:05 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"
#include "Parser.hpp"
#include "TcpServer.hpp"
#include "Config.hpp"

class Cluster {
	
	private:
		Cluster();
		~Cluster();
		
		static std::vector<TcpServer*> m_servers;
		static std::vector<int> m_serverSockets;
		static std::map<int, TcpServer*> m_fdToServer;
		static std::vector<Config> m_configs;
		
		static void serversLoop(void);

	public:
		static void startServers(const std::vector<Config>& configs);
		static void deleteServers(void);

};
