#include "convert_men_size.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


double convert_men_size(double size, string from_shoesize, string to_shoesize) {
    vector<double> men_us_sizes = { 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12, 12.5, 13, 13.5, 14, 14.5, 15 };
    vector<double> men_eu_sizes = { 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61 };
    vector<double> men_asia_sizes = { 22, 22.5, 23, 23.5, 24, 24.5, 25, 25.5, 26, 26.5, 27, 27.5, 28, 28.5, 29, 29.5, 30, 30.5, 31, 31.5, 32, 32.5, 33 };

    int index = -1;
    if (from_shoesize == "men_us") {
        index = distance(men_us_sizes.begin(), lower_bound(men_us_sizes.begin(), men_us_sizes.end(), size));
    }
    else if (from_shoesize == "men_eu") {
        index = distance(men_eu_sizes.begin(), lower_bound(men_eu_sizes.begin(), men_eu_sizes.end(), size));
    }
    else if (from_shoesize == "men_asia") {
        index = distance(men_asia_sizes.begin(), lower_bound(men_asia_sizes.begin(), men_asia_sizes.end(), size));
    }

    if (index < 0 || index >= men_us_sizes.size()) {
        cout << "size exceeded conversion rate " << from_shoesize << " maximum size is US-15, EU-61, and Asia-33" << endl;
        return 0.0;
    }

    if (to_shoesize == "men_us") {
        return men_us_sizes[index];
    }
    else if (to_shoesize == "men_eu") {
        return men_eu_sizes[index];
    }
    else if (to_shoesize == "men_asia") {
        return men_asia_sizes[index];
    }


    cout << "Invalid. Convert between: \nmen_us \nmen_eu \nmen_asia" << endl;
    return 0.0;
}