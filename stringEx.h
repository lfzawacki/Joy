#ifndef _STRING_EX_H
#define _STRING_EX_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

wstring  astows (string str);
string wstoas (wstring wstr);
wstring atows(const char *c_str);
string& stripExtraSpaces(string& t);

string& stripComments(string& conteudo, string strTok = "#");
vector<string> splitString(string& str, string separador);
string& trimSpaces( string& str);
string vectorToString(vector<string>& vec);
#endif
