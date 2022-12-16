#include "../interval.cpp"

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
              << "Assignment arithmetic:" << std::endl;
    p += a;
    std::cout << "p=\t" << p << std::endl;

    p -= a;
    std::cout << "p=\t" << p << std::endl;

    p *= a;
    std::cout << "p=\t" << p << std::endl;

    p /= a;
    std::cout << "p=\t" << p << std::endl;

    std::cout << std::endl
              << "non uniform types arithmetic" << std::endl;
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
}