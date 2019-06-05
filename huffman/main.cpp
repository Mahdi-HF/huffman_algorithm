//  be name khoda
//
//  huffman:
//  Created by mahdi.hf on 5/22/19.
//  Copyright © 2019 mahdi. All rights reserved.

#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;
#define size 26
#define fori(i,n) for(int i = 0; i < n; i++)

fstream Infile;
fstream outfile;

char character;
int count[size];

int main(){
    
    Infile.open ("Input.txt", ios::in);
    if (Infile.is_open())
    {
        while (Infile >> character)
        {
            if (character == ' ')
            {
                continue;
            }
            else cout << character << '\n';
            
        }
        Infile.close();
    }
    else cout << "Unable to open file";
//----------------------------------------------------------------------------------
    outfile.open ("Huffman.txt", ios::out);
    // writing ...
    //Infile << "Writing this to a file.\n";
    outfile.close();
    
    
    cout << "Hello, World!" <<endl;
    return 0 ;
}
