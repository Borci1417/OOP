#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

//  Razred zaposlenih
class Zaposleni {
private:
    int davcna;
    float placa;
public:
    string ime;
    string priimek;
    string naslov;
    
    // Setter
    void setPlaca(int p) {
        placa = p;
    }

    // Getter
    int getPlaca() {
        return placa;
    }

    void setDavcna(int d) {
        davcna = d;
    }

    // Getter
    int getDavcna() {
        return davcna;
    }
};
//Derived class
class Naslov: public Zaposleni{
    public:
    string address;
}; 
//main
int main() {
    int n = 30;
    random_device rd;
    string imena[30] = {"Boris", "Franc", "Marija", "Janez", "Ana", "Marko", "Maja", "Ivan", "Irena", "Anton", "Mojca", "Andrej", "Mateja", "Jožef", "Nina", "Jože", "Nataša", "Luka", "Andreja", "Peter", "Barbara", "Marjan", "Jožica", "Matej", "Petra", "Tomaž", "Eva", "Milan", "Anja", "Katja"};
    string priimki[30]= {"Novak", "Preseren", "Dukaric", "Cus", "Ornik", "Hlis", "Svensek", "Cankar", "Antolic", "Askerc", "Patekar", "Lampret", "Oresek", "Rizman", "Arnus", "Drofenik", "Pecar", "Cafuta", "Pivec", "Klepec", "Zenko", "Ceh", "Dragica", "Lev", "Golob", "Golub", "Gaspar", "Stojanovic", "Pecnik", "Krajnc"};
    string address[30]={"Cali","Hyderabad","Taichung","Karachi","Rio de Janeiro","Hyderabad","Kanpur","Dakar","Caracas","Isfahan","Rome","Belo Horizonte","Dhaka","Casablanca","Madrid","Cologne","Saitama","Bhopal","Managua","Almaty","Suwon","Moscow","New York City","Hiroshima","Montevideo","Quezon City","São Paulo","Nizhny Novgorod","Manila","Surat"};
    Zaposleni delavec;
    vector<Zaposleni> worker(n);
    vector<Zaposleni> temp(2);
//zanka za izpis
    for(int i = 0; i<n; i++)
    {
        worker[i].ime = imena[rd()%20];
        cout<<worker[i].ime<<endl;

        worker[i].priimek = priimki[rd()%20];
        cout<<worker[i].priimek<<endl;

        worker[i].naslov = address[rd()%20];
        cout<<worker[i].naslov<<endl;

        worker[i].setPlaca(rd()%2000+1000);
        worker[i].getPlaca();
        cout<<"$"<<worker[i].getPlaca()<<endl;

        worker[i].setDavcna(rd()%100000000);
        worker[i].getDavcna();
        cout<<worker[i].getDavcna()<<endl<<endl;
    }
//zanka za razvrstitev
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(worker[i].getPlaca()>worker[j].getPlaca())
            {
                swap(temp[0], worker[i]);
                swap(worker[i], worker[j]);
                swap(worker[j], temp[0]);
            }
        }
    }
//izpis najvišje in najmanjše plače
    cout<<"Najvisja placa: "<<endl;
    cout<<worker[0].ime<<endl;
    cout<<worker[0].priimek<<endl;
    cout<<worker[0].naslov<<endl;
    cout<<"$"<<worker[0].getPlaca()<<endl;
    cout<<worker[0].getDavcna()<<endl;
    cout<<endl;

    cout<<"Najmanjsa placa: "<<endl;
    cout<<worker[n-1].ime<<endl;
    cout<<worker[n-1].priimek<<endl;
    cout<<worker[n-1].naslov<<endl;
    cout<<"$"<<worker[n-1].getPlaca()<<endl;
    cout<<worker[n-1].getDavcna()<<endl;
    cout<<endl;

    float vsota;
//zanka
    for(int i = 0;i<n;i++)
    {
        vsota = vsota + worker[i].getPlaca();
    }
    vsota = vsota/n;
    cout<<vsota;

    float nagrada;
//zanka za določanje nagrade
    for(int i = 0;i<n;i++)
    {
        nagrada = rd()%20+10;
        nagrada = nagrada/100;
        nagrada = nagrada+1;
        worker[i].getPlaca()*nagrada;
    }
//zanka za razvrstitev
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
        //pogoj
            if(worker[i].getPlaca()>worker[j].getPlaca())
            {
                swap(temp[0], worker[i]);
                swap(worker[i], worker[j]);
                swap(worker[j], temp[0]);
            }
        }
    }
//zanka za izpis
    for(int i = 0; i<n;i++)
    {
        cout<<"Delavec "<<i+1<<endl;
        cout<<worker[i].ime<<endl;
        cout<<worker[i].priimek<<endl;
        cout<<worker[i].naslov<<endl;
        cout<<worker[i].getDavcna()<<endl;
        cout<<"$"<<worker[i].getPlaca()<<endl;
        cout<<endl;
    }

    return 0;
}
