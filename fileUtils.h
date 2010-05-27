#ifndef _FILE_UTILS_H
#define _FILE_UTILS_H

#include <fstream>
#include <string>

using namespace std;

#define STREAM_SIZE(s,i) (s).seekg(0,ios::end); (i) = (s).tellg(); (s).seekg(0,ios::beg)

bool fileExists(string name);
string readTextFile(string name);
void dumpTextFile(string name, string content);

#endif
