//
// Created by yh960 on 2020-04-03.
//

#ifndef LAB1_ITEMTYPE_H
#define LAB1_ITEMTYPE_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
using std::cout;
enum RelationType{LESS,GREATER,EQUAL};

class ItemType {
public:
    ItemType();
    ~ItemType();

    int GetId() const;


    string GetName() const;// 학생이름반환함수
    string GetAddress() const;// 학생주소반환함수
    void SetId(int inId);// 학생ID 저장함수
    void SetName(string inName);// 학생이름저장함수
    void SetAddress(string inAddress);// 학생주소저장함수
    void SetRecord(int inId, string inName, string inAddress); // 학생정보저장함수
    void DisplayIdOnScreen();// 학생ID 출력함수
    void DisplayNameOnScreen();// 학생이름출력함수
    void DisplayAddressOnScreen();// 학생주소출력함수
    void DisplayRecordOnScreen();//
    void SetIdFromKB();// 키보드로학생ID입력함수
    void SetNameFromKB();// 키보드로학생이름입력함수
    void SetAddressFromKB();// 키보드로학생주소입력함수
    void SetRecordFromKB();// 키보드로학생정보입력함수
    int ReadDataFromFile(ifstream& fin);// 학생정보를파일에서읽는함수
    int WriteDataToFile(ofstream& fout);// 학생정보를파일로출력하는함수
    RelationType CompareByID(const ItemType &data);// primary key (ID)를기준으로학생정보를비교하는함수

    bool operator==(const ItemType& A) {
        if(m_Id==A.GetId())
            return true;
        else false;
    }

    void operator=(const ItemType& _item){
        m_Id=_item.GetId();
        m_sName=_item.GetName();
        m_sAddress=_item.GetAddress();
    }
    bool operator >(const ItemType& A){
        if(m_Id>A.GetId())return true;
        else false;
    }
private:
    int m_Id;// 학생ID
    string m_sName;// 학생이름저장변수
    string m_sAddress;// 학생주소저장변수
};


#endif //LAB1_ITEMTYPE_H
