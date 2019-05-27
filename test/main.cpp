#include <iostream>
#include "vector.h"
//#include <vector>
//using std::vector;
#include <chrono>

int main() {

    int size = 10000000;
    vector <int> a(size,1);
    vector <int> b(size,2);
    Timer t;  // paleisti
    vector <int> c;
    c = a + b;
    std::cout << size << " elementų sudėti užtruko: " << t.elapsed() << " s\n";
    std::cout << "c[100000] = " << c[100000] << std::endl; // Patikriname ar tikrai sudėjo
    a.push_back(100);
    std::cout <<"a.capacity(): " <<  a.capacity() << std::endl;
    vector<int> v{4, 1};
    //std::cout << "v[5]:" << v[5]<< endl;
    //std::cout << "v.at(5):" <<v.at(5)<< endl;

    //vector <int> h (9999999999999, 1); //prideti exceptions visiems

    //shrink to fit ir move

    return 0;
}