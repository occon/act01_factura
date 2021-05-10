#include <iostream>

using namespace std;

class vendedor {
    public:
        string cve_vendedor;
        string nombre;
};

class inventario {
    public:
        string cve_articulo;
        string descripcion;
        double precio;
};

class factura {
    public:
        string no_Factura;
        string cve_vendedor;
        string cve_articulo;
        int cantidad;
};