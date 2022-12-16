/// @file interval.h
/// @brief Interval arithmetic class
/// @author George Downing
/// @date 16-12-2022
/// @version 1.0
/// @details This file declares thh interval arithmetic class. its purpose it to perform interval arithmetic on two intervals by overloading the operators +, -, *, /, +=, -=, *=, /=, <<, >>.

//---------------------------------------------------------------------------------------------------------------------
//                                                 #includes
//---------------------------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>

//---------------------------------------------------------------------------------------------------------------------
//                                                 class declaration
//---------------------------------------------------------------------------------------------------------------------

/// @brief Interval arithmetic
/// @details This class performs interval arithmetic on two intervals by overloading the operators +, -, *, /, +=, -=, *=, /=, <<, >>.
/// @author George Downing
/// @date 16-12-2022
class interval
{
public:
    //---------------------------------------------------------------------------------------------------------------------
    //                                              Global Read only access to interval
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Gets the minimum value of the interval
    /// @return the minimum value of the interval
    double min() const { return Min; }

    /// @brief Gets the maximum value of the interval
    /// @return the maximum value of the interval
    double max() const { return Max; }

    //---------------------------------------------------------------------------------------------------------------------
    //                                                 interval constructors
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Constructor for interval with two values
    /// @param min the minimum value of the interval
    /// @param max the maximum value of the interval
    interval(double min, double max);

    /// @brief Constructor for interval with one value
    /// @param val the value of the interval both min and max
    interval(double val);

    /// @brief Copy constructor for interval
    /// @param obj the interval to copy
    interval(interval const &obj);

    /// @brief Default constructor for interval
    interval();

    /// @brief Destructor for interval
    ~interval();

    //---------------------------------------------------------------------------------------------------------------------
    //                                                 basic interval operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload for addition of two intervals
    /// @param obj the interval to add to this interval
    /// @return the sum of the two intervals as a new interval
    interval operator+(interval const &obj);

    /// @brief Operator overload for subtraction of two intervals
    /// @param obj the interval to subtract from this interval
    /// @return the difference of the two intervals as a new interval
    interval operator-(interval const &obj);

    /// @brief Operator overload for multiplication of two intervals
    /// @param obj the interval to multiply this interval by
    /// @return the product of the two intervals as a new interval
    interval operator*(interval const &obj);

    /// @brief Operator overload for division of two intervals
    /// @param obj the interval to divide this interval by
    /// @return the quotient of the two intervals as a new interval
    interval operator/(interval const &obj);

    //---------------------------------------------------------------------------------------------------------------------
    //                                                 compound interval operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload for addition AND assignment of an interval
    /// @param obj the interval to add to this interval
    /// @return the sum of the two intervals as a new interval
    interval operator+=(interval const &obj);

    /// @brief Operator overload for subtraction AND assignment of an interval
    /// @param obj the interval to subtract from this interval
    /// @return the difference of the two intervals as a new interval
    interval operator-=(interval const &obj);

    /// @brief Operator overload for multiplication AND assignment of an interval
    /// @param obj the interval to multiply this interval by
    /// @return the product of the two intervals as a new interval
    interval operator*=(interval const &obj);

    /// @brief Operator overload for division AND assignment of an interval
    /// @param obj the interval to divide this interval by
    /// @return the quotient of the two intervals as a new interval
    interval operator/=(interval const &obj);

    //---------------------------------------------------------------------------------------------------------------------
    //                                                interval double operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload for addition of an interval and a double
    /// @param obj the double to add to this interval
    /// @return the sum of the interval and the double as a new interval
    interval operator+(double const &obj);

    /// @brief Operator overload for subtraction of an interval and a double
    /// @param obj the double to subtract from this interval
    /// @return the difference of the interval and the double as a new interval
    interval operator-(double const &obj);

    /// @brief Operator overload for multiplication of an interval and a double
    /// @param obj the double to multiply this interval by
    /// @return the product of the interval and the double as a new interval
    interval operator*(double const &obj);

    /// @brief Operator overload for division of an interval and a double
    /// @param obj the double to divide this interval by
    /// @return the quotient of the interval and the double as a new interval
    interval operator/(double const &obj);

    //---------------------------------------------------------------------------------------------------------------------
    //                                                interval double compound operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload for addition AND assignment of an interval and a double
    /// @param obj the double to add to this interval
    /// @return the sum of the interval and the double as a new interval
    interval operator+=(double const &obj);

    /// @brief Operator overload for subtraction AND assignment of an interval and a double
    /// @param obj the double to subtract from this interval
    /// @return the difference of the interval and the double as a new interval
    interval operator-=(double const &obj);

    /// @brief Operator overload for multiplication AND assignment of an interval and a double
    /// @param obj the double to multiply this interval by
    /// @return the product of the interval and the double as a new interval
    interval operator*=(double const &obj);

    /// @brief Operator overload for division AND assignment of an interval and a double
    /// @param obj the double to divide this interval by
    /// @return the quotient of the interval and the double as a new interval
    interval operator/=(double const &obj);

    //---------------------------------------------------------------------------------------------------------------------
    //                                                 double interval operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload for addition of a double and an interval
    /// @param obj the double to add to this interval
    /// @return the sum of the interval and the double as a new interval
    friend interval operator+(double const &obj, interval const &obj2);

    /// @brief Operator overload for subtraction of a double and an interval
    /// @param obj the double to subtract from this interval
    /// @return the difference of the interval and the double as a new interval
    friend interval operator-(double const &obj, interval const &obj2);

    /// @brief Operator overload for multiplication of a double and an interval
    /// @param obj the double to multiply this interval by
    /// @return the product of the interval and the double as a new interval
    friend interval operator*(double const &obj, interval const &obj2);

    /// @brief Operator overload for division of a double and an interval
    /// @param obj the double to divide this interval by
    /// @return the quotient of the interval and the double as a new interval
    friend interval operator/(double const &obj, interval const &obj2);

    //---------------------------------------------------------------------------------------------------------------------
    //                                                 ios interval operators
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Operator overload to load the output stream object
    /// @param obj the interval to print to the output stream object
    /// @return the output stream object
    friend std::ostream &operator<<(std::ostream &os, interval const &obj);

    /// @brief Operator overload to load the input stream object
    /// @param obj the interval to read from the input stream object
    /// @return the input stream object
    friend std::istream &operator>>(std::istream &is, interval &obj);

private:
    //---------------------------------------------------------------------------------------------------------------------
    //                                                 Private Variables
    //---------------------------------------------------------------------------------------------------------------------

    double Min; ///< The minimum value of the interval
    double Max; ///< The maximum value of the interval

    //---------------------------------------------------------------------------------------------------------------------
    //                                                Private Functions
    //---------------------------------------------------------------------------------------------------------------------

    /// @brief Finds the minimum of four values
    /// @param a value 1
    /// @param b value 2
    /// @param c value 3
    /// @param d value 4
    /// @return the minimum of the four values
    static double find_min(double a, double b, double c, double d);

    /// @brief Finds the maximum of four values
    /// @param a value 1
    /// @param b value 2
    /// @param c value 3
    /// @param d value 4
    /// @return the maximum of the four values
    static double find_max(double a, double b, double c, double d);
};