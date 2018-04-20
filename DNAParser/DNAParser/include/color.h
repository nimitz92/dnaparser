#ifndef COLOR_H_
#define COLOR_H

#include <string>
#include <regex>
#include <cstdio>
#include "node.h"
#include "utils/regex_utils.h"

namespace dnaparser {
	class color {
		int r;
		int g;
		int b;
		float a;
		std::string name;

		bool parse_transparent(std::string s) {
			if (regex_utils::contains(s, "transparent")) {
				r = 0;
				b = 0;
				g = 0;
				a = 0;
				name = "transparent";
				return true;
			}
			return false;
		}

		bool parse_rgba(std::string s) {
			if (regex_utils::contains(s, "rgba")) {
				std::sscanf(s.c_str(), "rgba(%d, %d, %d, %f", r, g, b, a);
				return true;
			}
			return false;
		}

		bool parse_rgb(std::string s) {
			if (regex_utils::contains(s, "rgb")) {
				std::sscanf(s.c_str(),"rgb(%d, %d, %d, %f", r, g, b);
				a = 1.0;
				return true;
			}
			return false;
		}

	public:
		bool parse(std::string s) {
			return 
				parse_transparent(s) ||
				parse_rgba(s) ||
				parse_rgb(s);
		}

		std::string print() {

		}
	};

}
#endif // !COLOR_H_

