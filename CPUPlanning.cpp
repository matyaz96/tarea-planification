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
        process.running = 0;
        process.waiting = 0;
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
    deque<Process> active_processes;
    deque<Process> inactive_processes;
    Process current_process ={-1,-1,-1};
    float total_processes = process_g.size();
    while(process_g.size()>0 or active_processes.size()>0 or current_process.id>-1){
        //Check if some process arrive
        vector<int> ids_to_remove;
        for(int i=0; i<process_g.size();i++){
            if(process_g[i].arrival==current_time_g){
                active_processes.push_back(process_g[i]);
                ids_to_remove.push_back(process_g[i].id);
            }
        }
        // Remove active processes from g
        for(auto id:ids_to_remove){
            int pos=0;
            for(int i=0; i<process_g.size();i++){
                if(process_g[i].id==id){
                    pos = i;
                }
            }
            process_g.erase(process_g.begin()+pos);
        }

        // Set current process
        if(current_process.id == -1) {
            current_process = active_processes.front();
            active_processes.pop_front();
        }

        // Run the current process
        current_process.running += 1;

        // Check if the process needs more time
        if (current_process.running == current_process.runtime){
            inactive_processes.push_back(current_process);
            current_process.id = -1;
        }

        //Update waiting times inside the queue
        for(int i=0; i<active_processes.size();i++)
            active_processes[i].waiting++;


        // update the time
        current_time_g++;
    }

    // Throughput
    cout << "Troughput: " << total_processes/current_time_g << endl;

    // Turnaround
    float total_time=0;
    for(auto p:inactive_processes)
    {
        total_time+=p.runtime + p.waiting;
    }
    cout << "Turnaround: " << total_time/total_processes << endl;

    // Waiting time
    total_time=0;
    for(auto p:inactive_processes)
    {
        total_time+= p.waiting;
    }
    cout << "Response time: " << total_time/total_processes << endl;

}

void CPUPlanning::run_sjf() {
    cout << "Calculando Short-Job-First" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
    deque<Process> active_processes;
    deque<Process> inactive_processes;
    Process current_process ={-1,-1,-1};
    float total_processes = process_g.size();
    while(process_g.size()>0 or active_processes.size()>0 or current_process.id>-1){
        //Check if some process arrive
        vector<int> ids_to_remove;
        for(int i=0; i<process_g.size();i++){
            if(process_g[i].arrival==current_time_g){
                active_processes.push_back(process_g[i]);
                ids_to_remove.push_back(process_g[i].id);
            }
        }
        // Remove active processes from g
        for(auto id:ids_to_remove){
            int pos=0;
            for(int i=0; i<process_g.size();i++){
                if(process_g[i].id==id){
                    pos = i;
                }
            }
            process_g.erase(process_g.begin()+pos);
        }

        // Set current process
        if(current_process.id == -1) {
            current_process = active_processes.front();
            active_processes.pop_front();
        }

        // Run the current process
        current_process.running += 1;

        // Check if the process needs more time
        if (current_process.running == current_process.runtime){
            inactive_processes.push_back(current_process);
            current_process.id = -1;
        }

        //Update waiting times inside the queue
        for(int i=0; i<active_processes.size();i++)
            active_processes[i].waiting++;


        // update the time
        current_time_g++;
    }

    // Throughput
    cout << "Troughput: " << total_processes/current_time_g << endl;

    // Turnaround
    float total_time=0;
    for(auto p:inactive_processes)
    {
        total_time+=p.runtime + p.waiting;
    }
    cout << "Turnaround: " << total_time/total_processes << endl;

    // Waiting time
    total_time=0;
    for(auto p:inactive_processes)
    {
        total_time+= p.waiting;
    }
    cout << "Response time: " << total_time/total_processes << endl;
}

void CPUPlanning::run_sjf_p() {
    cout << "Calculando Short-Job-First con apropiación" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}

void CPUPlanning::run_rr() {
    cout << "Calculando Round Robin" << endl;
    // Este método calcular e imprimir en pantalla el throughput, turnaround y response time
}
