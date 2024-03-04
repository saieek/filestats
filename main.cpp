#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

int countWordsInfile(string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"Error : Unable to open a file "<<filename<<endl;
        return -1;
    }
    string word;
    int wordCount = 0;
    while(file >> word){
        ++wordCount;
    }
    file.close();
    return wordCount;
}
int LinesCountInfile(string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"Error : Unable to open a file "<<filename<<endl;
        return -1;
    }
    string line;
    int linecount = 0;
    while(getline(file,line)){
        ++linecount;
    }
    file.close();
    return linecount;
}
long long ByteCountInfile(string& filename){
    ifstream file(filename, ios::binary | ios::ate);
    if(!file.is_open()){
        cerr<<"Error : Unable to open a file "<<filename<<endl;
        return -1;
    }
    long long fileSize= file.tellg();
    file.close();
    return fileSize;
}
long long characterCountinfile(string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"Error : Unable to open a file "<<filename<<endl;
        return -1;
    }
    char character =0;
    long long charactercount = 0;
    while(file >> character){
        ++charactercount;
    }
    file.close();
    return charactercount;
}

void fileStats(string& filename){
    int wordcount = countWordsInfile(filename);
    int linecount = LinesCountInfile(filename);
    long long byteCount =ByteCountInfile(filename);
    long long charatercount = characterCountinfile(filename);
    if(wordcount != -1){
        cout<<"words : "<<wordcount<<endl;
    }
    if(linecount != -1){
        cout<<"line : "<<linecount<<endl;
    }
    if(byteCount != -1){
        cout<<"Bytes : "<<byteCount<<endl;
    }
    // if(charatercount != -1){
    //     cout<<"character : "<<charatercount<<endl;
    // }
}


int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "Usage: " << argv[0] << "<command {-w,-c,-l,-b,-stats}> <filename>" << std::endl;
        return 1;
    }
     string command = argv[1];
    string filename = argv[2];
    if(command == "-w"){
        int wordCount = countWordsInfile(filename);
        if(wordCount != -1){
            cout << "Number of words in file " << filename << ": " << wordCount << std::endl;
        }
    }
    else if(command == "-l"){
        int linecount = LinesCountInfile(filename);
        if(linecount != -1){
            cout << "Number of lines in file " << filename << ": " << linecount << std::endl;
        }
    }
    else if(command == "-b"){
        int Bytecount = ByteCountInfile(filename);
        if(Bytecount != -1){
            cout << "Number of Bytes in file " << filename << ": " << Bytecount << std::endl;
        }
    }
    // else if(command == "-c"){
    //     int charactercount = characterCountinfile(filename);
    //     if(charactercount != -1){
    //         cout << "Number of charactercount in file " << filename << ": " << charactercount << std::endl;
    //     }
    // }
    else if(command =="-stats"){
        fileStats(filename);        
    }
    else{
        std::cerr<<"Unknow command : "<<command<<endl;
        return 1;
    }
 return 0;   
}