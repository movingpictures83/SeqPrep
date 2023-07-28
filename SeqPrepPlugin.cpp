#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "SeqPrepPlugin.h"

void SeqPrepPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 ifile >> forwardReads;
 ifile >> reverseReads;
 forwardReads = std::string(PluginManager::prefix()) + "/" + forwardReads;
 reverseReads = std::string(PluginManager::prefix()) + "/" + reverseReads;
}

void SeqPrepPlugin::run() {}

void SeqPrepPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "join_paired_ends.py";
myCommand += " ";
myCommand += "-f";
myCommand += " ";
myCommand += forwardReads;
myCommand += " ";
myCommand += "-r";
myCommand += " ";
myCommand += reverseReads;
myCommand += " ";
myCommand += " -m SeqPrep -o ";
myCommand += file;
std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<SeqPrepPlugin> SeqPrepPluginProxy = PluginProxy<SeqPrepPlugin>("SeqPrep", PluginManager::getInstance());
