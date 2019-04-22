#include"Singleton.cpp"
#include"head.h"

int main(){
    setlocale(LC_ALL, "Russian");
    Singleton *s = s->getInstance();
    int button = 1,button2;
    char nm[50];
	while (button) {
    cout << "\nВыберите действие:\n";
    cout << "|1| - Создать создание\n";
    cout << "|2| - Показать создания из файла\n";
    cout << "|3| - Загрузить создание из файла\n";
    cout << "|0| - Выход.\n";
		cin >> button;
		switch (button) {
		case 1:
        s->getcreature();
        s->fenix();
        break;
		case 2:
        cout << "|1| - Показать всю информацию:\n";
        cout << "|2| - Показать информацию о конкретном создании:\n";
        cout << "|0| - Выход.\n";
        cin>>button2;
        if(button2==1)
        s->reincornate(0,"");
        if(button2==2){
        cout<<"Доступные монстры:";
        s->reincornate(1,"");
        cout<<"\nО ком вы бы хотели узнать?\n";
        cin>>nm;
        s->reincornate(2,nm);
        }
        else
        break;
        break;
		case 0:
        break;
        case 3:
        cout<<"Доступные монстры:";
        s->reincornate(1,"");
        cout<<"\nКого бы вы хотели загрузить?\n";
        cin>>nm;
        s->reincornate(3,nm);
		}
	}
}
