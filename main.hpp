#ifndef SHOE_SIZE_CONVERTER_HPP
#define SHOE_SIZE_CONVERTER_HPP

#include <vector>
#include <string>

double convert_women_size(double size, std::string from_shoesize, std::string to_shoesize);
double convert_men_size(double size, std::string from_shoesize, std::string to_shoesize);
double convert_children_size(double size, std::string from_shoesize, std::string to_shoesize);
double convert_shoe_size(double size, std::string from_shoesize, std::string to_shoesize);

#endif