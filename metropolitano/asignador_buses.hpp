#ifndef ASIGNADOR_BUSES_HPP
#define ASIGNADOR_BUSES_HPP

#include "gestor_demandas.hpp"
#include <vector>

int asignarBusesOptimo(const std::vector<IntervaloDemanda>& demandas, int capacidadBus, double disponibilidad);

#endif
