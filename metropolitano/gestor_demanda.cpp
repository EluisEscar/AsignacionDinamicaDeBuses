#include "gestor_demandas.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

int convertirHoraAMinutos(const std::string& hora) {
    int horas = std::stoi(hora.substr(0, 2));
    int minutos = std::stoi(hora.substr(3, 2));
    return horas * 60 + minutos;
}

std::vector<IntervaloDemanda> cargarDemandasDesdeCSV(const std::string& archivoCSV) {
    std::vector<IntervaloDemanda> demandas;
    std::ifstream archivo(archivoCSV);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << archivoCSV << std::endl;
        return demandas;
    }

    std::string linea;
    std::getline(archivo, linea); // saltar cabecera

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string token;
        IntervaloDemanda d;

        std::getline(ss, token, ',');
        d.inicio = convertirHoraAMinutos(token);

        std::getline(ss, token, ',');
        d.fin = convertirHoraAMinutos(token);

        std::getline(ss, token, ',');
        d.pasajeros = std::stoi(token);

        demandas.push_back(d);
    }

    return demandas;
}
