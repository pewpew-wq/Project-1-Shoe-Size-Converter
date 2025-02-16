#include "converted_shoe_size.hpp"
#include "convert_men_size.hpp"
#include "convert_women_size.hpp"
#include "convert_children_size.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    double size;
    string from_shoesize, to_shoesize;

    while (true) {
        std::cout << "Convert Womens, Mens, and Children shoe sizes between US, EU, and Asia! \nEnter the shoe size you want to convert: " << endl;
        std::cin >> size;

        if (std::cin.fail() || size <= 0.0 || size > 61) {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "invalid shoe size. \n US sizes range from: 3-7(children) ; 3-12(women) ; 4-15(men) \n EU sizes range from: 18-39(children) ; 32.5-45(women) ; 39-61(men) \n Asia sizes range from 17-38(children) ; 19-28(women) ; 22-33(men) \n \n";
        }
        else {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    std::cout << "Enter the country of origin (type exactly: women_us, women_eu, women_asia / men_us, men_eu, men_asia / children_us, children_eu, children_asia): " << endl;
    std::cin >> from_shoesize;

    std::cout << "Enter the desired country (type exactly: women_us, women_eu, women_asia / men_us, men_eu, men_asia / children_us, children_eu, children_asia): ";
    std::cin >> to_shoesize;

    double converted_size = convert_shoe_size(size, from_shoesize, to_shoesize);

    if (converted_size < 61 && converted_size > 0) {
        std::cout << "Converted size: " << fixed << setprecision(1) << converted_size << endl;
    }
    else {
        cin.clear();
        cin.ignore();
    }

    return 0;
}