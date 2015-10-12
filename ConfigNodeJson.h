#ifndef CONFIG_H_
#define CONFIG_H_
#include <sstream>
#include <stdint.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "ConfigNodeBase.cpp"
#include <memory>
#include <map>
#include <vector>
#endif
#include "jsoncpp/json/json.h"


typedef std::shared_ptr<std::multimap<ConfigNode*,ConfigNode*> > ConfigNodeMap;
typedef std::pair<std::string, std::string>	strPair;

class ConfigNodeJson : public ConfigNodeBase
{
	public:
		ConfigNodeJson(): ConfigNodeBase(){};
		/**
		 * Reading XML or JSON file into our config structure.
		 * @param filename path to the file.
		 * @return true, if file was read successfully; false, otherwise.
		 */
		bool load(const std::string& filename);

	private:
		void    nextNode(const Json::Value &root, ConfigNode* parentNode);
		//ConfigNode*	top;
};
