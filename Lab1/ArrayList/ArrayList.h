//
// Created by yh960 on 2020-04-03.
//

#ifndef LAB1_ARRAYLIST_H
#define LAB1_ARRAYLIST_H

#include "../ItemType/ItemType.h"

#define MAXSIZE 5

class ArrayList {
public:
    ArrayList();
    ~ArrayList();

    void MakeEmpty();
    int GetLength();

    const ItemType *getMArray() const;

    bool IsFull();
    int Add(ItemType data);
    void ResetList();
    int GenNextItem(ItemType& data);

    bool IsEmpty();
    int Get(ItemType& data);
    int Delete(ItemType data);
    int Replace(ItemType data);

    int Retrieve(ItemType& target);

private:
    ItemType m_Array[MAXSIZE];
    int m_Length;
    int m_CurPointer;

};


#endif //LAB1_ARRAYLIST_H
