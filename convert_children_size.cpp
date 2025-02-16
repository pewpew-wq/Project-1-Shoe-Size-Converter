#include "convert_children_size.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


double convert_children_size(double size, string from_shoesize, string to_shoesize) {
    vector<double> us_sizes = { 11, 11.5, 12, 12.5, 13, 13.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7 };
    vector<double> eu_sizes = { 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 35, 36, 36, 37, 38, 39, 40, 41 };
    vector<double> asia_sizes = { 18, 18.5, 18.5, 19, 19.5, 20, 20.5, 21, 21.5, 21.5, 22, 22.5, 23, 23.5, 24, 24.5, 25, 25.5, 26 };

    int index = -1;
    if (from_shoesize == "children_us") {
        index = distance(us_sizes.begin(), lower_bound(us_sizes.begin(), us_sizes.end(), size));
    }
    else if (from_shoesize == "children_eu") {
        index = distance(eu_sizes.begin(), lower_bound(eu_sizes.begin(), eu_sizes.end(), size));
    }
    else if (from_shoesize == "children_asia") {
        index = distance(asia_sizes.begin(), lower_bound(asia_sizes.begin(), asia_sizes.end(), size));
    }

    if (index < 0 || index >= us_sizes.size()) {
        std::cout << "size exceeded conversion rate " << from_shoesize << " maximum size is US-7, EU-39, and Asia-38" << endl;
        return 0.0;
    }

    if (to_shoesize == "children_us") {
        return us_sizes[index];
    }
    else if (to_shoesize == "children_eu") {
        return eu_sizes[index];
    }
    else if (to_shoesize == "children_asia") {
        return asia_sizes[index];
    }

    std::cout << "Invalid. Convert between: \nchildren_eu \nchildren_us \nchildren_asia" << endl;
    return 0.0;
}
