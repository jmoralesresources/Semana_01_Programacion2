#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hablar() { cout << "Sonido generico.\n"; }
};

class Mamifero : public Animal {
public:
    void hablar() override { cout << "Mamifero.\n"; }
};

class Perro : public Mamifero {
public:
    void hablar() override { cout << "Guau!\n"; }
};

int main() {
    Perro p;
    Animal* a = &p;      // upcast nivel 2
    Mamifero* m = &p;    // upcast nivel 1
    a->hablar();         // "Guau!"
    m->hablar();         // "Guau!"
    return 0;
}