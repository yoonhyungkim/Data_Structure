//
// Created by yh960 on 2020-04-03.
//

#include "ArrayList.h"

ArrayList::ArrayList() {
    m_Length=0;
    m_CurPointer=-1;
}

ArrayList::~ArrayList() {

}

void ArrayList::MakeEmpty() {
   m_Length=0;
}

int ArrayList::GetLength() {
    return m_Length;
}

bool ArrayList::IsFull() {
    return m_Length>=MAXSIZE;
}

int ArrayList::Add(ItemType data) {
   if(IsFull())return 0;

    if(this->GetLength()==0){
        m_Array[m_Length++]=data;
    }
    else
    {
        ResetList();
        for(m_CurPointer=0;m_CurPointer<GetLength();m_CurPointer++)     if(data.CompareByID(m_Array[m_CurPointer])==GREATER)break;

        if(m_CurPointer==GetLength()){
            m_Array[m_Length++]=data;
            return 1;
        }
        else{
            int tp=m_Length;
            while(tp>=m_CurPointer){
                m_Array[tp+1]=m_Array[tp];
                tp--;
            }
            m_Array[m_CurPointer]=data;
            m_Length++;
            return 1;
        }

    }
}

void ArrayList::ResetList() {
    m_CurPointer=-1;
}

int ArrayList::GenNextItem(ItemType &data) {
   m_CurPointer++;
    if(m_CurPointer==MAXSIZE)return -1;

    data=m_Array[m_CurPointer];
    return m_CurPointer;
}

const ItemType *ArrayList::getMArray() const {
    return m_Array;
}

bool ArrayList::IsEmpty() {
    return m_Length==0;
}

int ArrayList::Get(ItemType &data) {
    for(m_CurPointer=0;m_CurPointer<m_Length;++m_CurPointer){
        if(data==m_Array[m_CurPointer]){
            data=m_Array[m_CurPointer];
            return m_CurPointer+1;
        }
    }
    return 0;
}

int ArrayList::Delete(ItemType data) {
    bool isFind = false;
    for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
        if (!isFind) {
            if (data == m_Array[m_CurPointer]) {
                isFind = true;
            }
        } else {
            m_Array[m_CurPointer - 1] = m_Array[m_CurPointer];
        }
    }
    m_Length--;
    if (isFind) {
        return 1;
    } else return -1;

}

int ArrayList::Replace(ItemType data) {
    for(m_CurPointer=0;m_CurPointer<m_Length;++m_CurPointer){
        if(m_Array[m_CurPointer]==data){
            m_Array[m_CurPointer]=data;
        }
    }
    return 0;
}

int ArrayList::Retrieve(ItemType &target) {
    ResetList();
    while(true){
        m_CurPointer++;
        if(target.CompareByID(m_Array[m_CurPointer])==EQUAL){
            target=m_Array[m_CurPointer];
            return 1;
        }
        if(target.CompareByID(m_Array[m_CurPointer])==GREATER || m_CurPointer>m_Length)return 0;
    }
}
