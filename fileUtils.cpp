#include "fileUtils.h"

bool fileExists(string name)
{
		fstream file(name.c_str(),fstream::in);
		
		if (file.is_open())
		{
				file.close();
				return true;
		}
		
		return false;
}

string readTextFile(string name)
{
    int size;
    ifstream in(name.c_str());

    STREAM_SIZE(in,size);

    char *buf = new char[size+1];

    in.read(buf,size);
    buf[size] = '\0';

    in.close();

    return string(buf);
}
