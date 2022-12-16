/// @file Example.cpp
/// @brief Example code for the interval class
/// @author George Downing
/// @date 16-12-2022
/// @details This is a simple example of how to use the interval class
/// @details DOxygen documentation: https://georgedowning20.github.io/The-Interval-Arithmetic-Project/files.html

#include "../interval.cpp"

/// @brief main to test the interval class
/** @test Output: \n
Hello World! \n
 \n
constructors: \n
x=      [3, 3.1] \n
y=      [7, 7] \n
p=      [3, 3.1] \n
 \n
Basic interval arithmetic: \n
a=      [10, 10.1]v
b=      [-4, -3.9]v
c=      [21, 21.7] \n
d=      [0.428571, 0.442857] \n
 \n
compound arithmetic: \n
p=      [13, 13.2] \n
p=      [2.9, 3.2] \n
p=      [29, 32.32] \n
p=      [2.87129, 3.232] \n
 \n
non interval types arithmetic \n
g=      [15, 15.1] \n
h=      [15, 15.1] \n
g=      [5, 5.1] \n
h=      [-5.1, -5] \n
g=      [50, 50.5] \n
h=      [50, 50.5] \n
g=      [2, 2.02] \n
h=      [0.49505, 0.5] \n
 \n
non interval types compound arithmetic: \n
p=      [14.2, 14.2 ]  \n
p=      [10, 10] \n
p=      [42, 42] \n
p=      [10, 10] \n
**/
int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl
              << "constructors:" << std::endl;

    interval x(3.0, 3.1);
    interval y(7);
    interval p(x);
    std::cout << "x=\t" << x << std::endl
              << "y=\t" << y << std::endl
              << "p=\t" << p << std::endl;

    std::cout << std::endl
              << "Basic interval arithmetic:" << std::endl;
    interval a = x + y;
    interval b = x - y;
    interval c = x * y;
    interval d = x / y;
    std::cout << "a=\t" << a << std::endl
              << "b=\t" << b << std::endl
              << "c=\t" << c << std::endl
              << "d=\t" << d << std::endl;

    std::cout << std::endl
              << "compound arithmetic:" << std::endl;
    p += a;
    std::cout << "p=\t" << p << std::endl;

    p -= a;
    std::cout << "p=\t" << p << std::endl;

    p *= a;
    std::cout << "p=\t" << p << std::endl;

    p /= a;
    std::cout << "p=\t" << p << std::endl;

    std::cout << std::endl
              << "non interval types arithmetic" << std::endl;
    float f(5.);
    interval g, h;

    g = a + f;
    h = f + a;
    std::cout << "g=\t" << g << std::endl
              << "h=\t" << h << std::endl;

    g = a - f;
    h = f - a;
    std::cout << "g=\t" << g << std::endl
              << "h=\t" << h << std::endl;

    g = a * f;
    h = f * a;
    std::cout << "g=\t" << g << std::endl
              << "h=\t" << h << std::endl;

    g = a / f;
    h = f / a;
    std::cout << "g=\t" << g << std::endl
              << "h=\t" << h << std::endl;

    std::cout << std::endl
              << "non interval types compound arithmetic:" << std::endl;

    float i = 4.2f;
    p = 10;

    p += i;
    std::cout << "p=\t" << p << std::endl;

    p -= i;
    std::cout << "p=\t" << p << std::endl;

    p *= i;
    std::cout << "p=\t" << p << std::endl;

    p /= i;
    std::cout << "p=\t" << p << std::endl;
}
