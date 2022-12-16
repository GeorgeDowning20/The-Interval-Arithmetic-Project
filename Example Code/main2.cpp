#include "../interval.cpp"

using namespace std;

int main()
{
    interval x;           // Default initialisation
    interval y(3.0, 3.1); // Initialisation from complete data
    interval z(7);        // Sensible (?) initialisation from a single float
    interval a(x);
    a = x;
    interval *intptr = new interval[4];
    delete[] intptr;
}