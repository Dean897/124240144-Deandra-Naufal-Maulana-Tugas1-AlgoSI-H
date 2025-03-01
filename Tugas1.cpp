#include <iostream>
#include <stdlib.h>
using namespace std;

string soldierType[3] = {"Infantry", "Archer", "Cavalry"};

struct pasukan
{
    int id;
    string nama;
    string type;
    int jumlah;
};

void tambahPasukan(pasukan p[100], int &jml_indeks)
{
    string nama;
    bool found;
    int i = 0;

    cin.ignore();
    do
    {
        found = false;
        cout << "Input Nama General : ";
        getline(cin, nama);

        for (i = 0; i < jml_indeks; i++)
        {
            if (p[i].nama == nama)
            {
                cout << "Nama General sudah ada! Silakan masukkan nama lain.\n";
                found = true;
                break;
            }
        }
    } while (found);

    p[jml_indeks].nama = nama;

    found = false;
    while (!found)
    {
        cout << "Input Soldier Type (Infantry/Archer/Cavalry): ";
        cin >> p[jml_indeks].type;

        for (i = 0; i < 3; i++)
        {
            if (p[jml_indeks].type == soldierType[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Tipe pasukan tidak valid! Silakan masukkan lagi.\n";
        }
    }
    cout << "Input Soldier Quantity: ";
    while (!(cin >> p[jml_indeks].jumlah) || p[jml_indeks].jumlah <= 0)
    {
        cout << "Error: Masukkan jumlah yang valid (harus angka positif).\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input Soldier Quantity: ";
    }
    jml_indeks++;
}
void cariPasukan(pasukan p[100], int &jml_indeks)
{
    int awal = 0, akhir = jml_indeks - 1, tengah;
    string cari;
    bool found = false;

    cin.ignore();
    cout << "Input Nama General yang Ingin Dicari : ";
    getline(cin, cari);

    while (!found && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;

        if (p[tengah].nama == cari)
        {
            found = true;
        }
        else if (p[tengah].nama > cari)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }

    if (found)
    {
        cout << "ID = " << tengah + 1 << endl;
        cout << "Soldier Type = " << p[tengah].type << endl;
        cout << "Soldier Quantity = " << p[tengah].jumlah << endl;
    }
    else
    {
        cout << "General " << cari << " tidak ditemukan dalam array." << endl;
    }
}
int main()
{
    string lnjt;
    int menu;
    pasukan p[100];
    int jml_indeks = 0;

    do
    {
        system("cls");
        cout << "Menu\n";
        cout << "1. Tambah Pasukan\n";
        cout << "2. Cari Pasukan\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahPasukan(p, jml_indeks);
            break;
        case 2:
            cariPasukan(p, jml_indeks);
            break;
        case 3:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Menu tidak valid! Silakan pilih menu yang tersedia.\n";
            break;
        }
        cout << "Apakah Anda ingin melanjutkan? (y/n) ";
        cin >> lnjt;
    } while (lnjt == "y" || lnjt == "Y");
    system("cls");
    return 0;
}