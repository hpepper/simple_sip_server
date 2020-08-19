/*
 * TODO get parameters
 * Call the 'game' loop
 */

#include <boost/program_options.hpp>
#include <iostream>

#include "client_engine.h"

int main(int argc, char *argv[])
{
    // The origin for doing the option thing is from the book: Boost CPP application dev cookbook 2nd ed.
    // Constructing an options describing variable and giving
    // it a textual description "All options".
    boost::program_options::options_description desc("All options");
    // When we are adding options, first parameter is a name
    // to be used in command line. Second parameter is a type
    // of that option, wrapped in value<> class. Third parameter
    // must be a short description of that option.
    desc.add_options()("port", boost::program_options::value<int>(), "Port to connect to")("help", "produce help message");

    // Variable to store our command line arguments.
    boost::program_options::variables_map optionsVariableMap;
    // Parsing and storing arguments.
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), optionsVariableMap);
    // Must be called after all the parsing and storing.
    boost::program_options::notify(optionsVariableMap);

    if (optionsVariableMap.count("help"))
    {
        std::cout << desc << "\n";
        return 1;
    }
    ClientEngine clientEngine;

    clientEngine.mainClientLoop();
}