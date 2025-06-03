#include "asignador_buses.hpp"
#include <queue>
#include <cmath>
#include <iostream>

/*
int asignarBusesOptimo(const std::vector<IntervaloDemanda>& demandas, int capacidadBus, double disponibilidad = 1.0) {
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
}*/

int asignarBusesOptimo(const std::vector<IntervaloDemanda>& demandas, int capacidadBus, double disponibilidad = 1.0);

    int asignarBusesOptimo(const std::vector<IntervaloDemanda>&demandas, int capacidadBus, double disponibilidad) {
        auto demandasOrdenadas = demandas;
        std::sort(demandasOrdenadas.begin(), demandasOrdenadas.end(),
            [](const IntervaloDemanda& a, const IntervaloDemanda& b) {
                return a.inicio < b.inicio;
            });

        std::priority_queue<int, std::vector<int>, std::greater<>> finBuses;
        int maxBusesSimultaneos = 0;

        for (const auto& d : demandasOrdenadas) {
            while (!finBuses.empty() && finBuses.top() <= d.inicio) {
                finBuses.pop();
            }

            int busesNecesarios = std::ceil((double)d.pasajeros / capacidadBus);

            // Aplicar restricción de disponibilidad
            int maxPermitido = std::floor(busesNecesarios * disponibilidad);

            if (maxPermitido < busesNecesarios) {
                std::cout << "Atencion: Se requieren " << busesNecesarios
                    << " buses en franja " << d.inicio / 60 << ":00 - " << d.fin / 60 << ":00, pero solo hay "
                    << maxPermitido << " disponibles (" << int(disponibilidad * 100) << "% de flota).\n";
            }

            int busesAsignados = std::min(busesNecesarios, maxPermitido);

            std::cout << "Franja " << d.inicio / 60 << ":00 - " << d.fin / 60 << ":00 -> "
                << busesAsignados << " buses asignados\n";

            for (int i = 0; i < busesAsignados; ++i) {
                finBuses.push(d.fin);
            }

            maxBusesSimultaneos = std::max(maxBusesSimultaneos, (int)finBuses.size());
        }

        std::cout << "\n>> Maximo de buses simultaneamente requeridos (con restricciones): "
            << maxBusesSimultaneos << std::endl;

        return maxBusesSimultaneos;
    }
