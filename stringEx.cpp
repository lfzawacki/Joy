#include "stringEx.h"

/*
    astows
    Função totalmente cortesia de:

    http://agraja.wordpress.com/2008/09/08/cpp-string-wstring-conversion/
*/
wstring atows(const char* c_str)
{
    string str = c_str;

    return astows(str);
}

wstring  astows (string str)
{
    wstring wstr(str.length(),L' ');
    copy(str.begin(),str.end(),wstr.begin());
    return wstr;
}

string wstoas (wstring wstr)
{
    string str(wstr.length(),' ');
    copy(wstr.begin(),wstr.end(),str.begin());
    return str;
}

/*
	trimSpaces
    cortesia de
    http://sarathc.wordpress.com/2007/01/31/how-to-trim-leading-or-trailing-spaces-of-string-in-c/
*/
string& trimSpaces( string& str)
{
    // Trim Both leading and trailing spaces
    size_t startpos = str.find_first_not_of(" \t"); // Find the first character position after excluding leading blank spaces
    size_t endpos = str.find_last_not_of(" \t"); // Find the first character position from reverse af

    // if all spaces or empty return an empty string
    if(( string::npos == startpos ) || ( string::npos == endpos))
    {
        str = "";
    }
    else
        str = str.substr( startpos, endpos-startpos+1 );

    /*
    // Code for  Trim Leading Spaces only
    size_t startpos = str.find_first_not_of(” \t”); // Find the first character position after excluding leading blank spaces
    if( string::npos != startpos )
        str = str.substr( startpos );
    */

    /*
    // Code for Trim trailing Spaces only
    size_t endpos = str.find_last_not_of(” \t”); // Find the first character position from reverse af
    if( string::npos != endpos )
        str = str.substr( 0, endpos+1 );
    */

    return str;
}

vector<string> splitString(string& str, string separador)
{
    vector<string> vecStr;
    int inicio = 0, encontrado = 0;
    int fim = str.size();

    while(encontrado >= 0 && encontrado != string::npos) {

        encontrado = str.find(separador,inicio);
        vecStr.push_back(string(str.substr(inicio,encontrado - inicio)));
        inicio = encontrado+separador.size();

    }

    return vecStr;
}

string& stripComments(string& conteudo, string strTok)
{
    int inicio = 0, fim = 0;

    inicio = conteudo.find(strTok);

    while (inicio != string::npos)
    {
        fim = conteudo.find("\n",inicio+1);

        // geralmente na frente do comentário sobra um espaço
        // mas nada me diz que o cara nao pode grudar um comentario num caracter, por isso
        // o espaço é preservado
        conteudo.erase(inicio,fim - inicio);
        inicio = conteudo.find(strTok);

    }

    return conteudo;
}

string& stripExtraSpaces(string& t)
{
      int pos;
      
      int t_size = 3;
      string tokens[] = {" ","\n","\t"};
      
      for (int i=0; i < t_size; ++i)
      {
      	string cur_tok = tokens[i];
				
				pos = t.find(cur_tok+cur_tok); //encontrar o token duplicado
				
       	while (pos != string::npos)
     	 	{
          t.replace(pos,2,cur_tok);
          pos = t.find(cur_tok+cur_tok); //encontrar o token duplicado
        }
        
		  }

      return t;
}

string vectorToString(vector<string>& vec)
{
    string ret;

    for (int i=0; i < vec.size(); i++)
    {
        ret += vec[i];

        if (i+1 != vec.size())
         ret += " ";
    }

    return ret;
}
