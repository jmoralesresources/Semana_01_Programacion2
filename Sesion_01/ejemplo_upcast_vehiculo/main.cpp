#include <iostream>
using namespace std;

class Vehiculo {
public:
    void arrancar() { cout << "Vehiculo arrancado.\n"; }
    virtual void describir() { cout << "Soy un vehiculo.\n"; }
};

class Automovil : public Vehiculo {
public:
    void describir() override { cout << "Soy un automovil.\n"; }
};

int main() {
    Automovil a;
    a.arrancar();

    // Upcast: puntero derivado -> base
    Vehiculo* pV = &a;
    pV->arrancar();
    pV->describir();  // polimorfismo: "Soy un automovil"

    // Upcast: referencia
    Vehiculo& rV = a;
    rV.describir();
    return 0;
}