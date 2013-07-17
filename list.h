struct node
{
	int key;
	int coloumn;
	int row;
	struct node* rlink;
	struct node* clink;
};
typedef struct node* node_t;

struct matrix
{
	node_t row_list_array[100];
	node_t coloumn_list_array[100];
	int row_size;
	int coloumn_size;
};
typedef struct matrix* matrix_t;

void display(matrix_t);
matrix_t init(matrix_t,int,int);
matrix_t create_list(matrix_t, char*);
matrix_t add_matrix(matrix_t,matrix_t,matrix_t);
matrix_t multiply_matrix(matrix_t,matrix_t,matrix_t);

