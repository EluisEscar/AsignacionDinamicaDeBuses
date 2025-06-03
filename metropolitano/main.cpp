#include <iostream>
#include "gestor_demandas.hpp"
#include "asignador_buses.hpp"
#include <cstdlib>
#include <ctime>
/*
int main() {
    std::string archivo = "demandas_pico.csv";
    auto demandas = cargarDemandasDesdeCSV(archivo);

    int capacidadBus = 164; // pasajeros por bus
    asignarBusesOptimo(demandas, capacidadBus);

    return 0;
}
*/

void simularEventosExcepcionales(std::vector<IntervaloDemanda>& demandas) {
    std::srand(std::time(nullptr));

    std::cout << "\nSimulando eventos excepcionales...\n";

    for (auto& d : demandas) {
        bool hayEvento = (rand() % 100 < 30); // 30% probabilidad

        if (hayEvento) {
            int aumento = 200 + rand() % 300; // 200–500 pasajeros extra
            d.pasajeros += aumento;

            std::cout << "Evento inesperado en franja "
                << d.inicio / 60 << ":00 - "
                << d.fin / 60 << ":00 -> Aumento de +"
                << aumento << " pasajeros. Total: "
                << d.pasajeros << std::endl;
        }
    }

    std::cout << "Eventos aplicados.\n" << std::endl;
}

int main() {
    std::string archivo = "demandas_pico.csv";
    auto demandas = cargarDemandasDesdeCSV(archivo);

    char respuesta;
    std::cout << "¿Deseas simular eventos excepcionales? (S/N): ";
    std::cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {
        simularEventosExcepcionales(demandas);
    }
    double disponibilidad;
    int capacidadBus = 164;

    std::cout << "Ingresa porcentaje de disponibilidad de flota (ej. 0.9 para 90%): ";
    std::cin >> disponibilidad;

    asignarBusesOptimo(demandas, capacidadBus, disponibilidad);

    return 0;
}