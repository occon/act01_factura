#include <iostream>
#include <ctime>
using namespace std;

class Vendedor{
    public:
        Vendedor(); //default constructor
        Vendedor(string clave, string nombre);
        void setVendedor(string clave, string nombre);
        string showClave(){return cve_vendedor;};
        string showNombre(){return Nombre;};
        void imprimeV();
    private:
        string cve_vendedor;
        string Nombre;
};

class Inventario{
    public:
        Inventario();
        Inventario(string clave, string descripcion, double precio);
        void setInventario(string clave, string descripcion, double precio);
        void agregar_inventario(string array, int n);
        string showClave();
        string showDescripcion();
        double showPrecio();
        void imprimeI();
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

class Factura{
    public:
        string no_Factura;
        string cve_vendedor;
        string cve_articulo;
        int cantidad;
};

std::string GETDATE() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y%m%d%H%S",timeinfo);
    std::string str(buffer);

    std::cout << str;

    return str;
};

void genera_factura(int i, Factura arreglo_factura[], Vendedor v1, Inventario i2, int cant){
    Factura f1;
    f1.cve_vendedor = v1.showClave();
    f1.cve_articulo = i2.showClave();
    f1.cantidad = cant;
    f1.no_Factura = "F" + GETDATE();
    arreglo_factura[i] = f1;
}


string Inventario::showClave(){return cve_articulo;};
string Inventario::showDescripcion(){return Descripcion;};
double Inventario::showPrecio(){return Precio;};

int main(){
    Vendedor arreglo_vendedor[100];
    Inventario arreglo_inventario[100];
    Factura arreglo_factura[5];
    string nombre_articulo;
    int cantVen=2;
    int cantArt=3;

    
    // variable v1, v2
    Vendedor v1 = {"v100", "Don Julio Estrella"};
    Vendedor v2 = {"v200", "Doña Esperanza Luna"};
    arreglo_vendedor[0] = v1;
    arreglo_vendedor[1] = v2;
    
    // variable i1, i2
    Inventario i1 = {"i500", "Tornillo sin fin", 10.00};
    Inventario i2 = {"i100", "Pinon Cremallera", 10.00};
    Inventario i3 = {"i200", "Angulo de Ackerman", 10.00};
    arreglo_inventario[0] = i1;
    arreglo_inventario[1] = i2;
    arreglo_inventario[2] = i3;
    
    // facturas
    int contador_factura = 0;
    genera_factura(contador_factura, arreglo_factura, v1, i2, 32);
    
    // imprimir facturas
        cout << "Facturas Generadas" << endl;
        cout << "No." << "\t\t" << "Vendedor" << "\t" << "Codigo Art.\t" << "Articulo" << endl;

        for (int j = 0; j <= contador_factura; j++){
            for (int k = 0; k < sizeof(arreglo_inventario)/sizeof(arreglo_inventario[0]); k++){
                if (arreglo_factura[j].cve_articulo == arreglo_inventario[k].showClave())
                    nombre_articulo = arreglo_inventario[k].showDescripcion();
            }

            cout << arreglo_factura[j].no_Factura << "\t"
            << arreglo_factura[j].cve_vendedor << "\t\t"
            << arreglo_factura[j].cve_articulo << "\t\t"
            << nombre_articulo << endl;
        }
    return 0;
}