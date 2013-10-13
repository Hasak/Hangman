#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<fstream>
#include<time.h>
#include<conio.h>
using namespace std;
int main()
{
    int n,i,a,b,c,d,r,ukupno;
    char pr[20],slovo,odabir;
    string rijec,crt,sl,pitanje,rec;
    while(1>0)
    {
    b=0,c=0,d=0,ukupno=0;
    system("cls");
    srand(time(NULL));
    cout<<" __    __  ________  ___     __  _________  ___      ___  _" <<"_______  ___     __"<<endl;
    cout<<"|  |  |  ||        ||   \\   |  ||         ||   \\    /   |" <<"|        ||   \\   |  |"<<endl;
    cout<<"|  |  |  ||   __   ||    \\  |  ||   ______||    \\  /    |" <<"|   __   ||    \\  |  |"<<endl;
    cout<<"|  |__|  ||  |__|  ||     \\ |  ||  |       |     \\/     |" <<"|  |__|  ||     \\ |  |"<<endl;
    cout<<"|        ||        ||  |\\  \\|  ||  |  ____ |  |\\    /|  |"<<"|        ||  |\\  \\|  |"<<endl;
    cout<<"|   __   ||   __   ||  | \\     ||  | |_   ||  | \\__/ |  |" <<"|   __   ||  | \\     |"<<endl;
    cout<<"|  |  |  ||  |  |  ||  |  \\    ||  |___|  ||  |      |  |"  <<"|  |  |  ||  |  \\    |"<<endl;
    cout<<"|  |  |  ||  |  |  ||  |   \\   ||         ||  |      |  |"  <<"|  |  |  ||  |   \\   |"<<endl;
    cout<<"|__|  |__||__|  |__||__|    \\__||_________||__|      |__|"  <<"|__|  |__||__|    \\__|"<<endl;
    cout<<endl<<"Molimo odaberite: \n"<<endl<<"1. Nasumicna rijec"<<endl<<"2. Napisati rijec"<<endl<<"3. Dopisati rijec"<<endl<<"4. Ispis rijeci"<<endl<<"5. Zatvori"<<endl;
    odabir=getch();
    system("cls");
    if(odabir=='1')
    {
        fstream file("hangman.txt");
        while(getline(file,rijec))
            b++;
        file.close();
        file.open("hangman.txt");
        r=rand() % b + 1;
        for(i=0;i<r;i++)
            file>>rijec;
        file.close();
    }
    if(odabir=='2')
    {
        cout<<"Unesi rijec"<<endl;cin>>rijec;
    }
    if(odabir=='3')
        do
        {
            system("cls");
            ukupno=0;
            cout<<"Unesi rijec"<<endl;cin>>rijec;
            ofstream file;
            file.open("hangman.txt", ios_base::app);
            file<<endl<<rijec;
            file.close();
            cout<<endl<<"Dodavanje uspjesno"<<endl<<"Zelite li jos dodati?"<<endl;
            cin>>pitanje;
            if(pitanje!="ne" && pitanje!="da")
            {
                cout<<"Greska!"<<endl;
                system("pause");
                return 0;
            }
        }
        while(pitanje=="da");
    if(odabir=='4')
    {
        b++;
        fstream file("hangman.txt");
        while(getline(file,rijec))
            cout<<b++<<". "<<rijec<<endl;
        cout<<endl;
        file.close();
        system("pause");
    }
    if(odabir=='5')
        return 0;
    if(odabir=='1' || odabir=='2')
    {
    a=rijec.length();
    for(i=0;i<a;i++)
        pr[i]='-';
    pr[a]='\0';
    crt=pr;
    while(c<6)
    {
        system("cls");
        if(c==0)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |"<<endl<<"   |"<<endl<<"   |"<<endl<<"   |"<<endl<<"   |"<<endl;
            cout<<"   |"<<endl<<"   |"<<endl<<"  / \\"<<endl<<" /   \\"<<endl<<"/     \\"<<endl;
        }
        if(c==1)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / oo \\"<<endl<<"   |       \\____/"<<endl;
            cout<<"   |     "<<endl<<"   |     "<<endl<<"   |"<<endl<<"   |"<<endl<<"  / \\"<<endl<<" /   \\"<<endl<<"/     \\"<<endl;
        }
        if(c==2)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / oo \\"<<endl<<"   |       \\____/"<<endl;
            cout<<"   |         |"<<endl<<"   |         |"<<endl<<"   |         |"<<endl<<"   |         |"<<endl<<"  / \\"<<endl;
            cout<<" /   \\"<<endl<<"/     \\"<<endl;
        }
        if(c==3)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / oo \\"<<endl<<"   |       \\____/"<<endl;
            cout<<"   |         |"<<endl<<"   |        /|"<<endl<<"   |       / |"<<endl<<"   |         |"<<endl;
            cout<<"  / \\"<<endl<<" /   \\"<<endl<<"/     \\"<<endl;
        }
        if(c==4)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / oo \\"<<endl<<"   |       \\____/"<<endl;
            cout<<"   |         |"<<endl<<"   |        /|\\"<<endl<<"   |       / | \\"<<endl<<"   |         |"<<endl;
            cout<<"  / \\"<<endl<<" /   \\"<<endl<<"/     \\"<<endl;
        }
        if(c==5)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / OO \\"<<endl;
            cout<<"   |       \\____/"<<endl<<"   |         |"<<endl<<"   |        /|\\"<<endl<<"   |       / | \\"<<endl;
            cout<<"   |         |"<<endl<<"  / \\       /"<<endl<<" /   \\     /"<<endl<<"/     \\"<<endl;
        }
        cout<<endl<<crt<<endl<<"Gesaka za napravit: "<<6-c<<endl;
        cout<<"Unesi slovo"<<endl<<endl;
        cin>>slovo;
        sl=slovo;
        n=rijec.find_first_of(sl);
        if(n<0)
            c++;
        else
            while(n!=-1)
            {
                if(rijec[n]!=crt[n])
                    d++;
                crt[n]=slovo;n=rijec.find_first_of(sl,n+1);
            }
        if(d>=a)
        {
            system("cls");
            cout<<"     ____"<<endl<<"    / ^^ \\"<<endl<<"    \\____/"<<endl<<"      |"<<endl<<"    \\ | /"<<endl<<"     \\|/ "<<endl;
            cout<<"      |"<<endl<<"      |"<<endl<<"     / \\"<<endl<<"    /   \\"<<endl<<endl;
            cout<<"Trazena rijec: "<<rijec<<endl<<endl<<"Cestitamo!"<<endl<<endl;
            system("pause");
            break;
        }
        system("cls");
        if(c==6)
        {
            cout<<"   ___________"<<endl<<"   |/        |"<<endl<<"   |        ____"<<endl<<"   |       / xx \\"<<endl<<"   |       \\____/"<<endl;
            cout<<"   |         |"<<endl<<"   |        /|\\"<<endl<<"   |       / | \\"<<endl<<"   |         |"<<endl<<"  / \\       / \\"<<endl;
            cout<<" /   \\     /   \\"<<endl<<"/     \\"<<endl<<endl<<"Netacno :("<<endl<<"Trazena rijec je: "<<rijec<<endl<<endl;
            system("pause");
        }}}}}
