#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <vector>
#include <iostream>
#include "utils\regex_utils.h"

namespace dnaparser {
	class node {
	public:
		std::vector<std::string> keys;
		std::string val;

		node(std::vector<std::string> keys, std::string val): keys(keys),val(val) {}
	};

}
#endif // !NODE_H_
