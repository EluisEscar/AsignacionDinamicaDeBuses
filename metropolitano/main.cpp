#include <iostream>
#include "gestor_demandas.hpp"
#include "asignador_buses.hpp"
/*
int main() {
    std::string archivo = "demandas_pico.csv";
    auto demandas = cargarDemandasDesdeCSV(archivo);

    for (const auto& d : demandas) {
        std::cout << "Inicio: " << d.inicio
            << " | Fin: " << d.fin
            << " | Pasajeros: " << d.pasajeros << std::endl;
    }

    return 0;
}
*/

int main() {
    std::string archivo = "demandas_pico.csv";
    auto demandas = cargarDemandasDesdeCSV(archivo);

    int capacidadBus = 164; // pasajeros por bus
    asignarBusesOptimo(demandas, capacidadBus);

    return 0;
}