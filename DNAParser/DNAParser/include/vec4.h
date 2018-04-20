#ifndef VEC4_H_
#define VEC4_H_

#include "spectrum_element.h"

namespace dnaparser {
	class vec4 : public value_type {
		double left;
		double right;
		double top;
		double bottom;

	public:
		vec4(double left, double top, double right, double bottom) :
			left(left), top(top), right(right), bottom(bottom) {
		}

		vec4(double horizontal, double vertical) :
			left(horizontal), right(horizontal), top(vertical), bottom(vertical) {
		}

		vec4(double val) : left(val), right(val), top(val), bottom(val) {}
	};

}

#endif // !VEC4_H_

