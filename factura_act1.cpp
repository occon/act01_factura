#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class Vendedor{
    public:
        string cve_vendedor;
        string nombre;
};

class Inventario{
    public:
        string cve_articulo;
        string descripcion;
        double precio;
};

class Factura{
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

void genera_factura(int i, Factura arreglo_factura[], Vendedor v1, Inventario i2, int cant){
    Factura f1;
    f1.cve_vendedor = v1.cve_vendedor;
    f1.cve_articulo = i2.cve_articulo;
    f1.cantidad = cant;
    f1.no_Factura = "F" + GETDATE();
    arreglo_factura[i] = f1;
};

int main(){
    Vendedor arreglo_vendedor[2];
    Inventario arreglo_inventario[4];
    Factura arreglo_factura[5];
    string nombre_articulo;

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
            if (arreglo_factura[j].cve_articulo == arreglo_inventario[k].cve_articulo)
                nombre_articulo = arreglo_inventario[k].descripcion;
        }

        cout << arreglo_factura[j].no_Factura << "\t"
        << arreglo_factura[j].cve_vendedor << "\t\t"
        << arreglo_factura[j].cve_articulo << "\t\t"
        << nombre_articulo << endl;
    }
    
    return 0;
}