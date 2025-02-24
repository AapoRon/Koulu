//osa1

#include <iostream>

#include <string>



class Pankkitili {

protected:

    std::string omistaja;

    double saldo;



public:

    Pankkitili(std::string nimi) : omistaja(nimi), saldo(0) {

        std::cout << "Pankkitili luotu: " << omistaja << std::endl;

    }

    virtual ~Pankkitili() {}



    double getBalance() const {

        return saldo;

    }



    virtual bool deposit(double amount) {

        if (amount < 0) return false;

        saldo += amount;

        return true;

    }



    virtual bool withdraw(double amount) {

        if (amount < 0 || amount > saldo) return false;

        saldo -= amount;

        return true;

    }

};



class Luottotili : public Pankkitili {

private:

    double luottoRaja;



public:

    Luottotili(std::string nimi, double raja) : Pankkitili(nimi), luottoRaja(raja) {}



    bool withdraw(double amount) override {

        if (amount < 0 || saldo - amount < -luottoRaja) return false;

        saldo -= amount;

        return true;

    }



    bool deposit(double amount) override {

        if (amount < 0 || saldo + amount > 0) return false;

        saldo += amount;

        return true;

    }

};



class Asiakas {

private:

    std::string nimi;

    Pankkitili pankkitili;

    Luottotili luottotili;



public:

    Asiakas(std::string nimi, double luottoRaja)

        : nimi(nimi), pankkitili(nimi), luottotili(nimi, luottoRaja) {}



    void showSaldo() {

        std::cout << "Pankkitilin saldo: " << pankkitili.getBalance() << " euroa" << std::endl;

        std::cout << "Luottotilin saldo: " << luottotili.getBalance() << " euroa" << std::endl;

    }



    void talletus(double amount) {

        if (pankkitili.deposit(amount)) {

            std::cout << "Talletus onnistui! Uusi pankkitilin saldo: " << pankkitili.getBalance() << " euroa" << std::endl;

        } else {

            std::cout << "Talletus epäonnistui!" << std::endl;

        }

    }



    void nosto(double amount) {

        if (pankkitili.withdraw(amount)) {

            std::cout << "Nosto onnistui! Uusi pankkitilin saldo: " << pankkitili.getBalance() << " euroa" << std::endl;

        } else {

            std::cout << "Nosto epäonnistui!" << std::endl;

        }

    }



    void luotonMaksu(double amount) {

        if (luottotili.deposit(amount)) {

            std::cout << "Luoton maksu onnistui! Uusi luottotilin saldo: " << luottotili.getBalance() << " euroa" << std::endl;

        } else {

            std::cout << "Luoton maksu epäonnistui!" << std::endl;

        }

    }



    void luotonNosto(double amount) {

        if (luottotili.withdraw(amount)) {

            std::cout << "Luoton nosto onnistui! Uusi luottotilin saldo: " << luottotili.getBalance() << " euroa" << std::endl;

        } else {

            std::cout << "Luoton nosto epäonnistui!" << std::endl;

        }

    }

};



int main() {

    Asiakas asiakas("Matti Meikalainen", 200);



    asiakas.talletus(100);

    asiakas.nosto(50);

    asiakas.luotonNosto(150);

    asiakas.luotonMaksu(50);

    asiakas.showSaldo();



    return 0;

}







//osa 2



#include <iostream>

#include <string>



class Pankkitili {

private:

    double saldo;

public:

    Pankkitili(double alkuSaldo) : saldo(alkuSaldo) {}

    bool nosto(double maara) {

        if (saldo >= maara) {

            saldo -= maara;

            return true;

        }

        return false;

    }

    void talletus(double maara) {

        saldo += maara;

    }

    double getSaldo() const {

        return saldo;

    }

};



class Asiakas {

private:

    std::string nimi;

    Pankkitili kayttotili;

public:

    Asiakas(std::string n, double saldo) : nimi(n), kayttotili(saldo) {}

    std::string getNimi() const {

        return nimi;

    }

    void showSaldo() const {

        std::cout << nimi << " saldo: " << kayttotili.getSaldo() << " EUR" << std::endl;

    }

    bool tiliSiirto(double maara, Asiakas &vastaanottaja) {

        if (kayttotili.nosto(maara)) {

            vastaanottaja.kayttotili.talletus(maara);

            return true;

        }

        return false;

    }

};



int main() {

    Asiakas asiakas1("Matti", 1000.0);

    Asiakas asiakas2("Maija", 500.0);



    asiakas1.showSaldo();

    asiakas2.showSaldo();



    std::cout << "Matti siirtaa 200 EUR Maijalle..." << std::endl;

    if (asiakas1.tiliSiirto(200, asiakas2)) {

        std::cout << "Siirto onnistui!" << std::endl;

    } else {

        std::cout << "Siirto epaonnistui!" << std::endl;

    }



    asiakas1.showSaldo();

    asiakas2.showSaldo();



    return 0;

}
