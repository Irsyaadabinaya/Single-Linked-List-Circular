#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int info;
	struct node *next;
}*start;

class single_list{
	public:
		node* create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
		void delete_pos();
		void display();
		
		single_list(){
			start = NULL;
		}
};

int main(){
	int n, node, elemen, posisi, i;
	single_list s1;
	start=NULL;
	while (1){        //biar dia ngulang terus wktu selesai satu case, dibuat looping.
		cout<<"1. masukan node di awal"<<endl;
		cout<<"2. masukan node di akhir"<<endl;
		cout<<"3. hapus node awal"<<endl;
		cout<<"4. hapus node akhir"<<endl;
		cout<<"5. masukan node pada posisi tertentu"<<endl;
		cout<<"6. menghapus node tertentu"<<endl;
		cout<<"7. display linked list"<<endl;
		cout<<"8. exit"<<endl;
		cout<<"pilihan : ";
		cin>>n;
		switch(n){
			case 1:
				cout<<"Masukan node di awal"<<endl;
				s1.insert_begin();
				cout<<endl;
				break;
			case 2:
				cout<<"Masukan node di akhir"<<endl;
				s1.insert_last();
				cout<<endl;
				break;
			case 3:
				cout<<"hapus node awal"<<endl;
				//belom
				break;
			case 4:
				cout<<"hapus node akhir"<<endl;
				//belom juga
				break;
			case 5:
				cout<<"masukan node di posisi tertentu"<<endl;
				s1.insert_pos();
				cout<<endl;
				break;
			case 6:
				cout<<"menghapus node tertentu"<<endl;
				s1.delete_pos();
				cout<<endl;
				break;
			case 7:
				cout<<"display list"<<endl;
				s1.display();
				cout<<endl;
				break;
			case 8:
				cout<<"byee"<<endl;
				return 0;
			default:
				cout<<"tidak ada pilihan";
		}
	}
}

//isi dari sini
