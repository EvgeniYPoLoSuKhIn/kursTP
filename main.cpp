#include"Singleton.cpp"
#include"head.h"

int main(){
    setlocale(LC_ALL, "Russian");
    Singleton *s = s->getInstance();
    int button = 1,button2;
    char nm[50];
	while (button) {
    cout << "\n�������� ��������:\n";
    cout << "|1| - ������� ��������\n";
    cout << "|2| - �������� �������� �� �����\n";
    cout << "|3| - ��������� �������� �� �����\n";
    cout << "|0| - �����.\n";
		cin >> button;
		switch (button) {
		case 1:
        s->getcreature();
        s->fenix();
        break;
		case 2:
        cout << "|1| - �������� ��� ����������:\n";
        cout << "|2| - �������� ���������� � ���������� ��������:\n";
        cout << "|0| - �����.\n";
        cin>>button2;
        if(button2==1)
        s->reincornate(0,"");
        if(button2==2){
        cout<<"��������� �������:";
        s->reincornate(1,"");
        cout<<"\n� ��� �� �� ������ ������?\n";
        cin>>nm;
        s->reincornate(2,nm);
        }
        else
        break;
        break;
		case 0:
        break;
        case 3:
        cout<<"��������� �������:";
        s->reincornate(1,"");
        cout<<"\n���� �� �� ������ ���������?\n";
        cin>>nm;
        s->reincornate(3,nm);
		}
	}
}
