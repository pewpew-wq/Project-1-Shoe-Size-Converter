#ifndef SHOE_SIZE_CONVERTER_HPP
#define SHOE_SIZE_CONVERTER_HPP

#include "convert_women_size.hpp"
#include "convert_men_size.hpp"
#include "convert_children_size.hpp"
#include <string>

double convert_shoe_size(double size, std::string from_shoesize, std::string to_shoesize);

#endif
