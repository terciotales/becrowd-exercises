#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
    double a, b;
    
    cout << fixed << setprecision(1);
    cin >> a >> b;
    cout << fixed << setprecision(5);
    cout << "MEDIA = " << ((a*3.5)+(b*7.5))/(3.5+7.5) << "\n";

}
