#include <iostream>
 
using namespace std;
 
int main() {
 double raio;
 constexpr double n = 3.14159;
 cin >> raio;
 const double area = n * (raio * raio);
 cout << "A=" << area << "\n";
}
