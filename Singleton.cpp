#include "head.h"
#include "Singleton.h"

Singleton *Singleton::instance = 0;
SingletonDestroyer Singleton::destroyer;

SingletonDestroyer::~SingletonDestroyer(){
    delete instance;
    }
    void SingletonDestroyer::initialize( Singleton* p ){
    instance = p;
    }


    Singleton::Singleton() {
    name=new char[50];
    razmer=new char[50];
    cvet=new char[50];
    svoystva=new char[50];
    mifolog=new char[50];
    opisaniye=new char[50];
    sposobatak=new char[50];
     }

     Singleton::~Singleton() {
    delete name;
    delete razmer;
    delete cvet;
    delete svoystva;
    delete mifolog;
    delete opisaniye;
    delete sposobatak;
    }


    Singleton* Singleton::getInstance() {
      if (!instance){
      instance = new Singleton;
      destroyer.initialize( instance);
      }
      return instance;
   }

   void Singleton::getcreature(){
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

   void Singleton::fenix(){
    ofstream ofs("text.txt", ios::binary| ios::app);
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


    ofs.write(reinterpret_cast<char*>(&tail), sizeof(tail));
    ofs.write(reinterpret_cast<char*>(&wings), sizeof(wings));
    ofs.write(reinterpret_cast<char*>(&legs), sizeof(legs));
    ofs.write(reinterpret_cast<char*>(&clegs), sizeof(clegs));
    ofs.close();
    }

     void Singleton::reincornate(int f, char *nm){
    try
        {
            ifstream ifs("text.txt", ios::binary);
            if (!ifs)
            {
                throw 404;
            }
            else
            {
     while(ifs.read(reinterpret_cast<char*>(&buffer), sizeof(buffer))!=NULL){
     if(f==3&&strcmp(buffer,nm))
       ifs.seekg(316,ios::cur);
     else{
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


     ifs.read(reinterpret_cast<char*>(&tail), sizeof(tail));
     ifs.read(reinterpret_cast<char*>(&wings), sizeof(wings));
     ifs.read(reinterpret_cast<char*>(&legs), sizeof(legs));
     ifs.read(reinterpret_cast<char*>(&clegs), sizeof(clegs));
     if(f==1)
     cout<<" \n"<<name;

     if(f==0)
     show();

     if(f==2)
     if(!strcmp(name,nm))
     show();

     if(f==3){
        show();
        break;
     }

     }
     }
     ifs.close();
            }
        }
        catch(int i)
        {
            cout<<"error "<<i<< " - файл отсутствует!"<<endl;
        }
     }

     void Singleton::show(){
    cout << "\n\nИмя монстра: "<<name;
    cout << "\nМифология: "<<mifolog;
	cout << "\nРзамер монстра: "<<razmer;
	cout << "\nОкраска: "<<cvet;
	cout << "\nОсобые свойства:"<<opisaniye;
	cout << "\nКраткое описание его аттаки: "<<sposobatak;
    cout << "\nНаличие ног/лап? (1 - есть; 0 - нет): "<<legs;
    if(legs==1)
    cout << "\nКоличество ног(лапы): "<<clegs;
    cout << "\nНаличие крыльев(1 - есть; 0 - нет): "<<wings<<"\n";
   }



