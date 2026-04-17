#include <iostream>
#include <string>
using namespace std;

class Curso;  // forward declaration

class Estudiante {
    string nombre;
    Curso* curso;
public:
    Estudiante(const string& n) : nombre(n), curso(nullptr) {}
    void inscribir(Curso* c);
    void mostrarCurso() const;
};

class Curso {
    string titulo;
    Estudiante* estudiante;
public:
    Curso(const string& t) : titulo(t), estudiante(nullptr) {}
    void asignarEstudiante(Estudiante* e) { estudiante = e; }
    string getTitulo() const { return titulo; }
};

void Estudiante::inscribir(Curso* c) {
    curso = c;
    c->asignarEstudiante(this);
}
void Estudiante::mostrarCurso() const {
    if (curso)
        cout << nombre << " cursa: " << curso->getTitulo() << endl;
}

int main() {
    Estudiante e("Ana");
    Curso c("Programacion 2");
    e.inscribir(&c);
    e.mostrarCurso();
    return 0;
}