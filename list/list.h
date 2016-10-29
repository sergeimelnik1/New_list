using namespace std;
struct List{
	int data;
	struct List *next;
	struct List *prev;
};

struct List *createlist(int data);
void printlist(struct List *first);
struct List * addTobegin(List*lst, int number);
struct List * addToend(List*lst, int number);
void addTomiddle(List**lst, int number, int after);
void deleteElem(List**lst,int number);
struct List *deletehead(List*root);
struct List *deletend(List*root);
struct List * search(List*node, int val);
void sort(List**head);
