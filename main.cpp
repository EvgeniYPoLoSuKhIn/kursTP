#include <iostream>
#include <cstddef>
#include <cstring>
#include<fstream>
using namespace std;

class Singleton {

   private:
   static Singleton *instance;

   Singleton(){}
    char* name=new char[50];
    char* razmer=new char[50];
    char* cvet=new char[50];
    char* svoystva=new char[50];
    char* mifolog=new char[50];
    char* opisaniye=new char[50];
    char* sposobatak=new char[50];
    char buffer[50];
    int tail,wings,legs;
    int clegs=0;

   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }
   void getcreature(){
    cout << "\n������� �������� �������\n";
    cin >> name;
    cout << "�� ����� �� ���������?\n";
    cin >> mifolog;
	cout << "������ �� �������?\n";
	cin >> razmer;
	cout << "����� � ���� �������?\n";
	cin >> cvet;
	cout << "����� � ���� ������ ��������?\n";
	cin >> opisaniye;
	cout << "����� ������� �������� ��� ������\n";
	cin >> sposobatak;
    cout << "� ���� ���� ����(����)? (1 - ��; 0 - ���)\n";
    cin >> legs;
    if(legs==1){
    cout << "������� � ���� ���(����)?\n";
    cin >>clegs;}
    else clegs=0;
    cout << "� ���� ���� ������? (1 - ��; 0 - ���)\n";
    cin >> wings;
   }

   void fenix(){
    ofstream ofs("text.txt", ios::binary| ios::app);
    ofs.write(reinterpret_cast<char*>(&tail), sizeof(tail));
    ofs.write(reinterpret_cast<char*>(&wings), sizeof(wings));
    ofs.write(reinterpret_cast<char*>(&legs), sizeof(legs));
    ofs.write(reinterpret_cast<char*>(&clegs), sizeof(clegs));

    strcpy(buffer,name);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,razmer);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,cvet);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,svoystva);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,mifolog);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,sposobatak);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    strcpy(buffer,opisaniye);
    ofs.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
    ofs.close();
    }

     void reincornate(){
    try
        {
            ifstream ifs("text.txt", ios::binary);
            if (!ifs)
            {
                throw 404;
            }
            else
            {
     while(ifs.read(reinterpret_cast<char*>(&tail), sizeof(tail))!=NULL){
     ifs.read(reinterpret_cast<char*>(&wings), sizeof(wings));
     ifs.read(reinterpret_cast<char*>(&legs), sizeof(legs));
     ifs.read(reinterpret_cast<char*>(&clegs), sizeof(clegs));

     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(name,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(razmer,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(cvet,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(svoystva,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(mifolog,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(sposobatak,buffer);
     ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
     strcpy(opisaniye,buffer);
     show();
     }

     ifs.close();
            }
        }
        catch(int i)
        {
            cout<<"error "<<i<< " - ���� �����������!"<<endl;
        }
     }

     void show(){
    cout << "\n\n��� �������: "<<name;
    cout << "\n���������: "<<mifolog;
	cout << "\n������ �������: "<<razmer;
	cout << "\n�������: "<<cvet;
	cout << "\n������ ��������:"<<opisaniye;
	cout << "\n������� �������� ��� ������: "<<sposobatak;
    cout << "\n������� ���/���? (1 - ����; 0 - ���): "<<legs;
    if(legs==1)
    cout << "\n���������� ���(����): "<<clegs;
    else clegs=0;
    cout << "\n������� �������(1 - ����; 0 - ���): "<<wings;
   }

};

Singleton *Singleton::instance = 0;

int main(){
    setlocale(LC_ALL, "Russian");
    Singleton *s = s->getInstance();
    int button = 1;
	while (button) {
    cout << "�������� ��������:\n";
    cout << "|1| - ������� ��������\n";
    cout << "|2| - ��������� �������� �� �����\n";
    cout << "|0| - �����.\n";
		cin >> button;
		switch (button) {
		case 1:
        s->getcreature();
        s->fenix();
        break;
		case 2:
        s->reincornate();
        break;
		case 0:
        break;
		}
	}
}
