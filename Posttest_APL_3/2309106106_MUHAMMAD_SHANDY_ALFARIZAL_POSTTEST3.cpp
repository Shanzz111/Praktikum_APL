#include <iostream>
#include <string>

using namespace std;
// Nama Pasien
// Nomor rekam medis / identitas yang dapat digunakan
// Alamat lengkap pasien tinggal sdh
// Data kelahiran pasien (tanggal, bulan, tahun, dan kota) sdh
// Jenis gender pasien sdh
// Kontak keluarga terdekat pasien
string nama_pasien[1000] = {"Muhammad Shandy Alfarizal", "Raihan fitri", "Vicky Ahmad"},alamat_pasien[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"},kelahiran_pasien[1000] = {"21 Mei 2005", "12 Oktober 2004", "29 Februari 2005"},gender_pasien[1000] = {"Laki-Laki", "Laki-Laki", "Laki-Laki"}, tempat[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"};
string gender;
string choose;
int nomor_medis_pasien[1000] = {1,2,3},kontak_keluarga[1000] = {234234,45345,356456},ukuran = 3;

string jenis_kelamin(){ //Fungsi
    x:
    cout << "Gender Pasien [ L/W ] : ";
    cin >> gender;
    if(gender == "L" || gender == "l"){
        return "Laki - Laki";    
    } else if(gender == "W" || gender == "w"){
        return "Wanita";
    } else {
        cout << "Anda Salah Input" << endl;
        goto x;
    } 
}

bool login(){ //Fungsi
    string nama,nim;
    cout << "NAMA : ";
    cin >> nama;
    cout << "NIM  : ";
    cin >> nim;
    if((nama == "Shandy" ) && (nim == "2309106106")){
        return true;
    } else{
        return false;
    }
}

void tambah(){ //Rekursif
    cout << "Nama Pasien : ";
    cin.ignore(); 
    getline(cin,nama_pasien[ukuran]);

    cout << "Nomor Rekam Medis Pasien : ";
    cin >> nomor_medis_pasien[ukuran];

    cout << "Alamat Pasien : ";
    cin.ignore(); 
    getline(cin,alamat_pasien[ukuran]);

    cout << "Tempat Lahir Pasien : ";
    cin.ignore(); 
    getline(cin,tempat[ukuran]);

    cout << "Tanggal Lahir Pasien :";
    cin.ignore(); 
    getline(cin,kelahiran_pasien[ukuran]);

    gender_pasien[ukuran] = jenis_kelamin();

    cin.ignore();
    cout << "Kontak Keluarga Pasien : ";
    cin >> kontak_keluarga[ukuran];
    ukuran++;
    p:
    cout << "Apakah ingin menambahkan data pasien lagi [ Y/N ] ? ";
    cin >> choose;
    if (choose == "Y" || choose == "y") {
        tambah();
    } else if (choose == "n" || choose == "N") {
    } else {
        cout << "Anda Salah Input" << endl;
        goto p;
    }
}

void tampil(){ //Prosedur
    for(int i = 0; i < ukuran; i++){
        cout << "Nama Pasien : " << nama_pasien[i] << endl;
        cout << "Nomor Pasien : " << nomor_medis_pasien[i] << endl;
        cout << "Alamat Pasien : " << alamat_pasien[i] << endl;
        cout << "Tempat Lahir Pasien : " << tempat[i] << endl;
        cout << "Tanggal Lahir Pasien : " << kelahiran_pasien[i] << endl;
        cout << "Gender Pasien : " << gender_pasien[i] << endl;
        cout << "Kontak Keluarga Pasien : " << kontak_keluarga[i] << endl;
        cout << endl;
    }
    system("pause");
}

void ubah(){ //Prosedur
    int cari;
    cout << "Nomor Pasien : ";
    cin >> cari;
    for(int i = 0; i < ukuran; i++){
        if(cari == nomor_medis_pasien[i]){
            cout << "Nama Pasien : ";
            cin.ignore(); 
            getline(cin,nama_pasien[i]);

            cout << "Nomor Rekam Medis Pasien : ";
            cin >> nomor_medis_pasien[i];

            cout << "Alamat Pasien : ";
            cin.ignore(); 
            getline(cin,alamat_pasien[i]);

            cout << "Tempat Lahir Pasien : ";
            cin.ignore(); 
            getline(cin,tempat[i]);

            cout << "Tanggal Lahir Pasien :";
            cin.ignore(); 
            getline(cin,kelahiran_pasien[i]);
            
            gender_pasien[ukuran] = jenis_kelamin();

            cout << "Kontak Keluarga Pasien : ";
            cin >> kontak_keluarga[i];
            break;
        }
    }
}

void hapus(){//Prosedur
    int hapus;
    cout << "Nomor Pasien : ";
    cin >> hapus;
    for(int i = 0; i < ukuran; i++){
        if(hapus == nomor_medis_pasien[i]){
            nama_pasien[i] = nama_pasien[i+1];
            nomor_medis_pasien[i] = nomor_medis_pasien[i+1];
            alamat_pasien[i] = alamat_pasien[i+1];
            tempat[i] = tempat[i + 1];
            kelahiran_pasien[i] = kelahiran_pasien[i+1];
            gender_pasien[i] = gender_pasien[i+1];
            kontak_keluarga[i] = kontak_keluarga[i+1];
            ukuran -= 1;
        }
    }
}

int main(){
    while(1){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   HALAMAN LOGIN   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] LOGIN       ::" << endl;
        cout << ":: [ 2 ] KELUAR      ::" << endl;
        cout << "=======================" << endl;

        int tanya;
        cout << "PILIH : ";
        cin >> tanya;
        if(tanya == 1){
            for(int i = 0 ; i <= 3 ; i++){
                if(i == 3){
                    exit(1);
                }
                system("cls");
                cout << "=======================" << endl;
                cout << "::   HALAMAN LOGIN   ::" << endl;
                cout << "=======================" << endl;
                if(login()){
                    system("cls");
                    menu:
                    cout << "==================================" << endl;
                    cout << "::           MENU USER          ::" << endl;
                    cout << "==================================" << endl;
                    cout << ":: [ 1 ] MASUKKAN DATA PASIEN   ::" << endl;
                    cout << ":: [ 2 ] TAMPILKAN DATA PASIEN  ::" << endl;
                    cout << ":: [ 3 ] UBAH DATA PASIEN       ::" << endl;
                    cout << ":: [ 4 ] HAPUS DATA PASIEN      ::" << endl;
                    cout << ":: [ 5 ] KELUAR                 ::" << endl;
                    cout << "==================================" << endl;
                    enum opsi{CREATE = 1, READ, UPDATE, DELETE, KELUAR};

                    int pilih;
                    cout << "PILIH : ";
                    cin >> pilih;

                    switch(pilih){
                        case CREATE:
                            tambah();
                            system("cls");
                            goto menu;
                            break;
                        case READ:
                            tampil();
                            system("cls");
                            goto menu;
                            break;
                        case UPDATE:
                            ubah();
                            system("cls");
                            goto menu;
                            break;
                        case DELETE:
                            hapus();
                            system("cls");
                            goto menu;
                            break;
                        case KELUAR:
                            break;
                            system("cls");
                        default:
                            cout << "Anda Salah Input" << endl;
                            system("pause");
                            goto menu;
                    }
                }else{
                    cout << "Anda Salah Input" << endl;
                    system("pause");
                    continue;
                }
                break;
            }   
        } else if (tanya == 2){
            exit(1);
            system("cls");
        } else {
            cout << "Anda Salah Input" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}