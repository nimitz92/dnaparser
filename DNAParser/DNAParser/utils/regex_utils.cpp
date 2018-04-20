#include "regex_utils.h"

namespace dnaparser {
	namespace regex_utils {
		bool begins_with(std::string src, std::string target) {
			return (src.compare(0, target.length(), target) == 0);
		}

		bool ends_with(std::string src, std::string target) {
			if (target.size() > src.size()) return false;
			return std::equal(target.rbegin(), target.rend(), src.rbegin());
		}

		bool contains(std::string src, std::string target) {
			return (src.find(target) != std::string::npos);
		}
	}
}