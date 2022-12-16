/// @file interval.cpp
/// @brief Implementation of the interval class
/// @author George Downing
/// @date 16-12-2022
/// @details This file contains the implementation of the interval class. This class performs interval arithmetic on two intervals by overloading the operators +, -, *, /, +=, -=, *=, /=, <<, >>.
/// @details Doxygen documentation: https://georgedowning20.github.io/The-Interval-Arithmetic-Project/files.html

//---------------------------------------------------------------------------------------------------------------------
//                                                    include files
//---------------------------------------------------------------------------------------------------------------------

#include "interval.h"

//---------------------------------------------------------------------------------------------------------------------
//                                                 class implementation
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
//                                                 interval constructors
//---------------------------------------------------------------------------------------------------------------------

/// @details This constructor initialises a interval object and places the values into the min and max variables.
interval::interval(double min, double max) : Min(min), Max(max) {}

/// @details This constructor initialises a interval object and places the value into the min and max variables.
interval::interval(double val) : Min(val), Max(val) {}

/// @details This constructor initialises a interval object and copies the values from the object passed in.
interval::interval(interval const &obj) : Min(obj.Min), Max(obj.Max) {}

/// @details This constructor initialises a interval object and sets the min and max variables to zero.
interval::interval() = default;

/// @details This destructor destroys the interval object.
interval::~interval() = default;

//---------------------------------------------------------------------------------------------------------------------
//                                                 Private functions
//---------------------------------------------------------------------------------------------------------------------

/// @details This function finds the minimum of four values by comparing each value to the current minimum until all values have been compared.
double interval::find_min(double a, double b, double c, double d)
{
    double min = a; // set min to a
    if (b < min)    // if b is less than min
        min = b;    // set min to b
    if (c < min)    // if c is less than min
        min = c;    // set min to c
    if (d < min)    // if d is less than min
        min = d;    // set min to d
    return min;     // return the minimum value
}

/// @details This function finds the maximum of four values by comparing each value to the current maximum until all values have been compared.
double interval::find_max(double a, double b, double c, double d)
{
    double max = a; // set max to a
    if (b > max)    // if b is greater than max
        max = b;    // set max to b
    if (c > max)    // if c is greater than max
        max = c;    // set max to c
    if (d > max)    // if d is greater than max
        max = d;    // set max to d
    return max;     // return the maximum value
}

//---------------------------------------------------------------------------------------------------------------------
//                                                 basic interval operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the + operator to add two intervals together. A temporary interval is created and the min and max values are added together. the temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator+(interval const &obj)
{
    interval temp; // create a temporary interval

    temp.Min = obj.Min + Min; // add the min values together
    temp.Max = obj.Max + Max; // add the max values together

    return temp; // return the temporary interval
}

/// @details This function overloads the - operator to subtract two intervals together. A temporary interval is created and the min and max values are subtracted together. the temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator-(interval const &obj)
{
    interval temp; // create a temporary interval

    temp.Min = Min - obj.Max; // subtract the max values
    temp.Max = Max - obj.Min; // subtract the min values

    return temp; // return the temporary interval
}

/// @details This function overloads the * operator to multiply two intervals together. A temporary interval is created and all permutations of the min and max values are multiplied together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: #Example/Example.cpp
interval interval::operator*(interval const &obj)
{
    interval temp; // create a temporary interval

    double a = Min * obj.Min; // multiply the min values
    double b = Min * obj.Max; // multiply the min value by the max value
    double c = Max * obj.Min; // multiply the max value by the min value
    double d = Max * obj.Max; // multiply the max values

    temp.Min = find_min(a, b, c, d); // find the minimum value
    temp.Max = find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

/// @details This function overloads the / operator to divide two intervals together. A temporary interval is created and all permutations of the min and max values are divided together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator/(interval const &obj)
{
    interval temp; // create a temporary interval

    double a = Min / obj.Min; // divide the min values
    double b = Min / obj.Max; // divide the min value by the max value
    double c = Max / obj.Min; // divide the max value by the min value
    double d = Max / obj.Max; // divide the max values

    temp.Min = find_min(a, b, c, d); // find the minimum value
    temp.Max = find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

//---------------------------------------------------------------------------------------------------------------------
//                                                 compound interval operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the += operator to add and assign an interval to another interval. The min and max values are added to the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator+=(interval const &obj)
{
    Min += obj.Min; // add the min values together
    Max += obj.Max; // add the max values together

    return *this; // return the interval
}

/// @details This function overloads the -= operator to subtract and assign an interval to another interval. The min and max values are subtracted from the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator-=(interval const &obj)
{
    Min -= obj.Max; // subtract the max values
    Max -= obj.Min; // subtract the min values

    return *this; // return the interval
}

/// @details This function overloads the *= operator to multiply and assign an interval to another interval. All permutations of the min and max values are multiplied together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator*=(interval const &obj)
{
    double a = Min * obj.Min; // multiply the min values
    double b = Min * obj.Max; // multiply the min value by the max value
    double c = Max * obj.Min; // multiply the max value by the min value
    double d = Max * obj.Max; // multiply the max values

    Min = find_min(a, b, c, d); // find the minimum value
    Max = find_max(a, b, c, d); // find the maximum value

    return *this; // return the interval
}

/// @details This function overloads the /= operator to divide and assign an interval to another interval. All permutations of the min and max values are divided together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator/=(interval const &obj)
{
    double a = Min / obj.Min; // divide the min values
    double b = Min / obj.Max; // divide the min value by the max value
    double c = Max / obj.Min; // divide the max value by the min value
    double d = Max / obj.Max; // divide the max values

    Min = find_min(a, b, c, d); // find the minimum value
    Max = find_max(a, b, c, d); // find the maximum value

    return *this; // return the interval
}

//---------------------------------------------------------------------------------------------------------------------
//                                                interval double operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the + operator to add a double to a interval. A temporary interval is created and the value of the double is added to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator+(double const &obj)
{
    interval temp; // create a temporary interval

    temp.Min = Min + obj; // add the min value to the double
    temp.Max = Max + obj; // add the max value to the double

    return temp; // return the temporary interval
}

/// @details This function overloads the - operator to subtract a double from a interval. A temporary interval is created and the value of the double is subtracted from the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator-(double const &obj)
{
    interval temp; // create a temporary interval

    temp.Min = Min - obj; // subtract the double from the min value
    temp.Max = Max - obj; // subtract the double from the max value

    return temp; // return the temporary interval
}

/// @details This function overloads the * operator to multiply a double by a interval. A temporary interval is created and all permutations of the min and max values are multiplied together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator*(double const &obj)
{
    interval temp; // create a temporary interval

    double a = Min * obj; // multiply the min value by the double
    double b = Max * obj; // multiply the max value by the double
    double c = Min * obj; // multiply the min value by the double
    double d = Max * obj; // multiply the max value by the double

    temp.Min = find_min(a, b, c, d); // find the minimum value
    temp.Max = find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

/// @details This function overloads the / operator to divide a double by a interval. A temporary interval is created and all permutations of the min and max values are divided together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval interval::operator/(double const &obj)
{
    interval temp; // create a temporary interval

    double a = Min / obj; // divide the min value by the double
    double b = Max / obj; // divide the max value by the double
    double c = Min / obj; // divide the min value by the double
    double d = Max / obj; // divide the max value by the double

    temp.Min = find_min(a, b, c, d); // find the minimum value
    temp.Max = find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

//---------------------------------------------------------------------------------------------------------------------
//                                                interval double compound operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the += operator to add and assign a double to an interval. The double is added to the min and max values of the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator+=(double const &obj)
{
    Min += obj; // add the double to the min value
    Max += obj; // add the double to the max value

    return *this; // return the interval
}

/// @details This function overloads the -= operator to subtract and assign a double from an interval. The double is subtracted from the min and max values of the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator-=(double const &obj)
{
    Min -= obj; // subtract the double from the min value
    Max -= obj; // subtract the double from the max value

    return *this; // return the interval
}

/// @details This function overloads the *= operator to multiply and assign a double to an interval. All permutations of the min and max values are multiplied together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator*=(double const &obj)
{
    double a = Min * obj; // multiply the min value by the double
    double b = Max * obj; // multiply the max value by the double
    double c = Min * obj; // multiply the min value by the double
    double d = Max * obj; // multiply the max value by the double

    Min = find_min(a, b, c, d); // find the minimum value
    Max = find_max(a, b, c, d); // find the maximum value

    return *this; // return the interval
}

/// @details This function overloads the /= operator to divide and assign a double by an interval. All permutations of the min and max values are divided together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the interval. The value of the interval is then assigned to the object that called the operator.
/// @par Test Data: Example/Example.cpp
interval interval::operator/=(double const &obj)
{
    double a = Min / obj; // divide the min value by the double
    double b = Max / obj; // divide the max value by the double
    double c = Min / obj; // divide the min value by the double
    double d = Max / obj; // divide the max value by the double

    Min = find_min(a, b, c, d); // find the minimum value
    Max = find_max(a, b, c, d); // find the maximum value

    return *this; // return the interval
}

//---------------------------------------------------------------------------------------------------------------------
//                                                 double interval operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the + operator to add a interval to a double. A temporary interval is created and the value of the double is added to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval operator+(double const &obj, interval const &obj2)
{
    interval temp; // create a temporary interval

    temp.Min = obj + obj2.Min; // add the double to the min value
    temp.Max = obj + obj2.Max; // add the double to the max value

    return temp; // return the temporary interval
}

/// @details This function overloads the - operator to subtract a interval from a double. A temporary interval is created and the value of the double is subtracted from the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval operator-(double const &obj, interval const &obj2)
{
    interval temp; // create a temporary interval

    temp.Min = obj - obj2.Max; // subtract the max value from the double
    temp.Max = obj - obj2.Min; // subtract the min value from the double

    return temp; // return the temporary interval
}

/// @details This function overloads the * operator to multiply a interval by a double. A temporary interval is created and all permutations of the min and max values are multiplied together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval operator*(double const &obj, interval const &obj2)
{
    interval temp; // create a temporary interval

    double a = obj * obj2.Min; // multiply the double by the min value
    double b = obj * obj2.Max; // multiply the double by the max value
    double c = obj * obj2.Min; // multiply the double by the min value
    double d = obj * obj2.Max; // multiply the double by the max value

    temp.Min = interval::find_min(a, b, c, d); // find the minimum value
    temp.Max = interval::find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

/// @details This function overloads the / operator to divide a interval by a double. A temporary interval is created and all permutations of the min and max values are divided together. The minimum and maximum values are then found using the #interval::find_min and #interval::find_max functions and written to the temporary interval. The temporary interval is then returned.
/// @par Test Data: Example/Example.cpp
interval operator/(double const &obj, interval const &obj2)
{
    interval temp; // create a temporary interval

    double a = obj / obj2.Min; // divide the double by the min value
    double b = obj / obj2.Max; // divide the double by the max value
    double c = obj / obj2.Min; // divide the double by the min value
    double d = obj / obj2.Max; // divide the double by the max value

    temp.Min = interval::find_min(a, b, c, d); // find the minimum value
    temp.Max = interval::find_max(a, b, c, d); // find the maximum value

    return temp; // return the temporary interval
}

//---------------------------------------------------------------------------------------------------------------------
//                                                 ios interval operators
//---------------------------------------------------------------------------------------------------------------------

/// @details This function overloads the << operator to print an interval to an ostream. The min and max values of the interval are printed to the ostream. The ostream is then returned.
/// @par Test Data: Example/Example.cpp
std::ostream &operator<<(std::ostream &os, interval const &obj)
{
    os << "[" << obj.min() << ", " << obj.max() << "]"; // print the interval
    return os;                                          // return the ostream
}

/// @details This function overloads the >> operator to read an interval from an istream. The min and max values of the interval are read from the istream. The interval is then set to the min and max values. The istream is then returned.
/// @par Test Data: Example/Example.cpp
std::istream &operator>>(std::istream &is, interval &obj)
{
    double min, max;          // create variables for the min and max values
    is >> min >> max;         // read the min and max values
    obj = interval(min, max); // set the interval to the min and max values
    return is;                // return the istream
}
