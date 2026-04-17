#include <iostream>
using namespace std;

class Vehiculo {
public:
    virtual ~Vehiculo() = default;
    virtual void tipo() { cout << "Vehiculo\n"; }
};

class Automovil : public Vehiculo {
public:
    void tipo() override { cout << "Automovil\n"; }
    void soloAutomovil() { cout << "Solo los automoviles tienen esto.\n"; }
};

int main() {
    Vehiculo* p = new Automovil();
    p->tipo();

    Automovil* a = dynamic_cast<Automovil*>(p);
    if (a != nullptr) {
        a->soloAutomovil();
    }

    Vehiculo* p2 = new Vehiculo();
    Automovil* a2 = dynamic_cast<Automovil*>(p2);
    if (a2 == nullptr)
        cout << "Downcast fallo: no es Automovil.\n";

    delete p;
    delete p2;
    return 0;
}