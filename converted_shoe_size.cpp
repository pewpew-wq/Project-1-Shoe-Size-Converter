#include "converted_shoe_size.hpp"
#include "convert_children_size.cpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include "convert_women_size.cpp"
#include "convert_men_size.cpp"

using namespace std;

double convert_shoe_size(double size, string from_shoesize, string to_shoesize) {
    string category = from_shoesize;

    while (true) {
        if (category == "women_us" || category == "women_eu" || category == "women_asia") {
            return convert_women_size(size, from_shoesize, to_shoesize);
        }
        else if (category == "men_us" || category == "men_eu" || category == "men_asia") {
            return convert_men_size(size, from_shoesize, to_shoesize);
        }
        else if (category == "children_us" || category == "children_eu" || category == "children_asia") {
            return convert_children_size(size, from_shoesize, to_shoesize);
        }
        else {
            std::cin >> from_shoesize;
            std::cout << left << "Invalid try again. Convert between: \n" << setfill(' ') << setw(14) << "women_us" << setfill(' ') << setw(10) << "men_us" << setfill(' ') << setw(15) << "children_us" << setfill(' ') << setw(15) << "\nwomen_eu" << setfill(' ') << setw(10) << "men_eu" << setfill(' ') << setw(20) << "children_eu" << setfill(' ') << setw(15) << "\nwomen_asia" << setfill(' ') << setw(10) << "men_asia" << setfill(' ') << setw(20) << "children_asia" << endl;
            std::cin.clear();
            break;
        }
    }
}