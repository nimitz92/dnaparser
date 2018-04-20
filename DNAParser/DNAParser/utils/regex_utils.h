#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <string>

namespace dnaparser {
	namespace regex_utils {
		bool begins_with(std::string src, std::string target);
		bool ends_with(std::string src, std::string target);
		bool contains(std::string src, std::string target);
	}
}
#endif // !REGEX_UTILS_H

