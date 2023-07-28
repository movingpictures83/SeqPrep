#ifndef SEQPREPPLUGIN_H
#define SEQPREPPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class SeqPrepPlugin : public Plugin
{
public: 
 std::string toString() {return "SeqPrep";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::string forwardReads;
 std::string reverseReads;
};

#endif
