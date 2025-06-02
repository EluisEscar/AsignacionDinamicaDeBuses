#include "asignador_buses.hpp"
#include <queue>
#include <cmath>
#include <iostream>

int asignarBusesOptimo(const std::vector<IntervaloDemanda>& demandas, int capacidadBus) {
    // Ordenar las franjas horarias por inicio
    auto demandasOrdenadas = demandas;
    std::sort(demandasOrdenadas.begin(), demandasOrdenadas.end(),
        [](const IntervaloDemanda& a, const IntervaloDemanda& b) {
            return a.inicio < b.inicio;
        });

    // Min-heap con tiempos de fin de los buses en uso
    std::priority_queue<int, std::vector<int>, std::greater<>> finBuses;

    int maxBusesSimultaneos = 0;

    for (const auto& d : demandasOrdenadas) {
        // Liberar buses que ya terminaron
        while (!finBuses.empty() && finBuses.top() <= d.inicio) {
            finBuses.pop();
        }

        int busesNecesarios = std::ceil((double)d.pasajeros / capacidadBus);

        std::cout << "Franja " << d.inicio / 60 << ":00 - " << d.fin / 60 << ":00 -> "
            << busesNecesarios << " buses asignados\n";

        for (int i = 0; i < busesNecesarios; ++i) {
            finBuses.push(d.fin);
        }

        maxBusesSimultaneos = std::max(maxBusesSimultaneos, (int)finBuses.size());
    }

    std::cout << "\n>> Buses simultaneamente requeridos: " << maxBusesSimultaneos << std::endl;
    return maxBusesSimultaneos;
}
