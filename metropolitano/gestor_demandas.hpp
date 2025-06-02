#ifndef GESTOR_DEMANDAS_HPP
#define GESTOR_DEMANDAS_HPP

#include <vector>
#include <string>

struct IntervaloDemanda {
    int inicio;     // en minutos desde 00:00
    int fin;
    int pasajeros;
};

std::vector<IntervaloDemanda> cargarDemandasDesdeCSV(const std::string& archivoCSV);

#endif
