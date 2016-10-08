#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "list.h"



int main() {
    list *head, *cur;
    int num;
    // Создаем список из 10 элементов
    cout << "a = ";
    cin >> num;
    head = init(num);
    cur = head;
    for (int i = 0; i < 9; i++) {
        cout << "a = ";
        cin >> num;
        cur = add_elem_end(cur, num);
    }
    listprint(head);
    cout << endl;
    // Удаляем третий элемент списка
//    cur = head->next->next;
    delete_elem(cur, 3);
    listprint(head);
    cout << endl;
    return 0;
}
