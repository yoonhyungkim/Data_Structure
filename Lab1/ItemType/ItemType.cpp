//
// Created by yh960 on 2020-04-03.
//

#include "ItemType.h"

int ItemType::GetId() const {
    return m_Id;
}

string ItemType::GetName() const{
    return m_sName;
}

string ItemType::GetAddress() const {
    return std::__cxx11::string(m_sAddress);
}

void ItemType::SetId(int inId) {
    this->m_Id=inId;
}

void ItemType::SetName(string inName) {
    this->m_sName=inName;
}

void ItemType::SetAddress(string inAddress) {
    this->m_sAddress=inAddress;
}

void ItemType::SetRecord(int inId, string inName, string inAddress) {
    this->m_Id=inId;
    this->m_sName=inName;
    this->m_sAddress=inAddress;
}

void ItemType::DisplayIdOnScreen() {
    cout<<"ID : "<<m_Id<<'\n';
}

void ItemType::DisplayNameOnScreen() {
    cout<<"Name : "<<m_sName<<'\n';
}

void ItemType::DisplayAddressOnScreen() {
    cout<<"Address : "<<m_sAddress<<'\n';
}

void ItemType::DisplayRecordOnScreen() {
    cout<<"\nID : "<<m_Id<<'\n';
    cout<<"Name : "<<m_sName<<'\n';
    cout<<"Address : "<<m_sAddress<<'\n';

}

void ItemType::SetIdFromKB() {
    cout<<"ID : ";
    cin>>m_Id;
}

void ItemType::SetNameFromKB() {
    cout<<"Name : ";
    getline(cin,m_sName);
}

void ItemType::SetAddressFromKB() {
    cout<<"Address : ";
    getline(cin,m_sAddress);
}

void ItemType::SetRecordFromKB() {
    cout<<"ID : ";
    cin>>m_Id;
    cin.ignore();
    cout<<"Name : ";
    getline(cin,m_sName);
    cout<<"Address : ";
    getline(cin,m_sAddress);
}

int ItemType::ReadDataFromFile(ifstream &fin) {
    if(!fin.is_open())return -1;

    //한 단어씪
    fin>>m_Id;
    fin>>m_sName;
    fin>>m_sAddress;

    return 1;
}

int ItemType::WriteDataToFile(ofstream &fout) {
    if(!fout.is_open())return -1;
    fout<<m_Id<<" ";
    fout<<m_sName<<" ";
    fout<<m_sAddress<<" ";
    fout<<endl;
    return 0;
}

RelationType ItemType::CompareByID(const ItemType &data) {
    if (this->m_Id - data.m_Id > 0)return GREATER;
    else if (this->m_Id - data.m_Id < 0)return LESS;
    else EQUAL;
}

ItemType::ItemType() {

}

ItemType::~ItemType() {

}
