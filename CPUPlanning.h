//
// Created by Cristhian Aguilera on 17/04/2017.
//

#ifndef PLANNING_CPUPLANNING_H
#define PLANNING_CPUPLANNING_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Process {
    int id;
    int runtime;
    int arrival;
};

class CPUPlanning {

private:
    int current_time_g;
    string method_g, file_g;
    vector<Process> process_g;

public:
    CPUPlanning(string method, string file);
    void run();

private:
    void read_file();
    void run_fcfs();
    void run_sjf();
    void run_sjf_p();
    void run_rr();
};


#endif //PLANNING_CPUPLANNING_H
