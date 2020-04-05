//
// Created by yh960 on 2020-04-03.
//

#ifndef LAB1_APPLICATION_H
#define LAB1_APPLICATION_H
#include <iostream>
#include "../ItemType/ItemType.h"
#include <fstream>
#include "../ArrayList/ArrayList.h"

#define FILENAMESIZE 1024

class Application {
public:
    void Run();
    int GetCommand();
    int AddItem();
    void DisplayAllItem();
    int OpenInFile(char *fileName);
    int OpenOutFile(char *fileName);
    int ReadDataFromFile();
    int WriteDataToFile();


    int RetrieveStudent();
    int DeleteStudent();
    int Replace();
private:
    ifstream m_InFile;///< input file descriptor.
    ofstream m_OutFile;///< output file descriptor.
    ArrayList m_List;///< item list.
    int m_Command;///< current command number.
};


#endif //LAB1_APPLICATION_H
