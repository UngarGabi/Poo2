#include<iostream>
#include<string>
#include<vector>

class Client {
private:
    std::string nume;
    double bani;
public:
    Client() = default;
    Client(std::string nume, double bani) : nume(nume), bani(bani) {}
    friend std::istream &operator>>(std::istream &in, Client &client);
};

std::istream& operator>>(std::istream& in, Client& client){
    std::cout<<"Nume client:";
    in>>client.nume;
    std::cout<<"Suma de bani pe care o are:";
    in>>client.bani;
    return in;
}

class Produs {
private:
    double pret;
    std::string nume;
public:
    Produs() = default;
    Produs(double pret, std::string nume) : pret(pret), nume(nume) {}
    friend std::ostream &operator<<(std::ostream &out, Produs &produs);
    std::string getNume() {
        return nume;
    }
    bool operator==(Produs produs) {
        return (this->nume == produs.nume);
    }
};

std::ostream& operator<<(std::ostream& out, Produs& produs){
    out<<"Nume produs: "<<produs.nume<<" Pret produs: "<<produs.pret<<'\n';
    return out;
}

class Magazin {
public:
    virtual void AdaugaProdus(Produs produs) = 0;
    virtual void EliminaProdus(Produs produs) = 0;
    virtual void AfiseazaListaProduse() = 0;
};

class RaionHaine: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseHaine;
public:
    void AdaugaProdus(Produs produs) override {
        int n = produseHaine.size();
        produseHaine.push_back(produs);
        produseHaine.resize(n + 1);
    }

    void EliminaProdus(Produs produs) override {
        int n = produseHaine.size();
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (produseHaine[i] == produs) {
                produseHaine.erase(produseHaine.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<< '\n';
                produseHaine.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<<'\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i< produseHaine.size(); i++)
            std::cout << produseHaine[i] << " ";
    }
};

class RaionDulce: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseDulci;
public:
    void AdaugaProdus(Produs produs) override {
        int n = produseDulci.size();
        produseDulci.push_back(produs);
        produseDulci.resize(n + 1);
    }

    void EliminaProdus(Produs produs) override {
        int n = produseDulci.size();
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (produseDulci[i] == produs) {
                produseDulci.erase(produseDulci.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<< '\n';
                produseDulci.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<<'\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i< produseDulci.size(); i++)
            std::cout << produseDulci[i] << " ";
    }
};

class RaionBauturi: public Magazin {
private:
    std::string nume;
    int nrproduse;
    std::vector<Produs> produseBauturi;
public:
    void AdaugaProdus(Produs produs) override {
        int n = produseBauturi.size();
        produseBauturi.push_back(produs);
        produseBauturi.resize(n + 1);
    }

    void EliminaProdus(Produs produs) override {
        int n = produseBauturi.size();
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (produseBauturi[i] == produs) {
                produseBauturi.erase(produseBauturi.begin() + i);
                ok = 0;
                std::cout << "Produsul " << produs << " a fost eliminat"<< '\n';
                produseBauturi.resize(n - 1);
                break;
            }
        }
        if (ok == 1)
            std::cout << "Produsul ales nu exista in magazinul nostru"<<'\n';
    }

    void AfiseazaListaProduse() override {
        for (int i = 0; i< produseBauturi.size(); i++)
            std::cout << produseBauturi[i] << " ";
    }
};


int main() {
    Produs ciocolata(20,"Milka");
    Produs jeleu(10,"Haribo");
    Produs biscuite(30,"Oreo");

    Produs suc(5,"Fanta");
    Produs vin(10,"Mateus");
    Produs apa(30,"Aqua");

    Produs tricou(50,"Tricou albastru");
    Produs sosete(10,"Sosete albe");
    Produs caciula(30,"Caciula neagra");

    RaionDulce dulce;
    RaionHaine haine;
    RaionBauturi bauturi;

    dulce.AdaugaProdus(ciocolata);
    dulce.AdaugaProdus(biscuite);
    dulce.AdaugaProdus(jeleu);
    dulce.AfiseazaListaProduse();

    bauturi.AdaugaProdus(vin);
    bauturi.AdaugaProdus(suc);
    bauturi.AdaugaProdus(apa);
    bauturi.EliminaProdus(apa);
    bauturi.AfiseazaListaProduse();

    haine.AdaugaProdus(tricou);
    haine.AdaugaProdus(sosete);
    haine.AdaugaProdus(caciula);
    haine.AfiseazaListaProduse();

    return 0;
}
