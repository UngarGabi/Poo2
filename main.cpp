#include<iostream>
#include<string>
#include<vector>

class Produs {
private:
    double pret;
    std::string nume;
public:
    Produs() = default;
    Produs(double pret, std::string nume) : pret(pret), nume(nume) {}
    std::string getNume() {
        return nume;
    }
    int getPret(){
        return pret;
    }
    bool operator==(const Produs& produs) {
        return (this->nume == produs.nume); //Supraincarcare operator == pentru a verifica daca produsul ales se afla in lista de produse
    }
    friend std::ostream& operator<<(std::ostream& out, const Produs& produs);
    friend class Manager;
};

std::ostream& operator<<(std::ostream& out, const Produs& produs) {
    out << "Nume produs: " << produs.nume << '\n' << "Pret produs: " << produs.pret << '\n' << '\n';
    return out;
}
//Produs

class Magazin {
public:
    virtual void AdaugaProdus(const Produs& produs) = 0; //Adauga produse pe raion
    virtual void EliminaProdus(const Produs& produs) = 0; //Elimina produse de pe raion
    virtual void AfiseazaListaProduse() = 0; //Afiseaza produsele de pe raion
    virtual Produs cautare(std::string alegere) = 0; // Cauta produsul in lista pentru a-l pune in cos
    virtual int marimevector() = 0; //Marimea listei
    virtual ~Magazin(){};
};
//Interfata Raioane magazin
class RaionHaine: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseHaine;
public:
    void AdaugaProdus(const Produs& produs) override {
        int n = produseHaine.size();
        produseHaine.push_back(produs);
        produseHaine.resize(n + 1);
    }

    void EliminaProdus(const Produs& produs) override {
        int n = produseHaine.size();
        int ok = 1;
        for (int i = 0; i < n; i++) { //Parcurg vectorul si vad daca se afla produsul ales in lista
            if (produseHaine[i] == produs) {
                produseHaine.erase(produseHaine.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<< '\n';
                produseHaine.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<< '\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i < produseHaine.size(); i++)
            std::cout << produseHaine[i];
        std::cout << '\n';
    }

    Produs cautare(std::string alegere) override {
        Produs null(-1,"null");
        int ok = 0;
        int i;
        for (i = 0; i < produseHaine.size(); i++) { //caut produsul ales in vector iar daca il gasesc il returnez pentru a fi folosit, in cazul in care nu il gasesc returnez un produs null
            if (alegere == produseHaine[i].getNume()) {
                ok = 1;
                break;
            }
        }
        if (ok == 1)
            return produseHaine[i];
        else
            return null;
    }

    int marimevector() override{
        return produseHaine.size();
    }
    ~RaionHaine(){};
};
//Haine


class RaionDulce: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseDulci;
public:
    void AdaugaProdus(const Produs& produs) override {
        int n = produseDulci.size();
        produseDulci.push_back(produs);
        produseDulci.resize(n + 1);
    }

    void EliminaProdus(const Produs& produs) override {
        int n = produseDulci.size();
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (produseDulci[i] == produs) { //Parcurg vectorul si vad daca se afla produsul ales in lista
                produseDulci.erase(produseDulci.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<<'\n';
                produseDulci.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<<'\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i < produseDulci.size(); i++)
            std::cout << produseDulci[i];
        std::cout << '\n';
    }

    Produs cautare(std::string alegere) override {
        Produs null(-1,"null");
        int ok = 0;
        int i;
        for (i = 0; i < produseDulci.size(); i++) {//caut produsul ales in vector iar daca il gasesc il returnez pentru a fi folosit, in cazul in care nu il gasesc returnez un produs null
            if (alegere == produseDulci[i].getNume()) {
                ok = 1;
                break;
            }
        }
        if (ok == 1)
            return produseDulci[i];
        else
            return null;
    }

    int marimevector() override{
        return produseDulci.size();
    }
    ~RaionDulce(){};
};
// Dulciuri

class RaionBauturi: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseBauturi;
public:
    void AdaugaProdus(const Produs& produs) override {
        int n = produseBauturi.size();
        produseBauturi.push_back(produs);
        produseBauturi.resize(n + 1);
    }

    void EliminaProdus(const Produs& produs) override {
        int n = produseBauturi.size();
        int ok = 1;
        for (int i = 0; i < n; i++) { //Parcurg vectorul si vad daca se afla produsul ales in lista
            if (produseBauturi[i] == produs) {
                produseBauturi.erase(produseBauturi.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<< '\n';
                produseBauturi.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<< '\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i < produseBauturi.size(); i++)
            std::cout << produseBauturi[i];
        std::cout << '\n';
    }

    Produs cautare(std::string alegere) override {
        Produs null(-1,"null");
        int ok=0;
        int i;
        for (i = 0; i < produseBauturi.size(); i++) { //caut produsul ales in vector iar daca il gasesc il returnez pentru a fi folosit, in cazul in care nu il gasesc returnez un produs null
            if (alegere == produseBauturi[i].getNume()) {
                ok = 1;
                break;
            }
        }
        if(ok==1)
            return produseBauturi[i];
        else
            return null;
    }

    int marimevector() override{
        return produseBauturi.size();
    }
    ~RaionBauturi(){};
};
//Bauturi


class Client {
private:
    std::string nume;
    double bani;
    std::vector<Produs> Cos;
public:
    Client() = default;
    Client(std::string nume, double bani) {
        this->nume=nume;
        this->bani=bani;
    }
    std::string getNume(){
        return nume;
    }
    double getBani(){
        return bani;
    }
    void AdaugaCos(const Produs& produs) {
        Cos.push_back(produs);
    }
    void EliminaCos(const Produs& produs) {
        int nr=Cos.size();
        int ok = 1;
        for (int i = 0; i < nr; i++) {
            if (Cos[i] == produs) {
                Cos.erase(Cos.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat din cos"<< '\n';
                Cos.resize(nr - 1);
                break;
            }
        }
    }
    void AfiseazaListaProduseCos() {
        for (int i = 0; i < Cos.size(); i++)
            std::cout << Cos[i];
    }
    int sumaCos() {
        int sum = 0;
        int nr = Cos.size();
        for (int i = 0; i < nr; i++)
            sum += Cos[i].getPret();
        return sum;
    }
    void cumparaProduse() {
        int a = sumaCos();
        if (bani >= a) {
            bani -= a;
            std::cout << "Multumim pentru cumparaturi!" << '\n';
        }
        else {
            std::cout << "Tranzactie esuata, fonduri insuficiente." << '\n';
        }
    }
    friend std::istream& operator>>(std::istream& in, Client& client);
};

std::istream& operator>>(std::istream& in, Client& client){
    std::cout<<"Nume client:";
    in>>client.nume;
    std::cout<<"Suma de bani pe care o are:";
    in>>client.bani;
    return in;
}

class Angajat {
protected:
    std::string nume;
    int id;
public:
    virtual void Rol() = 0;
    int logare(int cod) {
        if (cod == id)
            return 1;
        else
            return 0;
    }
    virtual ~Angajat(){};
};

class Manager : public Angajat {
private:
    std::string raion;
public:
    Manager()=default;
    Manager(std::string nume, int id, std::string raion) {
        this->nume = nume;
        this->id = id;
        this->raion = raion;
    }

    void Rol() override {
        std::cout << nume << " este un manager" << '\n';
    }

    void scumpire(Produs& produs, int procent){
        produs.pret+=produs.pret*procent/100;
    }
    void ieftinire(Produs& produs, int procent){
        produs.pret-=produs.pret*procent/100;
    }
    ~Manager(){};
};

class Casier : public Angajat {
private:
    std::string casa;
public:
    Casier() = default;
    Casier(std::string nume, int id, std::string casa) {
        this->nume = nume;
        this->id = id;
        this->casa = casa;
    }

    void Rol() override {
        std::cout << nume << " este casier/a." << '\n';
    }

    void setcasa(std::string casanoua){
        casa = casanoua;
    }

    void deschide() {
        std::cout << "Deschidem " << casa << " pentru clienti." << '\n';
    }
    ~Casier(){};
};

class Ingrijitor : public Angajat {
private:
    std::string raion;
public:
    Ingrijitor() = default;
    Ingrijitor(std::string nume, int id, std::string raion) {
        this->nume = nume;
        this->id = id;
        this->raion = raion;
    }

    void Rol() override {
        std::cout << nume << " este ingrijitor." << '\n';
    }

    void spala() {
        std::cout << "Am spalat raionul" << raion << '\n';
    }

    void setraion(std::string raionnou) {
        raion = raionnou;
    }
    ~Ingrijitor(){};
};
class Bon{
private:
    std::string numeclient;
    double pret;
    static std::string data;
public:
    Bon() = default;
    Bon(std::string numeclient, double pret) {
        this->numeclient = numeclient;
        this->pret = pret;
    }
    static void setData(std::string Data) {
        data = Data;
    }

    static void afiseazadata() {
        std::cout << data << '\n';
    }
    friend std::ostream& operator<<(std::ostream& out, Bon& bon);
    ~Bon(){};
};

std::ostream& operator<<(std::ostream& out, Bon& bon) {
    out << "Produsele au fost cumparate de:" << '\n';
    out << bon.numeclient << '\n';
    out << "Pentru pretul de:" << '\n';
    out << bon.pret << '\n';
    out << "Produsele au fost cumparate la data de:" << '\n';
    out << bon.data << '\n';
    return out;
}
std::string Bon::data="";

int main() {
    Produs ciocolata(20,"Milka");
    Produs jeleu(10,"Haribo");
    Produs biscuite(15,"Oreo");
    Produs croissant(5,"7days");
    Produs bomboane(10,"Merci");

    Produs suc(5,"Fanta");
    Produs vin(10,"Mateus");
    Produs apa(30,"Aqua");
    Produs bere(5,"Peroni");
    Produs vodka(10,"Finlandia");

    Produs tricou(50,"Tricou_albastru");
    Produs sosete(10,"Sosete_albe");
    Produs caciula(30,"Caciula_neagra");
    Produs geaca(50,"Geaca_gri");
    Produs pantaloni(10,"pantaloni_albe");

    RaionDulce dulce;
    RaionHaine haine;
    RaionBauturi bauturi;

    dulce.AdaugaProdus(ciocolata);
    dulce.AdaugaProdus(biscuite);
    dulce.AdaugaProdus(jeleu);
    dulce.AdaugaProdus(bomboane);
    dulce.AdaugaProdus(croissant);

    bauturi.AdaugaProdus(vin);
    bauturi.AdaugaProdus(suc);
    bauturi.AdaugaProdus(apa);
    bauturi.AdaugaProdus(bere);
    bauturi.AdaugaProdus(vodka);

    haine.AdaugaProdus(tricou);
    haine.AdaugaProdus(sosete);
    haine.AdaugaProdus(caciula);
    haine.AdaugaProdus(geaca);
    haine.AdaugaProdus(pantaloni);

    std::vector<Produs> produse;

    produse.push_back(ciocolata);
    produse.push_back(jeleu);
    produse.push_back(biscuite);
    produse.push_back(croissant);
    produse.push_back(bomboane);
    produse.push_back(suc);
    produse.push_back(vin);
    produse.push_back(apa);
    produse.push_back(bere);
    produse.push_back(vodka);
    produse.push_back(tricou);
    produse.push_back(sosete);
    produse.push_back(caciula);
    produse.push_back(geaca);
    produse.push_back(pantaloni);


    std::vector<Angajat*> angajati;

    angajati.push_back(new Manager("Gabi", 1111, "haine"));
    angajati.push_back(new Casier("Alex",1111," casa2"));
    angajati.push_back(new Casier("Tudor",1111, "casa1"));

    int okmare1=1;
        std::cout << "Doresc angajatii sa schimbe ceva(Da/Nu)?" << '\n';
        std::string s;
        int id;
        int okid = 0;
        int okpret;
        Manager manager;
        Casier casier;
        Ingrijitor ingrijitor;
        std::string produsul;
        std::string casaaleasa;
        std::string raionales;
        std::cin >> s;
        if (s == "Da") {
            std::cout <<" Va rugam selectati data zilei de azi:" <<'\n';
            std::string data;
            std::cin >> data;
            Bon::setData(data);
            while(okmare1==1) {
                std::cout << "introduceti ID(toate sunt 1111):" << '\n';
                std::cin >> id;
                for (Angajat *angajat: angajati) {
                    if (angajat->logare(id) == 1) {
                        std::cout << "ID corect!" << '\n';
                        okid = 1;
                        break;
                    }
                }
                if (okid == 1) {
                    std::cout << "Ce rol aveti?" << '\n';
                    std::cout << "1.Manager" << '\n';
                    std::cout << "2.Casier" << '\n';
                    std::cout << "3.Ingrijitor" << '\n';
                    int caz;
                    std::cin>>caz;
                    switch(caz) {
                        case 1:
                            std::cout << "Ce doriti sa faceti?" << '\n';
                            std::cout << "1. Cresc pretul unui produs." << '\n';
                            std::cout << "2. Scad pretul unui produs." << '\n';
                            int Alegere;
                            int procent;
                            std::cin >> Alegere;
                            okpret = 0;
                            if (Alegere == 1) {
                                std::cout << "Alegeti un produs" << '\n';
                                std::cin >> produsul;
                                std::cout << "Alegeti un procent cu care sa scumpiti" << '\n';
                                std::cin >> procent;
                                int n = produse.size();
                                for (int i = 0; i < n; i++)
                                    if (produse[i].getNume() == produsul) {
                                        manager.scumpire(produse[i], procent);
                                        std::cout << produse[i] << '\n';
                                        okpret = 1;
                                        break;
                                    }
                                if (okpret == 0)
                                    std::cout << "Produsul nu exista" << '\n';
                            }
                            else
                                if (Alegere == 2) {
                                    std::cout << "Alegeti un produs" << '\n';
                                    std::cin >> produsul;
                                    std::cout << "Alegeti un procent cu care sa ieftiniti" << '\n';
                                    std::cin >> procent;
                                    int n = produse.size();
                                    for (int i = 0; i < n; i++)
                                        if (produse[i].getNume() == produsul) {
                                            manager.ieftinire(produse[i], procent);
                                            std::cout << produse[i] << '\n';
                                            okpret = 1;
                                            break;
                                        }
                                    if (okpret == 0)
                                        std::cout << "Produsul nu exista" << '\n';
                                }
                            else
                                std::cout << "Alegere gresita";
                            break;

                        case 2:
                            std::cout << "Ce casa deschideti?" << '\n';
                            std::cin>>casaaleasa;
                            casier.setcasa(casaaleasa);
                            casier.deschide();
                            break;
                        case 3:
                            std::cout << "Ce raion curatati?" << '\n';
                            std::cin>>raionales;
                            ingrijitor.setraion(raionales);
                            ingrijitor.spala();
                            break;
                        default:
                            std::cout << "Rol introdus gresit" << '\n';
                    }
                }
                std::cout << "Mai sunt si alti angajati?" << '\n';
                std::string alegereangajat;
                std::cin >> alegereangajat;

                if (alegereangajat == "Nu")
                    okmare1 = 0;
            }

        }
        std::cout<<"Sunt clienti la coada?" << '\n';
        std::cin>>s;
            if (s == "Da") {
                int okmare2 = 1;
                while (okmare2 == 1) {
                    Client client;
                    std::cin >> client;
                    int i, ok = 1;
                    while (ok == 1) {
                        Produs null(-1, "null");
                        std::string alegere;
                        int c;
                        std::cout << "Bine ati venit" << '\n';
                        std::cout << "Pe ce raion doriti sa mergeti?" << '\n';
                        std::cout << "1.Dulciuri" << '\n' << "2.Bauturi" << '\n' << "3.Haine" << '\n';
                        std::cin >> i;
                        std::cout << '\n';
                        //cazuri de raioane
                        switch (i) {
                            case 1:
                                std::cout << "Selectati produsele pe care doriti sa le adaugati in cos:" << '\n';
                                dulce.AfiseazaListaProduse();
                                c = 1;
                                while (c == 1) {
                                    std::cin >> alegere;
                                    if (alegere == "atat")
                                        break;
                                    if (dulce.cautare(alegere) == null)
                                        std::cout << "Produsul nu a fost gasit." << '\n';
                                    else {
                                        client.AdaugaCos(dulce.cautare(alegere));
                                        std::cout << "Produsul ales a fost adaugat in cos cu succes." << '\n';
                                    }
                                    std::cout << "Mai adaugati ceva in cos?(Da/Nu)" << '\n';
                                    std::cin >> alegere;
                                    if (alegere == "Nu")
                                        c = 0;
                                    else
                                        std::cout << "Alegeti alt produs:" << '\n';
                                }
                                break;
                            case 2:
                                std::cout << "Selectati produsele pe care doriti sa le adaugati in cos:" << '\n';
                                bauturi.AfiseazaListaProduse();
                                c = 1;
                                while (c == 1) {
                                    std::cin >> alegere;
                                    if (bauturi.cautare(alegere) == null)
                                        std::cout << "Produsul nu a fost gasit." << '\n';
                                    else {
                                        client.AdaugaCos(bauturi.cautare(alegere));
                                        std::cout << "Produsul ales a fost adaugat in cos cu succes." << '\n';
                                    }
                                    std::cout << "Mai adaugati ceva in cos?(Da/Nu)" << '\n';
                                    std::cin >> alegere;
                                    if (alegere == "Nu")
                                        c = 0;
                                    else
                                        std::cout << "Alegeti alt produs:" << '\n';
                                }
                                break;
                            case 3:
                                std::cout << "Selectati produsele pe care doriti sa le adaugati in cos:" << '\n';
                                haine.AfiseazaListaProduse();
                                c = 1;
                                while (c == 1) {
                                    std::cin >> alegere;
                                    if (haine.cautare(alegere) == null)
                                        std::cout << "Produsul nu a fost gasit." << '\n';
                                    else{
                                        client.AdaugaCos(haine.cautare(alegere));
                                        std::cout << "Produsul ales a fost adaugat in cos cu succes." << '\n';
                                    }
                                    std::cout << "Mai adaugati ceva in cos?(Da/Nu)" << '\n';
                                    std::cin >> alegere;
                                    if (alegere == "Nu")
                                        c = 0;
                                    else
                                        std::cout << "Alegeti alt produs:" << '\n';
                                }
                                break;
                            default:
                                std::cout << "Raionul nu exista." << '\n';
                                break;
                        };
                        std::cout << "Mai doriti sa alegeti produse de pe alt raion?(Da/Nu):" << '\n';
                        std::cin >> alegere;
                        if (alegere == "Nu")
                            ok = 0;
                    }
                    std::cout << "Asa arata cosul dumneavostra:" << '\n';
                    client.AfiseazaListaProduseCos();
                    std::cout << "Suma totala a cosului dumneavoastra este de" << " " << client.sumaCos() << '\n';
                    std::cout << "Va rugam sa platiti suma afisata." << '\n';
                    client.cumparaProduse();
                    if(client.sumaCos()=>client.getBani()) {
                        Bon bon(client.getNume(), client.sumaCos());
                        std::cout << bon << '\n';
                    }
                    std::cout << "Mai sunt clienti?" << '\n';
                    std::string alegereclient;
                    std::cin >> alegereclient;

                    if (alegereclient == "Nu")
                        okmare2 = 0;
                }
            }
        else
            if(s == "Nu")
                std::cout << "O zi buna!";
            else
                std::cout << "Alegere introdusa gresit";


    for(Angajat* angajat : angajati){
        delete angajat;
    }

    
    return 0;
}
