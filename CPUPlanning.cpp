//
// Created by Cristhian Aguilera on 17/04/2017.
//

#include "CPUPlanning.h"

CPUPlanning::CPUPlanning(string method, string file) {
    method_g = method;
    file_g = file;
    current_time_g=0;
    read_file();
}

void CPUPlanning::read_file() {
    string line;
    int id, runtime, arrival;

    ifstream infile(file_g);
    getline(infile, line);
    while (std::getline(infile, line)){
        std::istringstream iss(line);
        iss >> id >> runtime >> arrival;
        Process process;
        process.id = id;
        process.runtime = runtime;
        process.arrival = arrival;
        process_g.push_back(process);
    }
}

void CPUPlanning::run() {
    if (method_g == "FCFS")
        run_fcfs();
    else if (method_g == "SJF")
        run_sjf();
    else if (method_g == "SJF_P")
        run_sjf_p();
    else if (method_g == "RR")
        run_rr();
    else {
        cout << "Método desconocido" << endl;
        exit(0);
    }
}

void CPUPlanning::run_fcfs() {
    cout << "Calculando First-Come-First-Served" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}

void CPUPlanning::run_sjf() {
    cout << "Calculando Short-Job-First" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}

void CPUPlanning::run_sjf_p() {
    cout << "Calculando Short-Job-First con apropiación" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}

void CPUPlanning::run_rr() {
    cout << "Calculando Round Robin" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}