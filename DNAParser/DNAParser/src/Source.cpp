#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include "nlohmann\json.hpp"
#include "keys.h"
#include "node.h"

using namespace std;
using namespace dnaparser;

void iterate_json(queue<pair<nlohmann::json, vector<string>>>& q, vector<std::shared_ptr<node>>& vals) {
	vector<string> keys;
	while (!q.empty()) {
		nlohmann::json j = q.front().first;
		for (auto i = j.begin(); i != j.end(); ++i) {
			if (dnaparser::unKnownKeys.find(i.key()) == dnaparser::unKnownKeys.end()) {
				if (i.value().is_object() || i.value().is_array()) {
					keys = q.front().second;
					keys.push_back(i.key());
					q.push({ i.value(), keys });
				}
				else if (i.value().is_primitive()) {
					keys = q.front().second;
					keys.push_back(i.key());
					vals.push_back(make_shared<node>(keys, i.value().dump()));
				}
			}
		}
		q.pop();
	}
}

vector<std::shared_ptr<node>> json_parser(std::istream& stream) {
	nlohmann::json j;
	stream >> j;
	queue<pair<nlohmann::json, vector<string>>> q;
	q.push({ j, vector<string>() });
	vector<std::shared_ptr<node>> vals;
	iterate_json(q, vals);
	return vals;
}

int main() {
	ifstream input("data\\data.json");
	auto vals = json_parser(input);

	for (auto& i : vals) {
		parse(i);
	}
}

