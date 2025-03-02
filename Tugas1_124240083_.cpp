#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits> // untuk numeric_limits

using namespace std;

struct barang
{
    int jumlah, harga;
    string nama;
};
barang brg[99999];
void mencari();
int index;

void input(int jumlah);
void tampil();
void sequentialSearchByPrice(int target);
int binarySearchByName(string nama);
void berdasarnama(char konfirmasi);
void berdasarkanharga(char konfirmasi);

int main(int argc, char const *argv[])
{
    int menu, jumlah;

    while (1)
    {
        cout << setfill('=') << setw(20) << "" << " Toko Kelontong 2-B " << setw(20) << "" << endl;
        cout << setfill('=') << setw(27) << "" << " MENU " << setw(27) << "";
        cout << setfill('=') << setw(81) << endl;
        cout << "\n1. Input Data Barang" << endl;
        cout << "2. Tampilkan Data Barang" << endl;
        cout << "3. Cari Data Barang" << endl;
        cout << "4. Keluar" << endl;
        
        while (1)
        {
            cout << "Masukkan Pilihan : ";
            cin >> menu;

        // error handling
        if (cin.fail())
        {
            cin.clear();
            // menghapus
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
            cout << "Input tidak valid, coba lagi! \n";
        }else { break;}
        }
        
        
        system("cls");

        switch (menu)
        {
        case 1:
            input(jumlah);
            break;

        case 2:
            tampil();

            break;

        case 3:
            mencari();

            break;

        case 4:
            return 0;
            break;

        default:
            cout << "Input tidak valid, coba lagi! \n";
            break;
        }
    }
}

void input(int jumlah)
{
    char konfirmasi;

    cout << setfill('=') << setw(20) << "" << " Toko Kelontong 2-B " << setw(20) << "" << endl;
    cout << setfill('=') << setw(21) << "" << " Input Data Barang " << setw(20) << "";
    cout << setfill('=') << setw(105) << endl;
    while (true)
    {
        cout << "\nBerapa Data Barang yang Ingin di Masukkan : ";
        cin >> jumlah;
        // error handling
        if (cin.fail())
        {
            cin.clear();
            // menghapus
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
            cout << "Input tidak valid, coba lagi! \n";
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Barang ke-" << index + 1 << endl;
        cout << "1.     Nama   : ";
        cin.ignore();
        getline(cin, brg[index].nama);

        while (true)
        {
            cout << "2.     Jumlah : ";
            cin >> brg[index].jumlah;
            if (cin.fail())
            {
                cin.clear();
                // menghapus
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
                cout << "Input tidak valid, coba lagi! \n";
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "3.     Harga : ";
            cin >> brg[index].harga;
            if (cin.fail())
            {
                cin.clear();
                // menghapus
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
                cout << "Input tidak valid, coba lagi! \n";
            }
            else
            {
                break;
            }
        }

        index++;
    }
    cout << setfill('=') << setw(110) << endl;
    while (1)
    {
        cout << "\nApakah Anda Ingin Kembali Ke Menu Awal ? (y/t) : ";
    cin >> konfirmasi;
    if (konfirmasi == 'y' or konfirmasi == 'Y')
    {
        system("cls");
        return;
    }
    else if (konfirmasi == 't' or konfirmasi == 'T')
    {
        system("cls");
        input(jumlah);
    }else{
        cout << "\nTidak Valid" << endl;
    }
    }
    
    
}

void tampil()
{
    char konfirmasi;

    cout << setfill('=') << setw(20) << "" << " Toko Kelontong 2-B " << setw(20) << "" << endl;
    cout << setfill('=') << setw(23) << "" << " Data Barang " << setw(24) << "";
    cout << setfill('=') << setw(70) << endl;

    // Mengurutkan data berdasarkan nama menggunakan bubble sort
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (brg[j].nama > brg[j + 1].nama)
            {
                // Tukar barang
                // Tukar seluruh data barang
                barang tempBarang = brg[j]; // Simpan data barang sementara
                brg[j] = brg[j + 1];        // Tukar barang j dengan j+1
                brg[j + 1] = tempBarang;    // Simpan barang sementara ke j+1
            }
        }
    }

    for (int i = 0; i < index; i++)
    {
        cout << "\nIndex ke-" << i << endl;
        cout << "1. Nama : " << brg[i].nama << endl;
        cout << "2. Jumlah : " << brg[i].jumlah << endl;
        cout << "3. Harga  : " << brg[i].harga << endl;
    }

    cout << setfill('=') << setw(110) << endl;
    while (1)
    {
        cout << "\nApakah Anda Ingin Kembali Ke Menu Awal ? (y/t) : ";
    cin >> konfirmasi;
    if (konfirmasi == 'y' or konfirmasi == 'Y')
    {
        system("cls");
        return;
    }
    else if (konfirmasi == 't' or konfirmasi == 'T')
    {
        system("cls");
        tampil();
    }else { cout << "\nTidak Valid!!" << endl;}
    }
    
    
}

void sequentialSearchByPrice(int target)
{
    bool found = false;
    for (int i = 0; i < index; i++)
    {
        if (brg[i].harga == target)
        {
            cout << "\nBarang ditemukan di index " << i << endl;
            cout << "1. Nama   : " << brg[i].nama << endl;
            cout << "2. Jumlah : " << brg[i].jumlah << endl;
            cout << "3. Harga  : " << brg[i].harga << endl;
            found=true;
        }
    }

    if(found==false){
        cout << "\nBarang tidak ditemukan!" << endl;
    }
    

}

int binarySearchByName(string nama)
{
    int low = 0;
    int high = index - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (brg[mid].nama == nama)
        {
            return mid;
        }
        else if (brg[mid].nama < nama)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // Barang tidak ditemukan
}

void mencari(){
    int search;
    char konfirmasi;

    cout << setfill('=') << setw(20) << "" << " Toko Kelontong 2-B " << setw(20) << "" << endl;
    cout << setfill('=') << setw(21) << "" << " Search Data Barang " << setw(20) << "";
    cout << setfill('=') << setw(85) << endl;
    cout << "\n Pilih Metode Search : " << endl;
    cout << "1. Binary Search (nama)" << endl;
    cout << "2. Sequential Search (harga)" << endl;
    cout << "3. Kembali" << endl;
    while (1)
    {
        cout << "Pilihan Anda : ";
        cin >> search;
        // error handling
        if (cin.fail())
        {
            cin.clear();
            // menghapus
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
            cout << "Input tidak valid, coba lagi! \n";
        }
        else
        {
            break;
        }
    }

    if (search == 1)
    {
        berdasarnama(konfirmasi);


    }else if (search==2){
        berdasarkanharga(konfirmasi);

    }else if (search==3)
    {
        system("cls");
        return;
    } else if (search > 3 or search < 1){
    cout << "Hanya 1-3 !!" << endl;
    cout << "\nTekan Enter Untuk Mengulangi . . . " << endl;
    getch();
    system("cls");
    mencari();

    }
    
    

}

void berdasarnama(char konfirmasi){
    string nama;
    cout << "Masukkan nama barang yang dicari: ";
    cin.ignore();
    getline(cin, nama);
    int foundIndex = binarySearchByName(nama);
    if (foundIndex != -1)
    {
        cout << "\nBarang ditemukan di index " << foundIndex << endl;
        cout << "1. Nama   : " << brg[foundIndex].nama << endl;
        cout << "2. Jumlah : " << brg[foundIndex].jumlah << endl;
        cout << "3. Harga  : " << brg[foundIndex].harga << endl;
    }
    else
    {
        cout << "Barang tidak ditemukan!" << endl;
    }

    cout << setfill('=') << setw(110) << endl;

    while (1)
    {
        cout << "\nApakah Anda Ingin Kembali Ke Menu Awal ? (y/t) : ";
        cin >> konfirmasi;
        if (konfirmasi == 'y' or konfirmasi == 'Y')
        {
            system("cls");
            return;
        }
        else if (konfirmasi == 't' or konfirmasi == 'T')
        {
            system("cls");
            mencari();
        }else{
            cout << "\nTidak Valid!!!" << endl;
        }
    }
    


}

void berdasarkanharga(char konfirmasi){

    int target;
    while (1)
    {
        cout << "Masukkan harga barang yang dicari: ";
        cin >> target;
        if (cin.fail())
    {
        cin.clear();
        // menghapus
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mengabaikan
        cout << "Input tidak valid, coba lagi! \n";
    }
    else
    {
        break;
    }
    }
        sequentialSearchByPrice(target);

        cout << setfill('=') << setw(110) << endl;
        while (1)
        {
            cout << "\nApakah Anda Ingin Kembali Ke Menu Awal ? (y/t) : ";
            cin >> konfirmasi;
            if (konfirmasi == 'y' or konfirmasi == 'Y')
            {
                system("cls");
                return;
            }
            else if (konfirmasi == 't' or konfirmasi == 'T')
            {
                system("cls");
                mencari();
            }else{
                cout << "\nTidak Valid" << endl;
            }
        }
        
       


}