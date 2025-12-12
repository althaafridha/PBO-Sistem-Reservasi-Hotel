#include <iostream>
#include <iomanip> 
using namespace std;

class Kamar {
protected:
    int malam;
    int tamu;

public:
    Kamar(int m, int t) : malam(m), tamu(t) {}

    virtual double hitungSubtotal() = 0;
    virtual double hitungPajak(double subtotal) = 0;
    virtual double hitungTotal() = 0;
    virtual void infoFasilitas() = 0;
};

class Standard : public Kamar {
public:
    Standard(int m, int t) : Kamar(m, t) {}

    double hitungSubtotal() override {
        double hargaDasar = 150000 * malam;
        return hargaDasar;
    }

    double hitungPajak(double subtotal) override {
        double pajak = subtotal * 0.10;
        return pajak;
    }

    double hitungTotal() override {
        double subtotal = hitungSubtotal();
        double pajak = hitungPajak(subtotal);
        double total = subtotal + pajak;

        if (malam >= 5)
            total *= 0.95;

        return total;
    }

    void infoFasilitas() override {
        cout << "Fasilitas: AC dan TV\n";
    }
};

class Deluxe : public Kamar {
public:
    Deluxe(int m, int t) : Kamar(m, t) {}

    double hitungSubtotal() override {
        double hargaDasar = 300000 * malam;
        double tambahan = 0;

        if (tamu > 2) {
            tambahan = (tamu - 2) * 25000 * malam;
        }

        return hargaDasar + tambahan;
    }

    double hitungPajak(double subtotal) override {
        return subtotal * 0.10;
    }

    double hitungTotal() override {
        double subtotal = hitungSubtotal();
        double pajak = hitungPajak(subtotal);
        double total = subtotal + pajak;

        if (malam >= 7)
            total *= 0.90;

        return total;
    }

    void infoFasilitas() override {
        cout << "Fasilitas: AC, TV, dan Sarapan\n";
    }
};

class Suite : public Kamar {
public:
    Suite(int m, int t) : Kamar(m, t) {}

    double hitungSubtotal() override {
        double hargaDasar = 500000 * malam;
        double tambahan = 0;

        if (tamu > 2) {
            tambahan = (tamu - 2) * 50000 * malam;
        }

        return hargaDasar + tambahan;
    }

    double hitungPajak(double subtotal) override {
        return subtotal * 0.12;
    }

    double hitungTotal() override {
        double subtotal = hitungSubtotal();
        double pajak = hitungPajak(subtotal);
        double total = subtotal + pajak;

        if (malam >= 3)
            total *= 0.85;

        return total;
    }

    void infoFasilitas() override {
        cout << "Fasilitas: Sarapan, Kolam Renang, AC, dan TV\n";
    }
};

int main() {
    int tipe, malam, tamu;

    cout << "=== RESERVASI HOTEL ===\n";

    cout << "Pricelist Kamar\n";
    cout << "Standard Room : Rp. 150.000 / malam\n";
    cout << "Deluxe Room : Rp. 300.000 / malam\n";
    cout << "Suite Room : Rp. 500.000 / malam\n\n";

    cout << "Harga diatas belum termasuk pajak\n";

    cout << "1. Standard Room\n";
    cout << "2. Deluxe Room\n";
    cout << "3. Suite Room\n";
    cout << "Pilih tipe kamar: ";
    cin >> tipe;

    cout << "Jumlah malam menginap: ";
    cin >> malam;

    cout << "Jumlah tamu: ";
    cin >> tamu;

    Kamar* k;
    cout << fixed << setprecision(0); 
    if (tipe == 1)
        k = new Standard(malam, tamu);
    else if (tipe == 2)
        k = new Deluxe(malam, tamu);
    else
        k = new Suite(malam, tamu);

    cout << "\n=== RINCIAN RESERVASI ===\n";
    k->infoFasilitas();

    double subtotal = k->hitungSubtotal();
    double pajak = k->hitungPajak(subtotal);
    double total = k->hitungTotal();

    cout << "\n--- BILL PEMBAYARAN ---\n";
    cout << "Harga Kamar: Rp. " << subtotal << endl;
    cout << "Pajak & Tambahan: Rp. " << pajak << endl;
    cout << "Total Pembayaran: Rp. " << total << endl;

    delete k;
    return 0;
}
