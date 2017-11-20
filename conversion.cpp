#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int nCelsius;
    cout << "Input degrees (in Celsius)\n\n";
    cin >> nCelsius;
    cout << "\nCelsius is " << nCelsius << endl;
    int nFactor = 212 - 32;
    int nFarhenheit = nFactor * nCelsius /100 + 32;
    cout << "\nFahrenheit is " << nFarhenheit << endl;
    std::getchar();
}
