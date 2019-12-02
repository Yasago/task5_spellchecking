#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <stdlib.h>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:

    unsigned int operator()( const string& s )  const
    {
        unsigned long num = 0;
        int p = 1;

        for (int i = 0; i < s.size(); ++i)
        {
            num += (s[i] * p) % INT64_MAX;
        }

        return num;
    }
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const
    {
        return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality> {

public:
	Dictionary(string filename)
    {
	    ifstream inf(filename);
        if (!inf)
        {
            throw invalid_argument("Unavailable to open file");
        }

        string s;
        while (inf >> s)
        {
            this->insert(s);
        }
    }

};
#endif // _DICTIONARY_H_
