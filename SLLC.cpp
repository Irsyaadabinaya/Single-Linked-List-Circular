#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int info;
	struct node *next;
}*start , *end;

class single_list{
	public:
		node* create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
	        void hapusawal();
	        void hapusakhir();
		void delete_pos();
		void display();
		
		single_list(){
			start = NULL;
			end   = NULL;
		}
};

int main(){
	int n, node, elemen, posisi, i;
	single_list s1;
	start=NULL;
	while (1){
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
				s1.hapusawal();
				break;
			case 4:
				cout<<"hapus node akhir"<<endl;
				s1.hapusakhir();
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
node *single_list::create_node(int value){
	struct node *temp, *s;
	temp = new(struct node);
	if (temp==NULL){
		cout<<"Memory tidak di alokasikan"<<endl;
		return 0;
	} else {
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
	}

void single_list::insert_begin(){		//case 1
	int value;
	cout<<"Masukan value: ";cin>>value;
	struct node *temp, *p;
	temp= create_node(value);
	if (start==NULL){
		start = temp;
		start->next = NULL;
	} else {
		p = start;
		start = temp;
		start->next = p;
	}
	cout<<"Element dimasukan pada awal"<<endl;

}
//case 2 
void single_list::insert_last(){
	int value;
	cout<<"masukan value : ";cin>>value;
	struct node *temp, *s;
	temp = create_node(value);
	s = start;
	while (s->next != NULL){
		s=s->next;
	}
	temp->next=NULL;
	s->next = temp;
	cout<<"elemen dimasukan pada akhir"<<endl;	
} 

//case 3
void single_list::hapusawal(){
	struct node *hapus;
     int d;
     if (kosong()==0){
          if(start!=end){
           hapus = start;
           d = hapus->info;
           start = start->next;
           delete hapus;
          } else {
           d = end->info;
           start=end=NULL;
          }
   cout<<d<<" Terhapus"<<endl;
     } else cout<<"Masih kosong\n";
}

//case 4
void single_list::hapusakhir(){
     struct node *bantu,*hapus;
     int d;
     if (kosong()==0){
      bantu = start;
          if(start!=end){
               while(bantu->next!=end){
                bantu = bantu->next;
               }
               hapus = end;
               end=bantu;
               d = hapus->info;
               delete hapus;
               end->next = NULL;
            }else {
            d = end->info;
             start=end=NULL;
            }
      cout<<d<<" Terhapus\n"<<endl;
     } else cout<<"Masih kosong\n";
}	

//case 5
void single_list::insert_pos(){
	int value, pos, counter = 0;
	cout<<"masukan value: ";cin>>value;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	cout<<"masukan posisi yang ingin dituju";cin>>pos;
	int i;
	s = start;
	while (s!=NULL){
		s = s->next;
		counter ++;
	}
	if (pos==1){
		if (start == NULL){
		start = temp;
		start->next= NULL;
		} else {
			ptr = start;
			start = temp;
			start->next=ptr;
		}
	}
	else if (pos>1 && pos <= counter){
			s = start;
			for (i=1; i<pos;i++){
				ptr =s;
				s=s->next;
			}
			ptr->next = temp;
			temp->next = s;
		} else {
			cout<<"posisi terlalu jauh"<<endl;	
		}	
}
//case 6
void single_list::delete_pos(){
	int pos, i, counter = 0;
	if (start == NULL){
		cout<<"list kosong"<<endl;
		return;
	}
	cout<<"masukan posisi yang ingin dihapus";cin>>pos;
	struct node *s, *ptr;
	s = start;
	if (pos==1){
		start = s->next;
	} else {
		while (s!=NULL){
			s=s->next;
			counter++;
		}
		if (pos>0 &&pos <=counter){
			s = start;
			for (i=1; i<pos;i++){
				ptr = s;
				s=s->next;
			}
			ptr->next = s->next;
		} else {
			cout<<"posisi diluar jangkauan"<<endl;
		}
		free(s);
		cout<<"elemen telah dihapus"<<endl;
	}
}





//case 7
void single_list::display(){			
	struct node *temp;
	if (start==NULL) {
		cout<<"list kosong"<<endl;
		return;
	}
	temp = start;
	cout<<"elemen dari list nya adalah : "<<endl;
	while (temp != NULL){
		cout<<temp->info<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	
		}
