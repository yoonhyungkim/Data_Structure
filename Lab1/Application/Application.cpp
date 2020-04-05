//
// Created by yh960 on 2020-04-03.
//

#include "Application.h"

using namespace std;
void Application::Run()
{
    while(1){
        m_Command=GetCommand();
        switch(m_Command){
            case 1:
                AddItem();
                break;
            case 2:
                DisplayAllItem();
                break;
            case 3:
                m_List.MakeEmpty();
                break;
            case 4:
                ReadDataFromFile();
                break;
            case 5:
                WriteDataToFile();
                break;
            case 6:
                RetrieveStudent();
                break;
            case 7:
                DeleteStudent();
                break;
            case 8:
                Replace();
                break;
            case 0:
                return;
            default:
                cout<<"\tIllegal selection \n";
                break;
        }
    }
}
int Application::GetCommand() {
    int command;
    std::cout<<"\n\n";
    cout << "\t---ID --Command -----" << endl;
    cout<< "\t 1 : Add item" << endl;
    cout<< "\t 2 : Print all on screen" << endl;
    cout<< "\t 3 : Make empty list" << endl;
    cout<< "\t 4 : Get from file" << endl;
    cout<< "\t 5 : Put to file " << endl;
    cout<< "\t 6 : Retrieve Student " << endl;
    cout<< "\t 7 : Delete Student " << endl;
    cout<< "\t 8 : Replace list " << endl;

    cout << "\t 0 : Quit" << endl;
    cout << endl << "\t Choose a Command--> ";
    cin>> command;
    cout<< endl;

    return command;
}

int Application::AddItem() {
    if(m_List.IsFull()){
        cout<<"List is full"<<endl;
        return 0;
    }
    ItemType a;
    a.SetRecordFromKB();
    m_List.Add(a);
    DisplayAllItem();
    return 0;
}

void Application::DisplayAllItem() {
    ItemType data;
    cout<<"\n\tCurrent List"<<endl;

    m_List.ResetList();     //used when trying to use from index 0
    int length=m_List.GetLength();
    int curIndex=m_List.GenNextItem(data);  //great thing, add 1 to m_CurPointer first
    while(curIndex<length && curIndex!=-1){
        data.DisplayRecordOnScreen();
        curIndex=m_List.GenNextItem(data);
    }
}

int Application::OpenInFile(char *fileName) {
    m_InFile.open(fileName);
    if(!m_InFile.is_open())return 0;

    return 1;
}

int Application::OpenOutFile(char *fileName) {

    m_OutFile.open(fileName);

    if(!m_OutFile.is_open()){
        return 0;
    }

    return 1;
}
int Application::ReadDataFromFile() {

    int index=0;
    ItemType data;

    char filename[FILENAMESIZE];
    cout<<"\n\tEnter Input file Name : ";
    cin>>filename;
    if(!OpenInFile(filename)) {
        cout<<"\nFile not Found";
        return 0;
    }

    while(!m_InFile.eof()){
        data.ReadDataFromFile(m_InFile);
        if(m_InFile.eof()) continue;
        m_List.Add(data);
    }

    m_InFile.close();

    DisplayAllItem();
    return 0;
}

int Application::WriteDataToFile() {
    ItemType data;

    char filename[FILENAMESIZE];
    cout<<"\n\ntEnter Output file Name : ";
    cin>>filename;

    if(!OpenOutFile(filename))return 0;

    m_List.ResetList();

    int length=m_List.GetLength();
    int curIndex=m_List.GenNextItem(data);
    while(curIndex<length && curIndex!=-1){
        data.WriteDataToFile(m_OutFile);
        curIndex=m_List.GenNextItem(data);
    }

    m_OutFile.close();

    return 1;
}

int Application::RetrieveStudent() {
    ItemType data;
    data.SetIdFromKB();

    if(m_List.Get(data)){
        data.DisplayRecordOnScreen();
        return 1;
    }
    else
    {
        cout<<"\n\tNo matching ID ";
        return 0;
    }
}

int Application::DeleteStudent() {
    ItemType data;
    data.SetIdFromKB();

    if(m_List.Get(data)){
        m_List.Delete(data);
        return 1;
    }
    else return -1;
}

int Application::Replace() {
    ItemType data;
    data.SetRecordFromKB();
    ItemType data2=data;
    if(m_List.Get(data)){
        m_List.Replace(data2);
        return 1;
    }
    else return -1;

}


