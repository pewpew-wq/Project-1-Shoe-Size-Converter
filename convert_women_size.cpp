#include "convert_women_size.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


double convert_women_size(double size, std::string from_shoesize, std::string to_shoesize) {
    vector<double> women_us_sizes = { 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12 };
    vector<double> women_eu_sizes = { 32.5, 33, 33.5, 34, 34.5, 35.5, 36.5, 37, 37.5, 38, 38.5, 39, 39.5, 40, 41, 42, 42.5, 43, 45 };
    vector<double> women_asia_sizes = { 19, 20, 20.5, 21, 21.5, 22, 22.5, 23, 23.5, 24, 24.5, 25, 25.5, 26, 26.5, 27, 27.5, 28, 28 };


    int index = -1;
    if (from_shoesize == "women_us") {
        index = distance(women_us_sizes.begin(), lower_bound(women_us_sizes.begin(), women_us_sizes.end(), size));
    }
    else if (from_shoesize == "women_eu") {
        index = distance(women_eu_sizes.begin(), lower_bound(women_eu_sizes.begin(), women_eu_sizes.end(), size));
    }
    else if (from_shoesize == "women_asia") {
        index = distance(women_asia_sizes.begin(), lower_bound(women_asia_sizes.begin(), women_asia_sizes.end(), size));
    }

    if (index < 0 || index >= women_us_sizes.size()) {
        cout << "size exceeded conversion rate " << from_shoesize << "maximum size is US-12, EU-45, and Asia-28" << endl;
        return 0.0;
    }


    if (to_shoesize == "women_us") {
        return women_us_sizes[index];
    }
    else if (to_shoesize == "women_eu") {
        return women_eu_sizes[index];
    }
    else if (to_shoesize == "women_asia") {
        return women_asia_sizes[index];
    }

    cout << "Invalid. Convert between: \nwomen_us \nwomen_eu \nwomen_asia" << endl;
    return 0.0;
}
