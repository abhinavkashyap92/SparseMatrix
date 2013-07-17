#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//Function Prototypes not required for client file
node_t add_node(int,int,int,node_t,node_t);
void display_list(node_t);
int multiply(node_t,node_t);
matrix_t add_list(node_t,node_t,int,matrix_t);
//-------------------------------------------------------------------------------------------------------------------
matrix_t init(matrix_t m,int r,int c)
{
	int i;
	int j;
	m=(matrix_t)malloc(sizeof(struct matrix));
	m->row_size=r;
	m->coloumn_size=c;
	for(i=0;i<r;++i)
	{
		m->row_list_array[i]=NULL;
	}
	for(j=0;j<c;++j);
	{
		m->coloumn_list_array[j]=NULL;
	}
	return m;
}

matrix_t create_list(matrix_t m,char* file)
{
	FILE* file_ptr;
	int i,j;
	int a;
	

	file_ptr=fopen(file,"r");
	
	if(file_ptr==NULL)
	{
		printf("No such file exits\n");
		exit(0);
	}
	else
	{
		for(i=0;i < m->row_size; ++i)
		{
			for(j=0; j< m->coloumn_size; ++j)
			{
				fscanf(file_ptr,"%d",&a);
				if(a!=0)
				{
					m->row_list_array[i] = m->coloumn_list_array[j]= add_node(i,j,a, m->row_list_array[i], m -> coloumn_list_array[j]);
				}
			}
		}
	}
	return m;
}

node_t add_node(int r,int c,int ele,node_t row_head,node_t coloumn_head)
{
	node_t temp;
	temp=(node_t)malloc(sizeof(struct node));

	temp->row=r;
	temp->coloumn=c;
	temp->key=ele;
	temp->rlink=NULL;
	temp->clink=NULL;
	

			
			temp->rlink=row_head;
			temp->clink=coloumn_head;
			return temp;
}

void display(matrix_t m)
{
	int i;
	for(i=0;i< m->row_size; ++i)
	{
		display_list(m->row_list_array[i]);
	}
}

void display_list(node_t row_head)
{
	node_t temp;
	temp=row_head;
	
	while(temp)
	{	
		printf("%-4d\t", temp->row);
		printf("%-4d\t" ,temp->coloumn);
		printf("%-4d\t",temp->key);
		temp=temp->rlink;
		printf("\n");
	}
}

matrix_t multiply_matrix(matrix_t m1, matrix_t m2, matrix_t m3)
{
	int i,j;
	int sum;
	if(m1->coloumn_size == m2->row_size)
	{
		//initialise product matrix
		m3=init(m3,m1->row_size,m2->coloumn_size);
		for(i=0;i< m1->row_size ;++i)
		{
			for(j=0; j< m2->coloumn_size;++j)
			{
				sum=multiply(m1->row_list_array[i],m2->coloumn_list_array[j]);
				if(sum!=0)
				{
					m3->row_list_array[i]=m3->coloumn_list_array[j]=add_node(i,j,sum,m3->row_list_array[i],m3->coloumn_list_array[j]);
				}
			}
		}
	}
	else
	{
		printf("Matrix cannot be multiplied\n");
		exit(0);
	}
	return m3;
}

int multiply(node_t row_head,node_t coloumn_head)
{
	int sum=0;


	//this ptr is used to traverse the row list of the first array
	node_t ptr_traversal;
	ptr_traversal=row_head;

	//this ptr is used to traverse the coloumn_list of the second array
	node_t ptr_traversal_1;
	ptr_traversal_1=coloumn_head;

 if(coloumn_head!=NULL&&row_head!=NULL)
{
	
	while(ptr_traversal!=NULL)
	{
		ptr_traversal_1=coloumn_head;

		while(ptr_traversal_1!=NULL&&ptr_traversal_1->row!=ptr_traversal->coloumn)
		{
			ptr_traversal_1=ptr_traversal_1->clink;	
		}
		if(ptr_traversal_1!=NULL)
		{
			sum+=ptr_traversal->key*ptr_traversal_1->key;

		}
		
		ptr_traversal=ptr_traversal->rlink;
		
	}
	return sum;
}

	return sum;

}

matrix_t add_matrix(matrix_t m1,matrix_t m2, matrix_t m3)
{
	int i;
	if(m1->row_size == m2->row_size && m2->coloumn_size == m2->coloumn_size)
	{
		m3=init(m3,m1->row_size,m2->coloumn_size);
		for(i=0;i< m1->row_size; ++i)
		{
			
				m3=add_list(m1->row_list_array[i],m2->row_list_array[i],i,m3);
			
			
		}
		
	}
	
	return m3;
}

matrix_t add_list(node_t row_head,node_t row_head_1,int r, matrix_t m)
{
	//This pointer is used to traverse the row lists of the first matrix
	node_t ptr_traversal;
	ptr_traversal=row_head;
	
	//This pointer is used to traverse the row lists of the second matrix
	node_t ptr_traversal_1;
	ptr_traversal_1=row_head_1;

	while(ptr_traversal!=NULL&&ptr_traversal_1!=NULL) //if either of these pointers become NULL the the loop is terminated
	{
		if(ptr_traversal->coloumn<ptr_traversal_1->coloumn)
		{
		m->row_list_array[r]=m->coloumn_list_array[ptr_traversal_1->coloumn]=add_node(r,ptr_traversal_1->coloumn,ptr_traversal_1->key,m->row_list_array[r],m->coloumn_list_array[ptr_traversal_1->coloumn]);
			ptr_traversal_1=ptr_traversal_1->rlink;
		}

		
		else if(ptr_traversal->coloumn==ptr_traversal_1->coloumn)
		{
m->row_list_array[r]=m->coloumn_list_array[ptr_traversal->coloumn]=add_node(r,ptr_traversal->coloumn,(ptr_traversal->key+ptr_traversal_1->key),m->row_list_array[r],m->coloumn_list_array[ptr_traversal->coloumn]);
			ptr_traversal_1=ptr_traversal_1->rlink;
			ptr_traversal=ptr_traversal->rlink;
		}
	
		else if(ptr_traversal->coloumn>ptr_traversal_1->coloumn)
		{
m->row_list_array[r]=m->coloumn_list_array[ptr_traversal->coloumn]=add_node(r,ptr_traversal->coloumn,ptr_traversal->key,m->row_list_array[r],m->coloumn_list_array[ptr_traversal->coloumn]);
			ptr_traversal=ptr_traversal->rlink;
		}
	}


	if(ptr_traversal!=NULL)
	{
		while(ptr_traversal!=NULL)
		{
			
			m->row_list_array[r]=m->coloumn_list_array[ptr_traversal->coloumn]=add_node(r,ptr_traversal->coloumn,ptr_traversal->key,m->row_list_array[r],m->coloumn_list_array[ptr_traversal->coloumn]);
			ptr_traversal=ptr_traversal->rlink;
		}
	}


	if(ptr_traversal_1!=NULL)
	{
		while(ptr_traversal_1!=NULL)
		{
			
		m->row_list_array[r]=m->coloumn_list_array[ptr_traversal_1->coloumn]=add_node(r,ptr_traversal_1->coloumn,ptr_traversal_1->key,m->row_list_array[r],m->coloumn_list_array[ptr_traversal_1->coloumn]);
			ptr_traversal_1=ptr_traversal_1->rlink;
		}
	}

	
	return m;
}
