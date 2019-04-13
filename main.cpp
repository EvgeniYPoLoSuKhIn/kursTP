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
    cout << "\nВведите название монстра\n";
    cin >> name;
    cout << "Из какой он мифологии?\n";
    cin >> mifolog;
	cout << "Какого он размера?\n";
	cin >> razmer;
	cout << "Какая у него окраска?\n";
	cin >> cvet;
	cout << "Какие у него особые свойства?\n";
	cin >> opisaniye;
	cout << "Дайте краткое описание его аттаки\n";
	cin >> sposobatak;
    cout << "У него есть ноги(лапы)? (1 - да; 0 - нет)\n";
    cin >> legs;
    if(legs==1){
    cout << "Сколько у него ног(лапы)?\n";
    cin >>clegs;}
    else clegs=0;
    cout << "У него есть крылья? (1 - да; 0 - нет)\n";
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
            cout<<"error "<<i<< " - файл отсутствует!"<<endl;
        }
     }

     void show(){
    cout << "\n\nИмя монстра: "<<name;
    cout << "\nМифология: "<<mifolog;
	cout << "\nРзамер монстра: "<<razmer;
	cout << "\nОкраска: "<<cvet;
	cout << "\nОсобые свойства:"<<opisaniye;
	cout << "\nКраткое описание его аттаки: "<<sposobatak;
    cout << "\nНаличие ног/лап? (1 - есть; 0 - нет): "<<legs;
    if(legs==1)
    cout << "\nКоличество ног(лапы): "<<clegs;
    else clegs=0;
    cout << "\nНаличие крыльев(1 - есть; 0 - нет): "<<wings;
   }

};

Singleton *Singleton::instance = 0;

int main(){
    setlocale(LC_ALL, "Russian");
    Singleton *s = s->getInstance();
    int button = 1;
	while (button) {
    cout << "Выберите действие:\n";
    cout << "|1| - Создать создание\n";
    cout << "|2| - Загрузить создания из файла\n";
    cout << "|0| - Выход.\n";
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
