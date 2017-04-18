#include <iostream>
#include "cxxopts.hpp"
#include "CPUPlanning.h"


using namespace std;

int main( int argc, char* argv[]) {
    // Option parser
    cxxopts::Options options("CPUPlanning", "Simple CPU Planning");
    options.add_options()
            ("m,method", "[FCFS, SJF, SJF_P, RR]", cxxopts::value<string>())
            ("f,file", "Filename", cxxopts::value<string>())
            ;
    options.parse(argc, argv);

    //Print options
    cout << "Planning Method: "<< options["method"].as<string>() << endl;
    cout << "File: "<< options["file"].as<string>() << endl;

    // Run CPU Planning
    CPUPlanning cpu_planning(options["method"].as<string>(), options["file"].as<string>());
    cpu_planning.run();
    return 0;
}