#include "margin.h"
#include "vec4.h"
#include "utils\regex_utils.h"

namespace dnaparser {
	const std::string margin::id = "margin";

	value_type* margin::parse(std::string uval) {
		std::string s = keys[keys.size() - 1];
		int value = std::stoi(uval);
		
		if (regex_utils::ends_with(s, id)) {
			return new vec4(value);
		}

		if (regex_utils::ends_with(s, "-x")) {

		}
	}


}