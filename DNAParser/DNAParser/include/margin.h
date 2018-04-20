#ifndef MARGIN_H
#define MARGIN_H

#include <string>
#include <vector>
#include "spectrum_element.h"

namespace dnaparser {
	class margin : public spectrum_element{
		value_type* parse(std::string uval);
	public:
		const static std::string id;
		margin(std::vector<std::string> keys, std::string u_val) :spectrum_element(keys, u_val) {
			val = parse(unparsed_val);
		}
	};
}

#endif // !MARGIN_H
