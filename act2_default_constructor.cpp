#include <iostream>

using namespace std;

class Vendedor{
    public:
        Vendedor(); //default constructor
        Vendedor(string clave, string nombre);
        void setVendedor(string clave, string nombre);
        string showClave();
        string showNombre();
    private:
        string cve_vendedor;
        string Nombre;
};

Vendedor::Vendedor(){
    cve_vendedor = "vacante";
    Nombre = "nadie";
};

void Vendedor::setVendedor(string clave, string nombre){
    cve_vendedor = clave;
    Nombre = nombre;
};

Vendedor::Vendedor(string clave, string nombre){
    cve_vendedor = clave;
    Nombre = nombre;
};

string Vendedor::showClave(){return cve_vendedor;};
string Vendedor::showNombre(){return Nombre;};

int main(){
    Vendedor vendedor1;
    Vendedor vendedor2("V1523", "Juan Martinez");
    cout << vendedor1.showClave() << " " << vendedor1.showNombre() << endl;
    cout << vendedor2.showClave() << " " << vendedor2.showNombre() << endl;

    return 0;
}


