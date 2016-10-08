
struct list * init(int a);
struct list * add_elem_end(list *lst, int number);
struct list * addToStart(list *lst, int number);
struct list * delete_elem(list *lst, int n);
struct list * deletehead(list *root);
void listprint(list *lst);
struct list * swap(struct list *lst1, struct list *lst2, struct list *head);
struct list *search(struct list *list, int find_num);

struct list {
    int field; // поле данных
    struct list *next; // указатель на следующий элемент
    struct list *prev; // указатель на предыдущий элемент
};
using namespace std;
