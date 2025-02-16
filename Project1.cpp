#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


double convert_women_size(double size, string from_shoesize, string to_shoesize) {
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
            //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}


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