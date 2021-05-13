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

class Inventario{
    public:
        Inventario();
        Inventario(string clave, string descripcion, double precio);
        void setInventario(string clave, string descripcion, double precio);
        string showClave();
        string showDescripcion();
        double showPrecio();
    private:
        string cve_articulo;
        string Descripcion;
        double Precio;
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

Inventario::Inventario(){
    cve_articulo = "ninguno";
    Descripcion = "nohay";
    Precio = 0.0;
};

void Inventario::setInventario(string clave, string descripcion, double precio){
    cve_articulo = clave;
    Descripcion = descripcion;
    Precio = precio;
};

Inventario::Inventario(string clave, string descripcion, double precio){
    cve_articulo = clave;
    Descripcion = descripcion;
    Precio = precio;
};

string Vendedor::showClave(){return cve_vendedor;};
string Vendedor::showNombre(){return Nombre;};

string Inventario::showClave(){return cve_articulo;};
string Inventario::showDescripcion(){return Descripcion;};
double Inventario::showPrecio(){return Precio;};

int main(){
    Vendedor vendedor1;
    Vendedor vendedor2("V1523", "Juan Martinez");
    Inventario inventario1;
    Inventario inventario2("I0941", "iPhone 12", 224);
    cout << vendedor1.showClave() << " " << vendedor1.showNombre() << endl;
    cout << vendedor2.showClave() << " " << vendedor2.showNombre() << endl;
    
    cout << inventario1.showClave() << " " << inventario1.showDescripcion() << " " << inventario1.showPrecio() << endl;
    cout << inventario2.showClave() << " " << inventario2.showDescripcion() << " " << inventario2.showPrecio() << endl;
    return 0;
}


