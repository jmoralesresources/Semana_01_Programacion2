#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() = default;
};

class Derivada : public Base {};

int main() {
    Base b;
    Derivada* d = dynamic_cast<Derivada*>(&b);
    if (d == nullptr)
        cout << "Correcto: &b no es un Derivada, cast devuelve nullptr.\n";
    return 0;
}