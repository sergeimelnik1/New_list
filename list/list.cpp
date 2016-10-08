#include "iostream"
#include "list.h"

struct list * init(int a) { // а- значение первого узла
    struct list *lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = NULL; // указатель на следующий узел
    lst->prev = NULL; // указатель на предыдущий узел
    return lst;
}
struct list * add_elem_end(list *lst, int number) {
    struct list *temp, *p;
    temp = (struct list*)malloc(sizeof(list));//выделение памяти
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->field = number; // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    if (p == NULL)
        p->prev = temp;
    return temp;
}
struct list * addToStart(list *lst, int number){
    struct list *curr = new list;
    curr->field = number;
    curr->prev = NULL;
    curr->next = lst;
    lst = curr;
   
    return lst;
}
struct list * delete_elem(list *lst, int n) {
   struct list *find_elem = search(lst,n);
    struct list *prev, *next;
    prev = find_elem->prev; // узел, предшествующий lst
    next = find_elem->next; // узел, следующий за lst
    if (prev != NULL)
        prev->next = find_elem->next; // переставляем указатель
    if (next != NULL)
        next->prev = find_elem->prev; // переставляем указатель
    free(find_elem); // освобождаем память удаляемого элемента
    return prev;
}
struct list * deletehead(list *root) {
    struct list *temp;
    temp = root->next;
    temp->prev = NULL;
    free(root);   // освобождение памяти текущей вершины
    return temp; // новая вершина списка
}
struct list * deleteend(list *root) {
    struct list *temp;
    temp = root->prev;
    temp->next = NULL;
    free(root);
    return temp;
}
void listprint(list *lst) {
    struct list *p;
    p = lst;
    do {
        cout << p->field; // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != NULL); // условие окончания обхода
}
struct list *swap(struct list *lst1, struct list *lst2, struct list *head) {
    // Возвращает новый корень списка
    struct list *prev1, *prev2, *next1, *next2;
    prev1 = lst1->prev;  // узел предшествующий lst1
    prev2 = lst2->prev;  // узел предшествующий lst2
    next1 = lst1->next; // узел следующий за lst1
    next2 = lst2->next; // узел следующий за lst2
    if (lst2 == next1) { // обмениваются соседние узлы
        lst2->next = lst1;
        lst2->prev = prev1;
        lst1->next = next2;
        lst1->prev = lst2;
        next2->prev = lst1;
        if (lst1 != head)
            prev1->next = lst2;
    }
    else if (lst1 == next2) { // обмениваются соседние узлы
        lst1->next = lst2;
        lst1->prev = prev2;
        lst2->next = next1;
        lst2->prev = lst1;
        next1->prev = lst2;
        if (lst2 != head)
            prev2->next = lst1;
    }
    else { // обмениваются отстоящие узлы
        if (lst1 != head)
            prev1->next = lst2;
        lst2->next = next1;
        if (lst2 != head)
            prev2->next = lst1;
        lst1->next = next2;
        lst2->prev = prev1;
        if (next2 != NULL)
            next2->prev = lst1;
        lst1->prev = prev2;
        if (next1 != NULL)
            next1->prev = lst2;
    }
    if (lst1 == head)
        return(lst2);
    if (lst2 == head)
        return(lst1);
    return head;
}
struct list *search(struct list *list, int find_num){
    while(list!=NULL && list->field!=find_num){
        list=list->next;
    }

    return list;
}
