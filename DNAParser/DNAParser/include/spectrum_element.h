#ifndef SPECTRUM_ELEMENTS_H_
#define SPECTRUM_ELEMENTS_H_

#include <string>
#include <memory>

#include "node.h"

namespace dnaparser {

	class value_type{};

	class spectrum_element {
	protected:
		std::vector<std::string> keys;
		std::string unparsed_val;
		value_type* val;

	public:
		spectrum_element(std::vector<std::string> keys, std::string u_val): keys(keys), unparsed_val(u_val) {}



	};
	
}
#endif // !SPECTRUM_ELEMENTS_H_

