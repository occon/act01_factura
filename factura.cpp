#include <iostream>
#include <ctime>
#include <windows.h>

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

string GETDATE(){
    char out[14];
    time_t t = time(NULL);
    strftime(out, sizeof(out), "%Y%m%d%H%S", localtime(&t));
    Sleep(2000);  // pauses for 10 seconds
    return out;
};

void genera_factura(int i, factura arreglo_factura[], vendedor v1, inventario i2, int cant){
    factura f1;
    f1.cve_vendedor = v1.cve_vendedor;
    f1.cve_articulo = i2.cve_articulo;
    f1.cantidad = cant;
    f1.no_Factura = "F" + GETDATE();
    arreglo_factura[i] = f1;
};

int main(){
    vendedor arreglo_vendedor[2];
    inventario arreglo_inventario[4];
    factura arreglo_factura[5];
    string nombre_articulo;

    // variable v1, v2
    vendedor v1 = {"v100", "Don Julio Estrella"};
    vendedor v2 = {"v200", "Doña Esperanza Luna"};
    arreglo_vendedor[0] = v1;
    arreglo_vendedor[1] = v2;
    
    // variable i1, i2
    inventario i1 = {"i500", "Tornillo sin fin", 10.00};
    inventario i2 = {"i100", "Pinon Cremallera", 10.00};
    inventario i3 = {"i200", "Angulo de Ackerman", 10.00};

    arreglo_inventario[0] = i1;
    arreglo_inventario[1] = i2;
    arreglo_inventario[2] = i3;

}